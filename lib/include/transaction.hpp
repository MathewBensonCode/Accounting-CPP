#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <memory>

#include <odb/core.hxx>

class Account;

class Transaction
{
    unsigned int m_id{};
    double m_amount{};
    std::weak_ptr<Account> m_debitAccount{};
    std::weak_ptr<Account> m_creditAccount{};

    friend odb::access;

  public:
    [[nodiscard]] unsigned int Id() const;
    void Id(unsigned int);

    [[nodiscard]] double Amount() const;
    void Amount(double);

    [[nodiscard]] const std::weak_ptr<Account> &DebitAccount() const;
    void DebitAccount(const std::weak_ptr<Account> &);

    [[nodiscard]] const std::weak_ptr<Account> &CreditAccount() const;
    void CreditAccount(const std::weak_ptr<Account> &);
};


#ifdef ODB_COMPILER
#include "account.hpp"
#pragma db object(Transaction) table("Transactions")
#pragma db member(Transaction::m_id) id
#pragma db member(Transaction::m_debitAccount) not_null inverse(m_debits)
#pragma db member(Transaction::m_creditAccount) not_null inverse(m_credits)


#endif

#endif
