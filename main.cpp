#include <iostream>
#include "pedido.hpp";
#include "FilaPedidos.hpp"

using namespace std;

int main()
{

    int TEMPO_MAX = 60;
    int PROBABILIDADE = 45;
    int MIN_PRODUTOS = 5;
    int MAX_PRODUTOS = 10;

    int tempo = 0;
    int pedidosCriados = 0;

    FilaPedidos *filaSeparador = new FilaPedidos(); // fila de pedidos para os separadores
    FilaPedidos *filaEntrega = new FilaPedidos();   // fila de pedidos para os entregadores

    while (tempo != TEMPO_MAX) // rodando tempo
    {
        if ((rand() % 101 <= 45)) // gera pedido
        {
            filaSeparador->enqueue(new Pedido(MIN_PRODUTOS + (rand() % (MAX_PRODUTOS - MIN_PRODUTOS + 1))));
            pedidosCriados++;
        }
        tempo++;
    }
}
