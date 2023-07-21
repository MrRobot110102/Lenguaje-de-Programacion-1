/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClLista.h
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 15:43
 */

#ifndef CLLISTA_H
#define CLLISTA_H
#include <fstream>
using namespace std;    
#include "ClNodo.h"
    
class ClLista {
private:
    class ClNodo *lista;
    void imprimeRecursivo(ofstream &archOut, class ClNodo *lista);
public:
    ClLista();
    virtual ~ClLista();
    void crear(const char*);
    void insertar(int);
    void imprimir(const char*);
    void imprimirR(const char*);
};

#endif /* CLLISTA_H */

