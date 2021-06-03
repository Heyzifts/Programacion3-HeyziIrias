#include<iostream>
#include"Estructura_HospedajeHI.h"

using namespace std;

class Apartamentos : public Hospedaje
{
private:
    int tiempo; // En meses
    int habitaciones;
public:
    Apartamentos(string lugar, int precio,int tiempo, int habitaciones) : Hospedaje(lugar,precio)
    {
        this->tiempo = tiempo;
        this->habitaciones = habitaciones;
    }

    int getPrecio()
    {
        int precioFinal=Hospedaje::getPrecio();

        return precioFinal*tiempo*habitaciones;
    }

    void setTiempo(int tiempo)
    {
        this->tiempo = tiempo;
    }

    void setHabitaciones(int habitaciones)
    {
        this->habitaciones = habitaciones;
    }

    void mostrarDatos()
    {
        cout<<"Mostrando Confirmacion de Datos: \n";
        cout<<"Lugar: "<<getLugar()<<endl;
        cout<<"Habitaciones: "<<habitaciones<<endl;
        cout<<"Tiempo: "<<tiempo<<endl;
        cout<<"Precio: "<<getPrecio()<<endl;
    }
};