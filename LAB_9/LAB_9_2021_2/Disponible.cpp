/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Disponible.cpp
 * Author: Sebastian
 * 
 * Created on 21 de junio de 2023, 21:02
 */

#include "Disponible.h"

Disponible::Disponible() {
}

Disponible::~Disponible() {
}

void Disponible::SetZona(int zona) {
    this->zona = zona;
}

int Disponible::GetZona() const {
    return zona;
}

void Disponible::AsignaZona(int zona){
    SetZona(zona);
}

void Disponible::Actualiza(int dias,int fecha,double precio){
}

void Disponible::Imprimir(ofstream &arch){
    arch<<"Zona:   "<<right<<setw(6)<<GetZona()<<left<<endl;
}
