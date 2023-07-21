/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   medicamento.cpp
 * Author: Sebastian
 * 
 * Created on 9 de junio de 2023, 21:45
 */

#include <cstring>
#include "medicamento.h"

medicamento::medicamento() {
    nombre = nullptr;
    precio = 0.0;
}

medicamento::~medicamento() {
    if(nombre != nullptr) delete nombre; 
}

void medicamento::SetFecha(int fecha) {
    this->fecha = fecha;
}

int medicamento::GetFecha() const {
    return fecha;
}

void medicamento::SetPrecio(double precio) {
    this->precio = precio;
}

double medicamento::GetPrecio() const {
    return precio;
}

void medicamento::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int medicamento::GetCantidad() const {
    return cantidad;
}

void medicamento::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void medicamento::GetNombre(char *nomb) const {
    if(nombre == nullptr) nomb[0] = 0;
    else strcpy(nomb,nombre);
}

void medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medicamento::GetCodigo() const {
    return codigo;
}

