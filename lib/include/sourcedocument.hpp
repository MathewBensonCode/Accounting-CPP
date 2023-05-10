#ifndef SOURCE_DOCUMENT_H
#define SOURCE_DOCUMENT_H

#include <chrono>
#include <vector>
#include <memory>

#include <odb/core.hxx>

using timepoint = std::chrono::sys_seconds;

class Transaction;
class BusinessEntity;

class SourceDocument
{
    unsigned int m_id{};
    long long m_date{};
    std::vector<std::weak_ptr<Transaction>> m_transactions{};
    std::weak_ptr<BusinessEntity> m_businessentity{};

    friend odb::access;

  public:

    [[nodiscard]] unsigned int Id() const;
    void Id(unsigned int);

    [[nodiscard]] const std::string & Name() const;
    void Name(const std::string &);

    [[nodiscard]] timepoint Date() const;
    void Date(const timepoint &);

    [[nodiscard]] const std::vector<std::weak_ptr<Transaction>> &Transactions() const;
    void Transactions(const std::vector<std::weak_ptr<Transaction>> &);

    [[nodiscard]] const std::weak_ptr<BusinessEntity> &Business_Entity() const;
    void Business_Entity(const std::weak_ptr<BusinessEntity> &);
};

#ifdef ODB_COMPILER
#include "transaction.hpp"
#include "businessentity.hpp"
#pragma db object(SourceDocument) table("SourceDocuments") pointer(std::shared_ptr)
#pragma db member(SourceDocument::m_id) id
#pragma db member(SourceDocument::m_businessentity) not_null
#pragma db member(SourceDocument::m_date) type("INT")
#pragma db member(SourceDocument::m_transactions) inverse(m_sourcedocument)

#endif

#endif
