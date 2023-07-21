/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Copia.h
 * Author: Sebastian
 *
 * Created on 21 de junio de 2023, 20:59
 */

#ifndef COPIA_H
#define COPIA_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Libro.h"

class Copia {
private:
    int numero;
    char *estado;
    class Libro *Olibro;
public:
    Copia();
    virtual ~Copia();
    void SetEstado(const char* est);
    void GetEstado(char *est) const;
    void SetNumero(int numero);
    int GetNumero() const;
    void asignaLibro(int zona,char *cod,char *tit,char *aut,int aa, int numero,double precio);
    void GetCodigo(char *cod);
    void asignaPrestamoPerdida(int dias,int fecha);
    void imprimirEncabezado(ofstream &arch);
    void imprime(ofstream &arch);
};

#endif /* COPIA_H */

