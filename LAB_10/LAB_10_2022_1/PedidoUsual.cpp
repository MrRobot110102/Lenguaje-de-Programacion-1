/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PedidoUsual.cpp
 * Author: Sebastian
 * 
 * Created on 23 de junio de 2023, 22:07
 */

#include "PedidoUsual.h"

void PedidoUsual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoUsual::GetFlete() const {
    return flete;
}

void PedidoUsual::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoUsual::GetDescuento() const {
    return descuento;
}

void PedidoUsual::lee(ifstream &arch){
    char car;
    arch>>descuento>>car>>flete>>car;
    Pedido::lee(arch);
    SetTotal(GetTotal() * (1 - (GetDescuento()/100) + (GetFlete()/100)));
}

void PedidoUsual::imprime(ofstream &arch){
    Pedido::imprime(arch);
    arch<<left<<setw(15)<<"Descuento:"<<right<<setw(10)<<GetDescuento()<<'%'<<endl;
    arch<<left<<setw(15)<<"Flete:"<<right<<setw(10)<<GetFlete()<<'%'<<endl;
}

void PedidoUsual::exonerarFlete(){
    SetTotal(GetTotal() / (1 + (GetFlete()/100)));
    SetFlete(0.0);
}

