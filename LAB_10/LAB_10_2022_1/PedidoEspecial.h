/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PedidoEspecial.h
 * Author: Sebastian
 *
 * Created on 23 de junio de 2023, 22:05
 */

#ifndef PEDIDOESPECIAL_H
#define PEDIDOESPECIAL_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Pedido.h"

class PedidoEspecial : public Pedido{
private:
    double descuento;
public:
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void exonerarFlete();
};

#endif /* PEDIDOESPECIAL_H */

