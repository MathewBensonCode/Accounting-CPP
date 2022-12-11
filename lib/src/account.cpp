#include "account.hpp"

unsigned int Account::Id() const
{
    return m_id;
}

void Account::Id(const unsigned int newid)
{
    m_id = newid;
}

const std::string & Account::Name() const
{
    return m_name;
}

void Account::Name(const std::string & name)
{
    m_name = name;
}

const std::vector<std::weak_ptr<Transaction>> &Account::Debits() const
{
    return m_debits;
}

const std::vector<std::weak_ptr<Transaction>> &Account::Credits() const
{
    return m_credits;
}
