/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   almacen.cpp
 * Author: Sebastian
 * 
 * Created on 25 de junio de 2023, 11:53
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "almacen.h"

void almacen::carga(){
    ifstream arch("medicamentos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo medicamentos.csv"<<endl;
        exit(1);
    }
    arbolalma.crear(arch);
}
    
void almacen::actualiza(){
    ifstream arch("recarga.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo recarga.csv"<<endl;
        exit(1);
    }
    arbolalma.actualizar(arch);
}
    
void almacen::imprime(){
    ofstream arch("reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo reporte.txt"<<endl;
        exit(1);
    }
    arbolalma.imprimir(arch);
}