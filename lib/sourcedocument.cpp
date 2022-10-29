#include "sourcedocument.hpp"

timepoint SourceDocument::Date() const{
    return m_date;
}

void SourceDocument::Date(const timepoint& time){
    m_date = time;
}

const std::vector<std::shared_ptr<Transaction>> &SourceDocument::Transactions()const{
    return m_transactions;
}

void SourceDocument::Transactions(std::vector<std::shared_ptr<Transaction>> &collection){
}

const std::weak_ptr<BusinessEntity> & SourceDocument::Business_Entity()const{
    return m_businessentity;
}

void SourceDocument::Business_Entity(const std::weak_ptr<BusinessEntity>& business_entity){
    m_businessentity = business_entity;
}
