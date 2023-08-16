#include "Circuit.h"
#include <cmath>

void Circuit::addComponent(Component* component, ConnectionType connectionType) {
    ComponentConnection componentConnection;
    componentConnection.component = component;
    componentConnection.connectionType = connectionType;
    components.push_back(componentConnection);
}

double Circuit::calculateImpedance(double frequency) const {
    double totalImpedance = 0.0;

    for (const ComponentConnection& componentConn : components) {
        if (componentConn.connectionType == ConnectionType::SERIES) {
            totalImpedance += componentConn.component->calculateImpedance(frequency);
        } else if (componentConn.connectionType == ConnectionType::PARALLEL) {
            double invImpedance = 1.0 / componentConn.component->calculateImpedance(frequency);
            totalImpedance += invImpedance;
        }
    }

    if (!components.empty() && components.back().connectionType == ConnectionType::PARALLEL) {
        totalImpedance = 1.0 / totalImpedance;
    }

    return totalImpedance;
}

double Circuit::calculatePower(double inputVoltage) const {
    double outputCurrent = calculateOutputCurrent(inputVoltage);
    double power = inputVoltage * outputCurrent;
    return power;
}

double Circuit::calculateOutputCurrent(double inputVoltage) const {
    double totalImpedance = calculateImpedance(50); // Frequency: 50 Hz
    double outputCurrent = inputVoltage / totalImpedance;
    return outputCurrent;
}

double Circuit::calculateOutputVoltage(double inputVoltage) const {
    double totalImpedance = calculateImpedance(50); // Frequency: 50 Hz
    double outputCurrent = calculateOutputCurrent(inputVoltage);
    double outputVoltage = inputVoltage - (outputCurrent * totalImpedance);
    return outputVoltage;
}