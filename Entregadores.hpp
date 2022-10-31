#pragma once
#include "pedido.hpp"

class Entregadores
{
private:
    Pedido **entregadores;
    int numEntregadores;
    int entregadoresOcupados;

public:
    Entregadores(int numEntregadores);

    void adicionaPedido(Pedido *pedido, int tempo);
    Pedido *removePedidoPronto(int tempo);
    bool existePedidoPronto(int tempo);
    bool existeEntregadorLivre();
};
