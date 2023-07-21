/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>  
using namespace std;
#include "Funciones Auxiliares.h"
#include "SobrecargaOperadores.h"
#include "medico.h"
#include "cita.h"
#include "paciente.h"

void leerMedicos(class medico *medicos,const char *nombArch){
    ifstream archMedicos(nombArch,ios::in);
    if(not archMedicos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numMedicos = 0;
    while(true){
        archMedicos>>medicos[numMedicos];
        if(archMedicos.eof()) break;
        numMedicos++;
    }
}

void leerPacientes(class paciente *pacientes,const char *nombArch){
    ifstream archPacientes(nombArch,ios::in);
    if(not archPacientes.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numPacientes = 0;
    while(true){
        archPacientes>>pacientes[numPacientes];
        if(archPacientes.eof()) break;
        numPacientes++;
    }
}
    
void agregarCitas(class paciente *pacientes,const char *nombArch){
    ifstream archCitas(nombArch,ios::in);
    if(not archCitas.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class cita citaAux;
    while(true){
        archCitas>>citaAux;
        if(archCitas.eof()) break;
        int pos = buscarPaciente(pacientes,citaAux.GetDni());
        cout<<"Posicion"<<pos<<endl;
        if(pos != -1) pacientes[pos] += citaAux;
    }
}
    
void actualizarTarifas(class paciente *pacientes,class medico *medicos){
    for (int i = 0; pacientes[i].GetDni(); i++){
        pacientes[i].actualizaTarifas(medicos);
        pacientes[i]++;
    }
}
    
void imprimirMedicos(class medico *medicos,const char *nombArch){
    ofstream archMedicosReporte(nombArch,ios::out);
    if(not archMedicosReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for (int i = 0; medicos[i].GetCodigo(); i++) archMedicosReporte<<medicos[i];
}

void imprimirPacientes(class paciente *pacientes,const char *nombArch){
    ofstream archPacientesReporte(nombArch,ios::out);
    if(not archPacientesReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for (int i = 0; pacientes[i].GetDni(); i++) archPacientesReporte<<pacientes[i];
}

int buscarPaciente(class paciente *paciente,int dni){
    for(int i=0; paciente[i].GetDni(); i++) if (dni == paciente[i].GetDni()) return i;
    return -1;
}
