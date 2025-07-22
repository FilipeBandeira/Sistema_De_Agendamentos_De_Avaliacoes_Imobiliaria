#include "agendamento.h"
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <tuple>

constexpr double EARTH_R = 6371.0;

double haversine(double lat1, double lon1, double lat2, double lon2) {
    auto deg2rad = [](double d){ return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = std::pow(std::sin(dlat/2), 2) +
               std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) *
               std::pow(std::sin(dlon/2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_R * c;
}

void agendarAvaliacoes(std::vector<Corretor>& corretores, std::vector<Imovel>& imoveis) {
    std::vector<Corretor*> avaliadores;
    for (auto& c : corretores) {
        if (c.avaliador)
            avaliadores.push_back(&c);
    }

    std::vector<std::vector<Imovel>> designacoes(avaliadores.size());

    std::sort(imoveis.begin(), imoveis.end(), [](const Imovel& a, const Imovel& b) {
        return a.id < b.id;
    });

    for (size_t i = 0; i < imoveis.size(); ++i) {
        designacoes[i % avaliadores.size()].push_back(imoveis[i]);
    }

    for (size_t i = 0; i < avaliadores.size(); ++i) {
        Corretor* corr = avaliadores[i];
        auto& lista = designacoes[i];

        int hora = 9, minuto = 0;
        double atualLat = corr->lat, atualLon = corr->lon;

        std::vector<bool> visitado(lista.size(), false);

        std::cout << "Corretor " << corr->id << std::endl;

        for (size_t j = 0; j < lista.size(); ++j) {
            int prox = -1;
            double menorDist = 1e9;

            for (size_t k = 0; k < lista.size(); ++k) {
                if (!visitado[k]) {
                    double dist = haversine(atualLat, atualLon, lista[k].lat, lista[k].lon);
                    if (dist < menorDist) {
                        menorDist = dist;
                        prox = k;
                    }
                }
            }

            if (prox != -1) {
                visitado[prox] = true;

                int tempoDesloc = static_cast<int>(std::round(menorDist * 2));
                minuto += tempoDesloc;

                hora += minuto / 60;
                minuto %= 60;

                std::cout << std::setfill('0') << std::setw(2) << hora << ":" 
                          << std::setw(2) << minuto << " Imóvel " << lista[prox].id << std::endl;

                minuto += 60;
                hora += minuto / 60;
                minuto %= 60;

                atualLat = lista[prox].lat;
                atualLon = lista[prox].lon;
            }
        }

        if (i + 1 < avaliadores.size())
            std::cout << std::endl;
    }
}
