#include "Pankkitili.h"
#include <iostream>

Pankkitili::Pankkitili(const std::string& owner)
    : omistaja(owner), saldo(0.0) {
    std::cout << "Pankkitili luotu " << omistaja << ":lle\n";
}

double Pankkitili::getBalance() const {
    return saldo;
}

bool Pankkitili::deposit(double amount) {
    if (amount < 0) return false;
    saldo += amount;
    std::cout << omistaja << " Pankkitili: talletus " << amount << " tehty\n";
    return true;
}

bool Pankkitili::withdraw(double amount) {
    if (amount < 0) return false;
    if (saldo - amount < 0) return false;
    saldo -= amount;
    std::cout << omistaja << " Pankkitili: nosto " << amount << " tehty\n";
    return true;
}
