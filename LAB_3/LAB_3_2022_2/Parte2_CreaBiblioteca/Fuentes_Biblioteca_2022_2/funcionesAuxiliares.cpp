/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Estructuras.h"
#include "operadoresSobrecargados.h"
#include "AperturaDeArchivos.h"
#include "funcionesAuxiliares.h"


void leerMedicos(struct StMedico *medicos,int &numMedicos){
    ifstream archMedicos;
    AperturaDeUnArchivoDeTextosParaLeer(archMedicos,"MedicosLab3.txt");
    while(true){
        if(archMedicos>>medicos[numMedicos]) numMedicos++;
        else break;
    }
}
    
void leerPacientes(struct StPaciente *pacientes, int &numPacientes){
    ifstream archPacientes;
    AperturaDeUnArchivoDeTextosParaLeer(archPacientes,"PacientesLab3.txt");
    while(true){
        if(archPacientes>>pacientes[numPacientes]) numPacientes++;
        else break;
    }
}

void leerCitas(struct StMedico *medicos,struct StPaciente *pacientes,const int numPacientes){
    ifstream archConsultas;
    struct StCita cita;
    int dni;
    AperturaDeUnArchivoDeTextosParaLeer(archConsultas,"ConsultasLab3.txt");
    
    while(true){
        dni = archConsultas>>cita;
        if(dni != -1){
            cita <= medicos;
            for (int i = 0; i < numPacientes; i++) 
                if(dni == pacientes[i].dni) pacientes[i] += cita;
        }else break; 
    }
    for (int i = 0; i < numPacientes; i++) ++pacientes[i];
}
    
void emitirReporte(struct StPaciente *pacientes,const int numPacientes){
    ofstream archPacReporte;
    AperturaDeUnArchivoDeTextosParaEscribir(archPacReporte,"Reporte.txt");
    archPacReporte<<right<<setw(50)<<"EMPRESA PRESTADORA DE SALUD LP1"<<endl;
    archPacReporte<<right<<setw(35)<<"PACIENTES QUE FUERON ATENDIDOS"<<left<<endl;
    imprimirLinea('=',66,archPacReporte);
    for (int i = 0; i < numPacientes; i++) archPacReporte<<pacientes[i];
}