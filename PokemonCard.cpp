#include <vector>
#include <tuple>

class PokemonCard : public Card {
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    vector<tuple<int, int, string, int>> attacks;

public:
    PokemonCard(const string& name, const string& type, const string& family, int level, int maxHp, int currHp,
                const string& attack1Desc, int attack1Dmg, int attack1Cost,
                const string& attack2Desc, int attack2Dmg, int attack2Cost)
        : Card(name), pokemonType(type), familyName(family), evolutionLevel(level), maxHP(maxHp), hp(currHp) {
        attacks.push_back({attack1Cost, 0, attack1Desc, attack1Dmg});
        attacks.push_back({attack2Cost, 0, attack2Desc, attack2Dmg});
    }

    void displayInfo() const override {
        cout << "Pokemon Card - Name: " << cardName << ", Type: " << pokemonType
             << ", Evolution Level: " << evolutionLevel << " of the family \"" << familyName
             << "\", HP: " << hp << " / " << maxHP << endl;
        for (size_t i = 0; i < attacks.size(); ++i) {
            cout << "Attack #" << i << ":\n"
                 << "Attack cost: " << get<0>(attacks[i]) << "\n"
                 << "Attack current energy storage: " << get<1>(attacks[i]) << "\n"
                 << "Attack description: " << get<2>(attacks[i]) << "\n"
                 << "Attack damage: " << get<3>(attacks[i]) << endl;
        }
    }

    void attachEnergy(int index) {
        if (index < attacks.size()) {
            get<1>(attacks[index])++;
        }
    }

    void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0) hp = 0;
    }

    void heal() {
        hp = maxHP;
    }

    int getHp() const { return hp; }
    const vector<tuple<int, int, string, int>>& getAttacks() const { return attacks; }
};
