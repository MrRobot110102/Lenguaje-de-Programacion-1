/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Sebastian
 *
 * Created on 20 de junio de 2023, 22:28
 */

#ifndef NODO_H
#define NODO_H
#include "Persona.h"
#include "Arbol.h"

class Nodo {
private:
    class Persona dato;
    class Nodo *izq;
    class Nodo *der;
public:
    Nodo();
    friend class Arbol;
};

#endif /* NODO_H */

