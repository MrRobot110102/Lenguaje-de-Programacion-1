/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Presencial.cpp
 * Author: Sebastian
 * 
 * Created on 6 de julio de 2023, 23:06
 */

#include "Presencial.h"

Presencial::Presencial() {
    total = 0.0;
}

void Presencial::SetTotal(double total) {
    this->total = total;
}

double Presencial::GetTotal() const {
    return total;
}

void Presencial::SetRecargo(double recargo) {
    this->recargo = recargo;
}

double Presencial::GetRecargo() const {
    return recargo;
}

void Presencial::lee(ifstream& arch) {
    Alumno::lee(arch);
    arch>>recargo;
}

void Presencial::imprime(ofstream& arch) {
    Alumno::imprime(arch);
    arch<<left<<setw(19)<<" "<<Alumno::GetTotal()<<setw(10)<<" "<<"Presencial"<<endl;
}

void Presencial::actualiza(int descuento,int num) {
}




