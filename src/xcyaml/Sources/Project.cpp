#include <xcyaml/Project.h>
#include <xcyaml/yaml-conversion.h>
#include <sstream>

using namespace xcyaml;

std::string Project::toYAML(const Project& value) {
    YAML::Node node;
    node = value;

    std::ostringstream stream;
    stream << node;
    return stream.str();
}

Project Project::fromYAML(const std::string& str) {
    std::istringstream stream(str);
    YAML::Node node = YAML::Load(str.c_str());
    return node.as<Project>();
}
