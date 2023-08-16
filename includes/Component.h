#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

enum class ConnectionType {
    SERIES,
    PARALLEL
};

class Component {
public:
    Component(const std::string& name, double value);
    virtual ~Component() {}

    virtual double calculateImpedance(double frequency) const = 0;
    virtual std::string getName() const;  // Declare getName as a virtual function
    double getValue() const;

protected:
    std::string name;
    double value;
};

#endif // COMPONENT_H
