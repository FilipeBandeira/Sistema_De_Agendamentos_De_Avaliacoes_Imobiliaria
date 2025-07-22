# Sistema de Agendamentos de Avaliações Imobiliária

Sistema de Agendamentos de Avaliações Imobiliária - Projeto final da disciplina de Linguagem de Programação I.

Este projeto em C++ implementa um sistema automatizado de agendamento de avaliações de imóveis para uma imobiliária. O programa lê dados de entrada via stdin (padrão), processa corretores, clientes e imóveis, e gera uma agenda otimizada de visitas para corretores avaliadores.

  Funcionalidades:
  
- Distribuição Round-Robin de imóveis entre os avaliadores.

- Roteamento de visitas com base no algoritmo do vizinho mais próximo.

- Cálculo de distância usando a fórmula de Haversine (2 min/km).

- Horários de visitas iniciam às 09:00 e são ajustados conforme deslocamento + tempo de avaliação (1h).

- Saída formatada conforme exigido: HH:MM Imóvel ID.

  Estrutura Modular: (O projeto é dividido em múltiplos arquivos):

- main.cpp: entrada e controle geral.

- corretor.*, cliente.*, imovel.*: classes de domínio com IDs automáticos.

- agendamento.*: lógica de agendamento e cálculo de rotas.

- Makefile: compila com make e gera o executável imobiliaria.
