#ifndef BUSINESS_ENTITY_H
#define BUSINESS_ENTITY_H

#include <string>
#include <string_view>
#include <memory>
#include <vector>

#include <odb/core.hxx>

class SourceDocument;

class BusinessEntity
{
    unsigned int m_id{};
    std::string m_name;
    std::vector<std::shared_ptr<SourceDocument>> m_sourcedocuments;

    friend odb::access;

  public:
    [[nodiscard]] unsigned int Id() const;
    void Id(unsigned int);

    [[nodiscard]] std::string_view Name() const;
    void Name(std::string_view);
};
#ifdef ODB_COMPILER

#include "sourcedocument.hpp"
#pragma db object(BusinessEntity) table("BusinessEntities")
#pragma db member(BusinessEntity::m_id) id

#endif


#endif
