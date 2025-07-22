#include "cliente.h"

int Cliente::nextId = 1;

Cliente::Cliente(std::string telefone, std::string nome)
    : telefone(telefone), nome(nome) {
    id = nextId++;
}
