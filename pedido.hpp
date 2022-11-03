#pragma once

class Pedido {
private:
	int produtos;
	int tempoPronto;
	int tempoGastoFila;
	bool pedidoCancelado;
	int tempoPedidoEntrou;

public:
	Pedido(int produtos, int tempo);

	int getProdutos();
	int getTempoPronto();
	void setTempoPronto(int tempo);
	int getTempoGastoFila();
	void addTempoGastoFila(int tempo);
	void probCancelamento(int probCancelamento);
	bool isPedidoCancelado();
	int getTempoPedidoEntrou();
};
