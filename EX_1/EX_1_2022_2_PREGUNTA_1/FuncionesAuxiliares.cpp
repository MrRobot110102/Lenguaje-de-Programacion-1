/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

//Sebastian Moises Esquivel Barreto
//20190638

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"
#define INCREMENTO 5
#define MAX_CAR 120

//    int *med_Codigo, ***consultas_int;
//    double *med_Precio;
//    char **med_Descripcion, ***consultas_char;
void CargarMedicamentos(int *&med_Codigo,char **&med_Descripcion,double *&med_Precio,const char *nombArch){
    ifstream archMedicamentos(nombArch,ios::in);
    if(not archMedicamentos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int codMedicamento;
    int numMedicamentos = 0,capMedicamentos = 0;
    char *descripcion;
    double precio;
    
    med_Codigo = nullptr;
    med_Descripcion = nullptr;
    med_Precio = nullptr;
    
    while(true){
        archMedicamentos>>codMedicamento;
        if(archMedicamentos.eof()) break;
        archMedicamentos.get();
        descripcion = leerCadena(archMedicamentos);
        archMedicamentos>>precio;
        if(numMedicamentos == capMedicamentos)
            aumentarEspacios(med_Codigo,med_Descripcion,med_Precio,numMedicamentos,capMedicamentos);
        med_Codigo[numMedicamentos] = 0;
        med_Codigo[numMedicamentos - 1] = codMedicamento;
        med_Descripcion[numMedicamentos] = nullptr;
        med_Descripcion[numMedicamentos - 1] = descripcion;
        med_Precio[numMedicamentos] = 0;
        med_Precio[numMedicamentos - 1] = precio;
        numMedicamentos++;
    }
}

void aumentarEspacios(int *&med_Codigo,char **&med_Descripcion,double *&med_Precio,int &numMedicamentos,int &capMedicamentos){
    int *auxC;
    char **auxD;
    double *auxP;
    capMedicamentos += INCREMENTO;
    if(med_Codigo == nullptr){
        med_Codigo = new int[capMedicamentos];
        med_Descripcion = new char*[capMedicamentos];
        med_Precio = new double[capMedicamentos];
        med_Codigo[0] = 0;
        med_Descripcion[0] = nullptr;
        med_Precio[0] = 0;
        numMedicamentos = 1;
    }else{
        auxC = new int[capMedicamentos];
        auxD = new char*[capMedicamentos];
        auxP = new double[capMedicamentos];
        for (int i = 0; i < numMedicamentos; i++) {
            auxC[i] = med_Codigo[i];
            auxD[i] = med_Descripcion[i];
            auxP[i] = med_Precio[i];
        }
        delete med_Codigo;
        delete med_Descripcion;
        delete med_Precio;
        med_Codigo = auxC;
        med_Descripcion = auxD;
        med_Precio = auxP;
    }
}

char *leerCadena(ifstream &arch){
    char *aux,buff[200];
    arch.getline(buff,200,',');
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}
    
void PruebaDeCargaDeMedicamentos(int *med_Codigo,char **med_Descripcion,double *med_Precio,const char *nombArch){
    ofstream archReporte(nombArch,ios::out);
    archReporte.precision(2);archReporte<<fixed;
    imprimirLinea('=',MAX_CAR,archReporte);
    archReporte<<left<<setw(10)<<"Codigo"<<setw(60)<<"Descripcion"<<setw(10)<<"Precio"<<endl;
    imprimirLinea('=',MAX_CAR,archReporte);
    for (int i = 0; med_Codigo[i]; i++) 
        archReporte<<left<<setw(10)<<med_Codigo[i]<<setw(60)<<med_Descripcion[i]
                   <<right<<setw(10)<<med_Precio[i]<<left<<endl;
}

//PARTE B    
void CargarConsultas(int ***&consultas_int,char ***&consultas_char,const char *nombArch){
    ifstream archConsultas(nombArch,ios::in);
    if(not archConsultas.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int fecha,dniPaciente,codMedicamento,cantidad,posPaciente,dd,mm,aa;
    char *nombPaciente, *codMed;
    int **buffConsultas_int[100],numDatos = 0,numMedicamentos[100]{},numMedicos[100]{};
    char **buffConsultas_char[100],car;
    for (int i = 0; i < 100; i++) {
        buffConsultas_int[i] = new int *[50];
        buffConsultas_char[i] = new char *[50];
    }
    while(true){
        archConsultas>>dd;
        if(archConsultas.eof()) break;
        leerDatosRestantes(dniPaciente,nombPaciente,dd,fecha,codMed,archConsultas);
        while(true){
            archConsultas>>codMedicamento>>car>>cantidad;
            posPaciente = obtenerPosicionPaciente(dniPaciente,buffConsultas_int,numDatos);
            if(posPaciente == -1){//no existe paciente, ademas se ingresa primera medicina
                ingresarPaciente(buffConsultas_int[numDatos],dniPaciente,fecha,codMedicamento,cantidad,numMedicamentos[numDatos],
                                 buffConsultas_char[numDatos],nombPaciente,codMed,numMedicos[numDatos]);
                numDatos++;
            }else{//ya exsite paciente, se actualiza cantidad de medicamentos o ingreso de nuevo medicamento
                ingresarPaciente(buffConsultas_int[posPaciente],dniPaciente,fecha,codMedicamento,cantidad,numMedicamentos[posPaciente],
                        buffConsultas_char[posPaciente],nombPaciente,codMed,numMedicos[posPaciente]);
            }
            if(archConsultas.get() == '\n') break;
        }
    }
    buffConsultas_int[numDatos] = nullptr;
    buffConsultas_char[numDatos] = nullptr;
    numDatos++;
    consultas_int = new int **[numDatos];
    consultas_char = new char **[numDatos];
    for (int i = 0; i < numDatos; i++) 
        espaciosExactos(consultas_int[i],buffConsultas_int[i],numMedicamentos[i],
                        consultas_char[i],buffConsultas_char[i],numMedicos[i]);
    for (int i = 0; i < 100; i++){
        delete buffConsultas_int[i];
        delete buffConsultas_char[i];
    }
}

void leerDatosRestantes(int &dniPaciente,char *&nombPaciente,int dd,int &fecha,char *&codMed, ifstream &arch){
    int mm,aa;
    char car;
    arch>>car>>mm>>car>>aa>>car>>dniPaciente>>car;
    fecha = aa * 10000 + mm * 100 + dd;
    nombPaciente = leerCadena(arch);
    codMed = leerCadena(arch);
}

void espaciosExactos(int **&consultas_int,int **&buffConsultas_int,int numDatos,
                     char **&consultas_char,char **&buffConsultas_char,int numMedicos){
    if(numDatos == 0){
        delete consultas_int;
        consultas_int = nullptr;
    }else{
        consultas_int = new int*[numDatos + 1];
        for (int i = 0; i < numDatos; i++) {
            consultas_int[i] = buffConsultas_int[i];
        }
        consultas_int[numDatos] = nullptr;
    }
    if(numMedicos == 0){
        delete consultas_char;
        consultas_char = nullptr;
    }else{
        consultas_char = new char*[numMedicos + 1];
        for (int i = 0; i < numMedicos; i++) {
            consultas_char[i] = buffConsultas_char[i];
        }
        consultas_char[numMedicos] = nullptr;
    }
}

int obtenerPosicionPaciente(int dni,int ***buffConsultas_int,int numDatos){
    for (int i = 0; i < numDatos; i++) if(*(buffConsultas_int[i][0]) == dni) return i;
    return -1;
}

void ingresarPaciente(int **&buffConsulta_int,int dni,int fecha, int codMedicamento,int cantidad,int &numMedicamentos,
                      char **&buffConsultas_char, char *nombPaciente, char *codMed,int &numMedicos){
    int *codCantidadMedicamento,*dniPaciente,*fechaPaciente,posMedicamento,posMedico;
    codCantidadMedicamento = new int[2];
    codCantidadMedicamento[0] = codMedicamento;
    codCantidadMedicamento[1] = cantidad;
    if(numMedicamentos == 0){
        dniPaciente = new int;
        *dniPaciente = dni;
        fechaPaciente = new int;
        *fechaPaciente = fecha;
        buffConsulta_int[numMedicamentos] = dniPaciente;
        numMedicamentos++;
        buffConsulta_int[numMedicamentos] = fechaPaciente;
        numMedicamentos++;
        buffConsulta_int[numMedicamentos] = codCantidadMedicamento;
        numMedicamentos++;
        buffConsultas_char[numMedicos] = nombPaciente;
        numMedicos++;
        buffConsultas_char[numMedicos] = codMed;
        numMedicos++;
    }else{
       posMedicamento = obtenerPosicionMedicamento(buffConsulta_int,codMedicamento,numMedicamentos);
       cambiarFecha(buffConsulta_int[1],fecha);
       if(posMedicamento == -1){//nuevo medicamento
           buffConsulta_int[numMedicamentos] = codCantidadMedicamento;
           numMedicamentos++;
       }else buffConsulta_int[posMedicamento][1] += cantidad;//actualizar cantidad de medicamentos en la posicion
       
       if(not existeMedico(buffConsultas_char,codMed,numMedicos)){
           buffConsultas_char[numMedicos] = codMed;
           numMedicos++;
       }
    }
}

bool existeMedico(char **buffConsultas_char,char *codMedico,int numMedicos){
    for (int i = 1; i < numMedicos; i++) 
        if(strcmp(buffConsultas_char[i],codMedico) == 0) return true;    
    return false;
}

void cambiarFecha(int *&buffConsulta_int,int fecha){
    if(*(buffConsulta_int) < fecha) *(buffConsulta_int) = fecha;
}

int obtenerPosicionMedicamento(int **buffConsulta_int,int codMedicamento,int numMedicamento){
    for (int i = 2; i < numMedicamento; i++) if(buffConsulta_int[i][0] == codMedicamento) return i;
    return -1;
}

    
void PruebaDeCargaDeConsultas(int ***consultas_int,char ***consultas_char,const char *nombArch){
    ofstream archReporte(nombArch,ios::out);
    for (int i = 0; consultas_int[i]; i++) {
        if(consultas_int[i]) imprimirInformacion(consultas_int[i],consultas_char[i],archReporte);
    }
}

void imprimirInformacion(int **consultas_int,char **consultas_char,ofstream &arch){
    arch<<left<<setw(10)<<*(consultas_int[0])<<setw(30)<<consultas_char[0]<<setw(10)<<*(consultas_int[1])<<endl;
    for (int i = 1; consultas_char[i]; i++) arch<<setw(10)<<consultas_char[i];
    arch<<endl;
    for (int i = 2; consultas_int[i]; i++) {
        arch<<setw(10)<<consultas_int[i][0]<<setw(10)<<consultas_int[i][1]<<endl;
    }
}
    
void ReporteDeGastos_e_IngresosMedicos(int *med_Codigo,char **med_Descripcion,double *med_Precio,
        int ***consultas_int,char ***consultas_char,const char *nombArch){
    ofstream archReporte(nombArch,ios::out);
    double totalIngreso = 0.0;
    archReporte.precision(2);archReporte<<fixed;
    imprimirLinea('=',MAX_CAR,archReporte);
    archReporte<<left<<"GASTOS MEDICOS POR PACIENTE"<<endl;
    for (int i = 0; consultas_int[i]; i++) {
        imprimirLinea('=',MAX_CAR,archReporte);
        archReporte<<left<<setw(10)<<"DNI"<<setw(30)<<"NOMBRE"
                   <<setw(20)<<"ULTIMA CONSULTA"<<"MEDICOS QUE LO ATENDIERON"<<endl;
        if(consultas_int[i]) imprimirDetalle(consultas_int[i],consultas_char[i],med_Codigo,med_Descripcion,med_Precio,archReporte,totalIngreso);
    }
    archReporte<<left<<"TOTAL DE INGRESOS POR MEDICINAS:"<<right<<setw(73)<<totalIngreso<<left<<endl;
    imprimirLinea('=',MAX_CAR,archReporte);
}

void imprimirDetalle(int **consultas_int,char **consultas_char,int *med_Codigo,
        char **med_Descripcion,double *med_Precio,ofstream &arch,double &totalIngreso){
    int dd,mm,aa,fecha,posMedicamento;
    double total = 0.0;
    fecha = *(consultas_int[1]);
    aa = fecha/10000;
    fecha = fecha%10000;
    mm = fecha/100;
    dd = fecha%100;
    arch<<left<<setw(10)<<*(consultas_int[0])<<setw(30)<<consultas_char[0]
        <<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aa<<left<<setfill(' ')<<"          ";
    for (int i = 1; consultas_char[i]; i++) arch<<setw(10)<<consultas_char[i];
    arch<<endl;
    imprimirLinea('-',MAX_CAR,arch);
    arch<<"MEDICAMENTOS QUE RECIBIO:"<<endl;
    imprimirLinea('-',MAX_CAR,arch);
    arch<<left<<setw(10)<<"CODIGO"<<setw(60)<<"DESCRIPCION"<<setw(15)<<"PRECIO"
        <<setw(15)<<"CANTIDAD"<<"TOTAL"<<endl;
    for (int i = 2; consultas_int[i]; i++) {
        posMedicamento = posicionMedicamento(consultas_int[i][0],med_Codigo);
        arch<<setw(10)<<consultas_int[i][0]<<setw(50)<<med_Descripcion[posMedicamento]
            <<right<<setw(16)<<med_Precio[posMedicamento]<<setw(14)<<consultas_int[i][1]
            <<setw(15)<<(med_Precio[posMedicamento] * consultas_int[i][1])<<left<<endl;
        total += (med_Precio[posMedicamento] * consultas_int[i][1]);
    }
    totalIngreso += total;
    imprimirLinea('-',MAX_CAR,arch);
    arch<<left<<"Total Gastado:"<<right<<setw(91)<<total<<left<<endl;
    imprimirLinea('=',MAX_CAR,arch);
}

int posicionMedicamento(int codMedicamento, int *med_Codigo){
    for (int i = 0; med_Codigo; i++) if(med_Codigo[i] == codMedicamento) return i;
}

void imprimirLinea(char car, int cantidad, ofstream &arch){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}