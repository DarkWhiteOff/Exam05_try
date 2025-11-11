#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : m_name(name), m_title(title)
{
    std::cout << getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
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