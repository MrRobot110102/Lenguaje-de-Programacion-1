/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.h
 * Author: Sebastian
 *
 * Created on 1 de julio de 2023, 11:51
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <list>
#include <vector>
using namespace std;
#include "Libro.h"
#include "RegistroUsuario.h"

class Biblioteca {
public:
    void leeLibros(const char *nombArch);
    void imprimeLibros(const char *nombArch);
    void leerUsuarios(const char *nombArch);
    void leerPrestamos(const char *nombArch);
    void imprimeUsuarios(const char *nombArch);
    void imprimirSuspendidos(const char *nombArch,int dd,int mm,int aa);
    list<Libro>::iterator buscarLibro(char *codLibro);
    vector<RegistroUsuario>::iterator buscarUsuario (int codigo,char tipo);
    int buscarUsu(int codigo,char tipo);
private:
    list<Libro>libros;
    vector<RegistroUsuario>usuarios;
};

#endif /* BIBLIOTECA_H */

