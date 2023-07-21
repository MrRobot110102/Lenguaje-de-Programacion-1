/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Sebastian
 * 
 * Created on 27 de junio de 2023, 20:37
 */

#include "Pedido.h"

Pedido::Pedido() {
    subTotal = 0.0;
}

Pedido::Pedido(const Pedido& orig) {
    subTotal = 0.0;
    *this = orig;
}

void Pedido::SetSubTotal(double subTotal) {
    this->subTotal = subTotal;
}

double Pedido::GetSubTotal() const {
    return subTotal;
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetCantidad(double cantidad) {
    this->cantidad = cantidad;
}

double Pedido::GetCantidad() const {
    return cantidad;
}

void Pedido::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Pedido::GetCodigo() const {
    return codigo;
}

int Pedido::leerDatos(ifstream &arch){
    char car;
    int dni,dd,mm,aa;
    arch>>cantidad>>car>>dni>>car>>dd>>car>>mm>>car>>aa;
    SetFecha(aa * 10000 + mm * 100 + dd);
    return dni;
}

void Pedido::imprimirDatos(ofstream &arch){
    arch.precision(2);arch<<fixed;
    int dd,mm,aa;
    int fech = GetFecha();
    dd=fech%100;
    fech/=100;
    mm=fech%100;
    aa=fech/100;
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)<<right<<aa<<setfill(' ')
        <<setw(10)<<GetCodigo()<<setw(10)<<GetCantidad()<<setw(10)<<GetSubTotal()<<endl;
}

bool Pedido::operator <(const class Pedido& ped) {
    return GetFecha() < ped.GetFecha();
}

void Pedido::operator=(const class Pedido& ped) {
    SetCodigo(ped.GetCodigo());
    SetCantidad(ped.GetCantidad());
    SetFecha(ped.GetFecha());
    SetSubTotal(ped.GetSubTotal());
}

