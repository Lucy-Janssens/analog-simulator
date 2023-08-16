#include "Component.h"

Component::Component(const std::string& name, double value)
        : name(name), value(value) {}

// Provide the definition for the virtual getName function
std::string Component::getName() const {
    return name;
}

double Component::getValue() const {
    return value;
}
