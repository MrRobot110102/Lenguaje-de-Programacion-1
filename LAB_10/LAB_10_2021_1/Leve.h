/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Leve.h
 * Author: Sebastian
 *
 * Created on 26 de junio de 2023, 16:09
 */

#ifndef LEVE_H
#define LEVE_H
#include "Infraccion.h"


class Leve : public Infraccion{
private:
    double descuento;
public:
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(int codigo);
    void imprimir(ofstream &arch);
};

#endif /* LEVE_H */

