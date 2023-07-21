/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   sinreceta.cpp
 * Author: Sebastian
 * 
 * Created on 16 de junio de 2023, 21:50
 */
#include <cstring>
#include "sinreceta.h"

sinreceta::sinreceta() {
    nombre = nullptr;
}

sinreceta::~sinreceta() {
    if(nombre != nullptr) delete nombre;
}

void sinreceta::SetNombre(char *nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void sinreceta::GetNombre(char *nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb,nombre);
}

void sinreceta::SetDni(int dni) {
    this->dni = dni;
}

int sinreceta::GetDni() const {
    return dni;
}

void sinreceta::leemedicamento(ifstream &arch,int codMed){
    int codigoMedico,dni;
    char car,nomb[500];
    medicamento::leemedicamento(arch,codMed);
    arch>>codigoMedico>>car>>dni>>car;
    arch.getline(nomb,500);
    SetDni(dni);
    sinreceta::SetNombre(nomb);
}

void sinreceta::imprimedicamento(ofstream &arch){
    char nomb[100];
    medicamento::imprimedicamento(arch);
    sinreceta::GetNombre(nomb);
    arch<<setw(12)<<GetDni()<<setw(30)<<nomb<<endl;
}

void sinreceta::aplicadescuento(){
    medicamento::aplicadescuento();
    SetTotal(GetTotal() * 0.90);
}

