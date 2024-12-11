#include <iostream>
#include "headers/card.h"
#include "headers/pokemon_card.h"
#include "headers/energy_card.h"
#include "headers/trainer_card.h"
#include "headers/player.h"

using namespace std;

// Test Functions
void testCardCreation() {
    cout << "=== Test Card Creation ===" << endl;

    PokemonCard pikachu("Pikachu", "Electric", "Pikachu", 2, 100, 100, "Thunderbolt", 20, 2, "Thunder Storm", 30, 3);
    cout << "Testing PokemonCard displayInfo:" << endl;
    pikachu.displayInfo();

    EnergyCard electricEnergy("Electric");
    cout << "Testing EnergyCard displayInfo:" << endl;
    electricEnergy.displayInfo();

    TrainerCard ashTrainer("Ash", "heal all your action pokemon");
    cout << "Testing TrainerCard displayInfo:" << endl;
    ashTrainer.displayInfo();

    cout << "=== End of Test Card Creation ===\n" << endl;
}

void testPlayerActions() {
    cout << "=== Test Player Actions ===" << endl;

    Player player("Hadi");

    // Adding cards to the player's bench
    player.addCardToBench(new EnergyCard("Electric"));
    player.addCardToBench(new TrainerCard("Ash", "heal all your action pokemon"));
    player.addCardToBench(new PokemonCard("Pikachu", "Electric", "Pikachu", 2, 100, 100, "Thunderbolt", 20, 2, "Thunder Storm", 30, 3));

    // Activate the Pokémon card
    player.activatePokemonCard(2); // Activate Pikachu

    // Attach energy card
    player.attachEnergyCard(0, 0);

    // Display bench and action cards
    cout << "\nPlayer's Bench:" << endl;
    player.displayBench();
    cout << "\nPlayer's Action Cards:" << endl;
    player.displayAction();

    cout << "=== End of Test Player Actions ===\n" << endl;
}

void testAttack() {
    cout << "=== Test Attack Functionality ===" << endl;

    Player player1("Hadi");
    Player player2("Germain");

    // Add PokemonCard to each player's bench and activate it
    player1.addCardToBench(new PokemonCard("Pikachu", "Electric", "Pikachu", 2, 100, 100, "Thunderbolt", 20, 2, "Thunder Storm", 30, 3));
    player2.addCardToBench(new PokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 100, "Leech Seed", 15, 2, "Vine Whip", 25, 3));

    player1.activatePokemonCard(0); // Activate Pikachu for player1
    player2.activatePokemonCard(0); // Activate Bulbasaur for player2

    // Perform an attack from player1's Pikachu to player2's Bulbasaur
    cout << "Testing attack from Pikachu to Bulbasaur:" << endl;
    player1.attack(0, 0, player2, 0); // Pikachu uses "Thunderbolt" on Bulbasaur

    // Display action cards to see the effect
    cout << "\nPlayer2's Action Cards after the attack:" << endl;
    player2.displayAction();

    cout << "=== End of Test Attack Functionality ===\n" << endl;
}

void testTrainerCardEffect() {
    cout << "=== Test Trainer Card Effect ===" << endl;

    Player player("Germain");

    // Add a Pokemon card with reduced HP
    PokemonCard* bulbasaur = new PokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 80, "Leech Seed", 15, 2, "Vine Whip", 25, 3);
    player.addCardToBench(bulbasaur);
    player.activatePokemonCard(0); // Activate Bulbasaur

    cout << "Before using Trainer Card (HP should be 80):" << endl;
    player.displayAction();

    // Add and use a TrainerCard to heal
    player.addCardToBench(new TrainerCard("Brock", "heal all your action pokemon"));
    player.useTrainer(1);

    cout << "After using Trainer Card (HP should be 100):" << endl;
    player.displayAction();

    cout << "=== End of Test Trainer Card Effect ===\n" << endl;
}

int main() {
   
    testCardCreation();
    testPlayerActions();
    testAttack();
    testTrainerCardEffect();

    return 0;
}
