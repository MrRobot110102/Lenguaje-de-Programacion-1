/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PedidoEspecial.cpp
 * Author: Sebastian
 * 
 * Created on 23 de junio de 2023, 22:05
 */

#include "PedidoEspecial.h"

void PedidoEspecial::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double PedidoEspecial::GetDescuento() const {
    return descuento;
}

void PedidoEspecial::lee(ifstream &arch){
    char car;
    arch>>descuento>>car;
    Pedido::lee(arch);
    SetTotal(GetTotal() * (1 - GetDescuento()/100));
}

void PedidoEspecial::imprime(ofstream &arch){
    Pedido::imprime(arch);
    arch<<left<<setw(15)<<"Descuento:"<<right<<setw(10)<<GetDescuento()<<'%'<<endl;
}

void PedidoEspecial::exonerarFlete(){
    
}