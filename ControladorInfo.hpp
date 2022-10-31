#pragma once

class ControladorInfo
{
private:
    int numPedidosCriados;
    int numPedidosCancelados;
    int numPedidosEnviados;

public:
    ControladorInfo();
    
    void addPedidoCriado();
    void addPedidoCancelado();
    void addPedidoEnviado();

    int getPedidosCriados();
    int getPedidosCancelados();
    int getPedidosEnviados();
};
