#include <iostream>
#include "FilaPedidos.hpp";
using namespace std;

int TAM_MAX = 10;

FilaPedidos::FilaPedidos()
{
    // this->pedidos = (Pedido**)malloc(TAM_MAX * sizeof(int)); // aloca��o de um bloco de mem�ria de tamanho 5 de pedidos, caso atingir 5, duplica o tamanho do bloco

    this->pedidos = new Pedido *[TAM_MAX];
    this->tamanho = 0;
}

void FilaPedidos::enqueue(Pedido *elemento)
{
    
    //Criação de uma nova lista com tam max e o for copia e passa a lista como
    
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
