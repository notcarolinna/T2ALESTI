#include <iostream>

#include "Pedido.h"
#include "FilaPedidos.h"
#include "Separadores.h"
#include "Entregadores.h"
#include "ControladorInfo.h"

using namespace std;

int main()
{
	int RODADAS = 60; // Rodadas
	int PROBABILIDADE = 45; // Probabilidade de aparecer um pedido
	int MIN_PRODUTOS = 5;
	int MAX_PRODUTOS = 10;

	int NUM_SEPARADORES = 3;
	int NUM_ENTREGADORES = 3;

	int PROB_CANCELAMENTO = 5;

	int tempo = 0;

	Pedido* pedido;

	FilaPedidos* filaSeparador = new FilaPedidos();
	FilaPedidos* filaEntrega = new FilaPedidos();
	ControladorInfo* controlador = new ControladorInfo();

	Separadores* separadores = new Separadores(NUM_SEPARADORES);    //criação de 3 separadores
	Entregadores* entregadores = new Entregadores(NUM_ENTREGADORES); //criação de 3 entregadores




	while (tempo != RODADAS) // vai rodar até chegar no número de rodadas dita pelo usuário
	{

		if (rand() % 100 <= PROBABILIDADE)// probabilidade do pedido ser criado
		{
			pedido = new Pedido(MIN_PRODUTOS + (rand() % (MAX_PRODUTOS - MIN_PRODUTOS + 1)));

			pedido->setTempoPronto(tempo); // *** Inicia a contagem de tempo?
			filaSeparador->enqueue(pedido);
			controlador->addPedidoCriado();
		}


		while (separadores->existeSeparadorLivre() && !(filaSeparador->isEmpty()))	//Verifica se há um separador livre e se a fila de separadores não está vazia
		{
			pedido = filaSeparador->dequeue(); //Sai da fila de espera de um separador

			//SOLICITAÇÃO DE CANCELAMENTO

			if (pedido->isPedidoCancelado())
			{
				controlador->addPedidoCancelado();
				delete pedido;
			}
			else
			{
				separadores->adicionaPedido(pedido, tempo); //Vai para um separador
			}
		}


		while (separadores->existePedidoPronto(tempo)) //Verifica se o separador terminou de organizar o pedido
		{
			pedido = separadores->removePedidoPronto(tempo); //Separador termina o pedido

			//SOLICITAÇÃO DE CANCELAMENTO

			if (pedido->isPedidoCancelado())
			{
				controlador->addPedidoCancelado();
				delete pedido;
			}
			else {
				filaEntrega->enqueue(pedido); //Coloca o pedido na fila de entrega
			}
		}

		while (entregadores->existeEntregadoresLivre() && !(filaEntrega->isEmpty()))//Verifica se há um entregador livre e se a fila de entregadores não está vazia
		{
			pedido = filaEntrega->dequeue(); //Sai da fila de entrega
			
			//SOLICITAÇÃO DE CANCELAMENTO
			
			if (pedido->isPedidoCancelado())
			{
				controlador->addPedidoCancelado();
				delete pedido;
			}
			else
			{
				entregadores->adicionaPedido(pedido, tempo); //Libera o pedido para o entregador
			}
		}


		while (entregadores->existePedidoPronto(tempo)) //Roda enquanto tiver um pedido para ser entregue
		{
			pedido = entregadores->removePedidoPronto(tempo); //Entregador pega o pedido e sai para entrega
			controlador->addPedidoEnviado();
			delete pedido;
		}

		filaSeparador->probCancelamento(PROB_CANCELAMENTO);
		filaEntrega->probCancelamento(PROB_CANCELAMENTO);


		tempo++;

	}


	// TESTES

	cout << "\nPedidos Criados: " << controlador->getPedidosCriados() << endl;
	cout << "\nPedidos Cancelados: " << controlador->getPedidosCancelados() << endl;
	cout << "\nPedidos Entregues: " << controlador->getPedidosEnviados() << endl;
}
