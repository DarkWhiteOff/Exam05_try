#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>

#include "ASpell.hpp"

class ASpell;

class ATarget
{
    public :
        ATarget(void);
        ATarget(std::string const &t);
        ATarget(ATarget const &copy);
        ATarget &operator=(ATarget const &src);
        virtual ~ATarget(void);

        std::string const &getType(void) const;

        void getHitBySpell(ASpell const &spell) const;

        virtual ATarget *clone(void) const = 0;

    protected :
        std::string type;
};

#endif