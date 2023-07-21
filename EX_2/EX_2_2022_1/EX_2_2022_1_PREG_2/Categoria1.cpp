/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria1.cpp
 * Author: Sebastian
 * 
 * Created on 27 de junio de 2023, 23:04
 */

#include "Categoria1.h"

void Categoria1::SetMinimo(int minimo) {
    this->minimo = minimo;
}

int Categoria1::GetMinimo() const {
    return minimo;
}

void Categoria1::SetPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria1::GetPrioridad() const {
    return prioridad;
}

void Categoria1::leer(ifstream& arch) {
    char car;
    arch>>prioridad>>car>>minimo>>car;
    Producto::leer(arch);
}

void Categoria1::imprime(ofstream& arch) {
    Producto::imprime(arch);
    arch<<"Prioridad: "<<GetPrioridad()<<endl;
    arch<<"Minimo:    "<<GetMinimo()<<endl;
}

int Categoria1::Prioridad() {
    return GetPrioridad();
}


