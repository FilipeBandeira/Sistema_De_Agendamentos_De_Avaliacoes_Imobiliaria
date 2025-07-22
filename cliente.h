#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
private:
    static int nextId;
public:
    int id;
    std::string telefone;
    std::string nome;

    Cliente(std::string telefone, std::string nome);
};

#endif
