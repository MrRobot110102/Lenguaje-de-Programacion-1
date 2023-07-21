/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Arbol.h
 * Author: Sebastian
 *
 * Created on 20 de junio de 2023, 21:18
 */

#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Nodo.h"

class Arbol {
private:
    class Nodo *arbol;
    void insertarR(class Nodo *&arbol,int dato);
    void mostrarEnOrdenR(class Nodo *arbol,ofstream &);
    void elimina(class Nodo *arbol);
    int buscarR(class Nodo *arbol, int dato);
public:
    Arbol();
    virtual ~Arbol();
    void crear(const char *);
    void insertar(int);
    void mostrarEnOrden(const char *);
    void buscar(int);
};

#endif /* ARBOL_H */

