/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.cpp
 * Author: Sebastian
 * 
 * Created on 6 de julio de 2023, 23:36
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Tesoreria.h"

void Tesoreria::cargaAlumnos() {
    ifstream arch("Alumnos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<endl;
    }
    Lboletas.crearLista(arch);
}

void Tesoreria::imprimeAlumnos(const char *nombArch) {
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
    }
    Lboletas.imprimirLista(arch);
}

void Tesoreria::cargaCursos() {
    ifstream arch("Cursos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Cursos.csv"<<endl;
    }
    Lboletas.ingresaCursos(arch);
}

void Tesoreria::ordenarCursos() {
    Lboletas.ordenaCursos();
}

void Tesoreria::borrarCurso(const char* nombCurso) {
    Lboletas.eliminaCurso(nombCurso);
}

void Tesoreria::eliminaAlumnosSinCursos() {
    Lboletas.eliminaAlumnosSinCursos();
}

void Tesoreria::eliminaUnAlumno(int codigoAlumno) {
    Lboletas.eliminaUnAlumno(codigoAlumno);
}

void Tesoreria::eliminaRangoCursos(int semestre) {
    Lboletas.eliminaRangoCursos(semestre);
}

void Tesoreria::actualizar(int anio,int descuento) {
    Lboletas.actualiza(anio,descuento);
}









