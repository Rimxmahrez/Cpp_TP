class Player {
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;

public:
    Player(const string& name) : playerName(name) {}

    void addCardToBench(Card* card) {
        benchCards.push_back(card);
    }

    void activatePokemonCard(int index) {
        if (index < benchCards.size()) {
            PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[index]);
            if (pokemon) {
                actionCards.push_back(pokemon);
                benchCards.erase(benchCards.begin() + index);
                cout << playerName << " is activating a Pokemon Card: " << pokemon->getCardName() << endl;
            }
        }
    }

    void attachEnergyCard(int benchIndex, int attackIndex) {
        if (benchIndex < benchCards.size() && dynamic_cast<EnergyCard*>(benchCards[benchIndex])) {
            if (actionCards.size() > 0) {
                actionCards[0]->attachEnergy(attackIndex);
                cout << playerName << " is attaching Energy Card of type " << benchCards[benchIndex]->getEnergyType()
                     << " to the Pokemon " << actionCards[0]->getCardName() << endl;
            }
        }
    }

    void displayBench() const {
        cout << "Bench cards for Player " << playerName << ":\n";
        for (auto* card : benchCards) {
            card->displayInfo();
        }
    }

    void displayAction() const {
        cout << "Action cards for Player " << playerName << ":\n";
        for (auto* pokemon : actionCards) {
            pokemon->displayInfo();
        }
    }

    void attack(int attackerIndex, int attackIndex, Player& opponent, int defenderIndex) {
        if (attackerIndex < actionCards.size() && attackIndex < actionCards[attackerIndex]->getAttacks().size()) {
            int damage = get<3>(actionCards[attackerIndex]->getAttacks()[attackIndex]);
            opponent.actionCards[defenderIndex]->takeDamage(damage);
            cout << playerName << " attacking " << opponent.getName() << "'s Pokemon "
                 << opponent.actionCards[defenderIndex]->getCardName() << " with the Pokemon "
                 << actionCards[attackerIndex]->getCardName() << " with its attack: "
                 << get<2>(actionCards[attackerIndex]->getAttacks()[attackIndex]) << endl;
        }
    }

    void useTrainer(int index) {
        if (index < benchCards.size()) {
            TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[index]);
            if (trainer) {
                trainer->applyEffect(actionCards);
                cout << playerName << " is using the Trainer Card to \"" << trainer->getEffect() << "\"" << endl;
            }
        }
    }
};
