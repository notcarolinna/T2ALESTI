#pragma once
#include "Pedido.h"

class FilaPedidos {
private:
    Pedido** pedidos;
    int tamanho;

public:
    FilaPedidos();

    void enqueue(Pedido* elemento);
    Pedido* dequeue();
    int size();
    bool isEmpty();
    void probCancelamento(int probCancelamento);
};
