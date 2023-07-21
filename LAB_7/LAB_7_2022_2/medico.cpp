/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   medico.cpp
 * Author: Sebastian
 * 
 * Created on 3 de junio de 2023, 22:21
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "medico.h"
using namespace std;

medico::medico() {
    codigo = 0;
    nombre = nullptr;   
}

medico::~medico() {
    if(nombre != nullptr) delete nombre;
}

void medico::SetTarifa(double tarifa) {
    this->tarifa = tarifa;
}

double medico::GetTarifa() const {
    return tarifa;
}

void medico::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void medico::GetNombre(char *nomb) const {
    if(nombre == nullptr) nombre[0] = 0;
    strcpy(nomb,nombre);
}

void medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medico::GetCodigo() const {
    return codigo;
}

