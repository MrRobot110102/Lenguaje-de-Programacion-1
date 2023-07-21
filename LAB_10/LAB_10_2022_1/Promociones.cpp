/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Promociones.cpp
 * Author: Sebastian
 * 
 * Created on 23 de junio de 2023, 22:44
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Promociones.h"

void Promociones::leepedidos(){
    ifstream arch("pedidos5.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo pedidos5.csv"<<endl;
        exit(1);
    }
    Lpedidos.crearLista(arch);
}

void Promociones::actualizapedidos(){
    ifstream arch("promocion.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo promocion.csv"<<endl;
        exit(1);
    }
    Lpedidos.actualizarLista(arch);
}

void Promociones::imprimepedidos(){
    ofstream arch("reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo reporte.txt"<<endl;
        exit(1);
    }
    arch<<right<<setw(36)<<"REPORTE DE PROMOCIONES"<<endl;
    imprimeLinea(arch,'=',50);
    Lpedidos.imprimirLista(arch);
}

void Promociones::imprimeLinea(ofstream &arch, char c, int n) {
    for(int i=0; i<n; i++) arch.put(c);
    arch<<endl;
}

