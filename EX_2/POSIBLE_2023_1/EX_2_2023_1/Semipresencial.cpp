/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Semipresencial.cpp
 * Author: Sebastian
 * 
 * Created on 6 de julio de 2023, 23:13
 */

#include "Semipresencial.h"

Semipresencial::Semipresencial() {
    total = 0.0;
}

void Semipresencial::SetTotal(double total) {
    this->total = total;
}

double Semipresencial::GetTotal() const {
    return total;
}

void Semipresencial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Semipresencial::GetDescuento() const {
    return descuento;
}

void Semipresencial::lee(ifstream& arch) {
    Alumno::lee(arch);
    arch>>descuento;
}

void Semipresencial::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch<<left<<setw(19)<<" "<<Alumno::GetTotal()<<setw(10)<<" "<<"SemiPresencial"<<endl;
}

void Semipresencial::actualiza(int descuento,int num) {
    if(num == 0) SetCodigo(GetCodigo()+300000);
    SetDescuento(descuento);
}



