#pragma once
#include <string>
#include "Seuraaja.h"

class Notifikaattori {
private:
    Seuraaja* seuraajat;

public:
    Notifikaattori();

    void lisaa(Seuraaja* s);
    void poista(Seuraaja* s);

    void tulosta() const;
    void postaa(const std::string& viesti) const;
};
