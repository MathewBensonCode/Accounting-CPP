#include "businessentity.hpp"
#include <string_view>

unsigned int BusinessEntity::Id() const
{
    return m_id;
}

void BusinessEntity::Id(unsigned int newid)
{
    m_id = newid;
}

[[nodiscard]] const std::string & BusinessEntity::Name() const{
    return m_name;
}

void BusinessEntity::Name(const const std::string & f_name){
    m_name = f_name;
}

[[nodiscard]] const std::vector<std::weak_ptr<SourceDocument>> &BusinessEntity::SourceDocuments() const
{
    return m_sourcedocuments;
}
