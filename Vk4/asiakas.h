#pragma once
#include <string>
#include "Pankkitili.h"
#include "Luottotili.h"

class Asiakas {
private:
    std::string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;

public:
    Asiakas(const std::string& n, double luottoRaja);

    std::string getNimi() const;
    void showSaldo() const;

    bool talletus(double amount);
    bool nosto(double amount);
    bool luotonMaksu(double amount);
    bool luotonNosto(double amount);

    bool tiliSiirto(double amount, Asiakas& vastaanottaja);
};
