/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.h
 * Author: Sebastian
 *
 * Created on 27 de junio de 2023, 23:04
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Pedido {
private:
    int codigo;
    int cantidad;
    int dni;
    int fecha;
    double total;
    int orden;
public:
    void SetOrden(int orden);
    int GetOrden() const;
    void SetTotal(double total);
    double GetTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void imprime(ofstream &arch);
    void leer(ifstream &arch);
};

#endif /* PEDIDO_H */

