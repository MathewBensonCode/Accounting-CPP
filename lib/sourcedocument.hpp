#ifndef SOURCE_DOCUMENT_H
#define SOURCE_DOCUMENT_H

#include <chrono>
#include "entitybase.hpp"
#include <vector>
#include <memory>


using myclock = std::chrono::system_clock;
using timepoint = std::chrono::time_point<myclock>;

class Transaction;
class BusinessEntity;

class SourceDocument : public EntityBase
{
    timepoint m_date{};
    std::vector<std::shared_ptr<Transaction>> m_transactions{};
    std::weak_ptr<BusinessEntity> m_businessentity{};

  public:
    [[nodiscard]] timepoint Date() const;
    void Date(const timepoint &);

    [[nodiscard]] const std::vector<std::shared_ptr<Transaction>> &Transactions()const;
    void Transactions(std::vector<std::shared_ptr<Transaction>>& );

    [[nodiscard]] const std::weak_ptr<BusinessEntity> &Business_Entity() const;
    void Business_Entity(const std::weak_ptr<BusinessEntity>&);
};

#endif
