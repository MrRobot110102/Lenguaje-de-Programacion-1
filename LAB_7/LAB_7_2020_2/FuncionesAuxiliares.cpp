/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"
#include "Medico.h"
#include "Paciente.h"

void leerMedicos(class Medico *medico,const char *nombArch){
    ifstream archMedicos("Medicos.txt",ios::in);
    if(not archMedicos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numMedicos = 0;
    while(true){
        archMedicos>>medico[numMedicos];
        if(archMedicos.eof()) break;
        numMedicos++;
    }
}
    
void leerYAgregarPacientes(class Medico *medico,const char *nombArch){
    ifstream archAtencion("AtencionPacientes.txt",ios::in);
    if(not archAtencion.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Paciente paciente;
    int dd,mm,aa,fecha;
    char codig[10],car;
    while(true){
        archAtencion>>dd;
        if(archAtencion.eof()) break;
        if(not archAtencion.fail()){
            archAtencion>>car>>mm>>car>>aa;
            fecha = aa * 10000 + mm * 100 + dd;
        }else{
            archAtencion.clear();
            archAtencion>>paciente>>codig;
            paciente.SetFecha(fecha);
            int pos = buscarMedico(medico,codig);
            if(pos != -1) medico[pos] + paciente;
        }
    }
}
    
void imprimirMedicos(class Medico *medico,const char *nombArch){
    ofstream archMedicosReporte("MedicosReporte.txt",ios::out);
    if(not archMedicosReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int fech  = 20200111;
    char cod[10];
    medico[0].GetCodigo(cod);
    for (int i = 0;strcmp(cod,"0"); i++){
        //medico[i] * fech;
        //medico[i] - fech;
        medico[i]++;
        archMedicosReporte<<medico[i];
        medico[i+1].GetCodigo(cod);
    }
}

int buscarMedico(class Medico *medicos,char *cod){
    char codigoMedico[10];
    medicos[0].GetCodigo(codigoMedico);
    for (int i = 0;strcmp(codigoMedico,"0"); i++){
        if(strcmp(codigoMedico,cod) == 0) return i;
        medicos[i+1].GetCodigo(codigoMedico);
    }
    return -1;
}