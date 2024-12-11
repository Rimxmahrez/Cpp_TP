#include <string>
#include <iostream>
using namespace std;

class Card {
protected:
    string cardName;

public:
    Card(const string& name) : cardName(name) {}
    virtual void displayInfo() const = 0;
    virtual ~Card() {}
};
