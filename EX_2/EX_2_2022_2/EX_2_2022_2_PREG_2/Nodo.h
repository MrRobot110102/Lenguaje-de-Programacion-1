/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Sebastian
 *
 * Created on 29 de junio de 2023, 15:23
 */

#ifndef NODO_H
#define NODO_H
#include "medicamento.h"
#include "Arbol.h"


class Nodo {
public:
    Nodo();
    virtual ~Nodo();
    friend class Arbol;
private:
    class medicamento *med;
    class Nodo *izq;
    class Nodo *der;
};

#endif /* NODO_H */

