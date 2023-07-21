/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClienteB.cpp
 * Author: Sebastian
 * 
 * Created on 13 de junio de 2023, 17:53
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "ClienteB.h"

ClienteB::ClienteB() {
    descuento = 0.0;
    flete = 0.0;
}

ClienteB::~ClienteB() {
}

void ClienteB::SetFlete(double flete) {
    this->flete = flete;
}

double ClienteB::GetFlete() const {
    return flete;
}

void ClienteB::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double ClienteB::GetDescuento() const {
    return descuento;
}

void ClienteB::lee(ifstream &arch){
    double descuento,flete;
    char car;
    arch>>descuento>>car>>flete>>car;
    SetCategoria('B');
    SetDescuento(descuento);
    SetFlete(flete);
    Cliente::lee(arch);
}

void ClienteB::imprime(ofstream &arch){
    Cliente::imprime(arch);
    arch<<"Descuento: "<<GetDescuento()<<'%'<<"   "<<"Flete: "<<GetFlete()<<'%'<<endl;
    arch<<"Total: "<<GetTotalped()<<endl;
    arch<<"Cantidad de Pedidos: "<<GetCantped()<<endl<<endl<<endl;
}

void ClienteB::calcula(){
    SetTotalped(GetTotalped() * (1-(GetDescuento()/100) + (GetFlete()/100)));
}
