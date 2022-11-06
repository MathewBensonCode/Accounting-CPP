#include "entitybase.hpp"

unsigned int EntityBase::Id() const
{
    return m_id;
}

void EntityBase::Id(const unsigned int id)
{
    m_id = id;
}
