#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
#include "Component.h"

class Circuit {
public:
    void addComponent(Component* component, ConnectionType connectionType);
    double calculateImpedance(double frequency) const;
    double calculateOutputVoltage(double inputVoltage) const;
    double calculateOutputCurrent(double inputVoltage) const;
    double calculatePower(double inputVoltage) const;

private:
    struct ComponentConnection {
        Component* component;
        ConnectionType connectionType;
    };

    std::vector<ComponentConnection> components;
};

#endif // CIRCUIT_H
