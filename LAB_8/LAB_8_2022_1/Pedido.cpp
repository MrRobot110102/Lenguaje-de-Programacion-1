/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Sebastian
 * 
 * Created on 9 de junio de 2023, 19:15
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Pedido.h"

Pedido::Pedido() {
    obs = nullptr;
    total = 0.0;
}

Pedido::~Pedido() {
    if(obs != nullptr) delete obs;
}

void Pedido::SetObs(const char* observacion) {
    if(obs != nullptr) delete obs;
    obs = new char[strlen(observacion)+1];
    strcpy(obs,observacion);
}

void Pedido::GetObs(char *observacion) const {
    if(obs==nullptr) observacion[0]=0;
    else strcpy(observacion,obs);
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

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

