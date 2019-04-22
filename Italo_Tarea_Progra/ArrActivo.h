#pragma once
#include "CActivo.h"
#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;

class ArActivo
{
private:
	int *N;
	Activo**arreglo;
public:

	ArActivo();
	void agregar(Activo*obj);
	Activo* obtener(int indice);
	int get_N();
	void Promedio();
	void Eliminar(int pos);
	void Eliminar_10();
	~ArActivo();

};

ArActivo::ArActivo()
{
	arreglo = NULL;
	N = new int;
	*N = 0;
}
void ArActivo::agregar(Activo*obj)
{												//*N=2 Activo arreglo[*N] [2]={a,b}
	Activo**ArrTemporal;
	ArrTemporal = new Activo*[*N + 1];			//temporal[3]={ , , }
	for (int i = 0; i<*N; i++)							//i=0 hasta 1// recorre 2 posiciones(llena 2 espacios) 
	{
		ArrTemporal[i] = arreglo[i];				//temporal[0]= arreglo[0]//temporal={a, , }
	}												//tempral= {a,b, }
	ArrTemporal[*N] = obj;							//temporal[*N]-> temporal[2]=c
	*N = *N + 1;									//temporal[3]={a,b,c}	
	arreglo = ArrTemporal;							//arreglo = temporal;
													//arreglo[3]={a,b,c}
													//*N=*N+1	
}


Activo* ArActivo::obtener(int indice)
{
	return arreglo[indice];
}
int ArActivo::get_N()
{
	return *N;
}
void ArActivo::Promedio()
{
	double suma = 0;
	double promedio;
	for (int i=0;i<*N;i++)
	{
		suma = suma + arreglo[i]->get_precio();
	}
	promedio = suma / (*N);
	cout << "El promedio es: " <<promedio<<endl;

	for (int i = 0; i<*N; i++)
	{
		if (arreglo[i]->get_precio()>promedio&&arreglo[i]->get_depreciacion()<7)
		{
			cout << "Activo" << i + 1 << endl;
			char *aux;
			char *aux2;
			aux=arreglo[i]->get_codigo();
			cout <<"Codigo: "<< aux<<endl;
			aux2 = arreglo[i]->get_descripcion();
			cout << "Descripcion: " << aux2<< endl;
			cout << "Precio Compra: " << arreglo[i]->get_precio()<<endl;
			cout << "Porcentaje de depreciacion: " << arreglo[i]->get_depreciacion() << "%" << endl;
		}
	}

}
void ArActivo::Eliminar(int pos)
{
	Activo**ArrTemporal;
	ArrTemporal = new Activo*[*N - 1];			
	int contador = 0;
	for (int i = 0; i<*N; i++)							
	{
		if (i != pos - 1)
		{
			ArrTemporal[contador] = arreglo[i];
			contador++;
		}								
	}																	
	*N = *N - 1;										
	arreglo = ArrTemporal;

}
void ArActivo::Eliminar_10()
{
	for (int i=0;i<*N;i++)
	{
		if (arreglo[i]->get_depreciacion()<10)
		{
			Eliminar(i+1);// porque la funcion que uso es con respecto a los activos que muestro 
		}
	}
}
ArActivo::~ArActivo()
{

}
