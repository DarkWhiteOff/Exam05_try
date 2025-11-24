#include "vect2.hpp"

vect2::vect2(void) : m_x(0), m_y(0)
{
    return ;
}

vect2::vect2(int x, int y) : m_x(x), m_y(y)
{
    return ;
}

vect2::vect2(vect2 const &copy)
{
    (*this) = copy;
}

vect2 &vect2::operator=(vect2 const &src)
{
    if (this != &src)
    {
        m_x = src.m_x;
        m_y = src.m_y;
    }
    return (*this);
}

vect2::~vect2(void)
{
    return ;
}

vect2 operator+(vect2 const &b) const
{
    vect2 temp(*this);

    temp.m_x += b.m_x;
    temp.m_y += b.m_y;
    return(temp);
}
    
vect2 operator-(vect2 const &b) const
{
    vect2 temp(*this);

    temp.m_x -= b.m_x;
    temp.m_y -= b.m_y;
    return(temp);
}

vect2 operator*(vect2 const &b) const
{
    vect2 temp(*this);

    temp.m_x *= b.m_x;
    temp.m_y *= b.m_y;
    return(temp);
}

vect2 &operator+=(vect2 const &b)
{
    m_x += b.m_x;
    m_y += b.m_y;
    return(*this);
}

vect2 &operator-=(vect2 const &b)
{
    m_x -= b.m_x;
    m_y -= b.m_y;
    return(*this);
}

vect2 &operator*=(vect2 const &b)
{
    m_x *= b.m_x;
    m_y *= b.m_y;
    return(*this);
}

vect2 operator+(int b) const
{
    vect2 temp(*this);

    temp.m_x += b;
    temp.m_y += b;
    return(temp);
}

vect2 operator-(int b) const
{
    vect2 temp(*this);

    temp.m_x -= b;
    temp.m_y -= b;
    return(temp);
}

vect2 operator*(int b) const
{
    vect2 temp(*this);

    temp.m_x *= b;
    temp.m_y *= b;
    return(temp);
}

vect2 &operator+=(int b)
{
    m_x += b;
    m_y += b;
    return(*this);
}

vect2 &operator-=(int b)
{
    m_x -= b;
    m_y -= b;
    return(*this);
}

vect2 &operator*=(int b)
{
    m_x *= b;
    m_y *= b;
    return(*this);
}

vect2 &vect2::operator++()
{
    vect2 temp(*this);

    temp.m_x += 1;
    temp.m_y += 1;
    return (temp);
}
    
vect2 vect2::operator++(int)
{
    m_x += 1;
    m_y += 1;
    return (*this);
}

vect2 &vect2::operator--()
{
    vect2 temp(*this);

    temp.m_x -= 1;
    temp.m_y -= 1;
    return (temp);
}

vect2 vect2::operator--(int)
{
    m_x -= 1;
    m_y -= 1;
    return (*this);
}

bool operator==(vect2 const &b) const
{
    if ((*this) == b)
        return true;
    return false;
}

bool operator!=(vect2 const &b) const
{
    if ((*this) != b)
        return true;
    return false;
}

bool operator<(vect2 const &b) const
{
    if ((*this) < b)
        return true;
    return false;
}

bool operator>(vect2 const &b) const
{
    if ((*this) > b)
        return true;
    return false;
}

bool operator<=(vect2 const &b) const
{
    if ((*this) <= b)
        return true;
    return false;
}

bool operator>=(vect2 const &b) const
{
    if ((*this) >= b)
        return true;
    return false;
}

int operator[](int b) const
{
    
}

int &operator[](int b)
{

}

std::ostream &operator<<(std::ostream &output, vect2 const &obj)
{
    std::cout << "{" << m_x << ", " << m_y << "}" << std::endl;
    return (output);
}