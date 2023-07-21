/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Antiguo.cpp
 * Author: Sebastian
 * 
 * Created on 1 de julio de 2023, 13:28
 */

#include "Antiguo.h"

Antiguo::Antiguo() {
    exmanejo = 0;
}

void Antiguo::SetEstado(int estado) {
    this->estado = estado;
}

int Antiguo::GetEstado() const {
    return estado;
}

void Antiguo::SetExmanejo(double exmanejo) {
    this->exmanejo = exmanejo;
}

double Antiguo::GetExmanejo() const {
    return exmanejo;
}

void Antiguo::lee(ifstream& arch, int licencia) {
    int licen,cod,cantMuyGrave = 0;
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
            if(strcmp(gravedad,"Muy Grave") == 0) cantMuyGrave++;
            SetMulta(GetMulta() + monto);
        }else arch.getline(gravedad,100,'\n');
    }
    if(cantMuyGrave >= 5) SetEstado(0);
    else{
        SetExmanejo(GetExmanejo() + 500);
        SetExmedico(GetExmedico() + 100);
        SetTramite(GetTramite() + 300);
        SetEstado(1);
    }
}

void Antiguo::imprime(ofstream& arch) {
    if(GetEstado() == 1){
        arch.precision(0);arch<<fixed;
        arch<<left<<setw(20)<<'-'<<right<<setw(10)<<GetMulta()
            <<setw(10)<<GetTramite()<<setw(10)<<GetExmedico()<<setw(10)<<GetExmanejo();
        arch.precision(2);arch<<fixed;
        arch<<setw(10)<<GetMulta() + GetExmanejo() + GetExmedico() + GetTramite()<<endl;
        arch.precision(0);arch<<fixed;
    }else if(GetEstado() == 0) arch<<left<<"No puede renovar"<<endl;
}



