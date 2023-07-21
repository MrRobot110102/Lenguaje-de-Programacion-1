/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boleta.cpp
 * Author: Sebastian
 * 
 * Created on 6 de julio de 2023, 23:22
 */

#include "Boleta.h"
#include "Presencial.h"
#include "Semipresencial.h"
#include "Virtual.h"

Boleta::Boleta() {
    pboleta = nullptr;
}

Boleta::~Boleta() {
    elimina();
}

void Boleta::escoger(char tipo) {
    if(tipo == 'P') pboleta = new class Presencial;
    else if(tipo == 'S') pboleta = new class Semipresencial;
    else if(tipo == 'V') pboleta = new class Virtual;
}

int Boleta::getCodigo() {
    return pboleta->GetCodigo();
}

void Boleta::leer(ifstream& arch) {
    pboleta->lee(arch);
}

void Boleta::imprimir(ofstream& arch) {
    pboleta->imprime(arch);
}

void Boleta::getDatosAlumno(int& cod, char* nomb, int& esca, double& cred, double& tot) {
    pboleta->getDatos(cod,nomb,esca,cred,tot);
}

void Boleta::setDatosAlumno(int cod, char* nomb, int esca, double cred, double tot) {
    pboleta->setDatos(cod,nomb,esca,cred,tot);
}

void Boleta::actualiza(int descuento,int num) {
    pboleta->actualiza(descuento,num);
}

void Boleta::elimina() {
    if(pboleta != nullptr) delete pboleta;
}









