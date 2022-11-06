#ifndef BUSINESS_ENTITY_H
#define BUSINESS_ENTITY_H

#include <string>
#include "entitybase.hpp"

class BusinessEntity : public EntityBase{
    std::string m_name;
    public:
        const std::string& Name();  
        void Name(const std::string&);
};

#endif
