#include "ASpell.hpp"

ASpell::ASpell(void) : name(), effects()
{
    return ;
}

ASpell::ASpell(std::string const &n, std::string const &e) : name(n), effects(e)
{
    return ;
}
    
ASpell::ASpell(ASpell const &copy) : name(copy.name), effects(copy.effects)
{
    return ;
}
    
ASpell &ASpell::operator=(ASpell const &src)
{
    if (this != &src)
    {
        name = src.name;
        effects = src.effects;
    }
    return (*this);
}
        
ASpell::~ASpell(void)
{
    return ;
}

std::string const &ASpell::getName(void) const
{
    return (name);
}
        
std::string const &ASpell::getEffects(void) const
{
    return (effects);
}

void ASpell::launch(ATarget const &target)
{
    target.getHitBySpell(*this);
}