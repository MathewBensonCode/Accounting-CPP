#ifndef SOURCE_DOCUMENT_H
#define SOURCE_DOCUMENT_H

#include <chrono>
#include "entitybase.hpp"
#include <vector>
#include <memory>

using myclock = std::chrono::system_clock;
using timepoint = std::chrono::time_point<myclock>;

class Transaction;

class SourceDocument : public EntityBase
{
    timepoint m_date{};

  public:
    [[nodiscard]] timepoint Date() const;
    void Date(const timepoint &);

    [[nodiscard]] const std::vector<std::shared_ptr<Transaction>> &Transactions() const;
};

#endif
