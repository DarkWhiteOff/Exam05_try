#include "set.hpp"

set::set(searchable_bag &bag) : m_bag(bag)
{

}
	
set::~set()
{

}

searchable_bag const &set::get_bag()
{
    return (m_bag);
}

bool set::has(int value) const
{
    return (m_bag.has(value));
}

void set::insert(int)
{
    if (!(this->has(value)))
        m_bag.insert(value);
}

void set::insert(int *data, int size)
{
    for(int i = 0; i < size; i++)
    {
        this->insert(data[i]);
    }
}

void set::print() const
{
    m_bag.print();
}

void set::clear()
{
    m_bag.clear();
}