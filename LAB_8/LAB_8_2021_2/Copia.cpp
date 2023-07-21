/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Copia.cpp
 * Author: Sebastian
 * 
 * Created on 10 de junio de 2023, 11:37
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Copia.h"

Copia::Copia() {
    estado = nullptr;
}

Copia::~Copia() {
    if(estado != nullptr) delete estado;
}

void Copia::SetEstado(const char *est) {
    if(estado != nullptr) delete estado;
    estado = new char[strlen(est) + 1];
    strcpy(estado,est);
}

void Copia::GetEstado(char *est) const {
    if(estado == nullptr) est[0] = 0;
    else strcpy(est,estado);
}

void Copia::SetNumero(int numero) {
    this->numero = numero;
}

int Copia::GetNumero() const {
    return numero;
}

void Copia::SetDisponible(int zona){
    SetEstado("Disponible");
    Odisponible.SetZona(zona);
}
    
void Copia::SetPrestamo(int dias,int fecha){
    SetEstado("Prestamo");
    Oprestamo.SetDias(dias);
    Oprestamo.SetFecha(fecha);
    Odisponible.SetZona(0);
}
    
void Copia::SetPerdida(double precio){
    SetEstado("Perdida");
    Operdida.SetPrecio(precio);
    Odisponible.SetZona(0);
}

void Copia::imprimeDisponible(ofstream &arch){
    arch<<"Zona:   "<<right<<setw(6)<<Odisponible.GetZona()<<left<<endl;
}
    
void Copia::imprimePrestamo(ofstream &arch){
    arch<<"Dias:   "<<right<<setw(6)<<Oprestamo.GetDias()<<left<<endl;
}
    
void Copia::imprimePerdida(ofstream &arch){
    arch<<"Precio: "<<right<<setw(6)<<Operdida.GetPrecio()<<left<<endl;
}

