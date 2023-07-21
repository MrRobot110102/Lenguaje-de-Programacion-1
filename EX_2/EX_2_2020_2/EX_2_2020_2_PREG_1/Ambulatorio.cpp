/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ambulatorio.cpp
 * Author: Sebastian
 * 
 * Created on 3 de julio de 2023, 18:58
 */

#include "Ambulatorio.h"

void Ambulatorio::SetPorcSeguro(double porcSeguro) {
    this->porcSeguro = porcSeguro;
}

double Ambulatorio::GetPorcSeguro() const {
    return porcSeguro;
}

void Ambulatorio::leer(ifstream& arch) {
    Paciente::leer(arch);
    arch>>porcSeguro;
    arch.get();
}

int Ambulatorio::prioridad() {
    return 100 + GetEdad();
}

void Ambulatorio::imprimir(ofstream& arch) {
    Paciente::imprimir(arch);
}

void Ambulatorio::observacion(char* obs) {
    if(GetEdad() > 65) strcpy(obs,"Persona de Riesgo");
    else if(GetEdad() < 18) strcpy(obs,"Debe venir con su apoderado");
    else obs[0] = 0;
}

int Ambulatorio::imprimirReferencia(ofstream &arch) {
    return 0;
}






