#include <iostream>
#include "Separadores.hpp"

using namespace std;

Separadores::Separadores(int numSeparadores)
{
    this->separadores = new Pedido *[numSeparadores]; // entregando o pedido para os separadores
    this->numSeparadores = numSeparadores;            // definindo o número de separadores
    this->separadoresOcupados = 0;
}
