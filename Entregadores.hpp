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

    void adicionaPedido(Pedido *pedido, int tempo); // um pedido é disponibilizado para o entregador
    Pedido *removePedidoPronto(int tempo);          // *** exclui o pedido da lista de entrega ou o pedido foi entregue?
    bool existePedidoPronto(int tempo);             // existe um pedido pronto para entrega
    bool existeEntregadorLivre();                   // existe um entregador disponível para entrega
};
