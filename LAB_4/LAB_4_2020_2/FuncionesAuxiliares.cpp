/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"

void cargarMedicos(char **&codigoMed, char **&medicos, double *&tarifas){
    ifstream archMedicos("RelacionMedicos.csv",ios::in);
    if(not archMedicos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RelacionMedicos.csv"<<endl;
        exit(1);
    }
    int numDatos = 0;
    char *buffCodigoMed[100],*buffMedicos[100],buff[100];
    double buffTarifas[100],tarifa;
    while(true){
        buffCodigoMed[numDatos] = leerCadena(archMedicos);
        if(archMedicos.eof()) break;
        buffMedicos[numDatos] = leerCadena(archMedicos);
        archMedicos.getline(buff,100,',');
        archMedicos>>tarifa;
        archMedicos.get();
        buffTarifas[numDatos] = tarifa;
        numDatos++;
    }
    buffCodigoMed[numDatos] = nullptr;
    buffMedicos[numDatos] = nullptr;
    buffTarifas[numDatos] = 0;
    numDatos++;
    codigoMed = new char*[numDatos];
    medicos = new char*[numDatos];
    tarifas = new double[numDatos];
    for (int i = 0; i < numDatos; i++) {
        codigoMed[i] = buffCodigoMed[i];
        medicos[i] = buffMedicos[i];
        tarifas[i] = buffTarifas[i];
    }
}

char *leerCadena(ifstream &arch){
    char *aux,buff[100];
    arch.getline(buff,100,',');
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

void reporteMedicos(char **codigoMed, char **medicos, double *tarifas){
    ofstream archReporte("ReporteMedicos.txt",ios::out);
    archReporte.precision(2);archReporte<<fixed;
    for (int i = 0; codigoMed[i]; i++)
        archReporte<<left<<setw(10)<<codigoMed[i]<<setw(60)<<medicos[i]
                <<right<<setw(10)<<tarifas[i]<<left<<endl;
}

void reporteDeIngresos(char **codigoMed, char **medicos, double *tarifas){
    ifstream archMedicos("Medicos.csv",ios::in);
    ofstream archReporte("ReporteDeIngresos.txt",ios::out);
    int *codigoPac, *veces;
    char **pacientes, codMed[7];
    double *porcentajes;

    while(true){
        archMedicos>>codMed;
        if(archMedicos.eof()) break;
        cargarPacientes(codMed,codigoPac, pacientes, porcentajes,veces);
        reporteDelMedico(codMed, codigoMed, medicos, tarifas,
            codigoPac, pacientes, porcentajes, veces,archReporte);
        liberarEspacios(codigoPac, pacientes, porcentajes,veces);
    }
}

void cargarPacientes(char *codMed,int *&codigoPac, char **&pacientes, double *&porcentajes,int *&veces){
    ifstream archMedicos("Pacientes-Atencion.csv",ios::in);
    int buffCodigoPac[300],buffVeces[300],numDatos = 0,dato,codPaciente,posicionPaciente;
    char *buffPacientes[300],car,estado,*nombrePaciente,*codigoMedico;
    double buffPorcentajes[300],porcentajeTarifa;
    while(true){
        archMedicos>>dato;
        if(archMedicos.eof()) break;
        if(not archMedicos.fail()) archMedicos>>car>>dato>>car>>dato>>car;
        else{
            archMedicos.clear();
            archMedicos>>estado>>car>>codPaciente>>car;
            nombrePaciente = leerCadena(archMedicos);
            archMedicos>>porcentajeTarifa>>car;
            codigoMedico = leerMedico(archMedicos);
            if(archMedicos.peek() == ',') archMedicos.get();
            if(estado == 'A' and strcmp(codMed,codigoMedico) == 0){
                posicionPaciente = existePaciente(codPaciente,buffCodigoPac,numDatos);
                if(posicionPaciente == -1){//nueva entrada
                    buffCodigoPac[numDatos] = codPaciente;
                    buffPacientes[numDatos] = nombrePaciente;
                    buffPorcentajes[numDatos] = porcentajeTarifa;
                    buffVeces[numDatos] = 1;
                    numDatos++;
                }else//ya existe
                    buffVeces[posicionPaciente]++;
            }
        }
    }
    buffCodigoPac[numDatos] = 0;
    buffPacientes[numDatos] = nullptr;
    buffPorcentajes[numDatos] = 0;
    buffVeces[numDatos] = 0;
    numDatos++;
    codigoPac = new int[numDatos];
    pacientes = new char*[numDatos];
    porcentajes = new double[numDatos];
    veces = new int[numDatos];
    for (int i = 0; i < numDatos; i++) {
        codigoPac[i] = buffCodigoPac[i];
        pacientes[i] = buffPacientes[i];
        porcentajes[i] = buffPorcentajes[i];
        veces[i] = buffVeces[i];
    }
}

char *leerMedico(ifstream &arch){
    char *aux = new char[7];
    arch.get(aux,7);
    return aux;
}

int existePaciente(int codPaciente,int *buffCodigoPac,int numDatos){
    for (int i = 0; i < numDatos; i++) if(buffCodigoPac[i] == codPaciente) return i;
    return -1;
}

void reporteDelMedico(char *codMed, char **codigoMed, char **medicos, double *tarifas,
        int *codigoPac, char **pacientes,double *porcentajes,int  *veces,ofstream &archReporte){
    double montoP = 0,montoS = 0;
    int totalCitas = 0;
    int posicionMedico = obtenerPosicionMedico(codMed,codigoMed);
    archReporte.precision(2);archReporte<<fixed;
    archReporte<<left<<"Medico: "<<medicos[posicionMedico]<<endl;
    archReporte<<left<<"Codigo: "<<codMed<<endl;
    archReporte<<"Honorarios por cita: "<<tarifas[posicionMedico]<<endl;
    imprimirLinea('=',100,archReporte);
    archReporte<<"Pacientes atendidos:"<<endl;
    imprimirLinea('-',100,archReporte);
    archReporte<<left<<setw(6)<< "No." << setw(15) << "Paciente" << setw(20) << "Pago"
            << setw(20) << "Seguro" << setw(15) << "Veces" << endl;
    for (int i = 0; codigoPac[i]; i++) {
        archReporte<<right<<setw(2) << i+1 << ')'
                <<left<<"   "<<setw(10) << codigoPac[i]
                <<right<<setw(10)<<(porcentajes[i]*tarifas[posicionMedico]/100)*veces[i]
                << setw(21) << ((100-porcentajes[i])*tarifas[posicionMedico]/100)*veces[i]
                << setw(17) << veces[i]<<endl;
        montoP += (porcentajes[i]*tarifas[posicionMedico]/100)*veces[i];
        montoS += ((100-porcentajes[i])*tarifas[posicionMedico]/100)*veces[i];
        totalCitas += veces[i];
    }
    imprimirLinea('=',100,archReporte);
    archReporte << left << setw(40) << "Monto total recibido por pacientes: "<< montoP<<endl;
    archReporte << setw(40) << "Monto a solicitar al seguro: " << montoS << endl;
    archReporte << setw(40) << "Total de citas atendidas: " << totalCitas << endl;
    imprimirLinea('=',100,archReporte);
}

void imprimirLinea(char car,int cantidad,ofstream &arch){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}

int obtenerPosicionMedico(char *codMed,char **codigoMed){
    for (int i = 0; codigoMed[i]; i++) if(strcmp(codigoMed[i],codMed) == 0) return i;
}
        
void liberarEspacios(int *&codigoPac, char **&pacientes,double *&porcentajes,int *&veces){
    delete codigoPac;
    delete pacientes;
    delete porcentajes;
    delete veces;
}