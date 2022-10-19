#include "transaction.hpp"

uint Transaction::Id() const{
    return m_id;
}

void Transaction::Id(uint id){
    m_id = id;
}

double Transaction::Amount() const{
    return m_amount;
}

void Transaction::Amount(const double amount){
    m_amount = amount;
}

std::shared_ptr<Account> Transaction::DebitAccount() const{
    return m_debitAccount;
}

void Transaction::DebitAccount(const std::shared_ptr<Account> &debitAccount){
    m_debitAccount = debitAccount; 
}

std::shared_ptr<Account> Transaction::CreditAccount() const{
    return m_debitAccount;
}

void Transaction::CreditAccount(const std::shared_ptr<Account> &debitAccount){
    m_debitAccount = debitAccount; 
}
