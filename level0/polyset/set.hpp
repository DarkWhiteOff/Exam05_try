#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include <string>
#include "searchable_bag.hpp"

class set
{
public :
    set(searchable_bag &bag);
	~set();

    searchable_bag const &get_bag();

    bool has(int) const;
    void insert(int);
	void insert(int *, int);
	void print() const;
	void clear();

private :
    searchable_bag &m_bag;

    set();
	set(const set &copy);
	set &operator=(const set &src);
};

#endif