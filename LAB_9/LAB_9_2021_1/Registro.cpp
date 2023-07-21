/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Registro.cpp
 * Author: Sebastian
 * 
 * Created on 17 de junio de 2023, 14:26
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Registro.h"
#include "Leve.h"
#include "Grave.h"
#include "MuyGrave.h"

Registro::Registro() {
    pfalta = nullptr;
}

Registro::~Registro() {
    if(pfalta != nullptr) delete pfalta;
}

void Registro::asignaRegistro(int codInfraccion){
    ifstream arch("Infracciones.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: NO se puede abrir el archivo Infracciones.csv"<<endl;
        exit(1);
    }
    if(codInfraccion/100 == 2) pfalta = new class Leve;
    else if(codInfraccion/100 == 1) pfalta = new class Grave;
    else if(codInfraccion/100 == 3) pfalta = new class MuyGrave;
    pfalta->SetCodigo(codInfraccion);
    pfalta->lee(arch,codInfraccion);
}

void Registro::operator =(class Infraccion *pt){
    pfalta = pt;
}

int Registro::validarRegistro(){
    return pfalta != nullptr;
}

void Registro::imprimir(ofstream &arch){
    pfalta->imprime(arch);
}

void Registro::aplicarDescuentos(){
    pfalta->aplica();
}

void Registro::acumularMontos(double &montoMulta,int &puntosPerdidos,int &mesesSancionados){
    pfalta->acumula(montoMulta,puntosPerdidos,mesesSancionados);
}


