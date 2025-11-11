#include "ATarget.hpp"

ATarget::ATarget(void) : type()
{
    return ;
}

ATarget::ATarget(std::string const &t) : type(t)
{
    return ;
}
    
ATarget::ATarget(ATarget const &copy) : type(copy.type)
{
    return ;
}
    
ATarget &ATarget::operator=(ATarget const &src)
{
    if (this != &src)
    {
        type = src.type;
    }
    return (*this);
}
        
ATarget::~ATarget(void)
{
    return ;
}

std::string const &ATarget::getType(void) const
{
    return (type);
}

void ATarget::getHitBySpell(ASpell const &spell) const
{
    std::cout << getType() << " has been " << spell.getEffects() << "!" << std::endl;
}