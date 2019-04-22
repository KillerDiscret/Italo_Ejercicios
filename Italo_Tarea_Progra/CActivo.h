#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;

class Activo
{
private:
	char*codigo;
	char*descripcion;
	double precio;
	double depreciacion;

public:
	Activo();
	~Activo();
	void set_codigo(char*aux);
	void set_descripcion(char*aux);
	void set_precio(double aux);
	void set_depreciacion(double aux);
	char* get_codigo();
	char* get_descripcion();
	double get_precio();
	double get_depreciacion();
};
Activo::Activo()
{
	codigo = new char[20];
	descripcion = new char[40];
}
Activo::~Activo()
{

}
void Activo::set_codigo(char*aux)
{
	codigo = aux;
}
void Activo::set_descripcion(char*aux)
{
	descripcion = aux;
}
void Activo::set_precio(double aux)
{
	precio = aux;
}
void Activo::set_depreciacion(double aux)
{
	depreciacion = aux;
}
char* Activo::get_codigo()
{
	return codigo;
}
char* Activo::get_descripcion()
{
	return descripcion;
}
double Activo::get_precio()
{
	return precio;
}
double Activo::get_depreciacion()
{
	return depreciacion;
}