#ifndef CORRETOR_H
#define CORRETOR_H

#include <string>

class Corretor {
private:
    static int nextId;
public:
    int id;
    std::string telefone;
    bool avaliador;
    double lat, lon;
    std::string nome;

    Corretor(std::string telefone, bool avaliador, double lat, double lon, std::string nome);
};

#endif
