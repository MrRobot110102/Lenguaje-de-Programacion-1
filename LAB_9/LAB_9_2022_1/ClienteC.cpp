/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   ClienteC.cpp
 * Author: Sebastian
 * 
 * Created on 13 de junio de 2023, 17:53
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "ClienteC.h"

ClienteC::ClienteC() {
    flete = 0.0;
}

ClienteC::~ClienteC() {
}

void ClienteC::SetFlete(double flete) {
    this->flete = flete;
}

double ClienteC::GetFlete() const {
    return flete;
}

void ClienteC::lee(ifstream &arch){
    double flete;
    char car;
    arch>>flete>>car;
    SetCategoria('C');
    SetFlete(flete);
    Cliente::lee(arch);
}

void ClienteC::imprime(ofstream &arch){
    Cliente::imprime(arch);
    arch<<"Flete: "<<GetFlete()<<'%'<<endl;
    arch<<"Total: "<<GetTotalped()<<endl;
    arch<<"Cantidad de Pedidos: "<<GetCantped()<<endl<<endl<<endl;
}

void ClienteC::calcula(){
    SetTotalped(GetTotalped() * (1 + (GetFlete()/100)));
}

