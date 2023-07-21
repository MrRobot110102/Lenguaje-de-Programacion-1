/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Alumno.cpp
 * Author: Sebastian
 * 
 * Created on 6 de julio de 2023, 23:00
 */

#include <cstring>

#include "Alumno.h"

Alumno::Alumno() {
    nombre = nullptr;
    total = 0.0;
}

Alumno::Alumno(const Alumno& orig) {
    nombre = nullptr;
    total = 0.0;
    *this = orig;
}

Alumno::~Alumno() {
    if(nombre != nullptr) delete nombre;
}

void Alumno::SetTotal(double total) {
    this->total = total;
}

double Alumno::GetTotal() const {
    return total;
}

void Alumno::SetCreditos(double creditos) {
    this->creditos = creditos;
}

double Alumno::GetCreditos() const {
    return creditos;
}

void Alumno::SetEscala(int escala) {
    this->escala = escala;
}

int Alumno::GetEscala() const {
    return escala;
}

void Alumno::SetNombre(char *nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void Alumno::GetNombre(char *nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb,nombre);
}

void Alumno::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Alumno::GetCodigo() const {
    return codigo;
}

void Alumno::operator=(const Alumno& alum) {
    char nomb[100];
    SetCodigo(alum.GetCodigo());
    SetCreditos(alum.GetCreditos());
    SetEscala(alum.GetEscala());
    alum.GetNombre(nomb);
    SetNombre(nomb);
}

void Alumno::getDatos(int& cod, char* nomb, int& esca, double& cred, double& tot) {
    cod = GetCodigo();
    GetNombre(nomb);
    esca = GetEscala();
    cred = GetCreditos();
    tot = GetTotal();
}

void Alumno::setDatos(int cod, char* nomb, int esca, double cred, double tot) {
    SetCodigo(cod);
    SetNombre(nomb);
    SetEscala(esca);
    SetCreditos(cred);
    SetTotal(tot);
}

void Alumno::lee(ifstream& arch) {
    char car,nomb[100];
    arch>>codigo>>car;
    arch.getline(nomb,100,',');
    arch>>escala>>car>>creditos>>car;
    SetNombre(nomb);
}

void Alumno::imprime(ofstream& arch) {
    char nomb[100];
    GetNombre(nomb);
    arch.precision(2);arch<<fixed;
    arch<<left<<setw(15)<<GetCodigo()<<setw(45)<<nomb<<setw(10)<<GetEscala()<<right<<setw(10)<<GetCreditos();
}






