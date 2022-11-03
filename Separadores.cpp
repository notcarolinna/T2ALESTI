#include <iostream>

#include "Separadores.h"

using namespace std;

Separadores::Separadores(int numSeparadores)
{
    this->separadores = new Pedido * [numSeparadores];
    this->comissoes = new int[numSeparadores];
    this->numSeparadores = numSeparadores;
    this->separadoresOcupados = 0;

    for (int i = 0; i < numSeparadores; i++)
    {
        separadores[i] = NULL;
        comissoes[i] = 0;
    }
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
                comissoes[i] += pedido->getProdutos();
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

void Separadores::probCancelamento(int probCancelamento)
{
    for (int i = 0; i < numSeparadores; i++)
    {
        if (separadores[i] != NULL)
            separadores[i]->probCancelamento(probCancelamento);
    }
}

void Separadores::exibeComissoes()
{
    for (int i = 0; i < numSeparadores; i++)
    {
        cout << "O separador " << i + 1 << " separou " << comissoes[i] << " produtos" << endl;
    }
}



