/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.h
 * Author: Sebastian
 *
 * Created on 27 de junio de 2023, 23:05
 */

#ifndef NODO_H
#define NODO_H
#include "Pedido.h"
#include "Lista.h"

class Nodo {
private:
    class Pedido *ped;
    class Nodo *sig;
public:
    Nodo();
    virtual ~Nodo();
    friend class Lista;
};

#endif /* NODO_H */

