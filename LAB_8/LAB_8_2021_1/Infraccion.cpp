/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Infraccion.cpp
 * Author: Sebastian
 * 
 * Created on 11 de junio de 2023, 13:26
 */

#include <cstring>
#include "Infraccion.h"

Infraccion::Infraccion() {
    gravedad = nullptr;
    codigo = 0;
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

