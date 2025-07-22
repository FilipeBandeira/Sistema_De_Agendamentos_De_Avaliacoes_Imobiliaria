#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>

enum TipoImovel { Casa, Apartamento, Terreno };

class Imovel {
private:
    static int nextId;
public:
    int id;
    TipoImovel tipo;
    int proprietarioId;
    double lat, lon;
    double preco;
    std::string endereco;

    Imovel(std::string tipoStr, int propId, double lat, double lon, double preco, std::string endereco);
};

#endif
