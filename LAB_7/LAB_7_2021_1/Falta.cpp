/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Falta.cpp
 * Author: Sebastian
 * 
 * Created on 4 de junio de 2023, 14:46
 */
#include <cstring>
#include "Falta.h"

Falta::Falta() {
    placa = nullptr;
}

Falta::~Falta() {
    if(placa != nullptr) delete placa;
}

void Falta::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Falta::GetFecha() const {
    return fecha;
}

void Falta::SetCodInf(int codInf) {
    this->codInf = codInf;
}

int Falta::GetCodInf() const {
    return codInf;
}

void Falta::SetPlaca(char* plac) {
    if(placa != nullptr) delete placa;
    placa = new char[strlen(plac) + 1];
    strcpy(placa,plac);
}

void Falta::GetPlaca(char* plac) const {
    if(placa == nullptr) placa[0] = 0;
    strcpy(plac,placa);
}

void Falta::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Falta::GetLicencia() const {
    return licencia;
}

