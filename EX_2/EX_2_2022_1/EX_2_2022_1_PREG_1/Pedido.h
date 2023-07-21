/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Pedido.h
 * Author: Sebastian
 *
 * Created on 27 de junio de 2023, 20:37
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
    double cantidad;
    int fecha;
    double subTotal;
public:
    Pedido();
    Pedido(const Pedido& orig);
    void SetSubTotal(double subTotal);
    double GetSubTotal() const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetCantidad(double cantidad);
    double GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    int leerDatos(ifstream &);
    void imprimirDatos(ofstream &);
    bool operator <(const class Pedido &ped);
    void operator =(const class Pedido &ped);
};

#endif /* PEDIDO_H */

