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

void cargarAlumnos(int *&codigo,char **&nombre,char ***&cursos){
    int buff[100],numDatos=0,cod;
    char *buffNom[100], **buffCursos[100];
    ifstream archAlumCursos("Alumnos-Cursos.csv",ios::in);
    if(not archAlumCursos.is_open()){
        cout<<"ERROR: No se puede abrir el archivo"<<endl;
        exit(1);
    }
    
    while(true){
        archAlumCursos>>cod;
        if(archAlumCursos.eof()) break;
        archAlumCursos.get();
        buff[numDatos] = cod;
        buffNom[numDatos] = leerNombre(archAlumCursos);
        buffCursos[numDatos] = leerCursos(archAlumCursos);
        numDatos++;
    }
    buff[numDatos] = 0;
    buffNom[numDatos] = nullptr;
    buffCursos[numDatos] = nullptr;
    numDatos++;
    codigo = new int[numDatos];
    nombre = new char*[numDatos];
    cursos = new char **[numDatos];
    for (int i = 0; i < numDatos; i++) {
        codigo[i] = buff[i];
        nombre[i] = buffNom[i];
        cursos[i] = buffCursos[i];
    }
}

char *leerNombre(ifstream &arch){
    char buffCad[100],*nombre;
    arch.getline(buffCad,100,',');
    nombre = new char[strlen(buffCad) + 1];
    strcpy(nombre,buffCad);
    return nombre;  
}

char **leerCursos(ifstream &arch){
    int numDatos = 0;
    char *buff[100],**cursos;
    while(true){
        buff[numDatos] = leerCurso(arch);
        numDatos++;
        if(arch.get() == '\n') break;
    }
    buff[numDatos] = nullptr;
    numDatos++;
    cursos = new char *[numDatos];
    for (int i = 0; i < numDatos; i++) cursos[i] = buff[i];
    return cursos;
}

char *leerCurso(ifstream &arch){
    char *curso = new char[7];
    arch.get(curso,7);
    return curso;
}

void imprimirAlumnos(int *codigo,char **nombre,char ***cursos){
    for (int i = 0; nombre[i]; i++) {
        cout<<right<<setw(10)<<codigo[i]<<" "<<left<<setw(45)<<nombre[i]<<endl;
        imprimeCursos(cursos[i]);
    }
}

void imprimeCursos(char **cursos){
    for(int i=0; cursos[i]; i++)
        cout<<right<<setw(20)<<cursos[i]<<endl;
}