#pragma once
#include "Pedido.h"

class Separadores
{
private:
	Pedido** separadores;
	int numSeparadores;
	int separadoresOcupados;

public:
	Separadores(int numSeparadores);

	void adicionaPedido(Pedido* pedido, int tempo);
	Pedido* removePedidoPronto(int tempo);
	bool existePedidoPronto(int tempo);
	bool existeSeparadorLivre();

};
