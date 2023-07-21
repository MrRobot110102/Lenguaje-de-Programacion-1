/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Paciente.cpp
 * Author: Sebastian
 * 
 * Created on 6 de junio de 2023, 14:09
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Paciente.h"

Paciente::Paciente() {
    nombre = nullptr;
}

Paciente::~Paciente() {
    if(nombre != nullptr) delete nombre;
}

void Paciente::SetEstado(char estado) {
    this->estado = estado;
}

char Paciente::GetEstado() const {
    return estado;
}

void Paciente::SetPrima(double prima) {
    this->prima = prima;
}

double Paciente::GetPrima() const {
    return prima;
}

void Paciente::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void Paciente::GetNombre(char* nomb) const {
    if(nombre == nullptr) nombre[0] = 0;
    strcpy(nomb,nombre);
}

void Paciente::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Paciente::GetCodigo() const {
    return codigo;
}

void Paciente::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Paciente::GetFecha() const {
    return fecha;
}

ifstream & operator >>(ifstream &arch,class Paciente &paciente){
    int cod;
    double p;
    char car, nomb[50], E;
    arch >> E >> cod >> nomb >> p;
    paciente.SetCodigo(cod);
    paciente.SetEstado(E);
    paciente.SetNombre(nomb);
    paciente.SetPrima(p);
    return arch;
}

void Paciente::operator =(const class Paciente &paciente){
    codigo = paciente.GetCodigo();
    estado = paciente.GetEstado();
    prima = paciente.GetPrima();
    fecha = paciente.GetFecha();
    char nomb[50];
    paciente.GetNombre(nomb);
    SetNombre(nomb);
}

ofstream & operator <<(ofstream &arch,const class Paciente &paciente){
    int aa,mm,dd;
    int fech = paciente.GetFecha();
    aa = fech/10000;
    fech %= 10000;
    mm = fech/100;
    dd = fech%100;
    arch<<setfill('0')<<right<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa
        <<setfill(' ')<<left<<"   "<<setw(10)<<paciente.GetCodigo();
}

