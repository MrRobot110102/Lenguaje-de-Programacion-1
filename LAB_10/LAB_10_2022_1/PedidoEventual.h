/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PedidoEventual.h
 * Author: Sebastian
 *
 * Created on 23 de junio de 2023, 22:08
 */

#ifndef PEDIDOEVENTUAL_H
#define PEDIDOEVENTUAL_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Pedido.h"

class PedidoEventual : public Pedido{
private:
    double flete;
public:
    void SetFlete(double flete);
    double GetFlete() const;
    void lee(ifstream &arch);
    void imprime(ofstream &arch);
    void exonerarFlete();
};

#endif /* PEDIDOEVENTUAL_H */

