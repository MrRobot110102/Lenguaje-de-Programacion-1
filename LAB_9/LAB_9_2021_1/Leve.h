/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Leve.h
 * Author: Sebastian
 *
 * Created on 17 de junio de 2023, 14:25
 */

#ifndef LEVE_H
#define LEVE_H
#include "Infraccion.h"

class Leve : public Infraccion{
private:
    double descuento;
public:
    Leve();
    virtual ~Leve();
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch,int codInfraccion);
    void imprime(ofstream &arch);
    void aplica();
    void acumula(double &montoMulta,int &puntosPerdidos,int &mesesSancionados);
};

#endif /* LEVE_H */

