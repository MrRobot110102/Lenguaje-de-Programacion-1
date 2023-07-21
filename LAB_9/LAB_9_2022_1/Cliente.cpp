/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Cliente.cpp
 * Author: Sebastian
 * 
 * Created on 13 de junio de 2023, 17:51
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Cliente.h"

Cliente::Cliente() {
    nombre = nullptr;
    cantped = 0;
    totalped = 0;
}

Cliente::~Cliente() {
    if(nombre != nullptr) delete nombre;
}

void Cliente::SetTotalped(double totalped) {
    this->totalped = totalped;
}

double Cliente::GetTotalped() const {
    return totalped;
}

void Cliente::SetCantped(int cantped) {
    this->cantped = cantped;
}

int Cliente::GetCantped() const {
    return cantped;
}

void Cliente::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void Cliente::GetNombre(char* nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb,nombre);
}

void Cliente::SetCategoria(char categoria) {
    this->categoria = categoria;
}

char Cliente::GetCategoria() const {
    return categoria;
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::imprimeLinea(ofstream &arch,int cantidad,char car){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}

void Cliente::lee(ifstream &arch){
    int dato;
    char nomb[100];
    arch>>dato;
    arch.get();
    arch.getline(nomb,100);
    SetDni(dato);
    SetNombre(nomb);
}

void Cliente::imprime(ofstream &arch){
    char nomb[200];
    GetNombre(nomb);
    arch<<left<<setw(10)<<GetDni()<<nomb<<endl;
    imprimeLinea(arch,50,'-');
}
