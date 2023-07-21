/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Producto.cpp
 * Author: Sebastian
 * 
 * Created on 9 de junio de 2023, 19:15
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Producto.h"

Producto::Producto() {
    nombre = nullptr;
    stock = 0;
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

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void Producto::GetNombre(char *nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    strcpy(nomb,nombre);
}

void Producto::SetCodprod(int codprod) {
    this->codprod = codprod;
}

int Producto::GetCodprod() const {
    return codprod;
}

