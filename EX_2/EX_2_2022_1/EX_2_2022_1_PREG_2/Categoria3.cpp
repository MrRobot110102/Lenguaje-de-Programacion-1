/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Categoria3.cpp
 * Author: Sebastian
 * 
 * Created on 27 de junio de 2023, 23:05
 */

#include "Categoria3.h"

void Categoria3::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Categoria3::GetDescuento() const {
    return descuento;
}

void Categoria3::SetPrioridad(int prioridad) {
    this->prioridad = prioridad;
}

int Categoria3::GetPrioridad() const {
    return prioridad;
}

void Categoria3::leer(ifstream& arch) {
    char car;
    arch>>prioridad>>car>>descuento>>car;
    Producto::leer(arch);
}

void Categoria3::imprime(ofstream& arch) {
    Producto::imprime(arch);
    arch<<"Prioridad: "<<GetPrioridad()<<endl;
    arch<<"Descuento: "<<GetDescuento()<<endl;
}

int Categoria3::Prioridad() {
    return GetPrioridad();
}




