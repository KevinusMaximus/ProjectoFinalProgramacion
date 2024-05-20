#include "Global.h"

void Global::setSeleccion(int valor)
{
	Seleccion = valor;
}
Global* Global::getInstance() {
	if (pInstance == nullptr)
	{
		pInstance = new Global();
	}
	return pInstance;
}
Global* Global::pInstance = nullptr;