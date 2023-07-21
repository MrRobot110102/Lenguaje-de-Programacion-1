/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Deudor.cpp
 * Author: Sebastian
 * 
 * Created on 13 de junio de 2023, 18:09
 */

#include "Deudor.h"
#include "ClienteA.h"
#include "ClienteB.h"
#include "ClienteC.h"

Deudor::Deudor() {
    Cdeudor = nullptr;
}

Deudor::~Deudor() {
    if(Cdeudor != nullptr) delete Cdeudor;
}

void Deudor::leer(ifstream &arch,char tipo){
    if(tipo == 'A') Cdeudor = new class ClienteA;
    else if(tipo == 'B') Cdeudor = new class ClienteB;
    else if(tipo == 'C') Cdeudor = new class ClienteC;
    Cdeudor->lee(arch);
}

int Deudor::obtenerDniDeudor(){
   return Cdeudor->GetDni();
}

void Deudor::imprimir(ofstream &arch){
    Cdeudor->imprime(arch);
}

void Deudor::calcular(){
    Cdeudor->calcula();
}

void Deudor::asignarMontosYCantidades(double monto,int cantidad){
    Cdeudor->SetCantped(cantidad);
    Cdeudor->SetTotalped(monto);
}

int Deudor::validaDeudor(){
   return Cdeudor != nullptr; 
}

void Deudor::operator =(class Cliente *pt){
    Cdeudor = pt;
}
