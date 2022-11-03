#pragma once

class ControladorInfo
{
private:
	int numPedidosCriados;
	int numPedidosCancelados;
	int numPedidosEnviados;
	int numPedidosQuaseCancelados;
	int tempoFilaPedidos;
	int pedidoMaisDemorado;

public:
	ControladorInfo();

	void addPedidoCriado();
	void addPedidoCancelado();
	void addPedidoEnviado();
	void addPedidoQuaseCancelado();
	void addTempoFilaPedidos(int tempo);
	void setPedidoMaisDemorado(int tempo);

	int getPedidosCriados();
	int getPedidosCancelados();
	int getPedidosEnviados();
	int getPedidoQuaseCancelados();
	float getMediaTempoFilaPedidos();
	int getPedidoMaisDemorado();
};
