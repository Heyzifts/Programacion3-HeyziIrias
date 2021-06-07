#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#pragma region Validaciones
bool esAñoValido(int año)
{
	if(año > 2021)
	{
		return false;
	}
	return true;	
}

bool esMesValido(int mes)
{
	if(mes <= 0 || mes > 12 )
	{
		return false;
	}
	return true;
}

bool esDiaValido(int dia)
{
	if(dia <= 0 || dia > 31 )
	{
		return false;
	}
	return true;
}

bool esHoraValido(int hora)
{
	if(hora <= 0 || hora > 24 )
	{
		return false;
	}
	return true;
}

bool esMinutoValido(int minuto)
{
	if(minuto <= 0 || minuto >= 60)
	{
		return false;
	}
	return true;
}

string concatenarDosStrings(const string &s1, const string &s2)
{
    return s1 + s2;
}

string GetMesString(int mes)
{
	switch (mes) {
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

void mostrarFechaHora (int año, int mes, int dia, int hora, int minuto)
{
	if(!esAñoValido(año) || !esMesValido(mes) || !esDiaValido(dia) || !esHoraValido(hora) ||!esMinutoValido(minuto))
	{
		std::cout << "LOS VALORES INGRESADOS NO SON VALIDOS, INTENTE DENUEVO!!";
		return;
	}
	
	//Buffer y string para poder construir fecha.
	char buffer [33];
	string Fecha = "";
	
	//Apuntadores y funcion ITOA en año.
	int *diaApuntador = &dia;
	itoa (*diaApuntador,buffer,10);	
	Fecha += concatenarDosStrings("", buffer);
	
	//Apuntadores y funcion GetMesString en mes.
	int *mesApuntador = &mes;
	Fecha += concatenarDosStrings(" de ", GetMesString(*mesApuntador));
	
	//Apuntadores y funcion ITOA en año.
	int *añoApuntador = &año;
	itoa (*añoApuntador,buffer,10);	
	Fecha += concatenarDosStrings(" de ", buffer);
	
	//Apuntadores y funcion ITOA en hora.
	int *horaApuntador = &hora;
	itoa (*horaApuntador,buffer,10);	
	Fecha += concatenarDosStrings(", ", buffer);
	
	//Apuntadores y funcion ITOA en minuto.
	int *minutoApuntador = &minuto;
	itoa (*minutoApuntador,buffer,10);	
	Fecha += concatenarDosStrings(":", buffer);	

	//Imprimimos la fecha previamente establecida.
	std::cout << Fecha;
}

int longitud(char *s)
{
    return (*s) ? 1 + longitud(s + 1) : 0;
}

int main(int argc, char** argv) {
	std::cout <<"#1 Ejercicio FECHA Y HORA\n";
	mostrarFechaHora(2020, 6, 6, 20, 30);
	
	std::cout <<"\n #1 Ejercicio MOSTAR LONGITUD DE CADENA \n";
	std::cout <<"La longitud de la cadena es: " << longitud("Prueba de longitud");
	
	return 0;
}