/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria2.h
 * Author: Sebastian
 *
 * Created on 27 de junio de 2023, 23:04
 */

#ifndef CATEGORIA2_H
#define CATEGORIA2_H
#include "Producto.h"

class Categoria2 :public Producto{
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

#endif /* CATEGORIA2_H */

