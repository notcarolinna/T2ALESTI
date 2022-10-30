#include <iostream>
#include <string>

#include "pedido.hpp"
#include "FilaPedidos.hpp"
#include "Separadores.hpp"

using namespace std;

int main()
{
    int TEMPO_MAX = 60;
    int PROBABILIDADE = 45;
    int MIN_PRODUTOS = 5;
    int MAX_PRODUTOS = 10;

    int NUM_SEPARADORES = 3;

    int tempo = 0;
    int pedidosCriados = 0;

    Pedido* pedido;

    FilaPedidos* filaSeparador = new FilaPedidos();
    FilaPedidos* filaEntrega = new FilaPedidos();

    Separadores* separadores = new Separadores(NUM_SEPARADORES);


    while (tempo != TEMPO_MAX)
    {
        if (rand() % 101 <= PROBABILIDADE)
        {
            pedido = new Pedido(MIN_PRODUTOS + (rand() % (MAX_PRODUTOS - MIN_PRODUTOS + 1)));
            pedido->setTempoPronto(tempo);

            filaSeparador->enqueue(pedido);
            pedidosCriados++;
        }

        while(separadores->existeSeparadorLivre() && !(filaSeparador->isEmpty()))
        {
            pedido = filaSeparador->dequeue();
            separadores->adicionaPedido(pedido, tempo);
        }

        while(separadores->existePedidoPronto(tempo))
        {
            pedido = separadores->removePedidoPronto(tempo);
            filaEntrega->enqueue(pedido);
        }



        tempo++;
    }
}
