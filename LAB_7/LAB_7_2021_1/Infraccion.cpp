/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Infraccion.cpp
 * Author: Sebastian
 * 
 * Created on 4 de junio de 2023, 14:46
 */

#include <cstring>

#include "Infraccion.h"

Infraccion::Infraccion() {
    descripcion = nullptr;
    gravedad = nullptr;
}

Infraccion::~Infraccion() {
    if(gravedad != nullptr) delete gravedad;
    if(descripcion != nullptr) delete descripcion;
}

void Infraccion::SetMulta(double multa) {
    this->multa = multa;
}

double Infraccion::GetMulta() const {
    return multa;
}

void Infraccion::SetGravedad(char* grav) {
    if(gravedad != nullptr) delete gravedad;
    gravedad = new char[strlen(grav) + 1];
    strcpy(gravedad,grav);
}

void Infraccion::GetGravedad(char *grav) const {
    if(gravedad == nullptr) gravedad[0] = 0;
    strcpy(grav,gravedad);
}

void Infraccion::SetDescripcion(char* desc) {
    if(descripcion != nullptr) delete descripcion;
    descripcion = new char[strlen(desc) + 1];
    strcpy(descripcion,desc);
}

void Infraccion::GetDescripcion(char *desc) const {
    if(descripcion == nullptr) descripcion[0] = 0;
    strcpy(desc,descripcion);
}

void Infraccion::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Infraccion::GetCodigo() const {
    return codigo;
}

