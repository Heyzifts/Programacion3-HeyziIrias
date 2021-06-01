#ifndef HOSPEDAJE_H
#define HOSPEDAJE_H

#include<iostream>

using namespace std;

class Hospedaje
{
    private:
    int precio;
    string lugar;

    public:
    Hospedaje()
    {

    }

    Hospedaje(string lugar,int precio)
    {
        this->lugar = lugar;
        this->precio = precio;
    }

    int getPrecio()
    {
        return precio;
    }

    string getLugar()
    {
        return lugar;
    }

    void setLugar(string lugar)
    {
        this->lugar = lugar;
    }


};
