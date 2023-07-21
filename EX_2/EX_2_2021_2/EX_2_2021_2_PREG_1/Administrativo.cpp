/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Administrativo.cpp
 * Author: Sebastian
 * 
 * Created on 30 de junio de 2023, 23:37
 */

#include <cstring>

#include "Administrativo.h"

Administrativo::Administrativo() {
    area = nullptr;
}

Administrativo::~Administrativo() {
    if(area != nullptr) delete area;
}

void Administrativo::SetArea(char *are) {
    if(area != nullptr) delete area;
    area = new char[strlen(are) + 1];
    strcpy(area,are);
}

void Administrativo::GetArea(char *are) const {
    if(area == nullptr) are[0] = 0;
    else strcpy(are,area);
}

void Administrativo::leer(ifstream& arch) {
    char nomb[100],area[100];
    arch.getline(nomb,100,',');
    arch.getline(area,100);
    SetNombre(nomb);
    SetArea(area);
    SetTipo('A');
}

void Administrativo::imprime(ofstream& arch) {
    char area[20];
    Usuario::imprime(arch);
    GetArea(area);
    arch<<"Area:"<<area<<endl<<endl;
}



