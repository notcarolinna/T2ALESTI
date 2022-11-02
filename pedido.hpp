#pragma once

class Pedido {
private:
	int produtos;
	int tempoPronto;	// Quando esta pronto
	int tempoGastoFila; // Diferença entre entrar e sair da fila
	bool pedidoCancelado;

public:
	Pedido(int produtos);

	int getProdutos();
	int getTempoPronto();
	int getTempoGastoFila();


	void setTempoPronto(int tempo);                //Quando o pedido fica pronto
	void addTempoGastoFila(int tempo);             //Quanto tempo o pedido fica na fila
	void probCancelamento(int probCancelamento);   //Proabilidade de o pedido ser cancelado

	bool isPedidoCancelado();
};
