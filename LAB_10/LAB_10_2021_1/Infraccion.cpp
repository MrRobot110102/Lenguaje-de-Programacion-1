/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Infraccion.cpp
 * Author: Sebastian
 * 
 * Created on 26 de junio de 2023, 16:08
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Infraccion.h"

Infraccion::Infraccion() {
    gravedad = nullptr;
}

Infraccion::Infraccion(const Infraccion& orig) {
    gravedad = nullptr;
    *this = orig;
}

Infraccion::~Infraccion() {
    if(gravedad != nullptr) delete gravedad;
}

void Infraccion::SetMulta(double multa) {
    this->multa = multa;
}

double Infraccion::GetMulta() const {
    return multa;
}

void Infraccion::SetGravedad(const char *grav) {
    if(gravedad != nullptr) delete gravedad;
    gravedad = new char[strlen(grav) + 1];
    strcpy(gravedad,grav);
}

void Infraccion::GetGravedad(char *grav) const {
    if(gravedad == nullptr) grav[0] = 0;
    else strcpy(grav,gravedad);
}

void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Infraccion::GetCodigo() const {
    return codigo;
}

void Infraccion::imprimir(ofstream &arch){
    char grav[100];
    GetGravedad(grav);
    arch<<setw(12)<<left<<grav<<setw(10)<<right<<GetMulta();
}

