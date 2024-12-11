#include <string>
#include <iostream>      
#include <vector>     
#include <tuple> 




class TrainerCard : public Card {
    std::string trainerEffect;

public:
    TrainerCard(const std::string& name, const std::string& effect) : Card(name), trainerEffect(effect) {}

    void displayInfo() const override {
        std::cout << "Nom du tainer " << cardName << ", Effect: " << trainerEffect << std::endl;
    }

    
    void applyEffect(Player& player) {
        if (trainerEffect == "heal all your action pokemon") {
            std::cout << cardName << " is using the Trainer Card to \"" << trainerEffect << "\"\n";
            for (auto& pokemon : player.getActionCards()) {
                pokemon->setHP(pokemon->getMaxHP()); // gets the maximum health that the Pokémon can have.then sets the Pokémon’s current health (hp) to this maximum value, healing it completely.
            }
        }
    }
};

