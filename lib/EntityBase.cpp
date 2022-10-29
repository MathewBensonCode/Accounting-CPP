#include "entitybase.hpp"

unsigned int EntityBase::Id() const
{
    return m_id;
}

void EntityBase::Id(const unsigned int f_id)
{
    m_id = f_id;
}
