/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Estudiante.cpp
 * Author: Sebastian
 * 
 * Created on 30 de junio de 2023, 23:38
 */

#include "Estudiante.h"

void Estudiante::SetCelular(int celular) {
    this->celular = celular;
}

int Estudiante::GetCelular() const {
    return celular;
}

void Estudiante::leer(ifstream& arch) {
    char nomb[100];
    arch.getline(nomb,100,',');
    arch>>celular;
    SetNombre(nomb);
    SetTipo('E');
}

void Estudiante::imprime(ofstream& arch) {
    Usuario::imprime(arch);
    arch<<"Celular:"<<GetCelular()<<endl<<endl;
}

