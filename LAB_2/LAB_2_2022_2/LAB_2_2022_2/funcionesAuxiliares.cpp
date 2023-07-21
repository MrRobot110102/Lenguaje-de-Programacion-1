/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/* 
 * File:   funcionesAuxiliares.cpp
 * Author: Sebastian Esquivel Barreto
 * 20190638
 *
 * Created on 20 de abril de 2023, 16:23
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "funcionesAuxiliares.h"

void crearArchivos(){
    int dniPaciente,cantMedicamentos,dd,mm,aa,codMedicamento;
    double precio;
    char car,codMedico[10],nombreMedico[100],nombrePaciente[100],desc[100];
    
    ifstream archDatos("Medico-Paciente-Medicinas.txt",ios::in);
    if(not archDatos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Medico-Paciente-Medicinas.txt"<<endl;
        exit(1);
    }
    ofstream archMedicos("Medicos.txt",ios::out);
    if(not archMedicos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Medicos.txt"<<endl;
        exit(1);
    }
    ofstream archPacientesBin("Pacientes.bin",ios::out | ios::binary);
    if(not archPacientesBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pacientes.bin"<<endl;
        exit(1);
    }
    ofstream archMedicinasBin("Medicinas.bin",ios::out | ios::binary);
    if(not archMedicinasBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Medicinas.bin"<<endl;
        exit(1);
    }
    ofstream archConsultas("Consultas.txt",ios::out);
    if(not archConsultas.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Consultas.txt"<<endl;
        exit(1);
    }
    
    while(true){
        archDatos>>dniPaciente;
        if(archDatos.eof()) break;
        if(archDatos.fail()){
            archDatos.clear();
            archDatos>>codMedico>>nombreMedico;
            insertarMedicos(archMedicos,codMedico,nombreMedico);
        }else{
            archDatos>>nombrePaciente>>codMedico>>dd>>car>>mm>>car>>aa>>cantMedicamentos;
            insertarPacientes(archPacientesBin,dniPaciente,nombrePaciente);
            insertarConsultas(archConsultas,dniPaciente,codMedico,dd,mm,aa,cantMedicamentos);
            for (int i = 0; i < cantMedicamentos; i++) {
                archDatos>>codMedicamento>>desc>>precio;
                insertarMedicinas(archMedicinasBin,codMedicamento,desc,precio);
                insertarConsultasMedicinas(archConsultas,codMedicamento);
            }
            archConsultas<<endl;
        }
    }
    
}

void insertarMedicos(ofstream &archMedicos,char *codMedico,char *nombreMedico){
    char especialidad[60];
    obtenerEspecialidad(nombreMedico,especialidad);
    archMedicos<<left<<setw(10)<<codMedico<<setw(60)<<nombreMedico
               <<setw(30)<<especialidad<<endl;
}

int cantidadPalabra(char *palabra){
    int i=0;
    while(palabra[i]) i++;
    return i;
}

void obtenerEspecialidad(char *nombre,char *especialidad){
    int cantPal = cantidadPalabra(nombre);
    int aux,i,j=0;
    for (i = cantPal-1; i > 0; i--) {
        if(nombre[i] == '_'){
            aux = i+1;
            break;
        }
    }
    while(aux <= cantPal){
        especialidad[j] = nombre[aux];
        j++;
        aux++;
    }
    nombre[i] = nombre[cantPal];
}

void darFormato(char *nombre){
    int i=0;
    while(nombre[i]){
        if(nombre[i] == '_') nombre[i] = ' ';
        i++;
    }
}

void insertarPacientes(ofstream &archPacientesBin,int dniPaciente,char *nombrePaciente){
    int dupli = duplicado(dniPaciente,"Pacientes.bin");
    double gasto = 0.0;
    if(not dupli){
        archPacientesBin.write(reinterpret_cast<const char *>(&dniPaciente),sizeof(int));
        archPacientesBin.write(reinterpret_cast<const char *>(nombrePaciente),sizeof(char) * 100);
        archPacientesBin.write(reinterpret_cast<const char *>(&gasto),sizeof(double));
        archPacientesBin.flush();
    }
}

void insertarMedicinas(ofstream &archMedicinasBin,int codMedicamento,char *desc,double precio){
    int dupli = duplicado(codMedicamento,"Medicinas.bin");
    double gasto = 0.0;
    if(not dupli){
        archMedicinasBin.write(reinterpret_cast<const char *>(&codMedicamento),sizeof(int));
        archMedicinasBin.write(reinterpret_cast<const char *>(desc),sizeof(char) * 100);
        archMedicinasBin.write(reinterpret_cast<const char *>(&precio),sizeof(double));
        archMedicinasBin.flush();
    }
}

int duplicado(int dni,const char *nombreArch){
    int dniP;
    ifstream archPacBin(nombreArch,ios::in | ios::binary);
    if(not archPacBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pacientes/Medicinas.bin"<<endl;
        exit(1);
    }
    archPacBin.seekg(0,ios::beg);
    while(true){
        archPacBin.read(reinterpret_cast<char *>(&dniP),sizeof(int));
        if(archPacBin.eof()) return 0; //no es repetido
        if(dni == dniP) return 1; //repetido
        else archPacBin.seekg(sizeof(char) * 100 + sizeof(double),ios::cur);
    }
}

void insertarConsultas(ofstream &archConsultas,int dniPaciente,char *codMedico,
                       int dd,int mm, int aa, int cantMedicamentos){
    int fecha = aa * 10000 +  mm * 100 + dd;
    archConsultas<<left<<setw(15)<<dniPaciente<<setw(15)<<codMedico<<setw(15)<<fecha
                 <<right<<setw(2)<<cantMedicamentos;
}

void insertarConsultasMedicinas(ofstream &archConsultas,int codMedicamento){
    archConsultas<<left<<"    "<<setw(10)<<codMedicamento;
}

void imprimirLinea(char car, int cantidad,ofstream &archReporte){
    for (int i = 0; i < cantidad; i++) archReporte<<car;
    archReporte<<endl;
}

void mostrarArchivos(){
    ifstream archMedicos("Medicos.txt",ios::in);
    if(not archMedicos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Medicos.txt"<<endl;
        exit(1);
    }
    ifstream archPacientesBin("Pacientes.bin",ios::in | ios::binary);
    if(not archPacientesBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pacientes.bin"<<endl;
        exit(1);
    }
    ifstream archMedicinasBin("Medicinas.bin",ios::in | ios::binary);
    if(not archMedicinasBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Medicinas.bin"<<endl;
        exit(1);
    }
    ifstream archConsultas("Consultas.txt",ios::in);
    if(not archConsultas.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Consultas.txt"<<endl;
        exit(1);
    }
    ofstream archReporte("Reporte.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se puede abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    
    archReporte.precision(2);archReporte<<fixed;
    
    archReporte<<right<<setw(65)<<"EMPRESA PRESTADORA DE SALUD EPS-LP1"<<endl;
    
    imprimirLinea('=',120,archReporte);
    archReporte<<right<<setw(65)<<"STAF DE MEDICOS"<<endl;
    archReporte<<right<<setw(20)<<"CODIGO"<<setw(10)<<"NOMBRE"<<setw(70)<<"ESPECIALIDAD"<<endl;
    mostrarMedicos(archMedicos,archReporte);
    
    imprimirLinea('=',120,archReporte);
    archReporte<<right<<setw(65)<<"PACIENTES REGISTRADOS"<<endl;
    archReporte<<right<<setw(20)<<"DNI"<<setw(10)<<"NOMBRE"<<setw(70)<<"GASTOS POR MEDICINAS"<<endl;
    mostrarPacientesBin(archPacientesBin,archReporte);
    
    imprimirLinea('=',120,archReporte);
    archReporte<<right<<setw(65)<<"MEDICINAS EN STOCK"<<endl;
    archReporte<<right<<setw(20)<<"CODIGO"<<setw(10)<<"DESCRIPCION"<<setw(70)<<"PRECIO"<<endl;
    mostrarMedicinas(archMedicinasBin,archReporte);
    
    imprimirLinea('=',120,archReporte);
    archReporte<<right<<setw(65)<<"RELACION DE CONSULTAS"<<endl;
    archReporte<<right<<setw(15)<<"PACIENTE"<<setw(15)<<"MEDICO"<<setw(10)<<"FECHA"
        <<setw(30)<<"CANTIDAD DE MEDICINAS"<<setw(30)<<"CODIGOS DE MEDICAMENTOS"<<endl;
    mostrarConsultas(archConsultas,archReporte);  
}

void mostrarMedicos(ifstream &archMedicos,ofstream &archReporte){
    int i=1;
    char codMedico[10],nombreMedico[100],especialidad[60];
    
    while(true){
        archMedicos>>codMedico;
        if(archMedicos.eof()) break;
        archMedicos>>nombreMedico>>especialidad;
        darFormato(nombreMedico);
        archReporte<<right<<setw(5)<<" "<<setw(2)<<i<<')'
                   <<left<<"   "<<setw(15)<<codMedico
                   <<setw(65)<<nombreMedico<<especialidad<<endl;
        i++;
    }
}

void mostrarPacientesBin(ifstream &archPacientesBin,ofstream &archReporte){
    int dniPaciente,i=1;
    double gasto,totalGasto=0.0;
    char nombrePaciente[100];
    
    while(true){
        archPacientesBin.read(reinterpret_cast<char *>(&dniPaciente),sizeof(int));
        if(archPacientesBin.eof()) break;
        archPacientesBin.read(reinterpret_cast<char *>(nombrePaciente),sizeof(char) * 100);
        archPacientesBin.read(reinterpret_cast<char *>(&gasto),sizeof(double));
        archReporte<<right<<setw(5)<<" "<<setw(2)<<i<<')'
                   <<left<<"   "<<setw(15)<<dniPaciente
                   <<setw(65)<<nombrePaciente<<right<<setw(10)<<gasto<<endl;
        totalGasto += gasto;
        i++;
    }
    archReporte<<right<<setw(85)<<"Total de gastos: "<<totalGasto<<endl;
}

void mostrarMedicinas(ifstream &archMedicinasBin,ofstream &archReporte){
    int codMedicamento,i=1;
    double precio;
    char desc[100];
    
    while(true){
        archMedicinasBin.read(reinterpret_cast<char *>(&codMedicamento),sizeof(int));
        if(archMedicinasBin.eof()) break;
        archMedicinasBin.read(reinterpret_cast<char *>(desc),sizeof(char) * 100);
        archMedicinasBin.read(reinterpret_cast<char *>(&precio),sizeof(double));
        archReporte<<right<<setw(5)<<" "<<setw(2)<<i<<')'
                   <<left<<"   "<<setw(15)<<codMedicamento
                   <<setw(65)<<desc<<right<<setw(10)<<precio<<endl;
        i++;
    }
}

void mostrarConsultas(ifstream &archConsultas,ofstream &archReporte){
    int dniPaciente,cantMedicamentos,dd,mm,aa,codMedicamento,i=1,fecha;
    char codMedico[10],nombreMedico[100],nombrePaciente[100],desc[100];
    
    while(true){
        archConsultas>>dniPaciente;
        if(archConsultas.eof()) break;
        archConsultas>>codMedico>>fecha>>cantMedicamentos;
        aa = fecha/10000;
        fecha = fecha % 10000;
        mm = fecha/100;
        dd = fecha%100;
        archReporte<<right<<setw(5)<<" "<<setw(2)<<i<<')'
                   <<left<<"   "<<setw(15)<<dniPaciente
                   <<setw(15)<<codMedico<<right<<setfill('0')
                   <<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aa
                   <<left<<setfill(' ')<<setw(8)<<" "<<setw(10)<<cantMedicamentos;
        for (int j = 0; j < cantMedicamentos; j++) {
            archConsultas>>codMedicamento;
            archReporte<<setw(10)<<codMedicamento;
        }
        archReporte<<endl;
        i++;
    }
}

double obtenerPrecioMedicamento(int codMedicamento,ifstream &archMedicinasBin){
    int codigoMedicamento;
    double precio;
    char desc[100];
    
    archMedicinasBin.seekg(0,ios::beg);
    
    while(true){
       archMedicinasBin.read(reinterpret_cast<char *>(&codigoMedicamento),sizeof(int));
       if(archMedicinasBin.eof()) break;
       if(codigoMedicamento == codMedicamento){
           archMedicinasBin.seekg(sizeof(char) * 100,ios::cur);
           archMedicinasBin.read(reinterpret_cast<char *>(&precio),sizeof(double));
           return precio;
       }else archMedicinasBin.seekg(sizeof(char) * 100 + sizeof(double),ios::cur);
    }
}

void actualizaPacienteBin(){
    int dniPaciente,cantMedicamentos,dd,mm,aa,codMedicamento,i=1,fecha;
    double gasto_total;
    char codMedico[10],nombreMedico[100],nombrePaciente[100],desc[100];
    fstream archPacienteBin("Pacientes.bin", ios::in | ios:: out | ios::binary);
    if(not archPacienteBin.is_open()){
        cout<<"ERROR: No se puede abrir el archivo Paciente.bin"<<endl;
        exit(1);
    }
    ifstream archConsultas("Consultas.txt",ios::in);
    if(not archConsultas.is_open()){
        cout<<"ERROR: No se puede abrir el archivo Consultas.txt"<<endl;
        exit(1);
    }
    ifstream archMedicinasBin("Medicinas.bin",ios::in | ios::binary);
    if(not archMedicinasBin.is_open()){
        cout<<"ERROR: No se puede abrir el archivo Consultas.txt"<<endl;
        exit(1);
    }
    
    int tamDelRegistro,tamDelArchivo,numRegistros;
    tamDelRegistro = sizeof(int) + sizeof(char) * 100 + sizeof(double);
    archPacienteBin.seekg(0,ios::end);
    tamDelArchivo = archPacienteBin.tellg();
    archPacienteBin.seekg(0,ios::beg);
    numRegistros = tamDelArchivo/tamDelRegistro;
    
    while(true){
        gasto_total = 0;
        archConsultas>>dniPaciente;
        if(archConsultas.eof()) break;
        archConsultas>>codMedico>>fecha>>cantMedicamentos;
        for (int i = 0; i < cantMedicamentos; i++) {
            archConsultas>>codMedicamento;
            gasto_total += obtenerPrecioMedicamento(codMedicamento,archMedicinasBin);
        }
        actualizarGastoPaciente(dniPaciente,gasto_total,archPacienteBin,numRegistros,tamDelRegistro);
    }
}

void actualizarGastoPaciente(int dni,double gasto_total,fstream &archPacienteBin,int numRegistros,int tamDelRegistro){
    int dniPaciente;
    double gasto;
    char nombrePaciente[100];
    
    archPacienteBin.seekg(0,ios::beg);
    for (int i = 0; i < numRegistros; i++) {
        archPacienteBin.read(reinterpret_cast<char *>(&dniPaciente),sizeof(int));
        if(dniPaciente == dni){
            archPacienteBin.seekg(sizeof(char) * 100,ios::cur);
            archPacienteBin.read(reinterpret_cast<char *>(&gasto),sizeof(double));
            gasto += gasto_total;
            archPacienteBin.seekg(i*tamDelRegistro,ios::beg);
            archPacienteBin.seekg(sizeof(char) * 100 + sizeof(int),ios::cur);
            archPacienteBin.write(reinterpret_cast<const char *>(&gasto),sizeof(double));
            break;
        }else archPacienteBin.seekg(sizeof(char) * 100 + sizeof(double),ios::cur);
    }
}