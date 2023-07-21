/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paciente.cpp
 * Author: Sebastian
 * 
 * Created on 3 de julio de 2023, 18:50
 */

#include <cstring>

#include "Paciente.h"

Paciente::Paciente() {
    nombre = nullptr;
    codMed = nullptr;
}

Paciente::Paciente(const Paciente& orig) {
    nombre = nullptr;
    codMed = nullptr;
    *this = orig;
}

Paciente::~Paciente() {
    if(nombre != nullptr) delete nombre;
    if(codMed != nullptr) delete codMed;
}

void Paciente::SetCodMed(char *cod) {
    if(codMed != nullptr) delete codMed;
    codMed = new char[strlen(cod) + 1];
    strcpy(codMed,cod);
}

void Paciente::GetCodMed(char *cod) const {
    if(codMed == nullptr) cod[0] = 0;
    else strcpy(cod,codMed);
}

void Paciente::SetNombre(char *nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void Paciente::GetNombre(char *nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb,nombre);
}

void Paciente::SetDni(int dni) {
    this->dni = dni;
}

int Paciente::GetDni() const {
    return dni;
}

void Paciente::operator=(const Paciente& pac) {
    char nomb[100],cod[100];
    pac.GetCodMed(cod);
    pac.GetNombre(nomb);
    SetEdad(pac.GetEdad());
    SetDni(pac.GetDni());
    SetCodMed(cod);
    SetNombre(nomb);
}

void Paciente::leer(ifstream& arch) {
    char nomb[100],cod[100],car;
    arch>>dni>>car;
    arch.getline(nomb,100,',');
    arch>>edad>>car;
    arch.getline(cod,100,',');
    SetNombre(nomb);
    SetCodMed(cod);
}

void Paciente::SetEdad(int edad) {
    this->edad = edad;
}

int Paciente::GetEdad() const {
    return edad;
}

void Paciente::imprimir(ofstream &arch) {
    char nomb[100];
    GetNombre(nomb);
    arch<<left<<setw(12)<<GetDni()<<setw(45)<<nomb<<setw(10)<<GetEdad();
}




