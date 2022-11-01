#include <iostream>
#include <string>

#include "pedido.hpp"
#include "FilaPedidos.hpp"
#include "Separadores.hpp"
#include "Entregadores.hpp"
#include "ControladorInfo.hpp"

using namespace std;

int main()
{
    int TEMPO_MAX = 60;     
    int PROBABILIDADE = 45; // probabilidade de aparecer um pedido
    int MIN_PRODUTOS = 5;   // mínimo de produtos
    int MAX_PRODUTOS = 10;  // máximo de produtos

    int NUM_SEPARADORES = 3;
    int NUM_ENTREGADORES = 3;

    int PROB_CANCELAMENTO = 5; // probabilidade de um pedido ser cancelado

    int tempo = 0;         
    int pedidosCriados = 0; // número de pedidos criados

    Pedido *pedido; // construtor da classe pedido

    FilaPedidos *filaSeparador = new FilaPedidos(); 
    FilaPedidos *filaEntrega = new FilaPedidos();

    Separadores *separadores = new Separadores(NUM_SEPARADORES);     // cria 3 separadores com a quantidade definida na linha 19
    Entregadores *entregadores = new Entregadores(NUM_ENTREGADORES); // cria 3 entregadores com a quantidade definida na linha 20

    ControladorInfo *controlador = new ControladorInfo(); 

    while (tempo != TEMPO_MAX) // while pra tudo isso rodar enquanto não bater no tempo max
    {
                  

        if (rand() % 100 <= PROBABILIDADE) // proabilidade do pedido ser criado
        {
           
            pedido = new Pedido(MIN_PRODUTOS + (rand() % (MAX_PRODUTOS - MIN_PRODUTOS + 1))); // resto de um número aleatório por (MAX_PRODUTOS - MIN_PRODUTOS + 1)

            pedido->setTempoPronto(tempo);  // modifica o tempo
            filaSeparador->enqueue(pedido); // reduz a quantidade de pedidos
            controlador->addPedidoCriado(); // adiciona o pedido na lista dos pedidos criados
        }

        // verificar se existe um separador livre pra organizar o pedido e deixar o pacote pronto pro entregador

        while (separadores->existeSeparadorLivre() && !(filaSeparador->isEmpty())) // vai no arquivo dos separadores e verifica se existe um livre enquanto a fila dos separadores NÃO ESTÁ VAZIA.
        {
            pedido = filaSeparador->dequeue(); // um separador fica ocupado
            
            //CANCELAMENTO
            
            if (pedido->isPedidoCancelado())   // se o pedido pôde ser cancelado
            {
                controlador->addPedidoCancelado(); // adiciona o pedido na lista de cancelados
                delete pedido;                     // deleta o pedido
            }
            else
            {
                separadores->adicionaPedido(pedido, tempo); // envia o pedido para os separadores
                // *** Não entendi o pedido e o tempo, seria para saber quanto tempo o pedido ficou na fila de espera?
            }
        }

        // verificar se o separador terminou de organizar o pedido

        while (separadores->existePedidoPronto(tempo)) // se existe um pedido disponível para entrega
        {
            pedido = separadores->removePedidoPronto(tempo); // o pedido ficou pronto para o entregador
            
            //CANCELAMENTO
            
            if (pedido->isPedidoCancelado())                
            {
                controlador->addPedidoCancelado(); // cancelou, foi pra lista
                delete pedido;                     // foi aniquilado
            }
            else 
            {
                filaEntrega->enqueue(pedido); // Coloca o pedido na lista de pedidos para serem entregues
            }
        }

        // Verificação de disponibilidade de um entregador
        while (entregadores->existeEntregadorLivre() && !(filaEntrega->isEmpty())) // verifica se tem um entregador livre enquanto a fila de motoboys NÃO ESTÁ VAZIA
        {
            pedido = filaEntrega->dequeue(); // O pedido saiu da fila de entrega
           
            //CANCELAMENTO
            
            if (pedido->isPedidoCancelado())
            {
                controlador->addPedidoCancelado(); 
                delete pedido;                     
            }
            else
            {
                entregadores->adicionaPedido(pedido, tempo); // O pedido foi entregue ao motoboy
            }
        }

        // O Entregador está na rua
        while (entregadores->existePedidoPronto(tempo)) 
        {
            pedido = entregadores->removePedidoPronto(tempo); 
            controlador->addPedidoEnviado();                  
            delete pedido;                                    
            
        }

        filaSeparador->probCancelamento(PROB_CANCELAMENTO); // ?????????
        filaEntrega->probCancelamento(PROB_CANCELAMENTO);

        tempo++;
    }
}

//NOTAS
// INTERFACE: O usuário decide apenas o número de rodadas





