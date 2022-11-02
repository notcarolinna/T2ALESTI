#include <iostream>
#include "ControladorInfo.h"

using namespace std;

ControladorInfo::ControladorInfo()
{
	this->numPedidosCriados = 0;
	this->numPedidosCancelados = 0;
	this->numPedidosEnviados = 0;
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
