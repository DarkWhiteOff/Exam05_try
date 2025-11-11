#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <string>
#include <vector>

#include "ATarget.hpp"

class TargetGenerator
{
public :
    TargetGenerator(void);
    ~TargetGenerator(void);

    void learnTargetType(ATarget *target);
    void forgetTargetType(std::string const &targetType);
    ATarget *createTarget(std::string const &targetType);

private :
    std::vector<ATarget*> targetBook;

    TargetGenerator(TargetGenerator const &copy);
    TargetGenerator &operator=(TargetGenerator const &src);
};

#endif