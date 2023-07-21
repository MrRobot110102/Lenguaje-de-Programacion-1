/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Arbol.h
 * Author: Sebastian
 *
 * Created on 29 de junio de 2023, 15:23
 */

#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Nodo.h"

class Arbol {
public:
    Arbol();
    virtual ~Arbol();
    void crear(ifstream &arch,int fechaComparar, const char* nombProfesor);
    void imprimir(ofstream &arch);
    void actualizar(int fechaComparar,const char *apellido);
private:
    class Nodo *raiz;
    void elimina(class Nodo *arbol);
    void insertar( class Nodo *&raiz,class Nodo *nuevo);
    void mostrarEnOrden(class Nodo *raiz,ofstream &arch);
    void buscar(class Nodo *raiz,int fechaComparar,const char *apellido);
};

#endif /* ARBOL_H */

