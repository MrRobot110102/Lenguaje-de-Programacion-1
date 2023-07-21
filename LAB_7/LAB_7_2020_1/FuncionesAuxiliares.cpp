/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Curso.h"
#include "Alumno.h"
#include "ACurso.h"
#include "FuncionesAuxiliares.h"

void leerAlumnos(class Alumno *alumnos,const char *nombArch){
    ifstream archAlumnos(nombArch,ios::in);
    if(not archAlumnos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numAlumnos = 0;
    while (true) {
        archAlumnos>>alumnos[numAlumnos];
        if(archAlumnos.eof()) break;
        numAlumnos++;
    }
}
    
void agregarCursos(class Alumno *alumnos,const char *nombArch){
    ifstream archCursos(nombArch,ios::in);
    if(not archCursos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class ACurso curso;
    int pos;
    while (true) {
        archCursos>>curso;
        if(archCursos.eof()) break;
        pos = buscarAlumno(alumnos,curso.GetCodigo());
        if(pos != -1) alumnos[pos] + curso;
    }
}
    
void realizarCorreciones(class Alumno *alumnos,const char *nombArch){
    ifstream archCorreciones(nombArch,ios::in);
    if(not archCorreciones.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class ACurso curso;
    int pos;
    while (true) {
        archCorreciones>>curso;
        if(archCorreciones.eof()) break;
        pos = buscarAlumno(alumnos,curso.GetCodigo());
        if(pos != -1){
            if(curso.GetOperacion() == 'A') alumnos[pos] * curso;
            else if(curso.GetOperacion() == 'E') alumnos[pos] - curso;
        }
    }
}
    
void imprimirAlumnos(class Alumno *alumnos,const char *nombArch){
    ofstream archAlumnosReporte("AlumnosReporte.txt",ios::out);
    if(not archAlumnosReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for (int i = 0; alumnos[i].GetCodigo(); i++) archAlumnosReporte<<alumnos[i];
}

int buscarAlumno(class Alumno *alumnos,int codigo){
    for (int i = 0; alumnos[i].GetCodigo(); i++) if(alumnos[i].GetCodigo() == codigo) return i;
    return -1;
}

int buscarCurso(int dato, int *cursos){
    for(int i=0;cursos[i];i++) if(dato==cursos[i]) return i;
    return -1;
}