/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   operadoresSobrecargados.h
 * Author: Sebastian
 *
 * Created on 28 de abril de 2023, 16:22
 */

#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H
#include "Estructuras.h"

bool operator >>(ifstream &arch,struct StCurso &curso);
bool operator >>(ifstream &arch, struct StAlumno &alumno);
bool operator >>(ifstream &arch,struct StRegistroDeMatricula &regMatricula);
void operator +=(struct StCurso *arrCursos,struct StCurso &curso);
void operator +=(struct StAlumno *arrAlumnos,struct StAlumno &alumno);
void operator *=(struct StCurso *arrCursos,struct StRegistroDeMatricula &regMatricula);
void operator *=(struct StAlumno *arrAlumnos,  struct StRegistroDeMatricula &regMatricula);
ofstream & operator <<(ofstream &arch,struct StCurso &curso);
ofstream & operator <<(ofstream &arch,struct StAlumno &alumno);


#endif /* OPERADORESSOBRECARGADOS_H */

