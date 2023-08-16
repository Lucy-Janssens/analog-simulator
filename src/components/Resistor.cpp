#include "Resistor.h"

Resistor::Resistor(const std::string& name, double resistance)
        : Component(name, resistance) {}

double Resistor::calculateImpedance(double frequency) const {
    // For a resistor, impedance is simply its resistance
    return value;
}


double Resistor::calculateOutputVoltage(double inputVoltage) const {
    double current = inputVoltage / getValue();
    double voltageDrop = current * getValue();
    double outputVoltage = (voltageDrop <= inputVoltage) ? (inputVoltage - voltageDrop) : 0.0;
    return outputVoltage;
}

double Resistor::calculateOutputCurrent(double inputVoltage) const {
    return inputVoltage / getValue();
}

double Resistor::calculatePower(double inputVoltage) const {
    double current = inputVoltage / getValue();
    return current * current * getValue();
}
