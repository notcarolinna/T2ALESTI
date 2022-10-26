#include <iostream>
#include "pedido.hpp"

using namespace std;

Pedido::Pedido(int produtos)
{

    this->produtos = produtos;
    this->tempoGastoFila = 0; // inicializa em 0
    this->tempoPronto = 0;
}

int Pedido::getProdutos()
{
    return produtos;
}

void Pedido::setTempoPronto(int tempo)
{
    tempoPronto = tempo; // definindo que tempo pronto é tempo ;)
}

int Pedido::getTempoPronto()
{
    return tempoPronto;
}

void Pedido::addTempoGastoFila(int tempo)
{
    tempoGastoFila += tempo;
}

int Pedido::getTempoGastoFila()
{
    return tempoGastoFila;
}