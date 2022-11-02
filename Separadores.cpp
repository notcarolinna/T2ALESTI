#include <iostream>
#include "Separadores.h"

using namespace std;

Separadores::Separadores(int numSeparadores)
{
    this->separadores = new Pedido * [numSeparadores];
    this->numSeparadores = numSeparadores;
    this->separadoresOcupados = 0;

    for (int i = 0; i < numSeparadores; i++)
        separadores[i] = NULL;
}

void Separadores::adicionaPedido(Pedido* pedido, int tempo)
{
    if (separadoresOcupados < numSeparadores)
    {
        for (int i = 0; i < numSeparadores; i++)
        {
            if (separadores[i] == NULL)
            {
                separadores[i] = pedido;
                separadoresOcupados++;

                pedido->addTempoGastoFila(tempo - pedido->getTempoPronto());
                pedido->setTempoPronto(tempo + pedido->getProdutos());

                return;
            }
        }
    }
}

Pedido* Separadores::removePedidoPronto(int tempo)
{
    for (int i = 0; i < numSeparadores; i++)
    {
        if (separadores[i] != NULL)
        {
            if (separadores[i]->getTempoPronto() == tempo)
            {
                Pedido* pedido = separadores[i];
                separadores[i] = NULL;
                separadoresOcupados--;
                return pedido;
            }
        }
    }
    return NULL;
}

bool Separadores::existePedidoPronto(int tempo)
{
    for (int i = 0; i < numSeparadores; i++)
    {
        if (separadores[i] != NULL)
        {
            if (separadores[i]->getTempoPronto() == tempo)
            {
                return true;
            }
        }
    }

    return false;
}

bool Separadores::existeSeparadorLivre()
{
    return numSeparadores != separadoresOcupados;
}


