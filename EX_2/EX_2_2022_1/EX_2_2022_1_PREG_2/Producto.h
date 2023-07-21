/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.h
 * Author: Sebastian
 *
 * Created on 27 de junio de 2023, 23:04
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Producto {
private:
    int codprod;
    char *nombre;
    int stock;
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetNombre(char *nomb);
    void GetNombre(char *nomb) const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
    virtual void leer(ifstream &arch);
    virtual void imprime(ofstream &arch);
    void operator=(const Producto& orig);
    virtual int Prioridad() = 0;
};

#endif /* PRODUCTO_H */

