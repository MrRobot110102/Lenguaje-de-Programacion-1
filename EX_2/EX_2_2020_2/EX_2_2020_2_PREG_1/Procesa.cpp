/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.cpp
 * Author: Sebastian
 * 
 * Created on 3 de julio de 2023, 19:12
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <list>
#include <iterator>
using namespace std;
#include "Procesa.h"

void Procesa::lee(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numPacientes = 0;
    while(true){
        lpacientes[numPacientes].leer(arch);
        if(arch.eof()) break;
        numPacientes++;
    }
    lpacientes[numPacientes] = nullptr;
    //cout<<numPacientes<<endl;
}

void Procesa::ordena() {
    list<NPacientes>listaPacientes;
    for (int i = 0; lpacientes[i].estaActivo(); i++) listaPacientes.push_back(lpacientes[i]);
    listaPacientes.sort();
    int i = 0;
    for (list<NPacientes>::iterator it = listaPacientes.begin();it != listaPacientes.end();it++,i++)    
        lpacientes[i] = (*it);
    lpacientes[i] = nullptr;
}

void Procesa::imprime(const char* nombArch) {
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int cantPacientes = 0,numRiesgo = 0,numMenoresEdad = 0;
    for (int i = 0; lpacientes[i].estaActivo(); i++){
        arch<<right<<setw(3)<<i+1<<')'<<"   ";
        lpacientes[i].imprimir(arch);
        lpacientes[i].actualizarCantidades(numRiesgo,numMenoresEdad);
        cantPacientes++;
    }
    arch<<"Pacientes:   "<<cantPacientes<<"   "<<"Personas de Riesgo:"<<numRiesgo<<endl;
    arch<<"Menores de Edad sin apoderado:   "<<numMenoresEdad<<endl;
}



