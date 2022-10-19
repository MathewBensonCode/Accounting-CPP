#include "account.hpp"

uint Account::Id() const
{
    return m_id;
}

void Account::Id(const uint id)
{
    m_id = id;
}

std::string_view Account::name() const
{
    return m_name;
};

void Account::name(std::string_view name)
{
    m_name = name;
}

Account::Account(std::string_view name)
  : m_name(name)
{
}

float Account::amount() const
{
    return m_amount;
}

void Account::amount(float newamount)
{
    m_amount = newamount;
}

const std::vector<std::shared_ptr<Transaction>> &Account::Debits() const
{
    return m_debits;
}

const std::vector<std::shared_ptr<Transaction>> &Account::Credits() const
{
    return m_credits;
}
