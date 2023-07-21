/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   medico.cpp
 * Author: Sebastian
 * 
 * Created on 9 de junio de 2023, 21:45
 */

#include <cstring>
#include "medico.h"

medico::medico() {
    especialidad = nullptr;
    nombre = nullptr;
}

medico::~medico() {
    if(especialidad != nullptr) delete especialidad;
    if(nombre != nullptr) delete nombre;
}

void medico::SetEspecialidad(char* espec) {
    if(especialidad != nullptr) delete especialidad;
    especialidad = new char[strlen(espec) + 1];
    strcpy(especialidad,espec);
}

void medico::GetEspecialidad(char *espec) const {
    if(especialidad == nullptr) espec[0] = 0;
    else strcpy(espec,especialidad);
}

void medico::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void medico::GetNombre(char *nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb,nombre);
}

void medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medico::GetCodigo() const {
    return codigo;
}

