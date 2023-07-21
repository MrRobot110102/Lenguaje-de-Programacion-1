/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   oferta.h
 * Author: Sebastian
 *
 * Created on 16 de junio de 2023, 21:50
 */

#ifndef OFERTA_H
#define OFERTA_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "medicamento.h"

class oferta {
private:
    class medicamento *poferta;
public:
    oferta();
    virtual ~oferta();
    void asignaReceta(ifstream &arch);
    void operator =(class medicamento *pt);
    int validaReceta();
    void imprimir(ofstream &arch);
    void aplicarDescuento();
};

#endif /* OFERTA_H */

