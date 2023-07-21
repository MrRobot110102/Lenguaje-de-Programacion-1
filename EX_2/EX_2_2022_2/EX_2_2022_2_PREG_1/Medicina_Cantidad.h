/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Medicina_Cantidad.h
 * Author: Sebastian
 *
 * Created on 28 de junio de 2023, 20:59
 */

#ifndef MEDICINA_CANTIDAD_H
#define MEDICINA_CANTIDAD_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Medicina_Cantidad {
public:
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void imprimeMedicina(ofstream &arch);
private:
    int codigo;
    int cantidad;
};

ifstream & operator >>(ifstream &arch,class Medicina_Cantidad &medicina);



#endif /* MEDICINA_CANTIDAD_H */

