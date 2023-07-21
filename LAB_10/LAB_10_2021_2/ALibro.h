/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ALibro.h
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 19:27
 */

#ifndef ALIBRO_H
#define ALIBRO_H
#include "NLibro.h"
#include "Libro.h"

class ALibro {
private:
    class NLibro *Raiz;
    void elimina(class NLibro *Raiz);
    void insertar(class NLibro *&arbol,const class Libro &dato);
    void insertarNuevo(class NLibro *&arbol,class NLibro *nuevo);
    void buscar(class NLibro *arbol,char *codLibro);
    void mostrarEnOrden(class NLibro* arbol,ofstream &arch);
public:
    ALibro();
    virtual ~ALibro();
    void crear(ifstream &arch);
    void actualizar(ifstream &arch);
    void imprimir(ofstream &arch);
    void imprimirLinea(ofstream &arch,int cantidad, char car);
};

#endif /* ALIBRO_H */

