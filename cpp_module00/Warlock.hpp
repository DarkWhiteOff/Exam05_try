#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class Warlock
{
public :
    Warlock(std::string const &name, std::string const &title);
    ~Warlock(void);

    std::string const &getName(void) const;
    std::string const &getTitle(void) const;

    void setTitle(std::string const &t);

    void introduce() const;

private :
    std::string name;
    std::string title;

    Warlock(void);
    Warlock(Warlock const &copy);
    Warlock &operator=(Warlock const &src);
};

#endif