/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Sebastian
 *
 * Created on 21 de junio de 2023, 21:05
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Copia.h"

class Biblioteca {
private:
    class Copia llibros[500];
public:
    void GeneraCopias();
    void ActualizaLibros();
    void ImprimeCopias();
    void imprimeLinea(ofstream &arch,int cantidad, char car);
    int buscarLibro(char *cod);
};

#endif /* BIBLIOTECA_H */

