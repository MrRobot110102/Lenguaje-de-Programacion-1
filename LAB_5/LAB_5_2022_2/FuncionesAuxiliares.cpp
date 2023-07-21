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
#define MAX_CAR 127
#define INCREMENTO 5

//    char ***medicoDatos, ****citaPaciente;
//    int **citaCantidad;
//    double *medicoTarifaHora, ***citaTiempoYPago;

void cargarCitas(const char *nomArch,char ***&medicoDatos,
                 double *&medicoTarifaHora, char ****&citaPaciente,
                 int **&citaCantidad,double ***&citaTiempoYPago){
    ifstream archCitas(nomArch,ios::in);
    if(not archCitas.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo"<<nomArch<<endl;
        exit(1);
    }
    int fecha,posMedico,numMedicos = 0,capMedicos = 0;
    int numCitas[100]{},capCitas[100]{};
    char *dniPaciente,*nombrePaciente,*nombreMedico,*codMedico;
    double tarifa,horasTotales;
    
    medicoDatos = nullptr;
    medicoTarifaHora = nullptr;
    citaPaciente = nullptr;
    citaCantidad = nullptr;
    citaTiempoYPago = nullptr;
    
    while(true){
        dniPaciente = leerCadena(archCitas);
        if(archCitas.eof()) break;
        leerDatosRestantes(nombrePaciente,codMedico,nombreMedico,tarifa,fecha,horasTotales,archCitas);
        posMedico = obtenerPosicionMedico(codMedico,medicoDatos);
        if(posMedico == -1){//no existe - nueva entrada
            if(numMedicos == capMedicos)
                aumentarEspacios(medicoDatos,medicoTarifaHora,citaPaciente,
                                 citaCantidad,citaTiempoYPago,numMedicos,capMedicos);
            agregarMedico(medicoDatos,codMedico,nombreMedico,medicoTarifaHora,
                          tarifa,numMedicos,capMedicos);
            posMedico = obtenerPosicionMedico(codMedico,medicoDatos);
        }
        agregarCitaMedico(citaPaciente[posMedico],dniPaciente,nombrePaciente,
                citaCantidad[posMedico],citaTiempoYPago[posMedico],horasTotales,
                numCitas[posMedico],capCitas[posMedico],medicoTarifaHora[posMedico]);
    }
}

void agregarCitaMedico(char ***&citaPaciente,char *dniPaciente,char *nombrePaciente,int *&citaCantidad,
        double **&citaTiempoYPago,double horasTotales,int &numCitas,int &capCitas,double medicoTarifaHora){
    int posCliente;
    if(numCitas == 0){
        citaPaciente = nullptr;
        citaCantidad = nullptr;
        citaTiempoYPago = nullptr;
    }
    if(numCitas == capCitas)
        aumentarEspacios(citaPaciente,citaCantidad,citaTiempoYPago,numCitas,capCitas);
    posCliente = obtenerPosicionPaciente(dniPaciente,citaPaciente);
    if(posCliente == -1){//primer paciente o no existe paciente
        char **datos;
        double *tiempoYPago;
        datos = new char*[2];
        tiempoYPago = new double[2];
        datos[0] = dniPaciente;
        datos[1] = nombrePaciente;
        tiempoYPago[0] = horasTotales;
        tiempoYPago[1] = medicoTarifaHora * horasTotales;
        
        citaPaciente[numCitas] = nullptr;
        citaPaciente[numCitas-1] = datos;
        citaCantidad[numCitas] = 0;
        citaCantidad[numCitas-1] = 1;
        citaTiempoYPago[numCitas] = nullptr;
        citaTiempoYPago[numCitas - 1 ] = tiempoYPago;
        numCitas++;
    }else{//ya existe paciente
        citaCantidad[posCliente]++;
        citaTiempoYPago[posCliente][0] += horasTotales;
        citaTiempoYPago[posCliente][1] += medicoTarifaHora * horasTotales;
    }
}

int obtenerPosicionPaciente(char *dniPaciente, char ***citaPaciente){
    if(citaPaciente == nullptr) return -1;//primer dato
    for (int i = 0; citaPaciente[i]; i++) 
        if(strcmp(*(citaPaciente[i]),dniPaciente) == 0) return i;
    return -1;
}

void aumentarEspacios(char ***&citaPaciente,int *&citaCantidad,double **&citaTiempo,int &numCitas,int &capCitas){
    char ***auxCPaciente;
    int *auxCCantidad;
    double **auxCTiempoYPago;
    capCitas += INCREMENTO;
    if(citaPaciente == nullptr){
        citaPaciente = new char **[capCitas];
        citaCantidad = new int[capCitas];
        citaTiempo = new double *[capCitas];
        citaPaciente[0] = nullptr;
        citaCantidad[0] = 0;
        citaTiempo[0] = nullptr;
        numCitas = 1;
    }else{
        auxCPaciente = new char **[capCitas];
        auxCCantidad = new int [capCitas];
        auxCTiempoYPago = new double *[capCitas];
        for (int i = 0; i < numCitas; i++) {
            auxCPaciente[i] = citaPaciente[i];
            auxCCantidad[i] = citaCantidad[i];
            auxCTiempoYPago[i] = citaTiempo[i];
        }
        delete citaPaciente;
        delete citaCantidad;
        delete citaTiempo;
        citaPaciente = auxCPaciente;
        citaCantidad = auxCCantidad;
        citaTiempo = auxCTiempoYPago;
    }
}

int obtenerPosicionMedico(char *codMedico,char ***medicoDatos){
    if(medicoDatos == nullptr) return -1;//primer dato
    for (int i = 0; medicoDatos[i]; i++) 
        if(strcmp(*(medicoDatos[i]),codMedico) == 0) return i;
    return -1;
}

void agregarMedico(char ***&medicoDatos,char *codMedico,char *nombreMedico, 
        double *&medicoTarifaHora,double tarifa,int &numMedicos,int &capMedicos){
    char **datos;
    datos = new char*[2];
    datos[0] = codMedico;
    datos[1] = nombreMedico;
    
    medicoDatos[numMedicos] = nullptr;
    medicoDatos[numMedicos -1] = datos;
    medicoTarifaHora[numMedicos] = 0;
    medicoTarifaHora[numMedicos -1] = tarifa;
    numMedicos++;
}

void aumentarEspacios(char ***&medicoDatos,double *&medicoTarifaHora,char ****&citaPaciente,
             int **&citaCantidad,double ***&citaTiempoYPago,int &numMedicos,int &capMedicos){
    char ***auxMDatos,****auxCPaciente;
    double *auxMTarifa,***auxCTiempoYPago;
    int **auxCCantidad;
    capMedicos += INCREMENTO;
    if(medicoDatos == nullptr){
        medicoDatos = new char **[capMedicos];
        medicoTarifaHora = new double[capMedicos];
        citaPaciente = new char ***[capMedicos];
        citaCantidad = new int *[capMedicos];
        citaTiempoYPago = new double **[capMedicos];
        medicoDatos[0] = nullptr;
        medicoTarifaHora[0] = 0;
        citaPaciente[0] = nullptr;
        citaCantidad[0] = nullptr;
        citaTiempoYPago[0] = nullptr;
        numMedicos = 1;
    }else{
        auxMDatos = new char **[capMedicos];
        auxMTarifa = new double[capMedicos];
        auxCPaciente = new char ***[capMedicos];
        auxCCantidad = new int *[capMedicos];
        auxCTiempoYPago = new double **[capMedicos];
        for (int i = 0; i < numMedicos; i++) {
            auxMDatos[i] = medicoDatos[i];
            auxMTarifa[i] = medicoTarifaHora[i];
            auxCPaciente[i] = citaPaciente[i];
            auxCCantidad[i] = citaCantidad[i];
            auxCTiempoYPago[i] = citaTiempoYPago[i];
        }
        delete medicoDatos;
        delete medicoTarifaHora;
        delete citaPaciente;
        delete citaCantidad;
        delete citaTiempoYPago;
        citaPaciente = auxCPaciente;
        citaCantidad = auxCCantidad;
        citaTiempoYPago = auxCTiempoYPago;
        medicoDatos = auxMDatos;
        medicoTarifaHora = auxMTarifa;
    }
}

void leerDatosRestantes(char *&nombrePaciente, char *&codMedico, char *&nombreMedico, 
                        double &tarifa,int &fecha,double &horasTotales,ifstream &arch){
    int dd,mm,aa;
    double horasIniciales,horasFinales;
    int horaInicio,minInicio,segInicio;
    int horaFinal,minFinal,segFinal;
    
    char car;
    nombrePaciente = leerCadena(arch);
    codMedico = leerCadena(arch);
    nombreMedico = leerCadena(arch);
    arch>>tarifa>>car>>dd>>car>>mm>>car>>aa>>car;
    fecha = aa * 10000 + mm * 100 + dd;
    arch>>horaInicio>>car>>minInicio>>car>>segInicio>>car>>horaFinal>>car>>minFinal>>car>>segFinal;
    arch.get();
    horasIniciales = (double)((double)horaInicio + ((double)minInicio/60) + ((double)segInicio/3600));
    horasFinales = (double)((double)horaFinal + ((double)minFinal/60) + ((double)segFinal/3600));
    horasTotales = horasFinales - horasIniciales;
}

char *leerCadena(ifstream &arch){
    char *aux,buff[100];
    arch.getline(buff,100,',');
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}
    
void pruebaDeCargaDeCitas(const char *nomArch,char ***medicoDatos,
                 double *medicoTarifaHora, char ****citaPaciente,
                 int **citaCantidad,double ***citaTiempoYPago){
    ofstream archReporte(nomArch,ios::out);
    archReporte.precision(2);archReporte<<fixed;
    for (int i = 0; medicoDatos[i]; i++) {
        archReporte<<left<<setw(10)<<medicoDatos[i][0]<<setw(50)<<medicoDatos[i][1]
                   <<right<<setw(10)<<medicoTarifaHora[i]<<left<<endl;
            imprimirCitas(archReporte,citaPaciente[i],citaCantidad[i],citaTiempoYPago[i]);
    }
}

void imprimirCitas(ofstream &arch,char ***citaPaciente,int *citaCantidad,double **citaTiempoYPago){
    for (int i = 0; citaPaciente[i]; i++) {
        arch<<left<<setw(10)<<citaPaciente[i][0]<<setw(50)<<citaPaciente[i][1]<<right<<setw(5)<<citaCantidad[i]
            <<setw(10)<<citaTiempoYPago[i][0]<<setw(10)<<citaTiempoYPago[i][1]<<left<<endl;
    }
}
    
void reporteDeCitasPorMedico(const char *nomArch,char ***medicoDatos,
                 double *medicoTarifaHora, char ****citaPaciente,
                 int **citaCantidad,double ***citaTiempoYPago){
    ofstream archReporte(nomArch,ios::out);
    archReporte.precision(2);archReporte<<fixed;
    archReporte<<right<<setw(65)<<"CLINICA PSICOLOGICA LP1"<<endl;
    imprimirLinea('=',MAX_CAR,archReporte);
    archReporte<<left<<"RELACION DE CITAS POR MEDICO"<<endl;
    for (int i = 0; medicoDatos[i]; i++) {
        imprimirLinea('=',MAX_CAR,archReporte);
        archReporte<<setw(15)<<"CODIGO"<<setw(50)<<"Nombre"
                   <<"TARIFA POR HORA DE CONSULTA:   "<<medicoTarifaHora[i]<<endl;
        archReporte<<left<<setw(10)<<medicoDatos[i][0]<<setw(50)<<medicoDatos[i][1]<<endl;
        imprimirLinea('-',MAX_CAR,archReporte);
        archReporte<<"RELACION DE PACIENTES ATENDIDOS:"<<endl;
        imprimirLinea('-',MAX_CAR,archReporte);
        archReporte<<left<<"       "<<setw(10)<<"DNI"<<setw(50)<<"Nombre"
                    <<setw(25)<<"Cantidad de citas"<<setw(25)<<"Tiempo total (hrs)"<<"Pago total"<<endl;
        imprimirLinea('-',MAX_CAR,archReporte);
        if(citaPaciente[i])
            imprimirCitasReporte(archReporte,citaPaciente[i],citaCantidad[i],citaTiempoYPago[i]);
    }
}

void imprimirCitasReporte(ofstream &arch,char ***citaPaciente,int *citaCantidad,double **citaTiempoYPago){
    int TotalCitas = 0;
    double TotalTiempo=0,PagoTotal=0;
    for (int i = 0; citaPaciente[i]; i++) {
        arch<<right<<setw(2)<<(i+1)<<')'<<"    "<<left<<setw(10)<<citaPaciente[i][0]
            <<setw(55)<<citaPaciente[i][1]<<right<<setw(5)<<citaCantidad[i]
            <<setw(25)<<citaTiempoYPago[i][0]<<setw(24)<<citaTiempoYPago[i][1]<<left<<endl;
        TotalCitas += citaCantidad[i];
        TotalTiempo += citaTiempoYPago[i][0];
        PagoTotal += citaTiempoYPago[i][1];
    }
    imprimirLinea('-',MAX_CAR,arch);
    arch<<left<<setw(17)<<" "<<setw(55)<<"TOTAL:"<<right<<setw(5)<<TotalCitas
        <<setw(25)<<TotalTiempo<<setw(24)<<PagoTotal<<left<<endl;
    imprimirLinea('=',MAX_CAR,arch);
}

void imprimirLinea(char car, int cantidad, ofstream &arch){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}