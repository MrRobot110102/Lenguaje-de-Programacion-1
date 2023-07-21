/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Prestamo.cpp
 * Author: Sebastian
 * 
 * Created on 21 de junio de 2023, 21:03
 */

#include "Prestamo.h"

Prestamo::Prestamo() {
}

Prestamo::~Prestamo() {
}

void Prestamo::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Prestamo::GetFecha() const {
    return fecha;
}

void Prestamo::SetDias(int dias) {
    this->dias = dias;
}

int Prestamo::GetDias() const {
    return dias;
}

void Prestamo::Actualiza(int dias,int fecha, double precio){
    SetDias(dias);
    SetFecha(fecha);
}

void Prestamo::AsignaZona(int zona){
}

void Prestamo::Imprimir(ofstream &arch){
    arch<<"Dias:   "<<right<<setw(6)<<GetDias()<<left<<endl;
}

