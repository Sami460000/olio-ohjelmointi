#include "Asiakas.h"
#include <iostream>

Asiakas::Asiakas(const std::string& n, double raja)
    : nimi(n),
    kayttotili(n),
    luottotili(n, raja) {
    std::cout << "Asiakkuus luotu " << nimi << "\n";
}

std::string Asiakas::getNimi() const {
    return nimi;
}

void Asiakas::showSaldo() const {
    std::cout << "Kayttotilin saldo " << kayttotili.getBalance() << "\n";
    std::cout << "Luottotilin saldo " << luottotili.getBalance() << "\n";
}

bool Asiakas::talletus(double amount) {
    return kayttotili.deposit(amount);
}

bool Asiakas::nosto(double amount) {
    return kayttotili.withdraw(amount);
}

bool Asiakas::luotonMaksu(double amount) {
    return luottotili.deposit(amount);
}

bool Asiakas::luotonNosto(double amount) {
    return luottotili.withdraw(amount);
}

bool Asiakas::tiliSiirto(double amount, Asiakas& vastaanottaja) {
    if (amount < 0) return false;

    std::cout << "Pankkitili: " << nimi << " siirtaa " << amount
              << " " << vastaanottaja.nimi << ":lle\n";

    if (!kayttotili.withdraw(amount)) return false;

    if (!vastaanottaja.kayttotili.deposit(amount)) {
        // rollback just in case
        kayttotili.deposit(amount);
        return false;
    }
    return true;
}
