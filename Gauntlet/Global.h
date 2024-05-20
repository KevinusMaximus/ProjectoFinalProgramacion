#pragma once
class Global
{

	int Seleccion;
	static Global* pInstance;
public:
	static Global* getInstance();
	void setSeleccion(int valor);
	int getSeleccion() { return Seleccion; };
};

