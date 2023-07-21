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

bool operator >>(ifstream &arch,struct StMedico &medico){
    arch>>medico.codigo;
    if(arch.eof()) return false;
    arch>>medico.nombre>>medico.tarifaPoxConsulta;
    obtenerEspecialidad(medico.nombre,medico.especialidad);
    return true;
}

void obtenerEspecialidad(char *nombre,char *especialidad){
    int aux,i,j=0;
    int cantidad = strlen(nombre);
    for(i=cantidad-1;i>0;i--){
        if(nombre[i] == '_'){
            aux = i+1;
            break;
        }
    }
    while(aux <= cantidad){
        especialidad[j] = nombre[aux];
        j++;
        aux++;	
    }
    nombre[i] = nombre[cantidad];
}

bool operator >>(ifstream &arch,struct StPaciente &paciente){
    arch>>paciente.dni;
    if(arch.eof()) return false;
    arch>>paciente.nombre>>paciente.telefono;
    paciente.numeroDeCitas = 0;
    paciente.totalGastado = 0.0;
    return true;
}

int operator >>(ifstream &arch,StCita &cita){
    int dni,dd,mm,aa;
    char car;
    arch>>dni;
    if(arch.eof()) return -1;
    arch>>cita.codigoDelMedico>>dd>>car>>mm>>car>>aa;
    cita.fecha = aa * 10000 + mm * 100 + dd;
    cita.tarifaPorConsulta = 0.0;
    return dni;
}

bool operator <=(struct StCita &cita,struct StMedico *medico){
    for (int i = 0; i < 50; i++) {
        if(cita.codigoDelMedico == medico[i].codigo){
            strcpy(cita.especialidad,medico[i].especialidad);
            cita.tarifaPorConsulta = medico[i].tarifaPoxConsulta;
            return true;
        }
    }
    return false;
}

bool operator +=(struct StPaciente &paciente,struct StCita &cita){
    paciente.citas[paciente.numeroDeCitas].codigoDelMedico = cita.codigoDelMedico;
    paciente.citas[paciente.numeroDeCitas].fecha = cita.fecha;
    paciente.citas[paciente.numeroDeCitas].tarifaPorConsulta = cita.tarifaPorConsulta;
    strcpy(paciente.citas[paciente.numeroDeCitas].especialidad,cita.especialidad);
    paciente.numeroDeCitas++;
}

bool operator ++(struct StPaciente &paciente){
    for (int i = 0; i < paciente.numeroDeCitas; i++) 
        paciente.totalGastado += paciente.citas[i].tarifaPorConsulta;
}

ofstream & operator <<(ofstream &arch,struct StPaciente &paciente){
    int fecha,dd,mm,aa;
    arch.precision(2);arch<<fixed;
    arch<<left<<setw(15)<<"   DNI"<<setw(42)<<"NOMBRE"<<setw(10)<<"TELEFONO"<<endl;
    arch<<setw(15)<<paciente.dni<<setw(42)<<paciente.nombre<<setw(10)<<paciente.telefono<<endl;
    arch<<"RELACION DE CITAS"<<endl;
    arch<<setw(5)<<"No."<<setw(15)<<"FECHA"<<setw(20)<<"CODIGO DEL MEDICO"<<setw(20)<<"ESPECIALIDAD"<<setw(20)<<"TARIFA"<<endl;
    for (int i = 0; i < paciente.numeroDeCitas; i++) {
        fecha = paciente.citas[i].fecha;
        aa = fecha/10000;
        fecha = fecha % 10000;
        mm = fecha/100;
        dd = fecha %100;
        arch<<i+1<<')'<<setw(3)<<" "<<right<<setfill('0')
            <<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aa<<left<<setfill(' ')
            <<setw(10)<<" "<<setw(15)<<paciente.citas[i].codigoDelMedico
            <<setw(20)<<paciente.citas[i].especialidad
            <<right<<setw(6)<<paciente.citas[i].tarifaPorConsulta<<left<<endl;
    }
    arch<<left<<"MONTO TOTAL GASTADO:"<<right<<setw(8)<<paciente.totalGastado<<left<<endl;
    imprimirLinea('=',66,arch);
    return arch;
}

void imprimirLinea(char car, int cantidad, ofstream &arch){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}



