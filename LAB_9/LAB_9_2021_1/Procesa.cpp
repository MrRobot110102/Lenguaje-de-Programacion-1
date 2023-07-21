/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Procesa.cpp
 * Author: Sebastian
 * 
 * Created on 17 de junio de 2023, 14:26
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Procesa.h"

Procesa::Procesa() {
    cantidad = 0;
}

Procesa::~Procesa() {
}

void Procesa::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Procesa::GetCantidad() const {
    return cantidad;
}

void Procesa::leer(){
    ifstream arch("RegistroDeFaltas.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RegistroDeFaltas.csv"<<endl;
        exit(1);
    }
    int licencia,codInfraccion,dd,mm,aa;
    char car,plac[10],nomb[100];
    while(true){
        arch>>licencia;
        if(arch.eof()) break;
        arch>>car>>codInfraccion>>car>>dd>>car>>mm>>car>>aa>>car;
        arch.getline(plac,10);
        lregistro[cantidad].SetLicencia(licencia);
        lregistro[cantidad].SetPlaca(plac);
        lregistro[cantidad].SetFecha(aa * 10000 + mm * 100 + dd);
        if(buscarConductor(licencia,nomb)) lregistro[cantidad].SetNombre(nomb);
        lregistro[cantidad].asignaRegistro(codInfraccion);
        cantidad++;
    }
    lregistro[cantidad] = nullptr;
}

void Procesa::imprimir(){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    char plac[10],nomb[100];
    for (int i = 0; lregistro[i].validarRegistro(); i++) {
        lregistro[i].GetPlaca(plac);
        lregistro[i].GetNombre(nomb);
        arch<<left<<"Licencia: "<<lregistro[i].GetLicencia()<<endl;
        arch<<left<<"Nombre:   "<<nomb<<endl;
        arch<<left<<"Placa:    "<<plac<<endl;
        arch<<left<<"Fecha:    "<<lregistro[i].GetFecha()<<endl;
        lregistro[i].imprimir(arch);
        arch<<endl<<endl;
    }
}

int Procesa::buscarConductor(int licencia,char *nomb){
    ifstream arch("Conductores.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: NO se puede abrir el archivo Conductores.csv"<<endl;
        exit(1);
    }
    int licen;
    while(true){
        arch>>licen;
        if(arch.eof()) break;
        arch.get();
        arch.getline(nomb,100);
        if(licen == licencia) return 1;
    }
    return 0;
}

void Procesa::aplicar(){
    for (int i = 0; lregistro[i].validarRegistro(); i++) lregistro[i].aplicarDescuentos();
}
    
void Procesa::consolidar(){
    ifstream arch("sancionados.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: NO se puede abrir el archivo sancionados.csv"<<endl;
        exit(1);
    }
    ofstream archReporte("ReporteConsolidar.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReporteConsolidar.txt"<<endl;
        exit(1);
    }
    int licen,puntosPerdidos = 0,mesesSancionados = 0;
    double montoMulta = 0.0;
    char nomb[100];
    while(true){
        montoMulta = 0.0;
        puntosPerdidos = 0;
        mesesSancionados = 0;
        arch>>licen;
        if(arch.eof()) break;
        for (int i = 0; lregistro[i].validarRegistro(); i++)
            if(licen == lregistro[i].GetLicencia()){
                lregistro[i].GetNombre(nomb);
                lregistro[i].acumularMontos(montoMulta,puntosPerdidos,mesesSancionados);
            }
        archReporte<<"Conductor    : "<<nomb<<endl;
        archReporte<<"Licencia No. : "<<licen<<endl;
        archReporte<<"Monto de Multas  :"<<right<<setw(8)<<montoMulta<<endl;
        archReporte<<"Puntos perdidos  :"<<right<<setw(8)<<puntosPerdidos<<endl;
        archReporte<<"Meses sancionados:"<<right<<setw(8)<<mesesSancionados<<endl<<endl<<endl;
    }
}


