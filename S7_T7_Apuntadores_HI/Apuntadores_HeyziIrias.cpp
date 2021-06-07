#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//TAREA 7 APUNTADORES HEYZI IRIAS 62041081


int main(int argc, char** argv) {
	std::cout <<"1) Ejercicio MOSTAR FECHA CON HORA\n";
	mostrarFechaconHora(2021, 6, 7, 20, 40);
	
	std::cout <<"\n2) Ejercicio MOSTAR LONGITUD DE CADENA EN BASE A APUNTADORES\n";
	std::cout <<"La longitud de la cadena es: " << longi("Prueba de longitud");
	
	return 0;
}

// VALIDACIONES

#pragma region Validaciones

bool esAñoVal(int año)
{
	if(año > 2021)
	{
		return false;
	}
	return true;	
}

bool esMesesVal(int mes)
{
	if(mes <= 0 || mes > 12 )
	{
		return false;
	}
	return true;
}

bool esDiaVal(int dia)
{
	if(dia <= 0 || dia > 31 )
	{
		return false;
	}
	return true;
}

bool esHoraVal(int hora)
{
	if(hora <= 0 || hora > 24 )
	{
		return false;
	}
	return true;
}

bool esMinutoVal(int minuto)
{
	if(minuto <= 0 || minuto >= 60)
	{
		return false;
	}
	return true;
}

string concatenarStrings(const string &stringnum1, const string &stringnum2)
{
    return stringnum1 + stringnum2;
}

string GetMesesString(int meses)
{
	switch (meses) {
  case 1:
    return "Enero";
    break;
  case 2:
    return "Febrero";
    break;
  case 3:
    return "Marzo";
    break;
  case 4:
    return "Abril";
    break;
  case 5:
    return "Mayo";
    break;
  case 6:
    return "Junio";
    break;
  case 7:
    return "Julio";
    break;
  case 8:
    return "Agosto";
    break;
  case 9:
    return "Septiembre";
    break;
  case 10:
    return "Octubre";
    break;
  case 11:
    return "Noviembre";
    break;
  case 12:
    return "Diciembre";
    break;
}

}
#pragma endregion Validaciones

// APUNTADORES 

void mostrarFechaconHora (int año, int mes, int dia, int hora, int minuto)
{
	if(!esAñoVal(año) || !esMesesVal(mes) || !esDiaVal(dia) || !esHoraVal(hora) ||!esMinutoVal(minuto))
	{
		std::cout << "FORMATO INCORRECTO, INTENTE DENUEVO!!";
		return;
	}
	
	//Buffer y string para la contruccion de fecha.
	char buffer [33];
	string Fecha = "";
	
	//Apuntadores y funcion ITOA en año.
	int *diaApuntador = &dia;
	itoa (*diaApuntador,buffer,10);	
	Fecha += concatenarStrings("", buffer);
	
	//Apuntadores y funcion GetMesesString en mes.
	int *mesApuntador = &mes;
	Fecha += concatenarStrings(" de ", GetMesesString(*mesApuntador));
	
	//Apuntadores y funcion ITOA en año.
	int *añoApuntador = &año;
	itoa (*añoApuntador,buffer,10);	
	Fecha += concatenarStrings(" de ", buffer);
	
	//Apuntadores y funcion ITOA en hora.
	int *horaApuntador = &hora;
	itoa (*horaApuntador,buffer,10);	
	Fecha += concatenarStrings(", ", buffer);
	
	//Apuntadores y funcion ITOA en minuto.
	int *minutoApuntador = &minuto;
	itoa (*minutoApuntador,buffer,10);	
	Fecha += concatenarStrings(":", buffer);	

	//Imprimimos FECHA.
	std::cout << Fecha;
}

int longi(char *h)
{
    return (*h) ? 1 + longi(h + 1) : 0;
}
