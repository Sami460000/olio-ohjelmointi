#include "Notifikaattori.h"
#include <iostream>

Notifikaattori::Notifikaattori() : seuraajat(nullptr) {
    std::cout << "Luodaan notifikaattori\n";
}


void Notifikaattori::lisaa(Seuraaja* s) {
    if (s == nullptr) return;

    // Optional: prevent duplicates (same pointer already in list)
    for (Seuraaja* cur = seuraajat; cur != nullptr; cur = cur->next) {
        if (cur == s) {
            return;
        }
    }

    std::cout << "Notifikaattori lisaa seuraajan " << s->getNimi() << "\n";
    s->next = seuraajat;
    seuraajat = s;
}

// Remove by bypassing the node (as in the slides)
void Notifikaattori::poista(Seuraaja* s) {
    if (s == nullptr || seuraajat == nullptr) return;

    // removing head
    if (seuraajat == s) {
        std::cout << "Notifikaattori poistaa seuraajan " << s->getNimi() << "\n";
        seuraajat = seuraajat->next;
        s->next = nullptr;
        return;
    }

    // removing from middle/end
    Seuraaja* prev = seuraajat;
    Seuraaja* cur = seuraajat->next;

    while (cur != nullptr) {
        if (cur == s) {
            std::cout << "Notifikaattori poistaa seuraajan " << s->getNimi() << "\n";
            prev->next = cur->next;
            s->next = nullptr;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void Notifikaattori::tulosta() const {
    std::cout << "Notifikaattorin seuraajat:\n";
    for (Seuraaja* cur = seuraajat; cur != nullptr; cur = cur->next) {
        std::cout << "Seuraaja " << cur->getNimi() << "\n";
    }
}

void Notifikaattori::postaa(const std::string& viesti) const {
    std::cout << "Notifikaattori postaa viestin " << viesti << "\n";
    for (Seuraaja* cur = seuraajat; cur != nullptr; cur = cur->next) {
        cur->paivitys(viesti);
    }
}
