#include "corretor.h"

int Corretor::nextId = 1;

Corretor::Corretor(std::string telefone, bool avaliador, double lat, double lon, std::string nome)
    : telefone(telefone), avaliador(avaliador), lat(lat), lon(lon), nome(nome) {
    id = nextId++;
}
