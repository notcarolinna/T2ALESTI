#include <iostream>
#include <string>

#include "pedido.hpp"
#include "FilaPedidos.hpp"
#include "Separadores.hpp"
#include "Entregadores.hpp"
#include "ControladorInfo.hpp"

using namespace std;

int main()
{
    int TEMPO_MAX = 60;
    int PROBABILIDADE = 45;
    int MIN_PRODUTOS = 5;
    int MAX_PRODUTOS = 10;

    int NUM_SEPARADORES = 3;
    int NUM_ENTREGADORES = 3;

    int tempo = 0;
    int pedidosCriados = 0;

    Pedido *pedido;

    FilaPedidos *filaSeparador = new FilaPedidos();
    FilaPedidos *filaEntrega = new FilaPedidos();

    Separadores *separadores = new Separadores(NUM_SEPARADORES);
    Entregadores *entregadores = new Entregadores(NUM_ENTREGADORES);
    ControladorInfo *controlador = new ControladorInfo();

    while (tempo != TEMPO_MAX)
    {
        if (rand() % 101 <= PROBABILIDADE)
        {
            pedido = new Pedido(MIN_PRODUTOS + (rand() % (MAX_PRODUTOS - MIN_PRODUTOS + 1)));
            pedido->setTempoPronto(tempo);

            filaSeparador->enqueue(pedido);
            controlador->addPedidoCriado();
        }

        while (separadores->existeSeparadorLivre() && !(filaSeparador->isEmpty()))
        {
            pedido = filaSeparador->dequeue();
            separadores->adicionaPedido(pedido, tempo);
        }

        while (separadores->existePedidoPronto(tempo))
        {
            pedido = separadores->removePedidoPronto(tempo);
            filaEntrega->enqueue(pedido);
        }

        while (entregadores->existeEntregadorLivre() && !(filaEntrega->isEmpty()))
        {
            pedido = filaEntrega->dequeue();
            entregadores->adicionaPedido(pedido, tempo);
        }

        while (entregadores->existePedidoPronto(tempo))
        {
            pedido = entregadores->removePedidoPronto(tempo);
            controlador->addPedidoEnviado();
            delete pedido;
        }

        tempo++;
    }
}
