/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: Sebastian
 * 
 * Created on 1 de julio de 2023, 13:29
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Nodo.h"
#include "Nuevo.h"
#include "Antiguo.h"

Nodo::Nodo() {
    pcosto = nullptr;
}

Nodo::Nodo(const Nodo& orig) {
    *this = orig;
}

void Nodo::operator=(const class Nodo& nd) {
    chofer = nd.chofer;
    pcosto = nd.pcosto;
}

void Nodo::leer(ifstream& arch) {
    ifstream archRegistro("RegistroConsolidado.csv",ios::in);
    if(not archRegistro.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RegistroConsolidado.csv"<<endl;
        exit(1);
    }
    chofer.leer(arch);
    if(arch.eof()) return;
    if(chofer.GetLicencia()/10000000 >= 5) pcosto = new class Nuevo;
    else pcosto = new class Antiguo;
    pcosto->lee(archRegistro,chofer.GetLicencia());
}

void Nodo::imprimir(ofstream& arch) {
    chofer.imprimir(arch);
    pcosto->imprime(arch);
}

int Nodo::getLicencia() const{
    return chofer.GetLicencia();
}

bool Nodo::operator<(const Nodo& nd) {
    return getLicencia() < nd.getLicencia();
}




