#include "imovel.h"

int Imovel::nextId = 1;

Imovel::Imovel(std::string tipoStr, int propId, double lat, double lon, double preco, std::string endereco)
    : proprietarioId(propId), lat(lat), lon(lon), preco(preco), endereco(endereco) {
    if (tipoStr == "Casa") tipo = Casa;
    else if (tipoStr == "Apartamento") tipo = Apartamento;
    else tipo = Terreno;
    id = nextId++;
}
