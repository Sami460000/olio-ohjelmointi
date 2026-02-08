#include "Seuraaja.h"
#include <iostream>

Seuraaja::Seuraaja(const std::string& n) : nimi(n), next(nullptr) {
    std::cout << "Luodaan seuraaja " << nimi << "\n";
}

std::string Seuraaja::getNimi() const {
    return nimi;
}

void Seuraaja::paivitys(const std::string& viesti) const {
    std::cout << "Seuraaja " << nimi << " sai viestin " << viesti << "\n";
}
