#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string_view>
#include <string>
#include <memory>
#include <vector>

#include <odb/core.hxx>

class Transaction;

class Account 
{
    unsigned int m_id{};
    std::string m_name;
    float m_amount{ 0.0F };
    std::vector<std::weak_ptr<Transaction>> m_debits{};
    std::vector<std::weak_ptr<Transaction>> m_credits{};

    friend odb::access;

  public:

    [[nodiscard]] unsigned int Id() const;
    void Id(unsigned int);

    [[nodiscard]] std::string_view Name() const;
    void Name(std::string_view);

    [[nodiscard]] float Amount() const;
    void Amount(float);

    [[nodiscard]] const std::vector<std::weak_ptr<Transaction>> &Debits() const;
    [[nodiscard]] const std::vector<std::weak_ptr<Transaction>> &Credits() const;

};

#ifdef ODB_COMPILER
#include "transaction.hpp"
#pragma db object(Account) table("Accounts")
#pragma db member(Account::m_id) id
#pragma db member(Account::m_debits) inverse(m_debitaccount)
#pragma db member(Account::m_credits) inverse(m_creditaccount)

#endif


#endif
