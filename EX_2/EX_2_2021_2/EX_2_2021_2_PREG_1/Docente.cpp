/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Docente.cpp
 * Author: Sebastian
 * 
 * Created on 30 de junio de 2023, 23:37
 */

#include "Docente.h"

void Docente::SetAnexo(int anexo) {
    this->anexo = anexo;
}

int Docente::GetAnexo() const {
    return anexo;
}

void Docente::leer(ifstream& arch) {
    char nomb[100];
    arch.getline(nomb,100,',');
    arch>>anexo;
    SetNombre(nomb);
    SetTipo('D');
}

void Docente::imprime(ofstream& arch) {
    Usuario::imprime(arch);
    arch<<"Anexo:"<<GetAnexo()<<endl<<endl;
}

