#include "Asiakas.h"
#include <iostream>

int main() {
    Asiakas Aapeli("Aapeli", 1000);
    Aapeli.showSaldo();
    std::cout << "\n";

    Aapeli.talletus(250);
    Aapeli.luotonNosto(150);
    Aapeli.showSaldo();

    std::cout << "\n";

    Asiakas Pertta("Bertta", 1000);
    Pertta.showSaldo();

    std::cout << "\n";

    std::cout << Aapeli.getNimi() << "\n";
    Aapeli.showSaldo();

    Aapeli.tiliSiirto(50, Pertta);

    std::cout << Pertta.getNimi() << "\n";
    Pertta.showSaldo();

    return 0;
}
