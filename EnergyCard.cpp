#include <string>
#include <iostream>      
#include <vector>     
#include <tuple> 



class EnergyCard : public Card {
    std::string energyType;

public:
    EnergyCard(const std::string& type) : Card("Energy"), energyType(type) {}
    void displayInfo() const override {
        std::cout << "Energy Card - Type: " << energyType << std::endl;
    }

}       