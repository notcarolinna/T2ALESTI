#pragma once

class Pedido
{
private:
    int produtos;
    int tempoPronto;    // quando está pronto
    int tempoGastoFila; // diferença entre entradar e sair da fila

public:
    Pedido(int produtos);

    int getProdutos();                 // retorna a quantidade de produto
    int getTempoPronto();              // retorna quando estiver pronto
    void setTempoPronto(int tempo);    // modifica o tempo pronto
    int getTempoGastoFila();           // retorna o tempo gasto em fila
    void addTempoGastoFila(int tempo); // adicionando tempo
};