#include <iostream>
#include "Pedido.h"

using namespace std;

Pedido::Pedido(int produtos) {
	this->produtos = produtos;
	this->tempoGastoFila = 0;
	this->tempoPronto = 0;
	this->pedidoCancelado = false;
}

int Pedido::getProdutos() {
	return produtos;
}

void Pedido::setTempoPronto(int tempo) {
	tempoPronto = tempo;
}

int Pedido::getTempoPronto() {
	return tempoPronto;
}

void Pedido::addTempoGastoFila(int tempo) {
	tempoGastoFila += tempo;
}

int Pedido::getTempoGastoFila() {
	return tempoGastoFila;
}

void Pedido::probCancelamento(int probCancelamento)
{
	if (rand() % (probCancelamento + 1))
	{
		pedidoCancelado = true;
	}
}

bool Pedido::isPedidoCancelado()
{
	return pedidoCancelado;
}


