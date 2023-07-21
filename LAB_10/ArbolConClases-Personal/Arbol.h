/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Arbol.h
 * Author: Sebastian
 *
 * Created on 20 de junio de 2023, 22:29
 */

#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"

class Arbol {
private:
    class Nodo *arbol;
    void insertarR(class Nodo *&arbol,const class Persona &dato);
    void mostrarEnOrdenR(class Nodo *arbol,ofstream &);
    void elimina(class Nodo *arbol);
    class Persona buscarR(class Nodo *arbol, int dato);
public:
    Arbol();
    virtual ~Arbol();
    void crear(const char *);
    void insertar(const class Persona &dato);
    void mostrarEnOrden(const char *);
    void buscar(int);
};

#endif /* ARBOL_H */

