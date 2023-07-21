/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 11:53
 */

#ifndef NODO_H
#define NODO_H
#include "Arbol.h"
#include "medicamento.h"

class Nodo {
private:
    class medicamento *med;
    class Nodo *izq;
    class Nodo *der;
public:
    Nodo();
    virtual ~Nodo();
    friend class Arbol;
};

#endif /* NODO_H */

