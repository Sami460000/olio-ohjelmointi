#include "Luottotili.h"
#include <iostream>

Luottotili::Luottotili(const std::string& owner, double limit)
    : Pankkitili(owner), luottoRaja(limit) {
    std::cout << "Luottotili luotu " << omistaja << ":lle, luottoraja " << luottoRaja << "\n";
}

// balansi
double Luottotili::getBalance() const {
    return luottoRaja + saldo;
}

// Takaisinmaksu ei yli nollan
bool Luottotili::deposit(double amount) {
    if (amount < 0) return false;
    if (saldo + amount > 0) return false;

    saldo += amount;
    std::cout << omistaja << " Luottotili: maksu " << amount
              << " tehty, luottoa jaljella " << getBalance() << "\n";
    return true;
}


bool Luottotili::withdraw(double amount) {
    if (amount < 0) return false;
    if (saldo - amount < -luottoRaja) return false;

    saldo -= amount;
    std::cout << "Luottotili: nosto " << amount
              << " tehty, luottoa jaljella " << getBalance() << "\n";
    return true;
}
