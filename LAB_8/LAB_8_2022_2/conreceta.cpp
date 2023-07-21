/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   conreceta.cpp
 * Author: Sebastian
 * 
 * Created on 9 de junio de 2023, 21:46
 */
#include <cstring>
#include "conreceta.h"

conreceta::conreceta() {
    especialidad = nullptr;
}

conreceta::~conreceta() {
    if(especialidad != nullptr) delete especialidad;
}

void conreceta::SetEspecialidad(char* espec) {
    if(especialidad != nullptr) delete especialidad;
    especialidad = new char[strlen(espec) + 1];
    strcpy(especialidad,espec);
}

void conreceta::GetEspecialidad(char *espec) const {
    if(especialidad == nullptr) espec[0] = 0;
    else strcpy(espec,especialidad);
}

void conreceta::SetCodmed(int codmed) {
    this->codmed = codmed;
}

int conreceta::GetCodmed() const {
    return codmed;
}

