/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nuevo.cpp
 * Author: Sebastian
 * 
 * Created on 1 de julio de 2023, 13:28
 */

#include "Nuevo.h"

Nuevo::Nuevo() {
    exreglas = 0;
}

void Nuevo::SetExreglas(double exreglas) {
    this->exreglas = exreglas;
}

double Nuevo::GetExreglas() const {
    return exreglas;
}

void Nuevo::lee(ifstream& arch, int licencia) {
    int licen,cod;
    char gravedad[100],car;
    double monto;
    while(true){
        arch>>licen;
        if(arch.eof()) break;
        arch.get();
        if(licen == licencia){
            arch>>cod>>car;
            arch.getline(gravedad,100,',');
            arch>>monto;
            if(strcmp(gravedad,"Muy Grave") == 0) SetMulta(GetMulta() + monto);
        }else arch.getline(gravedad,100,'\n');
    }
    SetTramite(GetTramite() + 200);
    SetExmedico(GetExmedico() + 100);
    SetExreglas(GetExreglas() + 150);
}

void Nuevo::imprime(ofstream& arch) {
    arch.precision(0);arch<<fixed;
    arch<<left<<setw(20)<<'-'<<right<<setw(10)<<GetMulta()
        <<setw(10)<<GetTramite()<<setw(10)<<GetExmedico()<<setw(10)<<GetExreglas();
    arch.precision(2);arch<<fixed;
    arch<<setw(10)<<GetMulta() + GetExreglas() + GetExmedico() + GetTramite()<<endl;
}



