#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(void)
{
    return ;
}

TargetGenerator::~TargetGenerator(void)
{
    std::vector<ATarget*>::iterator itb = targetBook.begin();
    std::vector<ATarget*>::iterator ite = targetBook.end();
    for (; itb != ite; itb++)
        delete (*itb);
    targetBook.clear();
}

void TargetGenerator::learnTargetType(ATarget *target)
{
    if (target)
    {
        std::vector<ATarget*>::iterator itb = targetBook.begin();
        std::vector<ATarget*>::iterator ite = targetBook.end();
        for (; itb != ite; itb++)
        {
            if ((*itb)->getType() == target->getType())
                return ;
        }
        targetBook.push_back(target->clone());
    }
}

void TargetGenerator::forgetTargetType(std::string const &targetType)
{
    std::vector<ATarget*>::iterator itb = targetBook.begin();
    std::vector<ATarget*>::iterator ite = targetBook.end();
    for (; itb != ite; itb++)
    {
        if ((*itb)->getType() == targetType)
        {
            delete (*itb);
            targetBook.erase(itb);
            return ;
        }
    }
}

ATarget *TargetGenerator::createTarget(std::string const &targetType)
{
    std::vector<ATarget*>::iterator itb = targetBook.begin();
    std::vector<ATarget*>::iterator ite = targetBook.end();
    for (; itb != ite; itb++)
    {
        if ((*itb)->getType() == targetType)
            return (*itb);
    }
    return (0);
}