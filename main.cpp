#include <iostream>
#include <string>

#include "Pedido.h"
#include "FilaPedidos.h"
#include "Separadores.h"
#include "Entregadores.h"
#include "ControladorInfo.h"

using namespace std;

int main()
{
	int RODADAS;

	cout << "Digite o numero de rodadas: ";

	cin >> RODADAS;

	int PROBABILIDADE = 100;
	int MAX_PRODUTOS = 10;

	int NUM_SEPARADORES = 3;
	int NUM_ENTREGADORES = 3;

	int PROB_CANCELAMENTO = 2;

	int tempo = 0;

	Pedido* pedido;

	FilaPedidos* filaSeparador = new FilaPedidos();
	FilaPedidos* filaEntrega = new FilaPedidos();

	Separadores* separadores = new Separadores(NUM_SEPARADORES);
	Entregadores* entregadores = new Entregadores(NUM_ENTREGADORES);

	ControladorInfo* controlador = new ControladorInfo();

	
	while (tempo != RODADAS)
	{
		
		if (rand() % 100 <= PROBABILIDADE)
		{
			pedido = new Pedido(MIN_PRODUTOS + (rand() % (MAX_PRODUTOS - MIN_PRODUTOS + 1)), tempo);
			pedido->setTempoPronto(tempo);

			filaSeparador->enqueue(pedido);
			controlador->addPedidoCriado();
		}

		
		while (separadores->existeSeparadorLivre() && !(filaSeparador->isEmpty()))
		{
			pedido = filaSeparador->dequeue();
			pedido->addTempoGastoFila(tempo - pedido->getTempoPronto());
			if (pedido->isPedidoCancelado())
			{
				controlador->addPedidoCancelado();
				delete pedido;
			} else
			{
				separadores->adicionaPedido(pedido, tempo);
			}
		}

		
		while (separadores->existePedidoPronto(tempo))
		{
			pedido = separadores->removePedidoPronto(tempo);
			if (pedido->isPedidoCancelado())
			{
				controlador->addPedidoCancelado();
				delete pedido;
			} else {
				filaEntrega->enqueue(pedido);
			}
		}

		while (entregadores->existeEntregadoresLivre() && !(filaEntrega->isEmpty()))
		{
			pedido = filaEntrega->dequeue();
			pedido->addTempoGastoFila(tempo - pedido->getTempoPronto());
			if (pedido->isPedidoCancelado())
			{
				controlador->addPedidoCancelado();
				delete pedido;
			} else
			{
				entregadores->adicionaPedido(pedido, tempo);
			}
		}


		while (entregadores->existePedidoPronto(tempo))
		{
			pedido = entregadores->removePedidoPronto(tempo);
			if (pedido->isPedidoCancelado()) {
				controlador->addPedidoQuaseCancelado();
			}
			controlador->addTempoFilaPedidos(pedido->getTempoGastoFila());
			controlador->setPedidoMaisDemorado(tempo - pedido->getTempoPedidoEntrou());
			controlador->addPedidoEnviado();
			delete pedido;
		}

		filaSeparador->probCancelamento(PROB_CANCELAMENTO);
		filaEntrega->probCancelamento(PROB_CANCELAMENTO);
		separadores->probCancelamento(PROB_CANCELAMENTO);
		entregadores->probCancelamento(PROB_CANCELAMENTO);
		
		tempo++;
		
	}

	cout << "\nPedidos Criados: " << controlador->getPedidosCriados() << endl;
	cout << "\nPedidos Cancelados: " << controlador->getPedidosCancelados() << endl;
	cout << "\nPedidos Quase Cancelados: " << controlador->getPedidoQuaseCancelados() << endl;
	cout << "\nPedidos Entregues: " << controlador->getPedidosEnviados() << endl;
	cout << endl;

	separadores->exibeComissoes();
	cout << endl;
	entregadores->exibeComissoes();

	cout << endl;

	cout << "Tempo Medio em Filas: " << controlador->getMediaTempoFilaPedidos() << " rodadas." << endl;
	cout << "Pedido que mais demorou: " << controlador->getPedidoMaisDemorado() << " rodadas." << endl;

}
