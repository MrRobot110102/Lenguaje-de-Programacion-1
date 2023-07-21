/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Conductor.cpp
 * Author: Sebastian
 * 
 * Created on 17 de junio de 2023, 14:25
 */

#include <cstring>

#include "Conductor.h"

Conductor::Conductor() {
    nombre = nullptr;
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

