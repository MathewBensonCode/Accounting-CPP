#include "businessentity.hpp"

const std::string& BusinessEntity::Name(){
    return m_name;
}

void BusinessEntity::Name(const std::string_view f_name){
    m_name = f_name;
}
