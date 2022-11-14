#include "transaction.hpp"

unsigned int Transaction::Id() const{
    return m_id;
}

void Transaction::Id(unsigned int newid){
    m_id = newid;
}

double Transaction::Amount() const{
    return m_amount;
}

void Transaction::Amount(const double amount){
    m_amount = amount;
}

const std::weak_ptr<Account> &Transaction::DebitAccount() const{
    return m_debitAccount;
}

void Transaction::DebitAccount(const std::weak_ptr<Account> &debitAccount){
    m_debitAccount = debitAccount; 
}

const std::weak_ptr<Account> &Transaction::CreditAccount() const{
    return m_creditAccount;
}

void Transaction::CreditAccount(const std::weak_ptr<Account> &creditAccount){
    m_creditAccount = creditAccount; 
}
