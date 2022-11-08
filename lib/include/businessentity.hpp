#ifndef BUSINESS_ENTITY_H
#define BUSINESS_ENTITY_H

#include <string>
#include <string_view>
#include "entitybase.hpp"

class BusinessEntity : public EntityBase{
    std::string m_name;
    public:
        const std::string& Name();  
        void Name(std::string_view);
};

#endif
