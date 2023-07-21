/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 9 de mayo de 2023, 16:02
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
void cargarAlumnos(void *&alumno);
void aumentarEspacios(void **&alumnos,int &numDatos,int &cap);
void *leerRegistro(ifstream &arch);
char *leerCadena(ifstream &arch,char car);
void reporteAlumnos(void *alumno);
void imprimirAlumno(void *alumno);
void cargarCursos(void *&alumno);
void colocarCurso(ifstream &arch,void *&alumnos,int &numDatos, int &cap);
void agregarCurso(void *curso, void *&alumno_cursos,int numDatos);
void aumentarEspacios(void *&alumnos, int &numDatos, int &cap);
void *leerCurso(ifstream &arch);
int obtenerPosicionAlumno(int codigoAlumno,void *alumnos);
bool sonIguales(int codigoAlumno,void *alumnos);
void imprimirCursos(void *alumno);
void imprimirCurso(void *alumno);
void calcularPromedios(void *&alumno);
void promedioAlumno(void *&alumno);
void *promedio(void *&alumno);
int notaCurso(void *&alumno);

#endif /* FUNCIONESAUXILIARES_H */

