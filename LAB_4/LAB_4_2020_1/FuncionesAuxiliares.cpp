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

void leerAlumnos(int *&codigos,char **&nombres,char ***&cursos){
    int codigo,buffCodigos[100],numDatos = 0;
    char *buffNombres[100],buff[50];
    char tipo;
    ifstream archAlumnos("Alumnos.csv",ios::in);
    if(not archAlumnos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Alumnos.csv"<<endl;
        exit(1);
    }
    while(true){
        archAlumnos>>tipo;
        if(archAlumnos.eof()) break;
        archAlumnos.get();
        archAlumnos>>codigo;
        archAlumnos.get();
        buffCodigos[numDatos] = codigo;
        buffNombres[numDatos] = leerNombre(archAlumnos);
        archAlumnos.getline(buff,50);
        numDatos++;
    }
    buffCodigos[numDatos] = 0;
    buffNombres[numDatos] = nullptr;
    numDatos++;
    codigos = new int[numDatos];
    nombres = new char*[numDatos];
    cursos = new char**[numDatos];
    for (int i = 0; i < numDatos; i++) {
        codigos[i] = buffCodigos[i];
        nombres[i] = buffNombres[i];
    }
    cursos[numDatos-1] = nullptr;
}

char *leerNombre(ifstream &arch){
    char *aux,buff[100];
    arch.getline(buff,100,',');
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}
    
void imprimirAlumnos(int *codigos,char **nombres){
    ofstream archReporte("ReporteAlumnos.txt",ios::out);
    for (int i = 0; codigos[i]; i++)
        archReporte<<left<<setw(15)<<codigos[i]<<setw(60)<<nombres[i]<<endl;
}
    
void leerCursos(int *codigos,char ***&cursos){
    ifstream archCursos("Cursos.csv",ios::in);
    if(not archCursos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Cursos.csv"<<endl;
        exit(1);
    }
    int numDatos[100]{},posicionAlumno,cod,nota,i;
    char *curso,buff[100];
    for (i = 0; codigos[i]; i++) cursos[i] = new char*[50];
    while(true){
        archCursos>>cod;
        if(archCursos.eof()) break;
        archCursos.get();
        curso = leerNombre(archCursos);
        archCursos>>nota;
        archCursos.getline(buff,100);
        if(nota >= 11){
            posicionAlumno = obtenerPosicionAlumno(codigos,cod);
            colocarCurso(curso,cursos[posicionAlumno],numDatos[posicionAlumno]);
        }
    }
    for (i = 0; codigos[i]; i++) espaciosExactos(cursos[i],numDatos[i]);
}

void espaciosExactos(char **&cursos,int numDatos){
    char **buffCursos;
    if(numDatos != 0){
        buffCursos = new char*[numDatos+1];
        for (int i = 0; i < numDatos; i++) buffCursos[i] = cursos[i];
        buffCursos[numDatos] = nullptr;
        delete cursos;
        cursos = buffCursos;
    }else{
        delete cursos;
        cursos = nullptr;
    }
}

void colocarCurso(char *curso,char **&cursos,int &numDatos){
    cursos[numDatos] = curso;
    numDatos++;
}

int obtenerPosicionAlumno(int *codigos,int cod){
    for (int i = 0; codigos[i]; i++) if(codigos[i] == cod) return i;
}
    
void imprimirReporte(int *codigos,char **nombres,char ***cursos){
    ofstream arch("ReporteCursos.txt",ios::out);
    for(int i=0;codigos[i];i++){
        imprimeLinea(arch,120,'=');
        arch<<setw(20)<<left<<"Codigo:"<<setw(10)<<left<<codigos[i]<<setw(10)
                <<left<<"Nombre: "<<nombres[i]<<endl;
        imprimeLinea(arch,120,'-');
        if(cursos[i]) imprimeCursos(cursos[i],arch);
        else arch<<"Cursos aprobados: El alumno no tiene cursos aprobados registrados"<<endl;
    }
    imprimeLinea(arch,120,'=');
}

void imprimeCursos(char **cursos,ofstream &arch){
    arch<<setw(15)<<left<<"Cursos aprobados: ";
    for(int i=0;cursos[i];i++) arch<<setw(10)<<left<<cursos[i];
    arch<<endl;
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}