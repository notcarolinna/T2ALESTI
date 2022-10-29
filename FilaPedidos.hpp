#pragma once
#include "pedido.hpp";

class FilaPedidos
{
private:
    Pedido** pedidos; //um * para o array e o outro pro ponteiro 
    int tamanho;

public:
    FilaPedidos();

    void enqueue(Pedido* element);
    Pedido* dequeue(); // vamos dar dequeue no pedido
    int size();
    bool isEmpty();
};
