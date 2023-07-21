/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 25 de abril de 2023, 10:20
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Estructuras.h"
#include "operadoresSobrecargados.h"
#include "AperturaDeArchivos.h"

int main(int argc, char** argv) {
    ifstream archPacientes,archMedicos,archConsultas;
    ofstream archPacReporte;
    struct StPaciente pacientes[150];
    struct StMedico medicos[50];
    struct StCita cita;
    int numPacientes=0,numMedicos=0;
    int dni;
    
    AperturaDeUnArchivoDeTextosParaLeer(archPacientes,"PacientesLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archMedicos,"MedicosLab3.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archConsultas,"ConsultasLab3.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archPacReporte,"Reporte.txt");
    
    //PARTE A
    while(true){
        if(archMedicos>>medicos[numMedicos]) numMedicos++;
        else break;
    }
    
    //PARTE B
    while(true){
        if(archPacientes>>pacientes[numPacientes]) numPacientes++;
        else break;
    }
    
    //PARTE C
    while(true){
        dni = archConsultas>>cita;
        if(dni != -1){
            cita <= medicos;
            for (int i = 0; i < numPacientes; i++) 
                if(dni == pacientes[i].dni) pacientes[i] += cita;
        }else break; 
    }
    for (int i = 0; i < numPacientes; i++) ++pacientes[i];
    
    //PARTE D
    archPacReporte<<right<<setw(50)<<"EMPRESA PRESTADORA DE SALUD LP1"<<endl;
    archPacReporte<<right<<setw(35)<<"PACIENTES QUE FUERON ATENDIDOS"<<left<<endl;
    imprimirLinea('=',66,archPacReporte);
    for (int i = 0; i < numPacientes; i++) archPacReporte<<pacientes[i];
    
    return 0;
}

