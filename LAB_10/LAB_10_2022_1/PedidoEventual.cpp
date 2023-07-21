/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   PedidoEventual.cpp
 * Author: Sebastian
 * 
 * Created on 23 de junio de 2023, 22:08
 */

#include "PedidoEventual.h"

void PedidoEventual::SetFlete(double flete) {
    this->flete = flete;
}

double PedidoEventual::GetFlete() const {
    return flete;
}

void PedidoEventual::lee(ifstream &arch){
    char car;
    arch>>flete>>car;
    Pedido::lee(arch);
    SetTotal(GetTotal() * (1 + (GetFlete()/100)));
}

void PedidoEventual::imprime(ofstream &arch){
    Pedido::imprime(arch);
    arch<<left<<setw(15)<<"Flete:"<<right<<setw(10)<<GetFlete()<<'%'<<endl;
}

void PedidoEventual::exonerarFlete(){
    SetTotal(GetTotal()/(1 + (GetFlete()/100)));
    SetFlete(0.0);
}
