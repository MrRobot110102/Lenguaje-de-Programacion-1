/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria3.h
 * Author: Sebastian
 *
 * Created on 27 de junio de 2023, 23:05
 */

#ifndef CATEGORIA3_H
#define CATEGORIA3_H
#include "Producto.h"


class Categoria3 : public Producto{
private:
    int prioridad;
    double descuento;
public:
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
    int Prioridad();
};

#endif /* CATEGORIA3_H */

