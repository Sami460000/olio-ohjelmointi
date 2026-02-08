#pragma once
#include <string>

class Seuraaja {
private:
    std::string nimi;

public:
    Seuraaja* next;

    explicit Seuraaja(const std::string& n);

    std::string getNimi() const;
    void paivitys(const std::string& viesti) const;
};
