#include <iostream>
#include "ControladorInfo.h"

using namespace std;

ControladorInfo::ControladorInfo()
{
	this->numPedidosCriados = 0;
	this->numPedidosCancelados = 0;
	this->numPedidosEnviados = 0;
	this->numPedidosQuaseCancelados = 0;
	this->tempoFilaPedidos = 0;
	this->pedidoMaisDemorado = 0;
}

void ControladorInfo::addPedidoCriado()
{
	numPedidosCriados++;
}

void ControladorInfo::addPedidoCancelado()
{
	numPedidosCancelados++;
}

void ControladorInfo::addPedidoEnviado()
{
	numPedidosEnviados++;
}

void ControladorInfo::addTempoFilaPedidos(int tempo)
{
	tempoFilaPedidos += tempo;
}


void ControladorInfo::addPedidoQuaseCancelado() {
	numPedidosQuaseCancelados++;
}

void ControladorInfo::setPedidoMaisDemorado(int tempo)
{
	if (tempo > pedidoMaisDemorado)
	{
		pedidoMaisDemorado = tempo;
	}
}


int ControladorInfo::getPedidosCriados()
{
	return numPedidosCriados;
}

int ControladorInfo::getPedidosCancelados()
{
	return numPedidosCancelados;
}

int ControladorInfo::getPedidosEnviados()
{
	return numPedidosEnviados;
}

int ControladorInfo::getPedidoQuaseCancelados()
{
	return numPedidosQuaseCancelados;
}

float ControladorInfo::getMediaTempoFilaPedidos()
{
	return (float) tempoFilaPedidos / (float) numPedidosEnviados;
}

int ControladorInfo::getPedidoMaisDemorado()
{
	return pedidoMaisDemorado;
}



