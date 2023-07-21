/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Conductor.cpp
 * Author: Sebastian
 * 
 * Created on 1 de julio de 2023, 13:28
 */

#include <cstring>

#include "Conductor.h"

Conductor::Conductor() {
    nombre = nullptr;
}

Conductor::Conductor(const Conductor& orig) {
    nombre = nullptr;
    *this = orig;
}

Conductor::~Conductor() {
    if(nombre != nullptr) delete nombre;
}

void Conductor::SetNombre(char *nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void Conductor::GetNombre(char *nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb,nombre);
}

void Conductor::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Conductor::GetLicencia() const {
    return licencia;
}

void Conductor::leer(ifstream& arch) {
    char car,nomb[100];
    arch>>licencia>>car;
    if(arch.eof()) return;
    arch.getline(nomb,100);
    SetNombre(nomb);
}

void Conductor::operator=(const class Conductor& conduc) {
    char nomb[100];
    SetLicencia(conduc.GetLicencia());
    conduc.GetNombre(nomb);
    SetNombre(nomb);
}

void Conductor::imprimir(ofstream& arch) {
    char nomb[100];
    GetNombre(nomb);
    arch<<left<<setw(15)<<GetLicencia()<<setw(40)<<nomb;
}



