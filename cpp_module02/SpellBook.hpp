#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <string>
#include <vector>

#include "ASpell.hpp"

class SpellBook
{
public :
    SpellBook(void);
    ~SpellBook(void);

    void learnSpell(ASpell *spell);
    void forgetSpell(std::string const &spellName);
    ASpell *createSpell(std::string const &spellName);

private :
    std::vector<ASpell*> spellBook;

    SpellBook(SpellBook const &copy);
    SpellBook &operator=(SpellBook const &src);
};

#endif