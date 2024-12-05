#ifndef SPICE_HEIST_H
#define SPICE_HEIST_H

#include <string>
#include <vector>
#include <map>

class SpiceType {
private:
    std::string name;
    double valuePerScoop;

public:
    SpiceType(std::string n, double value);
    
    std::string getName() const;
    double getValue() const;
    bool operator<(const SpiceType& other) const;
};

class Knapsack {
private:
    double capacity;
    std::map<SpiceType, double> contents;
    double remainingCapacity;
    double totalValue;

public:
    explicit Knapsack(double cap);
    
    void addSpice(const SpiceType& spice, double scoops);
    double getCapacity() const;
    double getRemainingCapacity() const;
    double getTotalValue() const;
    const std::map<SpiceType, double>& getContents() const;
    void printContents() const;
};

class SpiceHeist {
private:
    std::vector<SpiceType> availableSpices;
    std::vector<Knapsack> knapsacks;

public:
    void addSpiceType(const std::string& name, double value);
    void addKnapsack(double capacity);
    void optimizeKnapsacks();
    void printResults() const;
};

#endif 