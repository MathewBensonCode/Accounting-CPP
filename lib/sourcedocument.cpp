#include "sourcedocument.hpp"

timepoint SourceDocument::Date() const{
    return m_date;
}

void SourceDocument::Date(const timepoint& time){
    m_date = time;
}

const std::vector<std::shared_ptr<Transaction>> &SourceDocument::Transactions()const{
}
