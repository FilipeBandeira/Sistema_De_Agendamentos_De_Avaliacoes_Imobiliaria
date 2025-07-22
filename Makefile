CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

SRCS = main.cpp corretor.cpp cliente.cpp imovel.cpp agendamento.cpp
OBJS = $(SRCS:.cpp=.o)

imobiliaria: $(OBJS)
	$(CXX) $(CXXFLAGS) -o imobiliaria $(OBJS)

clean:
	rm -f *.o imobiliaria
