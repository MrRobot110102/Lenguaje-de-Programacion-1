/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   almacen.cpp
 * Author: Sebastian
 * 
 * Created on 29 de junio de 2023, 15:23
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "almacen.h"

void almacen::carga(int fecha, const char* nombProfesor) {
    ifstream arch("lotes.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo lotes.csv"<<endl;
        exit(1);
    }
    arbolalma.crear(arch,fecha,nombProfesor);
}

void almacen::actualiza(int fecha, const char* apellido) {
    arbolalma.actualizar(fecha,apellido);
}

void almacen::imprime() {
    ofstream arch("ReporteLotes.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReporteLotes.txt"<<endl;
        exit(1);
    }
    arbolalma.imprimir(arch);
}





