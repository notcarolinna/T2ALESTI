#include <iostream>
#include "Entregadores.h"

using namespace std;

Entregadores::Entregadores(int numEntregadores)
{
    this->entregadores = new Pedido * [numEntregadores];
    this->comissoes = new int[numEntregadores];
    this->numEntregadores = numEntregadores;
    this->entregadoresOcupados = 0;

    for (int i = 0; i < numEntregadores; i++) {
        entregadores[i] = NULL;
        comissoes[i] = 0;
    }
}

void Entregadores::adicionaPedido(Pedido* pedido, int tempo)
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

Pedido* Entregadores::removePedidoPronto(int tempo)
{
    for (int i = 0; i < numEntregadores; i++)
    {
        if (entregadores[i] != NULL)
        {
            if (entregadores[i]->getTempoPronto() == tempo)
            {
                Pedido* pedido = entregadores[i];
                comissoes[i] += 1;
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

bool Entregadores::existeEntregadoresLivre()
{
    return numEntregadores != entregadoresOcupados;
}

void Entregadores::probCancelamento(int probCancelamento)
{
    for (int i = 0; i < numEntregadores; i++)
    {
        if (entregadores[i] != NULL)
            entregadores[i]->probCancelamento(probCancelamento);
    }
}

void Entregadores::exibeComissoes()
{
    for (int i = 0; i < numEntregadores; i++)
    {
        cout << "O entregador " << i + 1 << " entregou " << comissoes[i] << " pedidos" << endl;
    }
}

