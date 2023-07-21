/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Procesa.h
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 18:10
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Pedido.h"
#include "Deudor.h"

class Procesa {
private:
    class Pedido lpedidos[200];
    class Deudor ldeudor[100];
public:
    void carga();
    void cargaPedidos(ifstream &arch);
    void cargaClientes(ifstream &arch);
    void actualiza();
    void actualizarCantidadMontos(int dni,int &cantidad,double &monto);
    void muestra();
    
};

#endif /* PROCESA_H */

