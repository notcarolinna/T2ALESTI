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
    int TEMPO_MAX = 60;     // *** tempo máximo de que, exatamente?
    int PROBABILIDADE = 45; // probabilidade de aparecer um pedido
    int MIN_PRODUTOS = 5;   // mínimo de produtos
    int MAX_PRODUTOS = 10;  // máximo de produtos

    int NUM_SEPARADORES = 3;
    int NUM_ENTREGADORES = 3;

    int PROB_CANCELAMENTO = 5; // probabilidade de um pedido ser cancelado

    int tempo = 0;          // *** tempo de que, exatamente?
    int pedidosCriados = 0; // número de pedidos criados

    Pedido *pedido; // construtor da classe pedido

    FilaPedidos *filaSeparador = new FilaPedidos(); // ***Criação de um FilaPedidos atribuído ao *filaSeparador?
    FilaPedidos *filaEntrega = new FilaPedidos();

    Separadores *separadores = new Separadores(NUM_SEPARADORES);     // cria 3 separadores com a quantidade definida na linha 19
    Entregadores *entregadores = new Entregadores(NUM_ENTREGADORES); // cria 3 entregadores com a quantidade definida na linha 20

    ControladorInfo *controlador = new ControladorInfo(); //***isso é a  chamada da classe e/ou a criação de um controlador na main?

    while (tempo != TEMPO_MAX) // while pra tudo isso rodar enquanto não bater no tempo max
    {
        if (rand() % 100 <= PROBABILIDADE) // proabilidade do pedido ser criado
        {
            // SE UM PEDIDO FOR CRIADO, o que acontece, o que é feito com ele e para onde ele vai.

            pedido = new Pedido(MIN_PRODUTOS + (rand() % (MAX_PRODUTOS - MIN_PRODUTOS + 1))); // resto de um número aleatório por (MAX_PRODUTOS - MIN_PRODUTOS + 1)

            pedido->setTempoPronto(tempo);  // modifica o tempo
            filaSeparador->enqueue(pedido); // filaseparador é a classe filapedidos, mas pra um separador. então reduz a quantidade de pedidos
            controlador->addPedidoCriado(); // adiciona o pedido na lista dos pedidos criados
        }

        // verificar se existe um separador livre pra organizar o pedido e deixar o pacote pronto pro entregador

        while (separadores->existeSeparadorLivre() && !(filaSeparador->isEmpty())) // vai no arquivo dos separadores e verifica se existe um livre enquanto a fila dos separadores NÃO ESTÁ VAZIA.
        {
            pedido = filaSeparador->dequeue(); // um separador fica ocupado
            if (pedido->isPedidoCancelado())   // se o pedido pôde ser cancelado
            {
                controlador->addPedidoCancelado(); // adiciona o pedido na lista de cancelados
                delete pedido;                     // deleta o pedido
            }
            else
            {
                separadores->adicionaPedido(pedido, tempo); // se ele não pôde ser cancelado ou não foi efetuada a tentativa, vai para o separador disponível
                // *** Não entendi o pedido e o tempo, seria para saber quanto tempo o pedido ficou na fila de espera?
            }
        }

        // vamos ver se o separador responsável foi fodão e deixou o pacotinho pronto pro entregador buscar

        while (separadores->existePedidoPronto(tempo)) // se existe um pedido disponível para entrega
        {
            pedido = separadores->removePedidoPronto(tempo); //*** Aqui o entregador pega o pedido e sai para entrega?
            if (pedido->isPedidoCancelado())                 // se o pedido pôde ser cancelado
            {
                controlador->addPedidoCancelado(); // cancelou, foi pra lista
                delete pedido;                     // foi aniquilado
            }
            else // sinãããão
            {
                filaEntrega->enqueue(pedido); // irmão eu vo leva essa marmita pro seu jorge
            }
        }

        // ALO ADENILSON TÁ LIVRE PRA PEGAR O PEDIDO?

        while (entregadores->existeEntregadorLivre() && !(filaEntrega->isEmpty())) // verifica se tem um entregador livre enquanto a fila de motoboys NÃO ESTÁ VAZIA
        {
            pedido = filaEntrega->dequeue(); // Adenilson, o motoboy, pegou o pacotin mas n saiu pra rua
            if (pedido->isPedidoCancelado()) // foi efetuada uma solicitação de cancelamento
            {
                controlador->addPedidoCancelado(); // canceladíssimo
                delete pedido;                     // impeachment do pedido
            }
            else
            {
                entregadores->adicionaPedido(pedido, tempo); // Adenilson foi liberado do estabelecimento com o xis de presunto parma
            }
        }

        // ADENILSON VÁ LEVAR O XIS PRO JORGE COM SAFETY
        while (entregadores->existePedidoPronto(tempo)) // se tiver um pedido no balcão, o adenilson leva o primeiro
        {
            pedido = entregadores->removePedidoPronto(tempo); // pedido saiu do balcão
            controlador->addPedidoEnviado();                  // adenilson botou na caixa da moto q n sei o nome e foi viajar por poa
            delete pedido;                                    // ai n tem mais pedido obviamente
            // Aqui n teria que ter um contador de pedido executado com sucesso?
        }

        filaSeparador->probCancelamento(PROB_CANCELAMENTO); //*** essas duas coisa aqui n foram usadas pra nada ainda né? pq eu só n sei oq fazem obg
        filaEntrega->probCancelamento(PROB_CANCELAMENTO);

        tempo++;
    }
}
