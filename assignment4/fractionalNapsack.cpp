#include "fractionalNapsack.h"
#include <iostream>
#include <algorithm>

SpiceType::SpiceType(std::string n, double value) : name(n), valuePerScoop(value) {}

std::string SpiceType::getName() const { return name; }

double SpiceType::getValue() const { return valuePerScoop; }

bool SpiceType::operator<(const SpiceType& other) const {
    return valuePerScoop > other.valuePerScoop;  // sorts in descending order
}


Knapsack::Knapsack(double cap) : capacity(cap), remainingCapacity(cap), totalValue(0.0) {}

void Knapsack::addSpice(const SpiceType& spice, double scoops) {
    if (scoops > 0) {
        contents[spice] += scoops;
        remainingCapacity -= scoops;
        totalValue += scoops * spice.getValue();
    }
}

double Knapsack::getCapacity() const { return capacity; }

double Knapsack::getRemainingCapacity() const { return remainingCapacity; }

double Knapsack::getTotalValue() const { return totalValue; }

const std::map<SpiceType, double>& Knapsack::getContents() const { return contents; }

void Knapsack::printContents() const {
    std::cout << "Knapsack of capacity " << capacity << " is worth " 
              << totalValue << " quatloos and contains ";
    bool first = true;
    for (const auto& [spice, scoops] : contents) {
        if (!first) std::cout << ", ";
        std::cout << scoops << " scoops of " << spice.getName();
        first = false;
    }
    std::cout << "." << std::endl;
}

void SpiceHeist::addSpiceType(const std::string& name, double value) {
    availableSpices.emplace_back(name, value);
}

void SpiceHeist::addKnapsack(double capacity) {
    knapsacks.emplace_back(capacity);
}

void SpiceHeist::optimizeKnapsacks() {
    // sort spices by value per scoop (descending)
    std::sort(availableSpices.begin(), availableSpices.end());
    
    // fill each avail knapsack using greedy approach
    for (auto& knapsack : knapsacks) {
        for (const auto& spice : availableSpices) {
            if (knapsack.getRemainingCapacity() > 0) {
                // find how much space remains and fill
                double scoopsToAdd = knapsack.getRemainingCapacity();
                knapsack.addSpice(spice, scoopsToAdd);
            }
        }
    }
}

void SpiceHeist::printResults() const {
    for (const auto& knapsack : knapsacks) {
        knapsack.printContents();
    }
}
