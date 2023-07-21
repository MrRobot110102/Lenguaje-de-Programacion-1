/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Biblioteca.h
 * Author: Sebastian
 *
 * Created on 10 de junio de 2023, 11:38
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Copia.h"

class Biblioteca {
private:
    class Copia llibros[500];   
public:
    void generaCopias();
    void actualizaLibros();
    int buscarLibro(char *cod);
    void imprimeCopias();
    void imprimeLinea(ofstream &arch,int cantidad, char car);
};

#endif /* BIBLIOTECA_H */

