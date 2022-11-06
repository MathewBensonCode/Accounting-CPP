#ifndef ENTITY_BASE_H
#define ENTITY_BASE_H

class EntityBase{
    unsigned int m_id{};

    public:
    [[nodiscard]] unsigned int Id() const;
    void Id(unsigned int);
};

#endif
