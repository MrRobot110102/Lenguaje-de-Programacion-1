/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   MuyGrave.cpp
 * Author: Sebastian
 * 
 * Created on 26 de junio de 2023, 16:09
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "MuyGrave.h"

void MuyGrave::SetMeses(int meses) {
    this->meses = meses;
}

int MuyGrave::GetMeses() const {
    return meses;
}

void MuyGrave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int MuyGrave::GetPuntos() const {
    return puntos;
}

void MuyGrave::lee(int codInfraccion){
    ifstream arch("Infracciones.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Infracciones.csv"<<endl;
        exit(1);
    }
    int codigo,meses,puntos;
    char desc[500],car;
    double monto;
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        arch.get();
        if(codigo == codInfraccion){
            arch.getline(desc,500,',');
            arch.getline(desc,500,',');
            arch>>monto>>car>>puntos>>car>>meses;
            SetCodigo(codigo);
            SetPuntos(puntos);
            SetMeses(meses);
            SetGravedad("MUY GRAVE");
            SetMulta(monto);
        }else arch.getline(desc,500,'\n');
    }
}

void MuyGrave::imprimir(ofstream &arch){
    arch.precision(2);arch<<fixed;
    Infraccion::imprimir(arch);
    arch<<setw(10)<<right<<0.0<<setw(10)<<right<<GetPuntos()<<setw(10)<<right<<GetMeses()<<endl;
}
