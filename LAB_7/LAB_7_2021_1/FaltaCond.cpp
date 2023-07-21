/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   FaltaCond.cpp
 * Author: Sebastian
 * 
 * Created on 4 de junio de 2023, 14:46
 */

#include <cstring>

#include "FaltaCond.h"

FaltaCond::FaltaCond() {
    gravedad = nullptr;
    placa = nullptr;
}

FaltaCond::~FaltaCond() {
    if(gravedad != nullptr) delete gravedad;
    if(placa != nullptr) delete placa;
}

void FaltaCond::SetGravedad(char* grav) {
    if(gravedad != nullptr) delete gravedad;
    gravedad = new char[strlen(grav) + 1];
    strcpy(gravedad,grav);
}

void FaltaCond::GetGravedad(char *grav) const {
    if(gravedad == nullptr) gravedad[0] = 0;
    strcpy(grav,gravedad);
}

void FaltaCond::SetMulta(double multa) {
    this->multa = multa;
}

double FaltaCond::GetMulta() const {
    return multa;
}

void FaltaCond::SetCodInf(int codInf) {
    this->codInf = codInf;
}

int FaltaCond::GetCodInf() const {
    return codInf;
}

void FaltaCond::SetFecha(int fecha) {
    this->fecha = fecha;
}

int FaltaCond::GetFecha() const {
    return fecha;
}

void FaltaCond::SetPlaca(char* plac) {
    if(placa != nullptr) delete placa;
    placa = new char[strlen(plac) + 1];
    strcpy(placa,plac);
}

void FaltaCond::GetPlaca(char *plac) const {
    if(placa == nullptr) placa[0] = 0;
    strcpy(plac,placa);
}

