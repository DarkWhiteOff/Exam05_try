#include "SpellBook.hpp"

SpellBook::SpellBook(void)
{
    return ;
}

SpellBook::~SpellBook(void)
{
    std::vector<ASpell*>::iterator itb = spellBook.begin();
    std::vector<ASpell*>::iterator ite = spellBook.end();
    for (; itb != ite; itb++)
        delete (*itb);
    spellBook.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
    if (spell)
    {
        std::vector<ASpell*>::iterator itb = spellBook.begin();
        std::vector<ASpell*>::iterator ite = spellBook.end();
        for (; itb != ite; itb++)
        {
            if ((*itb)->getName() == spell->getName())
                return ;
        }
        spellBook.push_back(spell->clone());
    }
}
    
void SpellBook::forgetSpell(std::string const &spellName)
{
    std::vector<ASpell*>::iterator itb = spellBook.begin();
    std::vector<ASpell*>::iterator ite = spellBook.end();
    for (; itb != ite; itb++)
    {
        if ((*itb)->getName() == spellName)
        {
            delete (*itb);
            spellBook.erase(itb);
            return ;
        }
    }
}
   
ASpell *SpellBook::createSpell(std::string const &spellName)
{
    std::vector<ASpell*>::iterator itb = spellBook.begin();
    std::vector<ASpell*>::iterator ite = spellBook.end();
    for (; itb != ite; itb++)
    {
        if ((*itb)->getName() == spellName)
            return (*itb);
    }
    return (0);
}