#pragma once
#include "pedido.hpp"

class Separadores
{
private:
    Pedido **separadores; // bota os pedidos nos separadores
    int numSeparadores;
    int separadoresOcupados;

public:
    Separadores(int numSeparadores);

    void adicionaPedido(Pedido *pedido);
    Pedido *removePedidoPronto();
    bool existePedidoPronto();
    bool existeSeparadorLivre();
};
