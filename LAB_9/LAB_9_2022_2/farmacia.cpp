/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   farmacia.cpp
 * Author: Sebastian
 * 
 * Created on 16 de junio de 2023, 21:50
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "farmacia.h"

void farmacia::leerecetas(){
    ifstream arch("recetas2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo recetas2.csv"<<endl;
        exit(1);
    }
    int numRecetas = 0;
    while(true){
        loferta[numRecetas].asignaReceta(arch);
        if(arch.eof()) break;
        numRecetas++;
    }
    loferta[numRecetas] = nullptr;
}
    
void farmacia::descuenta(){
    for (int i = 0; loferta[i].validaReceta(); i++) loferta[i].aplicarDescuento();
}
    
void farmacia::imprimirecetas(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    arch.precision(2);arch<<fixed;
    arch<<right<<setw(65)<<"REPORTE DE DEUDAS"<<endl;
    imprimirLinea(arch,150,'=');
    imprimirLinea(arch,150,'=');
    for (int i = 0; loferta[i].validaReceta(); i++) loferta[i].imprimir(arch);
}

void farmacia::imprimirLinea(ofstream &arch,int cantidad,char car){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}

