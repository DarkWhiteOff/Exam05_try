#include "searchable_tree_bg.hpp"

searchable_tree_bg::searchable_tree_bg()
{

}
	
searchable_tree_bg::searchable_tree_bg(const searchable_tree_bg &copy) : tree_bag(copy)
{

}

searchable_tree_bg &searchable_tree_bg::operator=(const searchable_tree_bg &src)
{
    if (this != &src)
    {
        tree_bag::operator=(src);
    }
    return (*this);
}

searchable_tree_bg::~searchable_tree_bg()
{

}

bool has1(node *t, int v) const
{
    if (t == 0)
        return false;
    else
    {
		has1(t->l);
		if (t->value != 0)
        {
            if (t->value == v)
                return true;
        }
		has1(t->r);
	}
    return false;
}

bool searchable_tree_bg::has(int value) const
{
    return (has1(tree, value));
}