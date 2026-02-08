#include "Notifikaattori.h"
#include "Seuraaja.h"

int main() {
    Notifikaattori n;

    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);

    n.tulosta();

    n.postita("viesti 1");

    n.poista(&b);

    n.postita("viesti 2");

    return 0;
}
