/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Sebastian
 * 
 * Created on 23 de junio de 2023, 22:01
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Pedido.h"

Pedido::Pedido() {
    nombre = nullptr;
}

Pedido::Pedido(const Pedido& orig) {
    nombre = nullptr;
    *this = orig;
}

Pedido::~Pedido() {
    if(nombre != nullptr) delete nombre;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetDni(int dni) {
    this->dni = dni;
}

int Pedido::GetDni() const {
    return dni;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetNombre(char *nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void Pedido::GetNombre(char *nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb,nombre);
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::lee(ifstream &arch){
    int dd,mm,aa;
    char nomb[100],car;
    arch.getline(nomb,100,',');
    arch>>cantidad>>car>>total>>car>>dni>>car>>dd>>car>>mm>>car>>aa;
    SetNombre(nomb);
    SetFecha(aa * 10000 + mm * 100 + dd);
}

void Pedido::imprime(ofstream &arch){
    int dd,mm,aa;
    char nomb[100];
    int fecha = GetFecha();
    aa = fecha / 10000;
    fecha = fecha % 10000;
    mm = fecha /100;
    dd = fecha % 100;
    arch.precision(2);arch<<fixed;
    GetNombre(nomb);
    arch<<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa<<setfill(' ')<<endl;
    arch<<left<<setw(10)<<codigo<<nomb<<endl;
    arch<<left<<setw(15)<<"DNI:"<<right<<setw(10)<<dni<<endl;
    arch<<left<<setw(15)<<"Monto Total:"<<right<<setw(10)<<total<<endl;
}





