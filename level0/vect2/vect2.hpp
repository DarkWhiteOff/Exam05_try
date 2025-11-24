#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
#include <string>
#include <vector>

class vect2
{
public :
    vect2(void);
    vect2(int x, int y);
    vect2(vect2 const &copy);
    vect2 &operator=(vect2 const &copy);
    ~vect2(void);

    vect2 operator+(vect2 const &b) const;
    vect2 operator-(vect2 const &b) const;
    vect2 operator*(vect2 const &b) const;

    vect2 &operator+=(vect2 const &b);
    vect2 &operator-=(vect2 const &b);
    vect2 &operator*=(vect2 const &b);

    vect2 operator+(int b) const;
    vect2 operator-(int b) const;
    vect2 operator*(int b) const;

    vect2 &operator+=(int b);
    vect2 &operator-=(int b);
    vect2 &operator*=(int b);

    vect2 &operator++();
    vect2 operator++(int);
    vect2 &operator--();
    vect2 operator--(int);

    bool operator==(vect2 const &b) const;
    bool operator!=(vect2 const &b) const;
    bool operator<(vect2 const &b) const;
    bool operator>(vect2 const &b) const;
    bool operator<=(vect2 const &b) const;
    bool operator>=(vect2 const &b) const;

    int operator[](int b) const;
    int &operator[](int b);

private :
    int m_x;
    int m_y;
};

std::ostream &operator<<(std::ostream &output, vect2 const &obj);

#endif