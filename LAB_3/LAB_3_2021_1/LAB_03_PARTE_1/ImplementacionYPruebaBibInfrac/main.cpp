/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 21 de abril de 2023, 18:53
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "StConductor.h"
#include "StFalta.h"
#include "StInfraccion.h"
#include "StInfraccionEstab.h"
#include "operadoresSobrecargados.h"

int main(int argc, char** argv) {
    
    ifstream archConductores("Conductores.txt", ios::in);
    if(not archConductores.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Conductores.txt"<<endl;
        exit(1);
    }
    ifstream archInfracciones("RegistroDeFallas.txt", ios::in);
    if(not archInfracciones.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RegistroDeFallas.txt"<<endl;
        exit(1);
    }
    ifstream archInfraccionesEstab("Infracciones.txt",ios::in);
    if(not archInfraccionesEstab.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Infracciones.txt"<<endl;
        exit(1);
    }
    ofstream archReporte("Reporte.txt", ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    ofstream archReporteFinal("ReporteFinal.txt", ios::out);
    if(not archReporteFinal.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReporteFinal.txt"<<endl;
        exit(1);
    }
    

  
    TconductorSt conductores[150];
    TInfraccionSt infraccion;
    TInfraccionEstabSt infraEstab;
    int numConductores = 0;
    int fecha = 20200722;
    
    
    //PARTE A
    while(true){
        archConductores>>conductores[numConductores];
        if(archConductores.eof()) break;
        numConductores++;
    }
    
    //PARTE B
    while(true){
        archInfracciones>>infraccion;
        if(archInfracciones.eof()) break;
        for (int i = 0; i < numConductores; i++) {
            conductores[i] + infraccion;
        }
    }
    
    //PARTE C
    while(true){
        archInfraccionesEstab>>infraEstab;
        if(archInfraccionesEstab.eof()) break;
        for (int i = 0; i < numConductores; i++) {
            conductores[i] + infraEstab;
        }
    }
    
    //PARTE D
    for (int i = 0; i < numConductores; i++) ++conductores[i];
    
    //PARTE E
    for (int i = 0; i < numConductores; i++) archReporte<<conductores[i];
    
    //PARTE F
    for (int i = 0; i < numConductores; i++) conductores[i] * fecha;
    for (int i = 0; i < numConductores; i++) ++conductores[i];
    
    //PARTE G
    for (int i = 0; i < numConductores; i++) archReporteFinal<<conductores[i];


        
    return 0;
}

