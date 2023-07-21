/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Virtual.cpp
 * Author: Sebastian
 * 
 * Created on 6 de julio de 2023, 23:16
 */

#include <cstring>
#include "Virtual.h"

Virtual::Virtual() {
    total = 0.0;
    licencia = nullptr;
}

Virtual::~Virtual() {
    if(licencia != nullptr) delete licencia;
}

void Virtual::SetTotal(double total) {
    this->total = total;
}

double Virtual::GetTotal() const {
    return total;
}

void Virtual::SetLicencia(char *licen) {
    if(licencia != nullptr) delete licencia;
    licencia = new char[strlen(licen) + 1];
    strcpy(licencia,licen);
}

void Virtual::GetLicencia(char *licen) const {
    if(licencia == nullptr) licen[0] = 0;
    else strcpy(licen,licencia);
}

void Virtual::lee(ifstream& arch) {
    char licen[100];
    Alumno::lee(arch);
    arch.getline(licen,100);
    SetLicencia(licen);
}

void Virtual::imprime(ofstream& arch) {
    char licen[100];
    Alumno::imprime(arch);
    GetLicencia(licen);
    arch<<left<<"    "<<setw(15)<<licen<<right<<Alumno::GetTotal()<<setw(10)<<" "<<"Virtual"<<endl;
}

void Virtual::actualiza(int descuento,int num) {
}



