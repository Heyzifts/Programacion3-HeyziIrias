#include <iostream>
using namespace std;
#include <iomanip>

//Heyzi Irias 62041081

int main()
{


        //DECLARACION DE VARIABLES
        double peso, altura, BMI;

        // MENSAJE DECORATIVO 
        std::cout << "========================\n";
        std::cout << "-  CALCULADORA DE BMI  -\n";
        std::cout << "========================\n";
        std::cout << "\n";
        //CAPTURA DE DATOS DE VARIABLE PESO EN LIBRAS Y ALTURA EN PULGADAS    
        std::cout << "Ingrese su peso en libras\n";
        std::cin >> peso;
        std::cout << "Ingrese su altura en pulgadas\n";
        std::cin >> altura;

        //CALCULO DEL BMI
        BMI = (peso * 703) / (altura * altura);

        // CONDICIONALES Y LOGICA 
        if (BMI < 18.5) {
            std::cout << " Su BMI es: " << fixed << setprecision(2) << BMI;

        }
        else if (BMI >= 18.5 && BMI <= 24.9) {
            std::cout << " Su BMI es: " << fixed << setprecision(2) << BMI;

        }
        else if (BMI >= 25 && BMI <= 29.9) {
            std::cout << " Su BMI es: " << fixed << setprecision(2) << BMI;
        }
        else if (BMI > 30) {
            std::cout << " Su BMI es: " << fixed << setprecision(2) << BMI;
        }

        // TABLA del Departamento de Salud y Servicios Humanos/Instituto Nacional de Salud para que el usuario pueda evaluar su BMI.
        std::cout << "\n";
        std::cout << "Puede evaluar su BMI en la siguente tabla.";
        std::cout << "\n";
        std::cout << "---------------------------------\n";
        std::cout << "|   Bajo peso: menos de 18.5.   |\n";
        std::cout << "|   Normal: entre 18.5 y 24.9.  |\n";
        std::cout << "|   Sobrepeso entre 25 y 29.9.  |\n";
        std::cout << "|   Obeso: 30 o mas.            |\n";
        std::cout << "---------------------------------\n";

        return 0;
    }
