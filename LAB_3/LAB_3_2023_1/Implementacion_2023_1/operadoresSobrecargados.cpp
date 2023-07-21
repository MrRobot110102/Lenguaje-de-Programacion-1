/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "operadoresSobrecargados.h"
#include "Estructuras.h"

bool operator >>(ifstream &arch,struct StCurso &curso){
    arch>>curso.codigoDelCurso;
    if(arch.eof()) return false;
    arch>>curso.nombreDelCurso>>curso.creditos>>curso.codigoDelProfesor>>curso.nombreDelProfesor;
    curso.numeroDeAlumnos = 0;
    curso.ingresos = 0.0;
    return true;
}

bool operator >>(ifstream &arch, struct StAlumno &alumno){
    char car;
    int porcentaje;
    arch>>alumno.semestre;
    if(arch.eof()) return false;
    arch>>car>>alumno.codigo>>alumno.nombre>>car>>porcentaje;
    if(not arch.fail()){
        if(car == 'S'){
            strcpy(alumno.modalidad,"SEMIPRESENCIAL");
            alumno.porcentaje = porcentaje;
            arch>>car>>alumno.escala;
        }else{
            strcpy(alumno.modalidad,"PRESENCIAL");
            alumno.escala = porcentaje;
            alumno.porcentaje = 0;
        }
    }else{
        arch.clear();
        strcpy(alumno.modalidad,"VIRTUAL");
        arch>>car>>alumno.escala;
        alumno.porcentaje = 0;
    }
    alumno.numeroDeCursos = 0;
    alumno.costoTotal = 0.0;
    return true;
}

bool operator >>(ifstream &arch,struct StRegistroDeMatricula &regMatricula){
    char car;
    arch>>regMatricula.codigoDelCurso;
    if(arch.eof()) return false;
    arch>>regMatricula.semestreDelAlumno>>car>>regMatricula.codigodelAlumno;
    return true;
}

void operator +=(struct StCurso *arrCursos,struct StCurso &curso){
    for (int i = 0; i < 150; i++) {
        if(strcmp(arrCursos[i].codigoDelCurso, "XXXXXX") == 0){
            strcpy(arrCursos[i].codigoDelCurso,curso.codigoDelCurso);
            strcpy(arrCursos[i].nombreDelCurso,curso.nombreDelCurso);   
            arrCursos[i].creditos = curso.creditos;
            arrCursos[i].codigoDelProfesor = curso.codigoDelProfesor;
            strcpy(arrCursos[i].nombreDelProfesor,curso.nombreDelProfesor); 
            arrCursos[i].numeroDeAlumnos = curso.numeroDeAlumnos;
            arrCursos[i].ingresos = curso.ingresos;
            strcpy(arrCursos[i+1].codigoDelCurso, "XXXXXX");
            break;
        }
    }
}

void operator +=(struct StAlumno *arrAlumnos,struct StAlumno &alumno){
    for (int i = 0; i < 150; i++) {
        if(arrAlumnos[i].semestre == 0){
            arrAlumnos[i].semestre = alumno.semestre;
            arrAlumnos[i].codigo = alumno.codigo;
            strcpy(arrAlumnos[i].nombre,alumno.nombre);
            strcpy(arrAlumnos[i].modalidad,alumno.modalidad);
            arrAlumnos[i].escala = alumno.escala;
            arrAlumnos[i].porcentaje = alumno.porcentaje;
            arrAlumnos[i].numeroDeCursos = alumno.numeroDeCursos;
            arrAlumnos[i].costoTotal = alumno.costoTotal;
            arrAlumnos[i+1].semestre = 0;
            break;
        }
    }
}

void operator *=(struct StCurso *arrCursos,struct StRegistroDeMatricula &regMatricula){
    int codAlumno;
    for (int i = 0; i < 150; i++) {
        if(strcmp(arrCursos[i].codigoDelCurso, "XXXXXX") != 0){
            if(strcmp(arrCursos[i].codigoDelCurso,regMatricula.codigoDelCurso) == 0){
                codAlumno = regMatricula.semestreDelAlumno * 10000 + regMatricula.codigodelAlumno;
                arrCursos[i].alumnos[arrCursos[i].numeroDeAlumnos] = codAlumno;
                arrCursos[i].numeroDeAlumnos++;
                break;
            }
        }
    }
}

void operator *=(struct StAlumno *arrAlumnos, struct StRegistroDeMatricula &regMatricula){
    for (int i = 0; i<150; i++) {
        if(arrAlumnos[i].semestre == regMatricula.semestreDelAlumno 
                and arrAlumnos[i].codigo == regMatricula.codigodelAlumno ){
            arrAlumnos[i].cursos[arrAlumnos[i].numeroDeCursos] = new char[7];
            strcpy(arrAlumnos[i].cursos[arrAlumnos[i].numeroDeCursos],regMatricula.codigoDelCurso);
            arrAlumnos[i].numeroDeCursos++;
            delete arrAlumnos[i].cursos[arrAlumnos[i].numeroDeCursos];
            break;
        }
    }
}

ofstream & operator <<(ofstream &arch,struct StCurso &curso){
    int codigo,semestre;
    arch.precision(2);arch<<fixed;
    arch<<left<<setw(10)<<curso.codigoDelCurso<<setw(30)<<curso.nombreDelCurso<<curso.creditos<<endl;
    arch<<"PROFESOR:   "<<setw(60)<<curso.nombreDelProfesor<<'['<<curso.codigoDelProfesor<<']'<<endl;
    arch<<"Alumnos matriculados:  "<<endl;
    for (int i = 0; i < curso.numeroDeAlumnos; i++) {
        semestre = curso.alumnos[i] / 10000;
        codigo = curso.alumnos[i] % 10000;
        arch<<left<<setw(10)<<semestre<<setw(10)<<codigo<<endl;
    }
    arch<<left<<"NUMERO DE ALUMNOS: "<<curso.numeroDeAlumnos<<endl;
    arch<<left<<"TOTAL INGRESADO"<<curso.ingresos<<endl;
    return arch;
}

ofstream & operator <<(ofstream &arch,struct StAlumno &alumno){
    arch<<left<<setw(10)<<alumno.semestre<<setw(10)<<alumno.codigo<<setw(60)<<alumno.nombre;
    if(strcmp(alumno.modalidad,"SEMIPRESENCIAL")==0){
        arch<<alumno.modalidad<<"CON  "<<alumno.porcentaje<<'%'<<"   "<<alumno.escala<<endl;
    }else{
        arch<<setw(15)<<alumno.modalidad<<alumno.escala<<endl;
    }
    arch<<left<<"Codigos de los cursos matriculados"<<endl;
    for (int i = 0; i < alumno.numeroDeCursos; i++) arch<<alumno.cursos[i]<<endl;
    
    arch<<"Numero de cursos:  "<<alumno.numeroDeCursos<<endl;
    arch<<"Costo total: "<<alumno.costoTotal<<endl<<endl<<endl;
    return arch;        
} 