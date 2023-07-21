    /*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Persona.cpp
 * Author: Sebastian
 * 
 * Created on 20 de junio de 2023, 22:13
 */

#include <cstring>

#include "Persona.h"

Persona::Persona() {
    nombre = nullptr;
}

Persona::Persona(const Persona& orig) {
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
    else strcpy(nomb,nombre);
}

void Persona::SetDni(int dni) {
    this->dni = dni;
}

int Persona::GetDni() const {
    return dni;
}

void Persona::operator = (const class Persona &per){
    char nomb[100];
    per.GetNombre(nomb);
    SetDni(per.GetDni());
    SetNombre(nomb);
    SetSueldo(per.GetSueldo());
}

bool Persona::operator >(const class Persona &per){
    return dni<per.GetDni();
}

bool Persona::operator <(const class Persona &per) {
    //return GetDni() > per.GetDni();
    char nomb[100],nombCmp[100];
    GetNombre(nomb);
    per.GetNombre(nombCmp);
    return strcmp(nomb,nombCmp) < 0;
}

bool Persona::operator == (int dato){
    return GetDni() == dato;
}

ifstream & operator >>(ifstream &arch,class Persona &per){
    int dni;
    char nomb[100];
    double sueldo;
    arch>>dni;
    if(arch.eof()) return arch;
    arch.get();
    arch.getline(nomb,100,',');
    arch>>sueldo;
    per.SetDni(dni);
    per.SetSueldo(sueldo);
    per.SetNombre(nomb);
    return arch;
}

istream & operator >>(istream &arch,class Persona &per){
    int dni;
    char nomb[100];
    double sueldo;
    arch>>dni;
    if(arch.eof()) return arch;
    arch.get();
    arch.getline(nomb,100,',');
    arch>>sueldo;
    per.SetDni(dni);
    per.SetSueldo(sueldo);
    per.SetNombre(nomb);
    return arch;
}

ofstream & operator <<(ofstream &arch,const class Persona &per){
    char nomb[100];
    arch.precision(2);arch<<fixed;
    per.GetNombre(nomb);
    arch<<left<<setw(10)<<per.GetDni()<<setw(40)<<nomb<<right<<setw(10)<<per.GetSueldo();
    return arch;
}

ostream & operator <<(ostream &arch,const class Persona&per){
    char nombre[100];
    arch.precision(2);arch<<fixed;
    per.GetNombre(nombre);
    arch<<left<<setw(10)<<per.GetDni()<<setw(40)<<nombre
    <<right<<setw(10)<<per.GetSueldo()<<endl;
    return arch;
}

