/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: Sebastian
 * 
 * Created on 27 de junio de 2023, 23:04
 */

#include "Pedido.h"

void Pedido::SetOrden(int orden) {
    this->orden = orden;
}

int Pedido::GetOrden() const {
    return orden;
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

void Pedido::imprime(ofstream& arch) {
    int dd,mm,aa;
    int f = fecha;
    aa = f/10000;
    f %= 10000;
    mm = f/100;
    dd = f%100;
    arch.precision(2);arch<<fixed;
    arch<<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa<<setfill(' ');
    arch<<setw(10)<<codigo<<setw(10)<<cantidad<<setw(10)<<total;
    if(orden==0) arch<<setw(10)<<"No"<<endl;
    else arch<<setw(10)<<"Si"<<endl;
}

void Pedido::leer(ifstream& arch) {
    int dd,mm,aa;
    char car;
    arch>>codigo;
    if(arch.eof()) return;
    arch>>car>>cantidad>>car>>total>>car>>dni>>car>>dd>>car>>mm>>car>>aa;
    SetFecha(aa * 10000 + mm * 100 + dd);
}



