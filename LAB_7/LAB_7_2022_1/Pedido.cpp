/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClasePedido.cpp
 * Author: Sebastian
 * 
 * Created on 31 de mayo de 2023, 22:46
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Pedido.h"

Pedido::Pedido() {
    nombre = nullptr;
}

Pedido::Pedido(const class Pedido &obj) {
    char n[100];
    obj.GetNombre(n);
    SetCodigo(obj.GetCodigo());
    SetNombre(n);
    SetCantidad(obj.GetCantidad());
    SetPrecio(obj.GetPrecio());
    SetDni(obj.GetDni());
    SetFecha(obj.GetFecha());
}

Pedido::~Pedido() {
    if(nombre != nullptr) delete nombre;
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

void Pedido::SetPrecio(double precio) {
    this->precio = precio;
}

double Pedido::GetPrecio() const {
    return precio;
}

void Pedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre,nomb);
}

void Pedido::GetNombre(char *nomb) const {
    if(nombre==nullptr) nomb[0]=0;
    strcpy(nomb,nombre);
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

void Pedido::operator = (const class Pedido &c){
    cantidad = c.GetCantidad();
    codigo = c.GetCodigo();
    dni = c.GetDni();
    fecha = c.GetFecha();
    char cadena[50];
    c.GetNombre(cadena);
    SetNombre(cadena);
    precio = c.GetPrecio();
}

