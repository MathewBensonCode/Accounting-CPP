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

[[nodiscard]] std::string_view BusinessEntity::Name() const{
    return m_name;
}

void BusinessEntity::Name(const std::string_view f_name){
    m_name = f_name;
}
