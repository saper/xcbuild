#pragma once

#include <string>

namespace xcyaml
{
    class Project
    {
    public:
        static std::string toYAML(const Project&);
        static Project fromYAML(const std::string&);

    public:
        bool operator ==(const Project& other)
        {
            return true;
        }

        bool operator !=(const Project& other)
        {
            return !this->operator==(other);
        }
    };
}
