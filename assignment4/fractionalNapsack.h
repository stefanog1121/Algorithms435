#ifndef SPICE_HEIST_H
#define SPICE_HEIST_H

#include <string>
#include <vector>
#include <map>

class SpiceType {
private:
    std::string name;
    double valuePerScoop;
    double availableQty;  

public:
    SpiceType(std::string n, double total_price, double qty);
    std::string getName() const;
    double getValue() const;
    double getQty() const;
    void reduceQty(double amount);
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
    void addSpiceType(const std::string& name, double total_price, double qty);
    void addKnapsack(double capacity);
    void optimizeKnapsacks();
    void printResults() const;
    
    static std::vector<SpiceHeist*> parseSpiceHeist(std::vector<std::string>& list);
};

#endif