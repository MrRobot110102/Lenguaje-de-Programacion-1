/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: Sebastian
 *
 * Created on 27 de junio de 2023, 23:05
 */

#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Nodo.h"
#include "Pedido.h"

class Lista {
private:
    class Nodo *lini;
    class Nodo *lfin;
    class Pedido *leePedido(ifstream &arch);
    void insertar(class Nodo *nuevo);
public:
    Lista();
    virtual ~Lista();
    void llenarLista(ifstream &arch);
    void imprimirLista(ofstream &arch);
    void obtenerCodigos(int *codProductos,int &n);
    void reordena(int *prioridades);
};

#endif /* LISTA_H */

