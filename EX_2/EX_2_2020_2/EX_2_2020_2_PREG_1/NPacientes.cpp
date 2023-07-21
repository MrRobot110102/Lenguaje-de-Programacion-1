/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPacientes.cpp
 * Author: Sebastian
 * 
 * Created on 3 de julio de 2023, 19:11
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "NPacientes.h"
#include "Ambulatorio.h"
#include "Emergencia.h"
#include "Urgencia.h"

NPacientes::NPacientes() {
    ppaciente = nullptr;
}

NPacientes::NPacientes(const NPacientes& orig) {
    *this = orig;
}

void NPacientes::operator =(const NPacientes &pac){
    ppaciente = pac.ppaciente;
}

void NPacientes::leer(ifstream& arch) {
    char tipo;
    arch>>tipo;
    if(arch.eof()) return;
    arch.get();
    if(tipo == 'A') ppaciente = new class Ambulatorio;
    else if(tipo == 'U') ppaciente = new class Urgencia;
    else if(tipo == 'E') ppaciente = new class Emergencia;
    ppaciente->leer(arch);
    //cout<<tipo<<"    "<<ppaciente->GetDni()<<endl;
}

int NPacientes::estaActivo() {
    return ppaciente != nullptr;
}

int NPacientes::getDni() {
    return ppaciente->GetDni();
}

bool NPacientes::operator <(const NPacientes& pac) {
    return ppaciente->prioridad() > pac.ppaciente->prioridad();
}

void NPacientes::operator=(Paciente* pac) {
    ppaciente = pac;
}

void NPacientes::imprimir(ofstream& arch) {
    char obs[100];
    ppaciente->imprimir(arch);
    ppaciente->observacion(obs);
    arch<<left<<setw(30)<<obs;
    if(not ppaciente->imprimirReferencia(arch)) arch<<endl;
}

void NPacientes::actualizarCantidades(int& numRiesgo, int& numMenoresEdad) {
    char obs[100];
    ppaciente->observacion(obs);
    if(strcmp(obs,"Persona de Riesgo") == 0) numRiesgo++;
    else if(strcmp(obs,"Debe venir con su apoderado") == 0) numMenoresEdad++;
}





