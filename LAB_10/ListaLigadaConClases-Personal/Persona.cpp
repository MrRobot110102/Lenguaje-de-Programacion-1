/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Persona.cpp
 * Author: Sebastian
 * 
 * Created on 17 de junio de 2023, 20:32
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Persona.h"

Persona::Persona() {
    nombre = nullptr;
}

 Persona::Persona(const Persona& orig){
    nombre = nullptr;
    *this = orig;
 }

Persona::~Persona() {
    if(nombre != nullptr) delete nombre;
}

void Persona::SetSueldo(double sueldo) {
    this->sueldo = sueldo;
}

double Persona::GetSueldo() const {
    return sueldo;
}

void Persona::SetNombre(char *nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void Persona::GetNombre(char *nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    strcpy(nomb,nombre);
}

void Persona::SetDni(int dni) {
    this->dni = dni;
}

int Persona::GetDni() const {
    return dni;
}

void Persona::operator =(const class Persona &per){
    char nomb[100];
    SetDni(per.GetDni());
    SetSueldo(per.GetSueldo());
    per.GetNombre(nomb);
    SetNombre(nomb);
}

bool Persona::operator >(const class Persona &per){
    //return GetDni() > per.GetDni();
    char nomb[100],nombCmp[100];
    GetNombre(nomb);
    per.GetNombre(nombCmp);
    return strcmp(nomb,nombCmp) > 0;
}

ifstream & operator >>(ifstream &arch,class Persona &per){
    char nomb[100];
    int dni;
    double sueldo;
    arch>>dni;
    if(arch.eof()) return arch;
    arch.get();
    arch.getline(nomb,100,',');
    arch>>sueldo;
    per.SetDni(dni);
    per.SetNombre(nomb);
    per.SetSueldo(sueldo);
    return arch;
}

ofstream & operator <<(ofstream &arch,const class Persona &per){
    char nomb[100];
    arch.precision(2);arch<<fixed;
    per.GetNombre(nomb);
    arch<<left<<setw(10)<<per.GetDni()<<setw(40)<<nomb<<right<<setw(12)<<per.GetSueldo()<<endl;
    return arch;
}
