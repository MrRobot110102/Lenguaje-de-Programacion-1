/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Grave.cpp
 * Author: Sebastian
 * 
 * Created on 17 de junio de 2023, 14:25
 */

#include "Grave.h"

Grave::Grave() {
}

Grave::~Grave() {
}

void Grave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int Grave::GetPuntos() const {
    return puntos;
}

void Grave::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Grave::GetDescuento() const {
    return descuento;
}

void Grave::lee(ifstream &arch,int codInfraccion){
    int codigo,puntos;
    char desc[500],car;
    double monto,descuento;
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        arch.get();
        if(codigo == codInfraccion){
            arch.getline(desc,500,',');
            arch.getline(desc,500,',');
            arch>>monto>>car>>descuento>>car>>puntos;
            SetPuntos(puntos);
            SetDescuento(descuento);
            SetGravedad("GRAVE");
            SetMulta(monto);
        }else arch.getline(desc,500,'\n');
    }
}

void Grave::imprime(ofstream &arch){
    char grav[15];
    GetGravedad(grav);
    arch<<left<<"Codigo:   "<<GetCodigo()<<endl;
    arch<<left<<"Gravedad: "<<grav<<endl;
    arch<<left<<"Monto:    "<<GetMulta()<<endl;
    arch<<left<<"Descuento:"<<GetDescuento()<<endl;
    arch<<left<<"Puntos:   "<<GetPuntos()<<endl;
}

void Grave::aplica(){
    SetMulta( GetMulta() * (1- GetDescuento()) );
}

void Grave::acumula(double &montoMulta,int &puntosPerdidos,int &mesesSancionados){
    montoMulta += GetMulta();
    puntosPerdidos += GetPuntos();
}