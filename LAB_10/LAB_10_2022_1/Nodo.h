/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Nodo.h
 * Author: Sebastian
 *
 * Created on 23 de junio de 2023, 22:09
 */

#ifndef NODO_H
#define NODO_H
#include "Lista.h"
#include "Pedido.h"

class Nodo {
private:
    class Pedido *ped;
    class Nodo *sig;
    class Nodo *ant;
public:
    Nodo();
    virtual ~Nodo();
    friend class Lista;
};

#endif /* NODO_H */

