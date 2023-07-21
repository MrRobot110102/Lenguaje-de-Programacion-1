/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Perdida.cpp
 * Author: Sebastian
 * 
 * Created on 21 de junio de 2023, 21:04
 */

#include "Perdida.h"

Perdida::Perdida() {
}

Perdida::~Perdida() {
}

void Perdida::SetPrecio(double precio) {
    this->precio = precio;
}

double Perdida::GetPrecio() const {
    return precio;
}

void Perdida::Actualiza(int dias, int fecha, double precio){
    Perdida::SetPrecio(precio);
}

void Perdida::AsignaZona(int zona){
}

void Perdida::Imprimir(ofstream &arch){
    arch<<"Precio: "<<right<<setw(6)<<GetPrecio()<<left<<endl;
}