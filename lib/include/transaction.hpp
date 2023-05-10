#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <memory>

#include <odb/core.hxx>

class Account;
class SourceDocument;

class Transaction
{
    unsigned int m_id{};
    double m_amount{};
    std::shared_ptr<Account> m_debitaccount{};
    std::shared_ptr<Account> m_creditaccount{};
    std::shared_ptr<SourceDocument> m_sourcedocument{};

    friend odb::access;

  public:
    [[nodiscard]] unsigned int Id() const;
    void Id(unsigned int);

    [[nodiscard]] double Amount() const;
    void Amount(double);

    [[nodiscard]] const std::shared_ptr<Account> &DebitAccount() const;
    void DebitAccount(const std::shared_ptr<Account> &);

    [[nodiscard]] const std::shared_ptr<Account> &CreditAccount() const;
    void CreditAccount(const std::shared_ptr<Account> &);

    [[nodiscard]] const std::shared_ptr<SourceDocument> &Sourcedocument() const;
};


#ifdef ODB_COMPILER
#include "account.hpp"
#include "sourcedocument.hpp"
#pragma db object(Transaction) table("Transactions") pointer(std::shared_ptr)
#pragma db member(Transaction::m_id) id
#pragma db member(Transaction::m_debitaccount) not_null column("DebitAccountId")
#pragma db member(Transaction::m_creditaccount) not_null column("CreditAccountId")
#pragma db member(Transaction::m_sourcedocument) not_null column("SourceDocumentId")
#endif

#endif
