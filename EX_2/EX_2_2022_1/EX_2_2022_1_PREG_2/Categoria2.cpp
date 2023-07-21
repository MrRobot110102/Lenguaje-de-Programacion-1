/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria2.cpp
 * Author: Sebastian
 * 
 * Created on 27 de junio de 2023, 23:04
 */

#include "Categoria2.h"

void Categoria2::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Categoria2::GetDescuento() const {
    return descuento;
}

void Categoria2::SetPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria2::GetPrioridad() const {
    return prioridad;
}

void Categoria2::leer(ifstream& arch) {
    char car;
    arch>>prioridad>>car>>descuento>>car;
    Producto::leer(arch);
}

void Categoria2::imprime(ofstream& arch) {
    Producto::imprime(arch);
    arch<<"Prioridad: "<<GetPrioridad()<<endl;
    arch<<"Descuento: "<<GetDescuento()<<endl;
}

int Categoria2::Prioridad() {
    return GetPrioridad();
}




