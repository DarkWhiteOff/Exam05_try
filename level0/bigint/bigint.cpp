#include "bigint.hpp"

bigint::bigint(void) : m_bint("0")
{
    return ;
}

bigint::bigint(unsigned int n)
{
    std::stringstream ss;
    ss << n;
    m_bint = ss.str();
}

bigint::bigint(bigint const &copy)
{
    (*this) = copy;
}

bigint &bigint::operator=(bigint const &src)
{
    if (this != &src)
    {
        m_bint = src.m_bint;
    }
    return (*this);
}

bigint::~bigint(void)
{
    return ;
}

std::string bigint::getBint(void) const
{
    return (m_bint);
}

std::string reverse(std::string str)
{
    std::string revStr;
    for (size_t i = str.length(); i > 0; i--)
        revStr.push_back(str[i - 1]);
    return (revStr);
}

std::string addition(bigint const &a, bigint const &b)
{
    std::string stra = reverse(a.getBint());
    std::string strb = reverse(b.getBint());
    size_t lena = stra.length();
    size_t lenb = strb.length();

    if (lena > lenb)
    {
        int diff = lena - lenb;
        while (diff--)
            strb.push_back('0');
    }
    else if (lenb > lena)
    {
        int diff = lenb - lena;
        while (diff--)
            stra.push_back('0');
    }

    std::string result;
    int digita;
    int digitb;
    int ret = 0;
    size_t len = stra.length();
    for (size_t i = 0; i < len; i++)
    {
        digita = stra[i] - '0';
        digitb = strb[i] - '0';

        int r = digita + digitb + ret;
        ret = 0;
        if (r >= 10)
        {
            ret = r / 10;
            result.push_back((r % 10) + '0');
        }
        else
            result.push_back(r + '0');
    }
    if (ret != 0)
        result.push_back(ret + '0');
    return (reverse(result));
}

bigint bigint::operator+(bigint const &b) const
{
    bigint temp(b);
    temp.m_bint.clear();
    temp.m_bint = addition((*this), b);
    return (temp);
}

bigint &bigint::operator+=(bigint const &b)
{
    (*this) = (*this) + b;
    return (*this);
}

bigint &bigint::operator++()
{
    (*this) = (*this) + bigint(1);
    return (*this);
}

bigint bigint::operator++(int)
{
    bigint temp(*this);
    (*this) = (*this) + bigint(1);
    return (temp);
}

bigint bigint::operator<<(unsigned int b) const
{
    bigint temp(*this);
    temp.m_bint.insert(temp.m_bint.end(), b, '0');
    return (temp);
}

bigint bigint::operator>>(unsigned int b) const
{
    bigint temp(*this);
    size_t len = temp.m_bint.length();
    if (b > len)
        temp.m_bint = "0";
    else
        temp.m_bint.erase(len - b, b);
    return (temp);
}

bigint &bigint::operator<<=(unsigned int b)
{
    (*this) = (*this) << b;
    return (*this);
}

bigint &bigint::operator>>=(unsigned int b)
{
    (*this) = (*this) >> b;
    return (*this);
}

unsigned int stoui(std::string str)
{
    std::stringstream ss(str);
    unsigned int res;
    ss >> res;
    return (res);
}

bigint bigint::operator<<(bigint const &b) const
{
    bigint temp;
    temp = (*this) << stoui(b.m_bint);
    return (temp);
}

bigint bigint::operator>>(bigint const &b) const
{
    bigint temp;
    temp = (*this) >> stoui(b.m_bint);
    return (temp);
}

bigint &bigint::operator<<=(bigint const &b)
{
    (*this) = (*this) << stoui(b.m_bint);
    return (*this);
}

bigint &bigint::operator>>=(bigint const &b)
{
    (*this) = (*this) >> stoui(b.m_bint);
    return (*this);
}

bool bigint::operator==(bigint const &b) const
{
    if (this->m_bint == b.m_bint)
        return true;
    return false;
}

bool bigint::operator!=(bigint const &b) const
{
    if (this->m_bint != b.m_bint) // if (!(this->m_bint == b.m_bint))
        return true;
    return false;
}

bool bigint::operator<(bigint const &b) const
{
    std::string stra = this->m_bint;
    std::string strb = b.m_bint;
    size_t lena = stra.length();
    size_t lenb = strb.length();

    if (lena < lenb)
        return (lena < lenb);
    return (stra < strb);
}

bool bigint::operator>(bigint const &b) const
{
    return (!((*this) < b));
}

bool bigint::operator<=(bigint const &b) const
{
    return (((*this) < b) || ((*this) == b));
}

bool bigint::operator>=(bigint const &b) const
{
    return (((*this) > b) || ((*this) == b));
}

std::ostream& operator<<(std::ostream& output, bigint const &obj)
{
    output << obj.getBint();
	return (output);
}