#include <iostream>
#include <string>
#include <algorithm>
using namespace std;




// ----------------------
// Base class: Chef
// ----------------------
class Chef {
protected:
    string chefName;   // protected as UML says (#)

public:
    // Constructor
    Chef(string name) {
        chefName = name;
        cout << "Chef " << chefName << " constructor" << endl;
    }

    // Destructor
    virtual ~Chef() {
        cout << "Chef " << chefName << " destructor" << endl;
    }

    // Getter
    string getName() {
        return chefName;
    }

    // Salad: 5 ingredients per portion
    int makeSalad(int items) {
        int portions = items / 5;
        cout << "Chef " << chefName
             << " with " << items
             << " items can make salad "
             << portions << " portions" << endl;
        return portions;
    }

    // Soup: 3 ingredients per portion
    int makeSoup(int items) {
        int portions = items / 3;
        cout << "Chef " << chefName
             << " with " << items
             << " items can make soup "
             << portions << " portions" << endl;
        return portions;
    }
};

// ----------------------
// Derived class: ItalianChef
// ----------------------
class ItalianChef : public Chef {
private:
    string password = "pizza"; // default value
    int flour;
    int water;

    // Private secret pizza function
    int makePizza() {
        int pizzas = min(flour / 5, water / 5);

        cout << "ItalianChef " << chefName
             << " with " << flour
             << " flour and " << water
             << " water can make "
             << pizzas << " pizzas" << endl;

        return pizzas;
    }

public:
    // Construktori
    ItalianChef(string name) : Chef(name) {
        cout << "ItalianChef " << chefName << " constructor" << endl;
    }

    // Destruktori
    ~ItalianChef() {
        cout << "ItalianChef " << chefName << " destructor" << endl;
    }

    // Ask secret: password check
    bool Salainen(string pw, int f, int w) {
        flour = f;
        water = w;

        if (pw == password) {
            cout << "Password ok!" << endl;
            makePizza();
            return true;
        }
        else {
            cout << "Wrong password!" << endl;
            return false;
        }
    }
};

//testausta varten
int main() {

    Chef chef1("Pasi");
    chef1.makeSalad(11);
    chef1.makeSoup(14);

    cout << endl;

    ItalianChef chef2("Erkki");
    chef2.makeSalad(9);

    chef2.Salainen("pizza", 12, 12);

    return 0;
}


