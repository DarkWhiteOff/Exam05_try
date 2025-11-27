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
    if (t == nullptr)
        return false;
    if (t->value == v)
        return (true);
    else if (v < t->value)
        return (has1(t->l, v));
    else
        return (has1(t->r, v));
}

bool searchable_tree_bg::has(int value) const
{
    return (has1(tree, value));
}