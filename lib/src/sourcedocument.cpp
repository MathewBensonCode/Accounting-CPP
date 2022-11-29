#include "sourcedocument.hpp"

unsigned int SourceDocument::Id() const{
    return m_id;
}

void SourceDocument::Id(unsigned int newid){
    m_id = newid;
}

timepoint SourceDocument::Date() const{
    return m_date;
}

void SourceDocument::Date(const timepoint& time){
    m_date = time;
}

const std::vector<std::shared_ptr<Transaction>> &SourceDocument::Transactions()const{
    return m_transactions;
}

void SourceDocument::Transactions(const std::vector<std::shared_ptr<Transaction>> &collection){
    m_transactions = collection;
}

const std::shared_ptr<BusinessEntity> & SourceDocument::Business_Entity()const{
    return m_businessentity;
}

void SourceDocument::Business_Entity(const std::shared_ptr<BusinessEntity>& business_entity){
    m_businessentity = business_entity;
}
