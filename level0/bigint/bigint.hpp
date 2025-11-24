#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <sstream>

class bigint
{
public :
    bigint(void);
    bigint(unsigned int n);
    bigint(bigint const &copy);
    bigint &operator=(bigint const &src);
    ~bigint(void);

    std::string getBint(void) const;

    bigint operator+(bigint const &b) const;
    bigint &operator+=(bigint const &b);

    bigint &operator++();
    bigint operator++(int);

    bigint operator<<(unsigned int b) const;
    bigint operator>>(unsigned int b) const;
    bigint &operator<<=(unsigned int b);
    bigint &operator>>=(unsigned int b);

    bigint operator<<(bigint const &b) const;
    bigint operator>>(bigint const &b) const;
    bigint &operator<<=(bigint const &b);
    bigint &operator>>=(bigint const &b);

    bool operator==(bigint const &b) const;
    bool operator!=(bigint const &b) const;
    bool operator<(bigint const &b) const;
    bool operator>(bigint const &b) const;
    bool operator<=(bigint const &b) const;
    bool operator>=(bigint const &b) const;

private :
    std::string m_bint;
};

std::ostream& operator<<(std::ostream& output, bigint const &obj);

#endif