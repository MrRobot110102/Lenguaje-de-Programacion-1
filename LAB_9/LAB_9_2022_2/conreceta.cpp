/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   conreceta.cpp
 * Author: Sebastian
 * 
 * Created on 16 de junio de 2023, 21:50
 */

#include <cstring>

#include "conreceta.h"

conreceta::conreceta() {
    especialidad = nullptr;
}

conreceta::~conreceta() {
    if(especialidad != nullptr) delete especialidad;
}

void conreceta::SetEspecialidad(char *espec) {
    if(especialidad != nullptr) delete especialidad;
    especialidad = new char[strlen(espec) + 1];
    strcpy(especialidad,espec);
}

void conreceta::GetEspecialidad(char *espec) const {
    if(especialidad == nullptr) espec[0] = 0;
    else strcpy(espec,especialidad);
}

void conreceta::SetCodmed(int codmed) {
    this->codmed = codmed;
}

int conreceta::GetCodmed() const {
    return codmed;
}

void conreceta::leemedicamento(ifstream &arch,int codMed){
    int codigoMedico,dni;
    char car,espec[100],nomb[500];
    medicamento::leemedicamento(arch,codMed);
    arch>>codigoMedico>>car>>dni>>car;
    arch.getline(nomb,500);
    SetCodmed(codigoMedico);
    if(buscarEspecialidad(codigoMedico,espec)) SetEspecialidad(espec);
}

int conreceta::buscarEspecialidad(int codMedico,char *espec){
    ifstream arch("medicos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo medicos.csv"<<endl;
        exit(1);
    }
    int codigo;
    char nomb[100];
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        arch.get();
        arch.getline(nomb,100,',');
        arch.getline(espec,100);
        if(codMedico == codigo) return 1;
    }
    return 0;
}

void conreceta::imprimedicamento(ofstream &arch){
    char espec[100];
    medicamento::imprimedicamento(arch);
    GetEspecialidad(espec);
    arch<<setw(12)<<GetCodmed()<<setw(30)<<espec<<endl;
}

void conreceta::aplicadescuento(){
    medicamento::aplicadescuento();
    SetTotal(GetTotal() *(1 + 0.05));
}
