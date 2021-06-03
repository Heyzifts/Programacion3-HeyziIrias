#include <iostream>
using namespace std;
#include <string.h>
#include "Estructura_HospedajeHI.h"
#include "Estructura_HotelesHI.h"
#include "Estructura_ApartamentosHI.h"
#include "Estructura_AirBnbHI.h"
 
 int main(){

menu();

     return 0;
 }
 void menu()
{
    int opt;
    string lugar;
    char comida='f';
    int precio, tiempo, personas , cuartos;
    Hoteles *hotel1;
    Apartamentos *apartamento1;
    AirBnb *airbnb1;
    do
    {
        system("cls");
        cout<<"============MENU=======\n";
        cout<<"1. Hospedarse en Hotel\n";
        cout<<"2. Hospedarse en AirBnB\n";
        cout<<"3. Hospedarse en Apartamento\n";
        cout<<"4. Salir\n";
        cout<<"Digite una opcion: ";
        cin>>opt;

        switch (opt)
        {
        case 1:
            system("cls");
            cout<<"\nDigite los Datos: \n";
            cin.ignore();
            cout<<"Lugar: ";
            cin>>lugar;
            cout<<"Precio: ";
            cin>>precio;
            cout<<" Cantidad de Comida: ";
            cin>>comida;
            if(comida == 's')
            {
               hotel1 = new Hoteles(lugar,precio,true) ;
               system("cls");
               hotel1->mostrarDatos();
               system("pause");
            }
            else
            {
                hotel1 = new Hoteles(lugar,precio,false) ;
                system("cls");
                hotel1->mostrarDatos();
                system("pause");
            }
            break;
        case 2:
            system("cls");
            cout<<"\nDigite los Datos: \n";
            cin.ignore();
            cout<<"Lugar: ";
            cin>>lugar;
            cout<<"Precio: ";
            cin>>precio;
            cout<<"Personas: ";
            cin>>personas;
            cout<<"Tiempo: ";
            cin>>tiempo;
            airbnb1 = new AirBnb(lugar,precio,personas,tiempo);
            system("cls");
            airbnb1->mostrarDatos();
            system("pause");
            break;
        case 3:
            system("cls");
            cout<<"\nDigite los Datos: \n";
            cout<<"Lugar: ";
            cin.ignore();
            cin>>lugar;
            cout<<"Precio: ";
            cin>>precio;
            cout<<"Tiempo: ";
            cin>>tiempo;
            cout<<"Habitaciones: ";
            cin>>cuartos;
            apartamento1 = new Apartamento(lugar,precio,tiempo,cuartos);
            system("cls");
            apartamento1->mostrarDatos();
            system("pause");
            break;
        case 4:
            break;
        default:
            break;
        }

    } while (opt != 4);
    
}