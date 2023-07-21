/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ServicioDeSalud.cpp
 * Author: Sebastian
 * 
 * Created on 28 de junio de 2023, 21:00
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "ServicioDeSalud.h"
#include "Paciente.h"

void ServicioDeSalud::leerMedicinas(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    Medicina medi;
    while(true){
        arch>>medi;
        if(arch.eof()) break;
        medicina[medi.GetCodigo()] = medi;
    }
}

void ServicioDeSalud::imprimirMedicinas(const char* nombArch) {
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for (map<int,Medicina>::iterator it = medicina.begin();it != medicina.end();it++)
        arch<<it->second;
}

void ServicioDeSalud::leerConsultas(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int dd,mm,aa,dni;
    char nomb[100],codMedico[20],car;
    class Paciente paciente;
    list<Paciente_Medicina>::iterator itPaciente;
    while (true) {
        class Paciente_Medicina pacienteMedicina;
        paciente.leerDatos(arch);
        //arch>>dd;
        if(arch.eof()) break;
        //arch>>car>>mm>>car>>aa>>car>>dni>>car;
        //arch.getline(nomb,100,',');
        //arch.getline(codMedico,20,',');
        //paciente.SetDni(dni);
        //paciente.SetNombre(nomb);
        //paciente.SetFechaUltimaConsulta(aa * 10000 + mm * 100 + dd);
        itPaciente = buscarPaciente(paciente.GetDni());
        if(itPaciente == paciente_medicina.end()){//nuevo paciente
            pacienteMedicina = paciente;
            pacienteMedicina.LeerMedicinas(arch);
            paciente_medicina.push_back(pacienteMedicina);
        }else{//ya existe el paciente - actualizar ultima atencion y fecha
            paciente.GetCodigoDelMedicoDeUltimaConsulta(codMedico);
            if(*itPaciente < paciente) itPaciente->actualizarFechaYMedico(paciente.GetFechaUltimaConsulta(),codMedico);
            itPaciente->LeerMedicinas(arch);
        }
    }
}

void ServicioDeSalud::totalizar() {
    for (list<Paciente_Medicina>::iterator it = paciente_medicina.begin();it != paciente_medicina.end(); it++)
        it->totalizar(medicina);
}


void ServicioDeSalud::imprimirPacientes(const char* nombArch) {
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for (list<Paciente_Medicina>::iterator it = paciente_medicina.begin();it != paciente_medicina.end(); it++)
        it->imprimirPaciente(arch);
    
}


list<Paciente_Medicina>::iterator ServicioDeSalud::buscarPaciente(int dni) {
    for (list<Paciente_Medicina>::iterator it = paciente_medicina.begin();it != paciente_medicina.end(); it++)
        if(it->GetDni() == dni) return it;
    return paciente_medicina.end();
}





