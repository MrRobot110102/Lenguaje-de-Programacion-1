/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "funcionesAuxiliares.h"

void crearArchAlumnosBin(){
    int codigo,codigoCarne;
    char car,nombre[100],especialidad[50],facultad[5];
    ifstream archAlum("Alumnos.txt",ios::in);
    if(not archAlum.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Alumnos.txt"<<endl;
        exit(1);
    }
    ofstream archAlumBin("Alumnos.Bin",ios::out | ios::binary);
    if(not archAlumBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Alumnos.bin"<<endl;
        exit(1);
    }
    while(true){
        archAlum>>car;
        if(archAlum.eof()) break;
        archAlum>>codigo>>nombre>>codigoCarne;
        if(archAlum.fail()){
            archAlum.clear();
            codigoCarne = 0;
        }
        archAlum>>especialidad>>facultad;
        archAlumBin.write(reinterpret_cast<const char *>(&codigo),sizeof(int));
        archAlumBin.write(reinterpret_cast<const char *>(nombre),sizeof(char) * 100);
        archAlumBin.write(reinterpret_cast<const char *>(&car),sizeof(char));
        archAlumBin.write(reinterpret_cast<const char *>(&codigoCarne),sizeof(int));
        archAlumBin.write(reinterpret_cast<const char *>(facultad),sizeof(char) * 5);
        archAlumBin.write(reinterpret_cast<const char *>(especialidad),sizeof(char) * 50);
    }
}

void crearArchConsolidadoBin(){
    int codigo,codigoCarne,sumaNotas=0,cantCursos=0,estado=0;
    double cantCred=0.0,cantCredAprob=0.0;
    char car,nombre[100],facultad[5],especialidad[50];
    
    
    ifstream archAlumBin("Alumnos.bin",ios::in | ios::binary);
    if(not archAlumBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Alumnos.bin"<<endl;
        exit(1);
    }
    ofstream archConsBin("Consolidado.Bin",ios::out | ios::binary);
    if(not archConsBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Consolidado.bin"<<endl;
        exit(1);
    }
    while(true){
        archAlumBin.read(reinterpret_cast< char *>(&codigo),sizeof(int));
        if(archAlumBin.eof()) break;
        archAlumBin.read(reinterpret_cast< char *>(nombre),sizeof(char) * 100);
        archAlumBin.read(reinterpret_cast< char *>(&car),sizeof(char));
        archAlumBin.read(reinterpret_cast< char *>(&codigoCarne),sizeof(int));
        archAlumBin.read(reinterpret_cast< char *>(facultad),sizeof(char) * 5);
        archAlumBin.read(reinterpret_cast< char *>(especialidad),sizeof(char) * 50);
                
        archConsBin.write(reinterpret_cast<const char *>(&codigo),sizeof(int));
        archConsBin.write(reinterpret_cast<const char *>(nombre),sizeof(char) * 100);
        archConsBin.write(reinterpret_cast<const char *>(&cantCred),sizeof(double));
        archConsBin.write(reinterpret_cast<const char *>(&cantCredAprob),sizeof(double));
        archConsBin.write(reinterpret_cast<const char *>(&sumaNotas),sizeof(int));
        archConsBin.write(reinterpret_cast<const char *>(&cantCursos),sizeof(int));
        archConsBin.write(reinterpret_cast<const char *>(facultad),sizeof(char) *5);
        archConsBin.write(reinterpret_cast<const char *>(&estado),sizeof(int));
    }
}

void mostrarArchConsolidadoBin(){
    int codigo,sumaNotas,cantCursos,estado;
    double cantCred,cantCredAprob;
    char nombre[100],facultad[5],especialidad[50];
    
    ifstream archConsBin("Consolidado.Bin",ios::in | ios::binary);
    if(not archConsBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Consolidado.bin"<<endl;
        exit(1);
    }
    
    ofstream archReporte("Reporte.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    
    while(true){      
        archConsBin.read(reinterpret_cast< char *>(&codigo),sizeof(int));
        if(archConsBin.eof()) break;
        archConsBin.read(reinterpret_cast< char *>(nombre),sizeof(char) * 100);
        archConsBin.read(reinterpret_cast< char *>(&cantCred),sizeof(double));
        archConsBin.read(reinterpret_cast< char *>(&cantCredAprob),sizeof(double));
        archConsBin.read(reinterpret_cast< char *>(&sumaNotas),sizeof(int));
        archConsBin.read(reinterpret_cast< char *>(&cantCursos),sizeof(int));
        archConsBin.read(reinterpret_cast< char *>(facultad),sizeof(char) *5);
        archConsBin.read(reinterpret_cast< char *>(&estado),sizeof(int));
        
        archReporte<<left<<setw(10)<<codigo<<setw(100)<<nombre
                   <<right<<setw(5)<<cantCred<<setw(5)<<cantCredAprob
                   <<setw(10)<<sumaNotas<<setw(5)<<cantCursos<<left<<setw(5)<<" "
                   <<setw(6)<<facultad<<setw(5)<<estado<<endl;
    }
}

void actualizarArchConsolidadoBin(){
    int codigoAlum,nota,codigo,sumaNotas,cantCursos,estado;
    double creditos,cantCred,cantCredAprob;
    char datos[10],facultad[5];
    
    ifstream archCursos("Cursos.txt",ios::in);
    if(not archCursos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Cursos.txt"<<endl;
        exit(1);
    }
    fstream archConsBin("Consolidado.Bin",ios::in | ios::out | ios::binary);
    if(not archConsBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Consolidado.bin"<<endl;
        exit(1);
    }
    
    int tamDelRegistro,tamDelArchivo,numRegistros;
    tamDelRegistro = sizeof(int) * 4 + sizeof(char) * 105 + sizeof(double) * 2;
    archConsBin.seekg(0,ios::end);
    tamDelArchivo = archConsBin.tellg();
    archConsBin.seekg(0,ios::beg);
    numRegistros = tamDelArchivo/tamDelRegistro;
    
    while(true){
        archCursos>>codigoAlum;
        if(archCursos.eof()) break;
        archCursos>>datos>>nota>>datos>>creditos;
        archConsBin.seekg(0,ios::beg);
        for (int i = 0; i < numRegistros; i++) {
            archConsBin.read(reinterpret_cast<char *>(&codigo),sizeof(int));
            if(codigo == codigoAlum){
                archConsBin.seekg(sizeof(char)*100,ios::cur);
                archConsBin.read(reinterpret_cast< char *>(&cantCred),sizeof(double));
                archConsBin.read(reinterpret_cast< char *>(&cantCredAprob),sizeof(double));
                archConsBin.read(reinterpret_cast< char *>(&sumaNotas),sizeof(int));
                archConsBin.read(reinterpret_cast< char *>(&cantCursos),sizeof(int));
                archConsBin.read(reinterpret_cast< char *>(facultad),sizeof(char) *5);
                archConsBin.read(reinterpret_cast< char *>(&estado),sizeof(int));
                cantCred = cantCred + creditos;
                if(nota >= 11) cantCredAprob = cantCredAprob + creditos;
                sumaNotas = sumaNotas + nota;
                cantCursos = cantCursos + 1;
                if(cantCredAprob >= 45) estado = 1;
                archConsBin.seekg(i*tamDelRegistro,ios::beg);
                archConsBin.seekg(sizeof(int) + sizeof(char)*100,ios::cur);
                archConsBin.write(reinterpret_cast<const char*> (&cantCred),sizeof(double));
                archConsBin.write(reinterpret_cast<const char*> (&cantCredAprob),sizeof(double));
                archConsBin.write(reinterpret_cast<const char*> (&sumaNotas),sizeof(int));
                archConsBin.write(reinterpret_cast<const char*> (&cantCursos),sizeof(int));
                archConsBin.seekg(sizeof(char)*5,ios::cur);
                archConsBin.write(reinterpret_cast<const char*> (&estado),sizeof(int));
            }else{
                archConsBin.seekg(sizeof(int)*3+sizeof(double)*2+sizeof(char)*105,ios::cur);
            }
        }
    }
}

void imprimirLinea(char car, int cantidad,ofstream &reporte){
    for (int i = 0; i < cantidad; i++) reporte<<car;
    reporte<<endl;
}

void generarEncabezado(ofstream &reporte){
    reporte<<"CONSOLIDADO DE NOTAS DE LOS ALUMNOS"<<endl;
    imprimirLinea('=',120,reporte);
    reporte<<left<<setw(10)<<"CODIGO"<<setw(65)<<"NOMBRE"<<setw(15)<<"CARNE"
           <<setw(20)<<"CRED. CURSADOS"<<setw(20)<<"CRED. APROBADOS"
            <<setw(10)<<"PROMEDIO"<<setw(10)<<"ESTADO"<<endl;
    imprimirLinea('=',120,reporte);
}

void mostrarArchReporteFinal(){
    int codigo,sumaNotas,cantCursos,estado;
    double cantCred,cantCredAprob;
    char nombre[100],facultad[5];
    
    ofstream archRepFinal("ReporteFinal.txt",ios::out);
    if(not archRepFinal.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReporteFinal.txt"<<endl;
        exit(1);
    }
    ifstream archConsBin("Consolidado.Bin",ios::in | ios::binary);
    if(not archConsBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Consolidado.bin"<<endl;
        exit(1);
    }
    
    archRepFinal.precision(2);archRepFinal<<fixed;
    generarEncabezado(archRepFinal);
    
    while(true){
        archConsBin.read(reinterpret_cast< char *>(&codigo),sizeof(int));
        if(archConsBin.eof()) break;
        archConsBin.read(reinterpret_cast< char *>(nombre),sizeof(char) * 100);
        archConsBin.read(reinterpret_cast< char *>(&cantCred),sizeof(double));
        archConsBin.read(reinterpret_cast< char *>(&cantCredAprob),sizeof(double));
        archConsBin.read(reinterpret_cast< char *>(&sumaNotas),sizeof(int));
        archConsBin.read(reinterpret_cast< char *>(&cantCursos),sizeof(int));
        archConsBin.read(reinterpret_cast< char *>(facultad),sizeof(char) *5);
        archConsBin.read(reinterpret_cast< char *>(&estado),sizeof(int));
        archRepFinal<<right<<setfill('0')<<setw(8)<<codigo<<setfill(' ')<<"  "<<left
                    <<setw(65)<<nombre<<setw(15)<<" "<<setw(20)<<cantCred
                    <<setw(20)<<cantCredAprob<<setw(10)<<(double)sumaNotas/cantCursos;
        if(estado == 1) archRepFinal<<setw(10)<<"EGRESADO"<<endl;
        else archRepFinal<<setw(20)<<"NO EGRESADO"<<endl;
    }
}
