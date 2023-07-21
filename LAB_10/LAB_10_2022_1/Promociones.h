/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Promociones.h
 * Author: Sebastian
 *
 * Created on 23 de junio de 2023, 22:44
 */

#ifndef PROMOCIONES_H
#define PROMOCIONES_H
#include "Lista.h"

class Promociones {
private:
    class Lista Lpedidos;
public:
    void leepedidos();
    void actualizapedidos();
    void imprimepedidos();
    void imprimeLinea(ofstream&,char,int);
    
};

#endif /* PROMOCIONES_H */

