/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Emergencia.cpp
 * Author: Sebastian
 * 
 * Created on 3 de julio de 2023, 19:03
 */

#include <cstring>

#include "Emergencia.h"

Emergencia::Emergencia() {
    nombreRef = nullptr;
}

Emergencia::~Emergencia() {
    if(nombreRef != nullptr) delete nombreRef;
}

void Emergencia::SetNombreRef(char *nomb) {
    if(nombreRef != nullptr) delete nombreRef;
    nombreRef = new char[strlen(nomb) + 1];
    strcpy(nombreRef,nomb);
}

void Emergencia::GetNombreRef(char *nomb) const {
    if(nombreRef == nullptr) nomb[0] = 0;
    else strcpy(nomb,nombreRef);
}

void Emergencia::SetTelefonoRef(int telefonoRef) {
    this->telefonoRef = telefonoRef;
}

int Emergencia::GetTelefonoRef() const {
    return telefonoRef;
}

void Emergencia::leer(ifstream& arch) {
    char nomb[100];
    Paciente::leer(arch);
    arch.getline(nomb,100,',');
    arch>>telefonoRef;
    arch.get();
    SetNombreRef(nomb);
}

int Emergencia::prioridad() {
    return 300 + GetEdad();
}

void Emergencia::imprimir(ofstream& arch) {
    Paciente::imprimir(arch);
}

void Emergencia::observacion(char* obs) {
    if(GetEdad() > 65) strcpy(obs,"Persona de Riesgo");
    else obs[0] = 0;
}

int Emergencia::imprimirReferencia(ofstream &arch) {
    char nomb[100];
    GetNombreRef(nomb);
    arch<<left<<setw(30)<<nomb<<GetTelefonoRef()<<endl;
    return 1;
}






