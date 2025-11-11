#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : m_name(name), m_title(title)
{
    std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
    std::vector<ASpell*>::iterator itb = spells.begin();
    std::vector<ASpell*>::iterator ite = spells.end();
    for (; itb != ite; itb++)
        delete (*itb);
    spells.clear();
    std::cout << getName() << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName(void) const
{
    return (m_name);
}

std::string const &Warlock::getTitle(void) const
{
    return (m_title);
}

void Warlock::setTitle(std::string const &t)
{
    m_title = t;
}

void Warlock::introduce() const
{
    std::cout << getName() << ": I am " << getName() << ", " << getTitle() << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    if (spell)
    {
        std::vector<ASpell*>::iterator itb = spells.begin();
        std::vector<ASpell*>::iterator ite = spells.end();
        for (; itb != ite; itb++)
        {
            if ((*itb)->getName() == spell->getName())
                return ;
        }
        spells.push_back(spell->clone());
    }
}
    
void Warlock::forgetSpell(std::string const &spellName)
{
    std::vector<ASpell*>::iterator itb = spells.begin();
    std::vector<ASpell*>::iterator ite = spells.end();
    for (; itb != ite; itb++)
    {
        if ((*itb)->getName() == spellName)
        {
            delete (*itb);
            spells.erase(itb);
            return ;
        }
    }
}
   
void Warlock::launchSpell(std::string const &spellName, ATarget const &target)
{
    std::vector<ASpell*>::iterator itb = spells.begin();
    std::vector<ASpell*>::iterator ite = spells.end();
    for (; itb != ite; itb++)
    {
        if ((*itb)->getName() == spellName)
        {
            (*itb)->launch(target);
            return ;
        }
    }
}