#include "fractionalNapsack.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>

// spice object implementation
SpiceType::SpiceType(std::string n, double total_price, double qty) 
    : name(n), valuePerScoop(total_price/qty), availableQty(qty) {}

std::string SpiceType::getName() const { return name; }
double SpiceType::getValue() const { return valuePerScoop; }
double SpiceType::getQty() const { return availableQty; }
void SpiceType::reduceQty(double amount) { availableQty -= amount; }
bool SpiceType::operator<(const SpiceType& other) const {
    return valuePerScoop > other.valuePerScoop;  
}

// knapsack implementation
Knapsack::Knapsack(double cap) 
    : capacity(cap), remainingCapacity(cap), totalValue(0.0) {}

void Knapsack::addSpice(const SpiceType& spice, double scoops) {
    if (scoops > 0) {
        contents[spice] = scoops;
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
              << std::fixed << std::setprecision(1) << totalValue 
              << " quatloos and contains ";
    
    bool first = true;
    for (const auto& [spice, scoops] : contents) {
        if (!first) std::cout << ", ";
        std::cout << std::fixed << std::setprecision(1) << scoops 
                  << " scoops of " << spice.getName();
        first = false;
    }
    std::cout << "." << std::endl;
}

// heist algorithm wrapper
void SpiceHeist::addSpiceType(const std::string& name, double total_price, double qty) {
    availableSpices.emplace_back(name, total_price, qty);
}

void SpiceHeist::addKnapsack(double capacity) {
    knapsacks.emplace_back(capacity);
}

void SpiceHeist::optimizeKnapsacks() {
    // sort spices by value per scoop (descending)
    std::sort(availableSpices.begin(), availableSpices.end());
    
    // fill each knapsack independently
    for (auto& knapsack : knapsacks) {
        double spaceLeft = knapsack.getCapacity();
        
        // each knapsack gets to try using the full amount of each spice
        for (const auto& spice : availableSpices) {
            if (spaceLeft <= 0) break;
            
            // take as much as we can of this spice
            double amountToTake = std::min(spaceLeft, spice.getQty());
            if (amountToTake > 0) {
                knapsack.addSpice(spice, amountToTake);
                spaceLeft -= amountToTake;
            }
        }
    }
}

void SpiceHeist::printResults() const {
    for (const auto& knapsack : knapsacks) {
        knapsack.printContents();
    }
}

std::vector<SpiceHeist*> SpiceHeist::parseSpiceHeist(std::vector<std::string>& list) {
    std::vector<SpiceHeist*> heists;
    SpiceHeist* curr = new SpiceHeist();
    
    for (const auto& line : list) {
        if (line.empty() || line.substr(0, 2) == "--") continue;

        std::istringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "spice") {
            std::string name, temp, price_str, qty_str;
            ss >> temp >> temp >> name;  // skip past "name ="
            name = name.substr(0, name.find(';'));
            
            ss >> temp >> temp >> price_str;  // skip past "total_price ="
            price_str = price_str.substr(0, price_str.find(';'));
            
            ss >> temp >> temp >> qty_str;  // skip past "qty ="
            qty_str = qty_str.substr(0, qty_str.find(';'));
            
            double total_price = std::stod(price_str);
            double qty = std::stod(qty_str);
            
            curr->addSpiceType(name, total_price, qty);
        }
        else if (type == "knapsack") {
            std::string temp;
            double capacity;
            ss >> temp >> temp >> capacity;
            curr->addKnapsack(capacity);
        }
    }

    heists.push_back(curr);
    return heists;
}