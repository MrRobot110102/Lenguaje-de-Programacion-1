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
#define MAX_CAR 52

//    char **codMed,**nombMed, ***nombPac;
//    int **codPac, **veces;
//    double *tarifas, **porcPac;

void leerMedicos(char **&codMed,char **&nombMed,double *&tarifas){
    char *buffCodMed[100],*buffNombMed[100],*codMedico,*nombre,buff[100];
    double buffTarifas[100],tarifa;
    int numDatos = 0;
    ifstream archMedicos("RelacionMedicos.csv",ios::in);
    while(true){
        codMedico = leerCadena(archMedicos);
        if(archMedicos.eof()) break;
        nombre = leerCadena(archMedicos);
        archMedicos.getline(buff,100,',');
        archMedicos>>tarifa;
        archMedicos.get();
        buffCodMed[numDatos] = codMedico;
        buffNombMed[numDatos] = nombre;
        buffTarifas[numDatos] = tarifa;
        numDatos++;
    }
    buffCodMed[numDatos] = nullptr;
    buffNombMed[numDatos] = nullptr;
    buffTarifas[numDatos] = 0;
    numDatos++;
    codMed = new char*[numDatos];
    nombMed = new char*[numDatos];
    tarifas = new double[numDatos];
    for (int i = 0; i < numDatos; i++) {
        codMed[i] = buffCodMed[i];
        nombMed[i] = buffNombMed[i];
        tarifas[i] = buffTarifas[i];
    }
}

char *leerCadena(ifstream &arch){
    char *aux,buff[200];
    arch.getline(buff,200,',');
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}
    
void repMedicos(char **codMed,char **nombMed,double *tarifas){
    ofstream archReporte("ReporteMedico.txt",ios::out);
    archReporte.precision(2);archReporte<<fixed;
    for (int i = 0; codMed[i]; i++) 
        archReporte<<left<<setw(10)<<codMed[i]<<setw(80)<<nombMed[i]
                <<right<<setw(10)<<tarifas[i]<<left<<endl;
}
    
void leerAtenciones(char **codMed,int **&codPac,char ***&nombPac,double **&porcPac,int **&veces){
    ifstream archPacientes("Pacientes-Atencion.csv",ios::in);
    int i,dato,codPaciente,posMedico,numPaciente[100]{},capPaciente[100]{};
    char car,estado,*nombre,*codMedico;
    double porcentaje;
    
    for (i = 0; codMed[i]; i++);
    codPac = new int *[i+1]{};
    nombPac = new char **[i+1]{};
    porcPac = new double *[i+1]{};
    veces = new int *[i+1]{};
    
    while(true){
        archPacientes>>dato;
        if(archPacientes.eof()) break;
        if(not archPacientes.fail()) archPacientes>>car>>dato>>car>>dato>>car;
        else{
            archPacientes.clear();
            archPacientes>>estado>>car>>codPaciente>>car;
            nombre = leerCadena(archPacientes);
            archPacientes>>porcentaje>>car;
            codMedico = leerMedico(archPacientes);
            if(archPacientes.peek() == ',') archPacientes.get();
            posMedico = obtenerPosicionMedico(codMedico,codMed);
            if(estado == 'A')
                agregarPaciente(codPac[posMedico],codPaciente,nombPac[posMedico],
                        nombre,porcPac[posMedico],porcentaje,veces[posMedico],numPaciente[posMedico],capPaciente[posMedico]);
        }
    }

}

void agregarPaciente(int *&codPac,int codPaciente,char **&nombPaciente,char *nomb,
                    double *&porcPac,double porcentaje,int *&veces,int &numPaciente,int &capPaciente){
    if(numPaciente == capPaciente)
        aumentarEspacios(codPac,nombPaciente,porcPac,veces,numPaciente,capPaciente);
    int posPaciente = obtenerPosicionPaciente(codPaciente,codPac);
    if(posPaciente == -1){// no existe o es primera entrada
        codPac[numPaciente] = 0;
        codPac[numPaciente - 1] = codPaciente;
        nombPaciente[numPaciente] = nullptr;
        nombPaciente[numPaciente - 1] = nomb;
        porcPac[numPaciente] = 0;
        porcPac[numPaciente - 1] = porcentaje;
        veces[numPaciente] = 0;
        veces[numPaciente - 1] = 1;
        numPaciente++;
    }else{//ya existe
        veces[posPaciente]++;
    }
}

void aumentarEspacios(int *&codPac,char **&nombPaciente,double *&porcPac,int *&veces,int &numDatos,int &cap){
    int *auxC, *auxV;
    char **auxN;
    double *auxP;
    cap += INCREMENTO;
    if(codPac == nullptr or numDatos == 0){
        codPac = new int[cap];
        nombPaciente = new char*[cap];
        porcPac = new double[cap];
        veces = new int[cap];
        codPac[0] = 0;
        nombPaciente[0] = nullptr;
        porcPac[0] = 0;
        veces[0] = 0;
        numDatos = 1;
    }else{
        auxC = new int[cap];
        auxN = new char*[cap];
        auxP = new double[cap];
        auxV = new int[cap];
        for (int i = 0; i < numDatos; i++) {
            auxC[i] = codPac[i];
            auxN[i] = nombPaciente[i];
            auxP[i] = porcPac[i];
            auxV[i] = veces[i];
        }
        delete codPac;
        delete nombPaciente;
        delete porcPac;
        delete veces;
        codPac = auxC;
        nombPaciente = auxN;
        porcPac = auxP;
        veces = auxV;
    }
}

int obtenerPosicionPaciente(int codPaciente, int *codPac){
    if(codPac == nullptr) return -1;
    for (int i = 0; codPac[i]; i++) if(codPac[i] == codPaciente) return i;
    return -1;
}

int obtenerPosicionMedico(char *codMedico,char **codMed){
    for (int i = 0; codMed[i]; i++) if(strcmp(codMed[i],codMedico) == 0) return i;
}

char *leerMedico(ifstream &arch){
    char *aux = new char[7];
    arch.get(aux,7);
    return aux;
}
    
void repDeIngresos(char **codMed,char **nombMed,double *tarifas,int **codPac,char ***nombPac,double **porcPac,int **veces){
    ofstream archReporte("ReporteIngresos.txt",ios::out);
    ifstream archMedicos("Medicos.csv",ios::in);
    char *codigoMedico;
    int posMedico;
    archReporte.precision(2);archReporte<<fixed;
    while(true){
        codigoMedico = leerMedico(archMedicos);
        if(archMedicos.eof()) break;
        archMedicos.get();
        posMedico = obtenerPosicionMedico(codigoMedico,codMed);
        archReporte<<left<<"Medico:  "<<nombMed[posMedico]<<endl;
        archReporte<<left<<"Codigo:  "<<codMed[posMedico]<<endl;
        archReporte<<left<<"Honorarios por cita:  "<<tarifas[posMedico]<<endl;
        imprimirLinea('=',MAX_CAR,archReporte);
        archReporte<<left<<"Pacientes atendidos"<<endl;
        imprimirLinea('-',MAX_CAR,archReporte);
        archReporte<<left<<setw(5)<<"No."<<setw(15)<<"Paciente"<<setw(11)<<"Veces"
                   <<setw(15)<<"Pago"<<setw(15)<<"Seguro"<<endl;
        if(codPac[posMedico])
            imprimirPacientes(codPac[posMedico],nombPac[posMedico],
                              porcPac[posMedico],veces[posMedico],tarifas[posMedico],archReporte);
    }
    
}

void imprimirPacientes(int *codPac,char **nombPac,double *porcPac,int *veces,double tarifa,ofstream &arch){
    int totalVeces = 0;
    double totalP = 0.0,totalS = 0.0;
    for (int i = 0; codPac[i]; i++) {
        arch<<right<<setw(2)<<(i+1)<<')'<<"  "<<left<<setw(10)<<codPac[i]
            <<right<<setw(8)<<veces[i]<<setw(13)<<(porcPac[i]*tarifa/100)*veces[i]
            <<setw(16) << ((100-porcPac[i])*tarifa/100)*veces[i]
            <<left<<endl;
        totalP += (porcPac[i]*tarifa/100)*veces[i];
        totalS += ((100-porcPac[i])*tarifa/100)*veces[i];
        totalVeces += veces[i];
    }
    imprimirLinea('=',MAX_CAR,arch);
    arch<<left<<"Monto total recibido por pacientes: "<<right<<setw(10)<<totalP<<endl;
    arch<<left<<"Monto a solicitar al seguro:        "<<right<<setw(10)<<totalS<<endl;
    arch<<left<<"Total de citas atendidas:           "<<right<<setw(7)<<totalVeces<<endl;
    imprimirLinea('=',MAX_CAR,arch);
    
}

void imprimirLinea(char car, int cantidad, ofstream &arch){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}