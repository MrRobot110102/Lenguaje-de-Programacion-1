/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NProductos.h
 * Author: Sebastian
 *
 * Created on 27 de junio de 2023, 23:05
 */

#ifndef NPRODUCTOS_H
#define NPRODUCTOS_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Producto.h"

class NProductos {
private:
    class Producto *prod;
public:
    NProductos();
    NProductos(const NProductos &orig);
    void leerProductos(ifstream &arch);
    void imprimirProductos(ofstream &arch);
    void operator=(const NProductos &orig);
    int getCodigo();
    int getPrioridad();
};

#endif /* NPRODUCTOS_H */

