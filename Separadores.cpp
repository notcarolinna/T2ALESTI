#include <iostream>
#include "Separadores.hpp"

using namespace std;

Separadores::Separadores(int numSeparadores)
{
    this->separadores = new Pedido *[numSeparadores]; // entregando o pedido para os separadores
    this->numSeparadores = numSeparadores;            // definindo o número de separadores
    this->separadoresOcupados = 0;
}

void Separadores::adicionaPedido(Pedido *pedido, int tempo)
{
    if (separadoresOcupados < numSeparadores)
    {
        for (int i = 0; i < numSeparadores; i++)
        {
            if (separadores[i] == NULL)
            {
                separadores[separadoresOcupados] = pedido;
                separadoresOcupados++;
                pedido->addTempoGastoFila(pedido->getTempoPronto() - tempo);
                pedido->setTempoPronto(tempo + pedido->getProdutos());

                return;
            }
        }
    }
}

Pedido *Separadores::removePedidoPronto(int tempo)
{
    for (int i = 0; i < numSeparadores; i++)
    {
        if (separadores[i] != NULL)
        {

            if (separadores[i]->getTempoPronto() == tempo)
            {
                Pedido *pedido = separadores[i];
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
}

bool Separadores::existeSeparadorLivre()
{
    return numSeparadores != separadoresOcupados;
}
