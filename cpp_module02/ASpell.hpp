#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>

#include "ATarget.hpp"

class ATarget;

class ASpell
{
    public :
        ASpell(void);
        ASpell(std::string const &n, std::string const &e);
        ASpell(ASpell const &copy);
        ASpell &operator=(ASpell const &src);
        virtual ~ASpell(void);

        std::string const &getName(void) const;
        std::string const &getEffects(void) const;

        virtual ASpell *clone(void) const = 0;

        void launch(ATarget const &target);

    protected :
        std::string name;
        std::string effects;
};

#endif