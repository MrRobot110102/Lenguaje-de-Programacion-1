/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.cpp
 * Author: Sebastian
 * 
 * Created on 27 de junio de 2023, 23:04
 */

#include <cstring>

#include "Producto.h"

Producto::Producto() {
    nombre = nullptr;
}

Producto::Producto(const Producto& orig) {
    nombre = nullptr;
    *this = orig;
}

Producto::~Producto() {
    if(nombre != nullptr) delete nombre;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetNombre(char *nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void Producto::GetNombre(char *nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb,nombre);
}

void Producto::SetCodprod(int codprod) {
    this->codprod = codprod;
}

int Producto::GetCodprod() const {
    return codprod;
}

void Producto::leer(ifstream& arch) {
    char car,nomb[100];
    arch>>codprod>>car;
    arch.getline(nomb,100,',');
    arch>>stock;
    SetNombre(nomb);
    //cout<<codprod<<'-'<<nomb<<endl;
}

void Producto::imprime(ofstream& arch) {
    char nomb[100];
    GetNombre(nomb);
    arch<<left<<setw(20)<<GetCodprod()<<setw(50)<<nomb<<GetStock()<<endl;
}

void Producto::operator=(const Producto& orig) {
    char nomb[100];
    SetCodprod(orig.GetCodprod());
    SetStock(orig.GetStock());
    orig.GetNombre(nomb);
    SetNombre(nomb);
}


