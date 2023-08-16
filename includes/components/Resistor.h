#ifndef RESISTOR_H
#define RESISTOR_H

#include "Component.h"

class Resistor : public Component {
public:
    Resistor(const std::string& name, double resistance);

    virtual double calculateImpedance(double frequency) const override;
    double calculateOutputVoltage(double inputVoltage) const;
    double calculateOutputCurrent(double inputVoltage) const;
    double calculatePower(double inputVoltage) const;
};

#endif // RESISTOR_H
