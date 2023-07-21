/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Conductor.cpp
 * Author: Sebastian
 * 
 * Created on 4 de junio de 2023, 14:46
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Conductor.h"
#include "SobrecargaOperadores.h"
#include "FaltaCond.h"
#include "Falta.h"
using namespace std;

Conductor::Conductor() {
    nombre = nullptr;
    numFaltas = 0;
    montoTotal = 0.0;
}

Conductor::~Conductor() {
    if(nombre != nullptr) delete nombre;
}

void Conductor::SetMontoTotal(double montoTotal) {
    this->montoTotal = montoTotal;
}

double Conductor::GetMontoTotal() const {
    return montoTotal;
}

void Conductor::SetNumFaltas(int numFaltas) {
    this->numFaltas = numFaltas;
}

int Conductor::GetNumFaltas() const {
    return numFaltas;
}

void Conductor::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void Conductor::GetNombre(char *nomb) const {
    if(nombre == nullptr) nombre[0] = 0;
    strcpy(nomb,nombre);
}

void Conductor::SetLicencia(int licencia) {
    this->licencia = licencia;
}

int Conductor::GetLicencia() const {
    return licencia;
}

void Conductor::imprimeFaltas(ofstream &arch) const{
    for (int i = 0;i< GetNumFaltas(); i++){
        arch<<right<<setw(2)<<i+1<<')'<<left<<"   ";
        arch<<lfaltas[i];
    }
}

void Conductor::operator +(const class Falta &falta){
    char plac[15];
    falta.GetPlaca(plac);
    lfaltas[numFaltas].SetFecha(falta.GetFecha());
    lfaltas[numFaltas].SetCodInf(falta.GetCodInf());
    lfaltas[numFaltas].SetPlaca(plac);
    numFaltas++;
}

void Conductor::operator +(const class Infraccion &infraccion){
    for (int i = 0; i < GetNumFaltas(); i++) {
        if(lfaltas[i].GetCodInf() == infraccion.GetCodigo()){
            char grav[15];
            infraccion.GetGravedad(grav);
            lfaltas[i].SetMulta(infraccion.GetMulta());
            lfaltas[i].SetGravedad(grav);
        }
    }
}

void Conductor::operator ++(int a){
    SetMontoTotal(0.0);
    for (int i = 0;i< GetNumFaltas(); i++) montoTotal += lfaltas[i].GetMulta();
}

void Conductor::operator *(const int fecha){
    char grav[15];
    for (int i = 0;i< GetNumFaltas(); i++){
        lfaltas[i].GetGravedad(grav);
        if(lfaltas[i].GetFecha() < fecha){
            if(strcmp("Leve",grav) == 0) lfaltas[i].SetMulta(lfaltas[i].GetMulta()*0.50);
            if(strcmp("Grave",grav) == 0)lfaltas[i].SetMulta(lfaltas[i].GetMulta()*0.75);
            if(strcmp("Muy Grave",grav) == 0) lfaltas[i].SetMulta(lfaltas[i].GetMulta()*0.90);
        }
    }
}

