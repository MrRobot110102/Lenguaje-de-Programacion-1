/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Falta.cpp
 * Author: Sebastian
 * 
 * Created on 26 de junio de 2023, 16:09
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Falta.h"

Falta::Falta() {
    placa = nullptr;
}

Falta::Falta(const Falta& orig) {
    placa = nullptr;
    *this = orig;
}

Falta::~Falta() {
    if(placa != nullptr) delete placa;
}

void Falta::SetPlaca(char *plac) {
    if(placa != nullptr) delete placa;
    placa = new char[strlen(plac) + 1];
    strcpy(placa,plac);
}

void Falta::GetPlaca(char *plac) const {
    if(placa == nullptr) plac[0] = 0;
    else strcpy(plac,placa);
}

void Falta::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Falta::GetFecha() const {
    return fecha;
}

void Falta::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Falta::GetLicencia() const {
    return licencia;
}

void Falta::operator =(const class Falta &fal){
    char plac[100];
    SetFecha(fal.GetFecha());
    SetLicencia(fal.GetLicencia());
    fal.GetPlaca(plac);
    SetPlaca(plac);
}

void Falta::leer(ifstream &arch){
    int licen,dd,mm,aa,codigo;
    char plac[100],car;
    arch>>licen;
    if(arch.eof()) return;
    arch>>car;
    arch.getline(plac,100,',');
    arch>>dd>>car>>mm>>car>>aa>>car;
    SetLicencia(licen);
    SetFecha(aa * 10000 + mm * 100 + dd);
    SetPlaca(plac);
}

ofstream & operator <<(ofstream &arch,const class Falta &fal){
    int dd,mm,aa;
    int fech = fal.GetFecha();
    dd=fech%100;
    fech/=100;
    mm=fech%100;
    aa=fech/100;
    arch<<setfill('0')<<setw(4)<<right<<aa<<"/"<<setw(2)<<right<<mm<<"/"<<setw(2)<<right<<dd<<setfill(' ');
    char plac[100];
    fal.GetPlaca(plac);
    arch<<"  "<<setw(12)<<left<<fal.GetLicencia()<<setw(15)<<left<<plac;
}

