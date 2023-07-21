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
#define INCREMENTO 5
#define MAX_CAR 120

//    char **conductor, ***placa;
//    int *licencia, **falta;
//    double **multa;

void cargarConductores(int *&licencia,char **&conductor){
    ifstream archConductores("Conductores.csv",ios::in);
    if(not archConductores.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Conductores.csv"<<endl;
        exit(1);
    }
    int numConductores = 0,capConductores = 0;
    int licen;
    char *nombre;
    licencia = nullptr;
    conductor = nullptr;
    
    while(true){
        archConductores>>licen;
        if(archConductores.eof()) break;
        archConductores.get();
        nombre = leerCadena(archConductores);
        if(numConductores == capConductores)
            aumentarEspacios(licencia,conductor,numConductores,capConductores);
        licencia[numConductores] = 0;
        licencia[numConductores - 1] = licen;
        conductor[numConductores] = nullptr;
        conductor[numConductores - 1] = nombre;
        numConductores++;
    }
}

void aumentarEspacios(int *&licencia,char **&conductor,int &numDatos,int &cap){
    int *auxL;
    char **auxC;
    cap += INCREMENTO;
    if(licencia == nullptr){
        licencia = new int[cap];
        conductor = new char*[cap];
        licencia[0] = 0;
        conductor[0] = nullptr;
        numDatos = 1;
    }else{
        auxL = new int[cap];
        auxC = new char*[cap];
        for (int i = 0; i < numDatos; i++) {
            auxL[i] = licencia[i];
            auxC[i] = conductor[i];
        }
        delete licencia;
        delete conductor;
        licencia = auxL;
        conductor = auxC;
    }
}

char *leerCadena(ifstream &arch){
    char *aux,buff[200];
    arch.getline(buff,200);
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}
    
void reporteConductores(int *licencia,char **conductor){
    ofstream archReporte("ReporteConductores.txt",ios::out);
    for (int i = 0; licencia[i]; i++) 
        archReporte<<left<<setw(12)<<licencia[i]<<setw(60)<<conductor[i]<<endl;
}
    
void cargarFaltas(int *licencia,char ***&placa,int **&falta){
    ifstream archFaltas("RegistroDeFaltas.csv",ios::in);
    if(not archFaltas.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RegistroDeFaltas.csv"<<endl;
        exit(1);
    }
    int i,licen,dato,infraccion,numPlacas[200]{},capPlacas[200]{},posConductor;
    char *plac,car;
    for (i = 0; licencia[i]; i++);
    placa = new char**[i+1]{};
    falta = new int*[i+1]{};
    
    while(true){
        archFaltas>>licen;
        if(archFaltas.eof()) break;
        archFaltas.get();
        plac = leePlaca(archFaltas);
        archFaltas>>dato>>car>>dato>>car>>dato>>car;
        archFaltas>>infraccion;
        posConductor = obtenerPosicionConductor(licencia,licen);
        agregarPlaca(placa[posConductor],plac,falta[posConductor],infraccion,numPlacas[posConductor],capPlacas[posConductor]);
    }
}

int obtenerPosicionConductor(int *licencia, int licen){
    for (int i = 0; licencia[i]; i++) if(licencia[i] == licen) return i;
}

void agregarPlaca(char **&placa, char *plac,int *&falta, int infraccion,int &numPlacas,int &capPlacas){
    if(numPlacas == capPlacas)
        aumentarEspacios(placa,falta,numPlacas,capPlacas);
    placa[numPlacas] = nullptr;
    placa[numPlacas - 1] = plac;
    falta[numPlacas] = 0;
    falta[numPlacas - 1] = infraccion;
    numPlacas ++;
}

void aumentarEspacios(char **&placa,int *&falta,int &numDatos,int &cap){
    char **auxP;
    int *auxF;
    cap += INCREMENTO;
    if(placa == nullptr){
        placa = new char*[cap];
        falta = new int[cap];
        placa[0] = nullptr;
        falta[0] = 0;
        numDatos = 1;
    }else{
        auxP = new char*[cap];
        auxF = new int[cap];
        for (int i = 0; i < numDatos; i++) {
            auxP[i] = placa[i];
            auxF[i] = falta[i];
        }
        delete placa;
        delete falta;
        placa = auxP;
        falta = auxF;
    }
}

char *leePlaca(ifstream &arch){
    char *aux,buff[20];
    arch.getline(buff,20,',');
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}
    
void reporteFaltas(int *licencia,char **conductor,char ***placa,int **falta){
    ofstream archReporte("ReporteFaltas.txt",ios::out);
    for (int i = 0; licencia[i]; i++) {
        archReporte<<left<<setw(12)<<licencia[i]<<conductor[i]<<endl;
        if(placa[i]) imprimirFaltas(placa[i],falta[i],archReporte);
    }
}

void imprimirFaltas(char **placa,int *falta,ofstream &arch){
    for (int i = 0; placa[i]; i++) arch<<setw(10)<<placa[i]<<falta[i]<<endl;
}
    
void resumenMultas(int *licencia,int **falta,double **&multa){
    int i;
    for (i = 0; licencia[i]; i++);
    multa = new double*[i+1]{};
    for ( i = 0; licencia[i]; i++) multa[i] = new double[3]{};
    
    for (i = 0; licencia[i]; i++) if(falta[i]) actualizarMulta(falta[i],multa[i]);
}

void actualizarMulta(int *falta,double *&multa){
    double monto;
    char *gravedad;
    
    for (int i = 0; falta[i]; i++) {
        gravedad = obtenerGravedadYMonto(falta[i],monto);
        if(strcmp(gravedad,"Grave") == 0) multa[1] += monto;
        else if(strcmp(gravedad,"Muy Grave") == 0) multa[2] += monto;
        else if(strcmp(gravedad,"Leve") == 0) multa[0] += monto;
    }
}

char *obtenerGravedadYMonto(int falta,double &monto){
    ifstream archInfracciones("Infracciones.csv",ios::in);
    if(not archInfracciones.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Infracciones.csv"<<endl;
        exit(1);
    }
    int infraccion;
    char buff[500],*gravedad;
    double montoInfraccion;
    while(true){
        archInfracciones>>infraccion;
        if(archInfracciones.eof()) break;
        archInfracciones.get();
        archInfracciones.getline(buff,500,',');
        gravedad = leePlaca(archInfracciones);
        archInfracciones>>montoInfraccion;
        if(infraccion == falta){
            monto = montoInfraccion;
            return gravedad;
        }
    }
}
    
void reporteMultas(int *licencia,char **conductor,double **multa){
    ofstream archReporte("ReporteMultas.txt",ios::out);
    archReporte.precision(2);archReporte<<fixed;
    for (int i = 0; licencia[i]; i++) {
        archReporte<<left<<setw(12)<<licencia[i]<<conductor[i]<<endl;
        imprimirMultas(multa[i],archReporte);
    }
}

void imprimirMultas(double *multa, ofstream &archReporte){
    archReporte<<right<<setw(10)<<multa[0]<<endl;
    archReporte<<right<<setw(10)<<multa[1]<<endl;
    archReporte<<right<<setw(10)<<multa[2]<<endl;
}