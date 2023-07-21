/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 28 de abril de 2023, 16:19
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "operadoresSobrecargados.h"
#include "Estructuras.h"


int main(int argc, char** argv) {
    ifstream archCursos("Cursos.txt",ios::in);
    ifstream archAlumnos("Alumnos.txt",ios::in);
    ifstream archRegMatricula("Matricula.txt",ios::in);
    ofstream repCursos("ReporteCursos.txt",ios::out);  
    ofstream repAlumnos("ReporteAlumnos.txt",ios::out);  
    struct StCurso curso,cursos[100];
    struct StAlumno alumno,alumnos[200];
    struct StRegistroDeMatricula regMatricula;
    
    strcpy(cursos[0].codigoDelCurso,"XXXXXX");
    while(true){
        if(archCursos>>curso) cursos += curso;
        else break;
    }
    
    alumnos[0].semestre = 0;
    while(true){
        if(archAlumnos>>alumno) alumnos += alumno;
        else break;
    }
    
    while(true){
        if(archRegMatricula>>regMatricula){
            //repAlumnos<<regMatricula.codigoDelCurso<<endl;
            alumnos *= regMatricula;
            cursos *= regMatricula;
        }else break;        
    }
    
    for (int i = 0; strcmp(cursos[i].codigoDelCurso,"XXXXXX") != 0; i++) repCursos<<cursos[i];
    for (int i = 0; alumnos[i].semestre != 0; i++) repAlumnos<<alumnos[i];
    return 0;
}

