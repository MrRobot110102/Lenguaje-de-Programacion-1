/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria1.h
 * Author: Sebastian
 *
 * Created on 27 de junio de 2023, 23:04
 */

#ifndef CATEGORIA1_H
#define CATEGORIA1_H
#include "Producto.h"


class Categoria1 : public Producto{
private:
    int prioridad;
    int minimo;
public:
    void SetMinimo(int minimo);
    int GetMinimo() const;
    void SetPrioridad(int prioridad);
    int GetPrioridad() const;
    void leer(ifstream &arch);
    void imprime(ofstream &arch);
    int Prioridad();
};

#endif /* CATEGORIA1_H */

