/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   farmacia.h
 * Author: Sebastian
 *
 * Created on 16 de junio de 2023, 21:50
 */

#ifndef FARMACIA_H
#define FARMACIA_H
#include "oferta.h"

class farmacia {
private:
    class oferta loferta[200];
public:
    void leerecetas();
    void descuenta();
    void imprimirecetas();
    void imprimirLinea(ofstream &arch,int cantidad,char car);
};

#endif /* FARMACIA_H */

