/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Grave.h
 * Author: Sebastian
 *
 * Created on 17 de junio de 2023, 14:25
 */

#ifndef GRAVE_H
#define GRAVE_H
#include "Infraccion.h"

class Grave : public Infraccion{
private:
    double descuento;
    int puntos;
public:
    Grave();
    virtual ~Grave();
    void SetPuntos(int puntos);
    int GetPuntos() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch,int codInfraccion);
    void imprime(ofstream &arch);
    void aplica();
    void acumula(double &montoMulta,int &puntosPerdidos,int &mesesSancionados);
};

#endif /* GRAVE_H */

