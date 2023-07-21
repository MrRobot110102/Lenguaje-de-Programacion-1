/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Procesa.cpp
 * Author: Sebastian
 * 
 * Created on 11 de junio de 2023, 13:27
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Procesa.h"

Procesa::Procesa(){
    cantidad = 0;
}

void Procesa::lee(){
    ifstream arch("RegistroDeFaltas.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RegistroDeFaltas.csv"<<endl;
        exit(1);
    }
    int licencia,codFalta,dd,mm,aa;
    char car,plac[10],nomb[100];
    while(true){
        arch>>licencia;
        if(arch.eof()) break;
        arch>>car>>codFalta>>car>>dd>>car>>mm>>car>>aa>>car;
        arch.getline(plac,10);
        lregistro[cantidad].SetLicencia(licencia);
        if(buscarConductor(licencia,nomb)) lregistro[cantidad].SetNombre(nomb);
        if(codFalta/100 == 1) lregistro[cantidad].agregarRegistroGrave(codFalta,plac,aa * 10000 + mm * 100 + dd);
        else if(codFalta/100 == 2) lregistro[cantidad].agregarRegistroLeve(codFalta,plac,aa * 10000 + mm * 100 + dd);
        else if(codFalta/100 == 3) lregistro[cantidad].agregarRegistroMuyGrave(codFalta,plac,aa * 10000 + mm * 100 + dd);
        cantidad++; 
    }
}

void Procesa::imprime(){
    ofstream archReporte("Reporte.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    char nomb[100];
    for (int i = 0; i < cantidad; i++) {
        lregistro[i].GetNombre(nomb);
        archReporte<<left<<setw(10)<<lregistro[i].GetLicencia()<<setw(45)<<nomb;
        lregistro[i].imprimirRegistro(archReporte);
    }

}

void Procesa::procesa(){
    ifstream arch("sancionados.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo sancionados.csv"<<endl;
        exit(1);
    }
    ofstream archReporte("ReporteProcesa.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReporteProcesa.txt"<<endl;
        exit(1);
    }
    int licencia,puntosPerdidos = 0,mesesSancionados = 0;
    char nomb[100];
    double montoMulta = 0.0;  
    while(true){
        puntosPerdidos = 0;
        mesesSancionados = 0;
        montoMulta = 0.0;
        arch>>licencia;
        if(arch.eof()) break;
        for (int i = 0; i < cantidad; i++)
            if(licencia == lregistro[i].GetLicencia()){
                lregistro[i].GetNombre(nomb);
                archReporte<<"Conductor    : "<<nomb<<endl;
                archReporte<<"Licencia No. : "<<lregistro[i].GetLicencia()<<endl;
                break;
            }
        imprimeLinea(archReporte,100,'-');
        procesarFaltas(licencia,montoMulta,puntosPerdidos,mesesSancionados);
        archReporte<<"Monto de Multas  :"<<right<<setw(8)<<montoMulta<<endl;
        archReporte<<"Puntos perdidos  :"<<right<<setw(8)<<puntosPerdidos<<endl;
        archReporte<<"Meses sancionados:"<<right<<setw(8)<<mesesSancionados<<endl<<endl<<endl;
    }
}

void Procesa::procesarFaltas(int licencia,double &montoMulta, int &puntosPerdidos, int &mesesSancionado){
    for (int i = 0; i < cantidad; i++)
        if(licencia == lregistro[i].GetLicencia())
            lregistro[i].procesaSanciones(montoMulta,puntosPerdidos,mesesSancionado);
}

int Procesa::buscarConductor(int licencia, char *nomb){
    ifstream arch("Conductores.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Conductores.csv"<<endl;
        exit(1);
    }
    int licen;
    while(true){
        arch>>licen;
        if(arch.eof()) break;
        arch.get();
        arch.getline(nomb,100);
        if(licencia == licen) return 1;
    }
    return 0;
}

void Procesa::imprimeLinea(ofstream &arch, int cantidad, char car){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}
