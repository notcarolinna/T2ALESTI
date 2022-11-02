#include <iostream>

#include "FilaPedidos.h"

using namespace std;

int TAM_MAX = 10;

FilaPedidos::FilaPedidos() {
	this->pedidos = new Pedido * [TAM_MAX];
	this->tamanho = 0;
}

void FilaPedidos::enqueue(Pedido* elemento)
{
	if (tamanho >= TAM_MAX) {
		TAM_MAX += 10;

		Pedido** newPedidos = new Pedido * [TAM_MAX];

		for (int i = 0; i < tamanho; i++)
		{
			newPedidos[i] = pedidos[i];
		}

		// delete pedidos;
		pedidos = newPedidos;
	}

	pedidos[tamanho] = elemento;
	tamanho++;
}

Pedido* FilaPedidos::dequeue()
{
	Pedido* pedido = pedidos[0];
	for (int i = 1; i <= tamanho; i++) {
		pedidos[i - 1] = pedidos[i];
	}
	tamanho--;
	return pedido;
}

int FilaPedidos::size()
{
	return tamanho;
}

bool FilaPedidos::isEmpty()
{
	return tamanho == 0;
}

void FilaPedidos::probCancelamento(int probCancelamento)
{
	for (int i = 0; i < tamanho; i++)
	{
		pedidos[i]->probCancelamento(probCancelamento);
	}
}




