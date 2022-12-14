#pragma once
#include "Pedido.h"

class Entregadores
{
private:
	Pedido** entregadores;
	int numEntregadores;
	int entregadoresOcupados;

	int* comissoes;

public:
	Entregadores(int numEntregadores);

	void adicionaPedido(Pedido* pedido, int tempo);
	Pedido* removePedidoPronto(int tempo);
	bool existePedidoPronto(int tempo);
	bool existeEntregadoresLivre();
	void probCancelamento(int probCancelamento);
	void exibeComissoes();
};
