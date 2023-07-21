/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Urgencia.cpp
 * Author: Sebastian
 * 
 * Created on 3 de julio de 2023, 19:02
 */

#include "Urgencia.h"

void Urgencia::SetPorcUrgencia(double porcUrgencia) {
    this->porcUrgencia = porcUrgencia;
}

double Urgencia::GetPorcUrgencia() const {
    return porcUrgencia;
}

void Urgencia::SetPorcSeguro(double porcSeguro) {
    this->porcSeguro = porcSeguro;
}

double Urgencia::GetPorcSeguro() const {
    return porcSeguro;
}

void Urgencia::leer(ifstream& arch) {
    Paciente::leer(arch);
    arch>>porcSeguro;
    arch.get();
    arch>>porcUrgencia;
    arch.get();
}

int Urgencia::prioridad() {
    return 200 + GetEdad();
}

void Urgencia::imprimir(ofstream& arch) {
    Paciente::imprimir(arch);
}

void Urgencia::observacion(char* obs) {
    if(GetEdad() > 65) strcpy(obs,"Persona de Riesgo");
    else if(GetEdad() < 18) strcpy(obs,"Debe venir con su apoderado");
    else obs[0] = 0;
}

int Urgencia::imprimirReferencia(ofstream &arch) {
    return 0;
}






