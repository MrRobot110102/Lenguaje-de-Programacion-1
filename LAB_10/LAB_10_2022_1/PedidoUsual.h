/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PedidoUsual.h
 * Author: Sebastian
 *
 * Created on 23 de junio de 2023, 22:07
 */

#ifndef PEDIDOUSUAL_H
#define PEDIDOUSUAL_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Pedido.h"

class PedidoUsual : public Pedido{
private:
    double descuento;
    double flete;
public:
    void SetFlete(double flete);
    double GetFlete() const;
    void SetDescuento(double descuento);
    double GetDescuento() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void exonerarFlete();
};

#endif /* PEDIDOUSUAL_H */

