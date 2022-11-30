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

const std::shared_ptr<Account> &Transaction::DebitAccount() const{
    return m_debitaccount;
}

void Transaction::DebitAccount(const std::shared_ptr<Account> &debitAccount){
    m_debitaccount = debitAccount; 
}

const std::shared_ptr<Account> &Transaction::CreditAccount() const{
    return m_creditaccount;
}

void Transaction::CreditAccount(const std::shared_ptr<Account> &creditAccount){
    m_creditaccount = creditAccount; 
}

const std::shared_ptr<SourceDocument> &Transaction::Sourcedocument() const{
    return m_sourcedocument;
}
