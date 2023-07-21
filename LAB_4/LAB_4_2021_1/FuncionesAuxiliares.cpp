/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <valarray>
using namespace std;
#include "FuncionesAuxiliares.h"

void cargarConductores(int *&licencia,char **&conductor){
    int buffLicencia[200],numDatos=0,licen;
    char *buffConductor[200];
    ifstream archConductores("Conductores.csv",ios::in);
    if(not archConductores.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Conductores.csv"<<endl;
        exit(1);
    }
    while(true){
        archConductores>>licen;
        if(archConductores.eof()) break;
        archConductores.get();
        buffConductor[numDatos] = leerNombre(archConductores);
        buffLicencia[numDatos] = licen;
        numDatos++;
    }
    buffConductor[numDatos] = nullptr;
    buffLicencia[numDatos] = 0;
    numDatos++;
    licencia = new int[numDatos];
    conductor = new char*[numDatos];
    for (int i = 0; i < numDatos; i++) {
        licencia[i] = buffLicencia[i];
        conductor[i] = buffConductor[i];
    }
}

char *leerNombre(ifstream &archConductores){
    char *aux,nombre[100];
    archConductores.getline(nombre,100);
    aux = new char[strlen(nombre) + 1];
    strcpy(aux,nombre);
    return aux;
}
    
void reporteConductores(int *licencia,char **conductor){
    ofstream archReporte("ConductoresReporte.txt",ios::out);
    for (int i = 0; licencia[i]; i++) 
        archReporte<<left<<setw(15)<<licencia[i]<<setw(60)<<conductor[i]<<endl;
}
    
void cargarInfracciones(int *&infraccion,char *&gravedad,double *&multa){
    int buffInfra[150],numDatos=0,infrac;
    char buffGravedad[150],descrip[500];
    double buffMulta[150],mul;
    ifstream archInfracciones("Infracciones.csv",ios::in);
    if(not archInfracciones.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Infracciones.csv"<<endl;
        exit(1);
    }
    while(true){
        archInfracciones>>infrac;
        if(archInfracciones.eof()) break;
        archInfracciones.get();
        archInfracciones.getline(descrip,500,',');
        buffInfra[numDatos] = infrac;
        buffGravedad[numDatos] = leerGravedad(archInfracciones);
        archInfracciones>>mul;
        buffMulta[numDatos] = mul;
        numDatos++;
    }
    buffInfra[numDatos] = 0;
    buffGravedad[numDatos] = 0;
    buffMulta[numDatos] = 0;
    numDatos++;
    infraccion = new int[numDatos];
    gravedad = new char[numDatos];
    multa = new double[numDatos];
    for (int i = 0; i < numDatos; i++) {
        infraccion[i] = buffInfra[i];
        gravedad[i] = buffGravedad[i];
        multa[i] = buffMulta[i];
    }
}

char leerGravedad(ifstream &arch){
    char nombre[100];
    arch.getline(nombre,100,',');
    if(strcmp(nombre,"Grave") == 0) return 'G';
    else if(strcmp(nombre,"Muy Grave") == 0) return 'M';
    else if(strcmp(nombre,"Leve") == 0) return 'L'; 
}
    
void reporteInfracciones(int *infraccion,char *gravedad,double *multa){
    ofstream archReporte("InfraccionesReporte.txt",ios::out);
    archReporte.precision(2);archReporte<<fixed;
    for (int i = 0; infraccion[i]; i++) 
        archReporte<<left<<setw(15)<<infraccion[i]<<setw(5)<<gravedad[i]
                <<right<<setw(10)<<multa[i]<<endl;
}
    
void reporteDeFaltas(int *licencia,char **conductor,int *infraccion,char *gravedad,double *multa){
    ofstream archReporte("ReporteFaltas.txt",ios::out);
    reporteSegunTipo(infraccion,gravedad,multa,'L',archReporte);
    archReporte<<endl;
    reporteSegunTipo(infraccion,gravedad,multa,'G',archReporte);
    archReporte<<endl;
    reporteSegunTipo(infraccion,gravedad,multa,'M',archReporte);
}

void reporteSegunTipo(int *infraccion,char *gravedad,double *multa,char tipo,ofstream &arch){
    ifstream archFaltas("RegistroDeFaltas.csv",ios::in);
    int *licencia,buffLicencia[300],*cantidad,buffCantidad[300],licen,dd,mm,aa,fecha,infracc,posConductor,numDatos = 0,posInfraccion;
    char **placa,*plac,car,*buffPlaca[300];
    double *monto,buffMonto[300];
    while(true){
        archFaltas>>licen;
        if(archFaltas.eof()) break;
        archFaltas.get();
        plac = leerPlaca(archFaltas);
        archFaltas>>dd>>car>>mm>>car>>aa>>car>>infracc;
        posInfraccion = obtenerTipoInfraccion(infracc,infraccion,gravedad);
        if(tipo == gravedad[posInfraccion]){
            posConductor = existeConductor(buffLicencia,licen,buffPlaca,plac,numDatos);
            if(posConductor == -1){
                buffLicencia[numDatos] = licen;
                buffPlaca[numDatos] = plac;
                buffCantidad[numDatos] = 1;
                buffMonto[numDatos] = multa[posInfraccion];
                numDatos++;
            }else{
                buffCantidad[posConductor]++;
                buffMonto[posConductor] += multa[posInfraccion];
            }
        }
    }
    buffLicencia[numDatos] = 0;
    buffPlaca[numDatos] = nullptr;
    buffCantidad[numDatos] = 0;
    buffMonto[numDatos] = 0;
    numDatos++;
    licencia = new int[numDatos];
    placa = new char*[numDatos];
    cantidad = new int[numDatos];
    monto = new double[numDatos];
    for (int i = 0; i < numDatos; i++) {
        licencia[i] = buffLicencia[i];
        placa[i] = buffPlaca[i];
        cantidad[i] = buffCantidad[i];
        monto[i] = buffMonto[i];
    }
    imprimirReporte(licencia,placa,cantidad,monto,arch);
    delete licencia;
    delete placa;
    delete cantidad;
    delete monto; 
}

void imprimirReporte(int *licencia,char **placa,int *cantidad,double *monto,ofstream &arch){
    for (int i = 0; licencia[i]; i++) {
        arch<<setw(2)<<right<<i+1<<")    "<<setw(12)<<left<<licencia[i]<<
                setw(20)<<left<<placa[i]<<setw(12)<<left<<cantidad[i]
                <<setw(18)<<right<<setprecision(2)<<fixed<<monto[i]<<endl;
    }
}

int existeConductor(int *buffLicencia,int licen,char **buffPlaca,char *placa,int numDatos){
    for (int i = 0; i < numDatos; i++){
        if(buffLicencia[i] == licen and strcmp(buffPlaca[i],placa) == 0) return i;
    }
    return -1;
}

int obtenerTipoInfraccion(int infracc,int *infraccion,char *gravedad){
    for (int i = 0; infraccion[i]; i++) 
        if(infraccion[i] == infracc) return i;
}

char *leerPlaca(ifstream &arch){
    char *aux,buff[10];
    arch.getline(buff,10,',');
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}