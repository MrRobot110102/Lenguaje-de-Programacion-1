/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClienteA.cpp
 * Author: Sebastian
 * 
 * Created on 13 de junio de 2023, 17:52
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "ClienteA.h"

ClienteA::ClienteA() {
    descuento = 0.0;
}

ClienteA::~ClienteA() {
}

void ClienteA::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double ClienteA::GetDescuento() const {
    return descuento;
}

void ClienteA::lee(ifstream &arch){
    double descuento;
    char car;
    arch>>descuento>>car;
    SetCategoria('A');
    SetDescuento(descuento);
    Cliente::lee(arch);
}

void ClienteA::imprime(ofstream &arch){
    Cliente::imprime(arch);
    arch<<"Descuento: "<<GetDescuento()<<'%'<<endl;
    arch<<"Total: "<<GetTotalped()<<endl;
    arch<<"Cantidad de Pedidos: "<<GetCantped()<<endl<<endl<<endl;
}

void ClienteA::calcula(){
    SetTotalped(GetTotalped() * (1 - (GetDescuento()/100)));
}

