#include <iostream>
#include<conio.h>
#include "ArrActivo.h"
#include "CActivo.h"
using namespace std;
using namespace System;

int main()
{
	int opcion=0;
	ArActivo*arrobj = new ArActivo();
	
	

	while (true)
	{
		if (opcion==0)
		{
			system("CLS");
			cout << "\t\t MENU" << endl;
			cout << "1- Registrar un Activo" << endl;
			cout << "2-Eliminar un Activo" << endl;
			cout << "3-Eliminar todos los Activos con una depreciacion menor al 10%" << endl;
			cout << "4-Reportes" << endl;
			cout << "Ingrese su opcion:" << endl;
			cin >> opcion;
		}
		if (opcion==1)
		{
			Activo*obj = new Activo();
			char *auxcodigo = new char[20];
			char *auxdescrip = new char[40];
			double precio;
			double porcentaje;
			system("CLS");
			cout << "Ingrese el codigo del activo(solo letras):" << endl;
			cin >> auxcodigo;
			cout << "Ingrese la descripcion del activo(solo letras):" << endl;
			cin >> auxdescrip;
			cout << "Ingrese el precio de compra:" << endl;
			cin >> precio;
			cout << "Ingrese el procentaje de depreciacion:" << endl;
			cin >> porcentaje;
			obj->set_codigo(auxcodigo);
			obj->set_descripcion(auxdescrip);
			obj->set_precio(precio);
			obj->set_depreciacion(porcentaje);
			arrobj->agregar(obj);
			opcion = 0;
		}
		if (opcion==4)
		{
			system("CLS");
			arrobj->Promedio();
			opcion = 0;
		}
		if (opcion==2)
		{
			int auxactivo;
			for (int i=0;i<arrobj->get_N();i++)
			{
				char*aux1;
				char*aux2;
				cout << "Activo N°_" << i + 1 << endl;
				aux1=arrobj->obtener(i)->get_codigo();
				aux2 = arrobj->obtener(i)->get_descripcion();
				cout << "Codigo: " << aux1<<endl;
				cout << "Descripcion: " << aux2<<endl;
				cout << "Precio: " << arrobj->obtener(i)->get_precio() << endl;
				cout << "Porcentaje: " << arrobj->obtener(i)->get_depreciacion() << "%" << endl;
			}
			cout << endl;
			cout << "Ingrese el numero de activo a eliminar: " << endl;
			cin >> auxactivo;
			arrobj->Eliminar(auxactivo - 1);
			opcion = 0;
		}
		if (opcion==3)
		{
			arrobj->Eliminar_10();
			opcion = 0;
		}


	}







	_getch();
	return 0;
}
