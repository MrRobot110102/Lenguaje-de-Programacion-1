/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Medicina_Cantidad.cpp
 * Author: Sebastian
 * 
 * Created on 28 de junio de 2023, 20:59
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Medicina_Cantidad.h"

void Medicina_Cantidad::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Medicina_Cantidad::GetCantidad() const {
    return cantidad;
}

void Medicina_Cantidad::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Medicina_Cantidad::GetCodigo() const {
    return codigo;
}

ifstream & operator >>(ifstream &arch,class Medicina_Cantidad &medicina){
    int codigo,cantidad;
    char car;
    arch>>codigo>>car>>cantidad;
    medicina.SetCodigo(codigo);
    medicina.SetCantidad(cantidad);
}

void Medicina_Cantidad::imprimeMedicina(ofstream& arch) {
    arch<<right<<setw(10)<<codigo<<setw(5)<<cantidad<<endl;
}


