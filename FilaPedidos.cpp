#include <iostream>
#include "FilaPedidos.hpp";
using namespace std;

int TAM_MAX = 10;

FilaPedidos::FilaPedidos()
{

    this->pedidos = new Pedido *[TAM_MAX];
    this->tamanho = 0;
}

void FilaPedidos::enqueue(Pedido *elemento)
{

    if (tamanho >= TAM_MAX)
    {
        TAM_MAX += 10;
        Pedido **newPedidos = new Pedido *[TAM_MAX];
        for (int i = 0; i < sizeof(pedidos); i++)
        {
            newPedidos[i] = pedidos[i];
        }
        delete pedidos; // o delete tá aqui pra deletar o bloco de memória alocada
        pedidos = newPedidos;
    }
    pedidos[tamanho] = elemento;
    tamanho++;
}

Pedido *FilaPedidos::dequeue()
{
    Pedido *pedido = pedidos[0];
    for (int i = 1; i <= tamanho; i++)
    {
        pedidos[i - 1] = pedidos[i];
    }
    tamanho--;
    return pedido;
}

int FilaPedidos::size()
{
    return tamanho;
}

void FilaPedidos::probCancelamento(int probCancelamento)
{
    for (int i = 0; i < tamanho; i++)
    {
        pedidos[i]->probCancelamento(probCancelamento);
    }
