#include <iostream>
#include "Pedido.h"

using namespace std;

Pedido::Pedido(int produtos, int tempo) {
	this->produtos = produtos;
	this->tempoGastoFila = 0;
	this->tempoPronto = 0;
	this->pedidoCancelado = false;
	this->tempoPedidoEntrou = tempo;
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
	if ((rand() % 100 + 1) < probCancelamento)
	{
		pedidoCancelado = true;
	}
}

bool Pedido::isPedidoCancelado()
{
	return pedidoCancelado;
}

int Pedido::getTempoPedidoEntrou() {
	return tempoPedidoEntrou;
}



