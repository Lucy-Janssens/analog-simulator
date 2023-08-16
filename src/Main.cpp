#include <iostream>
#include <vector>
#include "Resistor.h"
#include "Circuit.h"

int main(int argc, char* argv[]) {
    double inputVoltage = 0;
    std::vector<Component*> components;
    std::vector<ConnectionType> connections; // Declare and define the connections vector
    ConnectionType connectionType = ConnectionType::SERIES;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-v" && i + 1 < argc) {
            inputVoltage = std::stod(argv[i + 1]);
            ++i;
        } else if (arg == "-r" && i + 1 < argc) {
            double value = std::stod(argv[i + 1]);
            components.push_back(new Resistor("R" + std::to_string(components.size() + 1), value));
            connections.push_back(connectionType); // Store the connection type
            ++i;
        } else if (arg == "parallel") {
            connectionType = ConnectionType::PARALLEL;
        } else if (arg == "series") {
            connectionType = ConnectionType::SERIES;
        } else {
            std::cerr << "Invalid input: " << arg << std::endl;
            return 1; // Exit with an error code
        }
    }

    Circuit circuit;

    for (size_t i = 0; i < components.size(); ++i) {
        circuit.addComponent(components[i], connections[i]); // Pass connection type
    }

    // Calculate circuit properties and output results
    double totalImpedance = circuit.calculateImpedance(50);  // Frequency: 50 Hz
    double outputVoltage = circuit.calculateOutputVoltage(inputVoltage);
    double outputCurrent = circuit.calculateOutputCurrent(inputVoltage);
    double power = circuit.calculatePower(inputVoltage);

    std::cout << "Total Impedance: " << totalImpedance << " Ohms" << std::endl;
    std::cout << "Input Voltage: " << inputVoltage << " V" << std::endl;
    std::cout << "Output Voltage: " << outputVoltage << " V" << std::endl;
    std::cout << "Output Current: " << outputCurrent << " A" << std::endl;
    std::cout << "Power: " << power << " W" << std::endl;

    // Clean up memory
    for (Component* component : components) {
        delete component;
    }

    return 0;
}
