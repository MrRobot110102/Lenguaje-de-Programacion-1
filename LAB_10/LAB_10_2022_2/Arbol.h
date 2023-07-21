/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Arbol.h
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 11:53
 */

#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Arbol {
private:
    class Nodo *raiz;
    void elimina(class Nodo *arbol);
    void insertar(class Nodo *&raiz,class Nodo *nuevo);
    void mostrarEnOrden(class Nodo *raiz,ofstream &);
    void buscarR(class Nodo *raiz, int codigo);
public:
    Arbol();
    virtual ~Arbol();
    void crear(ifstream &arch);
    void actualizar(ifstream &arch);
    void imprimir(ofstream &arch);
    void imprimirLinea(ofstream &arch,int cantidad, char car);
};

#endif /* ARBOL_H */

