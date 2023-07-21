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

void cargarAlumnos(int *&codigo,char **&nombre){
    int buffCodigo[100],numDatos = 0,cod;
    char *buffNombre[100];
    
    ifstream archAlumnos("Alumnos.csv",ios::in);
    if(not archAlumnos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Alumnos.csv"<<endl;
        exit(1);
    }
    while(true){
        archAlumnos>>cod;
        if(archAlumnos.eof()) break;
        archAlumnos.get();
        buffCodigo[numDatos] = cod;
        buffNombre[numDatos] = leeNombre(archAlumnos);
        numDatos++;
    }
    buffCodigo[numDatos] = 0;
    buffNombre[numDatos] = nullptr;
    numDatos++;
    codigo = new int[numDatos];
    nombre = new char*[numDatos];
    for (int i = 0; i < numDatos; i++) {
        codigo[i] = buffCodigo[i];
        nombre[i] = buffNombre[i];
    }

}

char *leeNombre(ifstream &arch){
    char *aux,buff[100];
    arch.getline(buff,100);
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}
    
void cargarCursos(int *codigo,char ***&cursos){
    int numDatos=0,posicionAlumno,cod,nd[100]{};
    ifstream archCursos("Cursos.csv",ios::in);
    if(not archCursos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Cursos.csv"<<endl;
        exit(1);
    }
    for (int i = 0; codigo[i]; i++) numDatos++;
    cursos = new char**[numDatos+1];
    for (int i = 0; i < numDatos; i++) cursos[i] = new char*[50];
    while(true){
        archCursos>>cod;
        if(archCursos.eof()) break;
        archCursos.get();
        posicionAlumno = buscarAlumno(codigo,cod);
        if(posicionAlumno != -1) agregarCursoAlumno(archCursos,cursos[posicionAlumno],nd[posicionAlumno]);
    }
    for (int i = 0; i < numDatos; i++) espaciosExactos(cursos[i],nd[i]);
    cursos[numDatos] = nullptr;
}

void espaciosExactos(char **&cursos,int numDatos){
    char **buffCursos;
    if(numDatos == 0){
        delete cursos;
        cursos = nullptr;
    }else{
        buffCursos = new char*[numDatos+1]; 
        for (int i = 0; i < numDatos; i++) buffCursos[i] = cursos[i];
        buffCursos[numDatos] = nullptr;
        delete cursos;
        cursos = buffCursos;
    }
}

int buscarAlumno(int *codigo,int cod){
    for (int i = 0; codigo[i]; i++) if(codigo[i] == cod) return i;
    return -1;
}

void agregarCursoAlumno(ifstream &arch,char **cursos,int &numCursos){
    char *curso;
    curso = leeCurso(arch);
    cursos[numCursos] = curso;
    numCursos++;
}

char *leeCurso(ifstream &arch){
    char *cur = new char[7];
    arch.getline(cur,7);
    return cur;
}
    
void reporteAlumnos(int *codigo,char **nombre,char ***cursos){
    for (int i = 0; codigo[i]; i++) {
        cout<<right<<setw(10)<<codigo[i]<<" "<<left<<setw(45)<<nombre[i]<<endl;
        if(cursos[i]) imprimeCursos(cursos[i]);
    }
}

void imprimeCursos(char **cursos){
    for(int i=0; cursos[i]; i++) cout<<right<<setw(20)<<cursos[i]<<endl;
}
