#include <iostream>
#include "Entregadores.hpp"

using namespace std;

Entregadores::Entregadores(int numEntregadores)
{
    this->entregadores = new Pedido *[numEntregadores];
    this->numEntregadores = numEntregadores;
    this->entregadoresOcupados = 0;

    for (int i = 0; i < numEntregadores; i++)
        entregadores[i] = NULL;
}

void Entregadores::adicionaPedido(Pedido *pedido, int tempo)
{
    if (entregadoresOcupados < numEntregadores)
    {
        for (int i = 0; i < numEntregadores; i++)
        {
            if (entregadores[i] == NULL)
            {
                entregadores[i] = pedido;
                entregadoresOcupados++;

                pedido->addTempoGastoFila(tempo - pedido->getTempoPronto());
                pedido->setTempoPronto(tempo + (4 + (rand() % 5)));

                return;
            }
        }
    }
}

Pedido *Entregadores::removePedidoPronto(int tempo)
{
    for (int i = 0; i < numEntregadores; i++)
    {
        if (entregadores[i] != NULL)
        {
            if (entregadores[i]->getTempoPronto() == tempo)
            {
                Pedido *pedido = entregadores[i];
                entregadores[i] = NULL;
                entregadoresOcupados--;
                return pedido;
            }
        }
    }
    return NULL;
}

bool Entregadores::existePedidoPronto(int tempo)
{
    for (int i = 0; i < numEntregadores; i++)
    {
        if (entregadores[i] != NULL)
        {
            if (entregadores[i]->getTempoPronto() == tempo)
            {
                return true;
            }
        }
    }

    return false;
}

bool Entregadores::existeEntregadorLivre()
{
    return numEntregadores != entregadoresOcupados;
}
