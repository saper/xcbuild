#pragma once

#include <yaml-cpp/yaml.h>
#include <xcyaml/Project.h>

namespace YAML
{
    template<>
    struct convert<xcyaml::Project>
    {
        static Node encode(const xcyaml::Project& value)
        {
            Node n;
            return n;
        }

        static bool decode(const Node& node, xcyaml::Project& value)
        {
            if (!node.IsMap()) return false;

            return true;
        }
    };
}
