#include <iostream>
#include "FilaPedidos.hpp";
using namespace std;

int TAM_MAX = 10;

FilaPedidos::FilaPedidos()
{
    this->pedidos = (Pedido **)malloc(TAM_MAX * sizeof(int)); // alocação de um bloco de memória de tamanho 5 de pedidos, caso atingir 5, duplica o tamanho do bloco
    this->tamanho = 0;
}

void FilaPedidos::enqueue(Pedido* elemento)
{
    if (tamanho >= TAM_MAX)
    {
        TAM_MAX += 10;
        pedidos = (Pedido **)realloc(pedidos, TAM_MAX * sizeof(int));
    }
    pedidos[tamanho] = elemento;
    tamanho++;
}

Pedido* FilaPedidos::dequeue()
{
    Pedido* pedido = pedidos[0];
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
