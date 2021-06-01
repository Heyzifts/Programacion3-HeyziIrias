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
    Hoteles *h1;
    Apartamento *ap1;
    AirBnb *ab1;
    do
    {
        system("cls");
        cout<<"===MENU===\n";
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
            std::cin.getline(lugar);
            cout<<"Precio: ";
            cin>>precio;
            cout<<"Comida (s/n): ";
            cin>>comida;
            if(comida == 's')
            {
               h1 = new Hoteles(lugar,precio,true) ;
               system("cls");
               h1->mostrarDatos();
               system("pause");
            }
            else
            {
                h1 = new Hoteles(lugar,precio,false) ;
                system("cls");
                h1->mostrarDatos();
                system("pause");
            }
            break;
        case 2:
            system("cls");
            cout<<"\nDigite los Datos: \n";
            cin.ignore();
            cout<<"Lugar: ";
            getline(cin,lugar);
            cout<<"Precio: ";
            cin>>precio;
            cout<<"Personas: ";
            cin>>personas;
            cout<<"Tiempo: ";
            cin>>tiempo;
            ab1 = new AirBnb(lugar,precio,personas,tiempo);
            system("cls");
            ab1->mostrarDatos();
            system("pause");
            break;
        case 3:
            system("cls");
            cout<<"\nDigite los Datos: \n";
            cout<<"Lugar: ";
            cin.ignore();
            getline(cin,lugar);
            cout<<"Precio: ";
            cin>>precio;
            cout<<"Tiempo: ";
            cin>>tiempo;
            cout<<"Habitaciones: ";
            cin>>cuartos;
            ap1 = new Apartamento(lugar,precio,tiempo,cuartos);
            system("cls");
            ap1->mostrarDatos();
            system("pause");
            break;
        case 4:
            break;
        default:
            break;
        }

    } while (opt != 4);
    
}