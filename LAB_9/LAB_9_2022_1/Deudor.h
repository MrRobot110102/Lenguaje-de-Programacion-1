/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Deudor.h
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 18:09
 */

#ifndef DEUDOR_H
#define DEUDOR_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Cliente.h"

class Deudor {
private:
    class Cliente *Cdeudor;
public:
    Deudor();
    virtual ~Deudor();
    void leer(ifstream &arch,char tipo);
    void imprimir(ofstream &arch);
    void calcular();
    void asignarMontosYCantidades(double monto,int cantidad);
    int validaDeudor();
    int obtenerDniDeudor();
    void operator = (class Cliente *);
};

#endif /* DEUDOR_H */

