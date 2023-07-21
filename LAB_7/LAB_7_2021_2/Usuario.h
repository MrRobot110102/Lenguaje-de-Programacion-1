/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Usuario.h
 * Author: Sebastian
 *
 * Created on 5 de junio de 2023, 18:22
 */

#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include "LibroPrestado.h"
using namespace std;

class Usuario {
private:
    int carne;
    char tipo;
    char *nombre;
    class LibroPrestado libPrest[20];
    int numLibPrest;
    int condicion;
public:
    Usuario();
    virtual ~Usuario();
    void SetCondicion(int condicion);
    int GetCondicion() const;
    void SetNumLibPrest(int numLibPrest);
    int GetNumLibPrest() const;
    void SetNombre(char* nomb);
    void GetNombre(char *nomb) const;
    void SetTipo(char tipo);
    char GetTipo() const;
    void SetCarne(int carne);
    int GetCarne() const;
    void imprimirLibrosPrestados(ofstream &arch) const;
    void operator +=(const class LibroPrestado &libPrestado);
    void operator *(int fecha);
};

#endif /* USUARIO_H */

