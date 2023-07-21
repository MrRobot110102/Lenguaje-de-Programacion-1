/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   paciente.cpp
 * Author: Sebastian
 * 
 * Created on 3 de junio de 2023, 22:21
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "paciente.h"
#include "SobrecargaOperadores.h"
using namespace std;

paciente::paciente() {
    dni = 0;
    nombre = nullptr;
    totalgastado = 0.0;
}

paciente::~paciente() {
    if(nombre != nullptr) delete nombre;
}

void paciente::SetTotalgastado(double totalgastado) {
    this->totalgastado = totalgastado;
}

double paciente::GetTotalgastado() const {
    return totalgastado;
}

void paciente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int paciente::GetTelefono() const {
    return telefono;
}

void paciente::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void paciente::GetNombre(char *nomb) const {
    if(nombre == nullptr) nombre[0] = 0;
    strcpy(nomb,nombre);
}

void paciente::SetDni(int dni) {
    this->dni = dni;
}

int paciente::GetDni() const {
    return dni;
}

void paciente::operator +=(const class cita &cit){
    int i = 0;
    for (i = 0; lcitas[i].GetDni(); i++);
    lcitas[i] = cit;
}

void paciente::imprimeCitas(ofstream &arch) const{
    for (int i = 0; lcitas[i].GetDni(); i++){
        arch<<right<<setw(2)<<i+1<<')'<<left<<"   ";
        arch<<lcitas[i];
    } 
}

void paciente::actualizaTarifas(const class medico *arrMedicos){
    for (int i = 0; lcitas[i].GetDni(); i++) lcitas[i]<=arrMedicos;
     
}

void paciente::operator ++(int a){
    for (int i = 0; lcitas[i].GetDni(); i++) totalgastado += lcitas[i].GetTarifa();
}