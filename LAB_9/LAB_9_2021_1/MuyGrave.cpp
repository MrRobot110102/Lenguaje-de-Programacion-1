/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   MuyGrave.cpp
 * Author: Sebastian
 * 
 * Created on 17 de junio de 2023, 14:25
 */

#include "MuyGrave.h"

MuyGrave::MuyGrave() {
}

MuyGrave::~MuyGrave() {
}

void MuyGrave::SetMeses(int meses) {
    this->meses = meses;
}

int MuyGrave::GetMeses() const {
    return meses;
}

void MuyGrave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int MuyGrave::GetPuntos() const {
    return puntos;
}

void MuyGrave::lee(ifstream &arch,int codInfraccion){
    int codigo,meses,puntos;
    char desc[500],car;
    double monto;
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        arch.get();
        if(codigo == codInfraccion){
            arch.getline(desc,500,',');
            arch.getline(desc,500,',');
            arch>>monto>>car>>puntos>>car>>meses;
            SetPuntos(puntos);
            SetMeses(meses);
            SetGravedad("GRAVE");
            SetMulta(monto);
        }else arch.getline(desc,500,'\n');
    }
}

void MuyGrave::imprime(ofstream &arch){
    char grav[15];
    GetGravedad(grav);
    arch<<left<<"Codigo:   "<<GetCodigo()<<endl;
    arch<<left<<"Gravedad: "<<grav<<endl;
    arch<<left<<"Monto:    "<<GetMulta()<<endl;
    arch<<left<<"Puntos:   "<<GetPuntos()<<endl;
    arch<<left<<"Meses:    "<<GetMeses()<<endl;
}

void MuyGrave::aplica(){
}

void MuyGrave::acumula(double &montoMulta,int &puntosPerdidos,int &mesesSancionados){
    montoMulta += GetMulta();
    puntosPerdidos += GetPuntos();
    mesesSancionados += GetMeses();
}
