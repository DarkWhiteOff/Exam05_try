#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <vector>

#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
public :
    Warlock(std::string const &name, std::string const &title);
    ~Warlock(void);

    std::string const &getName(void) const;
    std::string const &getTitle(void) const;

    void setTitle(std::string const &t);

    void introduce() const;

    void learnSpell(ASpell *spell);
    void forgetSpell(std::string const &spellName);
    void launchSpell(std::string const &spellName, ATarget const &target);

private :
    std::string m_name;
    std::string m_title;
    SpellBook spells;

    Warlock(void);
    Warlock(Warlock const &copy);
    Warlock &operator=(Warlock const &src);
};

#endif