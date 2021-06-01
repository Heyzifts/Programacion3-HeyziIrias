#include<iostream>
#include"Estructura_HospedajeHI.h"

using namespace std;

class Hoteles : public Hospedaje
{
private:
    bool comida = false;
    int precioComida = 1000; 
public:
    Hoteles()
    {

    }
    Hoteles(string lugar, int precio, bool comida) : Hospedaje(lugar,precio)
    {
        this->comida = comida;
    }

    int getPrecio()
    {
        int precioFinal = Hospedaje::getPrecio();

        if(comida == true)
        {
            return precioFinal += precioComida;
        }
        else
        {
            return precioFinal;
        }
    }

    void setComida(bool comida)
    {
        this->comida = comida;
    }

    void mostrarDatos()
    {
        cout<<"Mostrando Confirmacion de Datos: \n";
        cout<<"Lugar: "<<getLugar()<<endl;
        cout<<"Comida: "<<comida<<endl;
        cout<<"Precio: "<<getPrecio()<<endl;
    }
    ~Hoteles();
};
