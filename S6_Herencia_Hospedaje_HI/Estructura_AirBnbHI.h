#include<iostream>
#include "Estructura_HospedajeHI.h"

using namespace std;

class AirBnb : public Hospedaje
{
private:
    int personas;
    int tiempo;
public:
    AirBnB(string lugar,int precio, int personas, int tiempo) : Hospedaje(lugar,precio)
    {
        this->personas = personas;
        this->tiempo = tiempo;
    }

    int getPrecio()
    {
        int precioFinal = Hospedaje::getPrecio();

        return precioFinal*tiempo*personas;
    }

    void setPersonas(int personas)
    {
        this->personas = personas;
    }

    void setTiempo()
    {
        this->tiempo = tiempo;
    }

    void mostrarDatos()
    {
        cout<<"Mostrando Confirmacion de Datos: \n";
        cout<<"Lugar: "<<getLugar()<<endl;
        cout<<"Color: "<<getColor()<<endl;
        cout<<"Personas: "<<personas<<endl;
        cout<<"Tiempo: "<<tiempo<<endl;
        cout<<"Precio: "<<getPrecio()<<endl;
    }
};