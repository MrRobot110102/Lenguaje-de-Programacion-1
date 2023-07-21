/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Grave.cpp
 * Author: Sebastian
 * 
 * Created on 26 de junio de 2023, 16:09
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Grave.h"

void Grave::SetPuntos(int puntos) {
    this->puntos = puntos;
}

int Grave::GetPuntos() const {
    return puntos;
}

void Grave::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Grave::GetDescuento() const {
    return descuento;
}

void Grave::lee(int codInfraccion){
    ifstream arch("Infracciones.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Infracciones.csv"<<endl;
        exit(1);
    }
    int codigo,puntos;
    char desc[500],car;
    double monto,descuento;
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        arch.get();
        if(codigo == codInfraccion){
            arch.getline(desc,500,',');
            arch.getline(desc,500,',');
            arch>>monto>>car>>descuento>>car>>puntos;
            SetCodigo(codigo);
            SetPuntos(puntos);
            SetDescuento(descuento);
            SetGravedad("GRAVE");
            SetMulta(monto);
        }else arch.getline(desc,500,'\n');
    }
}

void Grave::imprimir(ofstream &arch){
    arch.precision(2);arch<<fixed;
    Infraccion::imprimir(arch);
    arch<<setw(10)<<right<<GetDescuento()<<setw(10)<<right<<GetPuntos()<<setw(10)<<right<<0<<endl;
}

