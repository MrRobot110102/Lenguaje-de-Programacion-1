/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClLista.h
 * Author: Sebastian
 *
 * Created on 17 de junio de 2023, 20:32
 */

#ifndef CLLISTA_H
#define CLLISTA_H
#include "ClNodo.h"

class ClLista {
private:
    class ClNodo *lista;
    void imprimeRecursivo(ofstream& arch, ClNodo* lista);
public:
    ClLista();
    virtual ~ClLista();
    void crear(const char*nombArch);
    void insertar(const class Persona &dato);
    void imprimir(const char*nombArch);
    void imprimirR(const char*);
};

#endif /* CLLISTA_H */

