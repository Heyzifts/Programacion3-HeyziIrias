#include <iostream> 
#include <stdlib.h> //LIBRRIA PARA GENERADOR DE NUMEROS ALEATORIOS.
#include <time.h>   //LIBRRIA PARA GENERADOR DE NUMEROS ALEATORIOS.
#include <string.h> //LIBRRIA PARA CHAR Y ALMACENAMIENTO DEL STRING.

using namespace std;

int main()
{
	srand(time(NULL)); //INDICADOR DE NUMEROS ALEATORIOS.

	//DECLARACIÓN DE VARIABLES.
	int PartidosPendientes = 0, CantGolEquipoA = 0, CantGolEquipoB = 0, PtsEquipoA = 0, PtsEquipoB = 0, Opcion = 0;
	char NombredelEquipo[50];

	//DATOS SOLICITADOS AL USAUARIO PARA LA EJECUCIÓN DEL PROGRAMA.
	std::cout << "Ingrese el nombre de su equipo\n";
	std::cin.getline(NombredelEquipo, 50, '\n');

	std::cout << "Ingrese la cantidad de partidos pendientes\n";
	std::cin >> PartidosPendientes;

	//LOGICA UTILIZADA PARA LOS GOLES ANOTADOR POR ENCUENTRO.
	for (int i = 0; i < PartidosPendientes; i++) {

		CantGolEquipoA = (rand() % 3);
		CantGolEquipoB = (rand() % 3);

		if (CantGolEquipoA > CantGolEquipoB)
		{
			PtsEquipoA += 3;
		}
		else if (CantGolEquipoA < CantGolEquipoB)
		{
			PtsEquipoB += 3;
		}
		else {
			PtsEquipoA += 1;
			PtsEquipoB += 1;
		}
	}

	//OPCIONES PARA EL USURIO
	std::cout << "Para imprimir resultados presione (1).\n";
	std::cout << "Para declarar su equipo campeon presione (2).\n";
	std::cin >> Opcion;

	//LOGICA PARA DETERMINAR LA POSICIÓN DE SU EQUIPO SI GANO/PERDIO/EMPATE O HACER QUE EL EQUIPO SEA GANADOR AUTOMATICAMENTE.
	if (Opcion == 1)
	{
		std::cout << "Los puntos de su equipo " << NombredelEquipo << " fueron: " << PtsEquipoA << "\n";
		std::cout << "Los puntos del equipo contrario fueron: " << PtsEquipoB << "\n";


		if (PtsEquipoA > PtsEquipoB)
		{
			std::cout << "Su equipo " << NombredelEquipo << " ha resultado GANADOR.\n";
		}
		else if (PtsEquipoA < PtsEquipoB)
		{
			std::cout << "Su equipo " << NombredelEquipo << " ha PERDIDO, suerte para la siguiente temporada.\n";
		}
		else
		{
			std::cout << "Los equipos han quedado empatados\n";
		}
	}
	else
	{
		std::cout << "Su equipo " << NombredelEquipo << " ha quedado campeon, FELICIDADES!\n";
	}



	return 0; //FIN DEL PROGRAMA CON EXITO
}


