#include <iostream>
#include "pedido.hpp";
#include "FilaPedidos.hpp"

using namespace std;

int main()
{

    FilaPedidos *filha = new FilaPedidos();

    Pedido *pedidoUm = new Pedido(10);
    Pedido *pedidoDois = new Pedido(5);

    filha->enqueue(pedidoUm);
    filha->enqueue(pedidoDois);

    Pedido *pedidoFilhaUm = filha->dequeue();
    Pedido *pedidoFilhaDois = filha->dequeue();

    cout << pedidoFilhaUm->getProdutos() << endl;
    cout << pedidoFilhaDois->getProdutos() << endl;
}