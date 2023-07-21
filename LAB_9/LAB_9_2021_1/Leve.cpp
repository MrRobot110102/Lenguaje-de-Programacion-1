/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Leve.cpp
 * Author: Sebastian
 * 
 * Created on 17 de junio de 2023, 14:25
 */

#include "Leve.h"

Leve::Leve() {
}

Leve::~Leve() {
}

void Leve::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Leve::GetDescuento() const {
    return descuento;
}

void Leve::lee(ifstream &arch,int codInfraccion){
    int codigo;
    char desc[500],car;
    double monto,descuento;
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        arch.get();
        if(codigo == codInfraccion){
            arch.getline(desc,500,',');
            arch.getline(desc,500,',');
            arch>>monto>>car>>descuento;
            SetDescuento(descuento);
            SetGravedad("LEVE");
            SetMulta(monto);
        }else arch.getline(desc,500,'\n');
    }
}

void Leve::imprime(ofstream &arch){
    char grav[15];
    GetGravedad(grav);
    arch<<left<<"Codigo:   "<<GetCodigo()<<endl;
    arch<<left<<"Gravedad: "<<grav<<endl;
    arch<<left<<"Monto:    "<<GetMulta()<<endl;
    arch<<left<<"Descuento:"<<GetDescuento()<<endl;
}

void Leve::aplica(){
    SetMulta( GetMulta() * (1- GetDescuento()) );
}

void Leve::acumula(double &montoMulta,int &puntosPerdidos,int &mesesSancionados){
    montoMulta += GetMulta();
}
