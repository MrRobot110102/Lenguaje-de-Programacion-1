/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 8 de junio de 2023, 0:09
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerAlumnos(class Alumno *alumnos,const char *nombArch);
void agregarCursos(class Alumno *alumnos,const char *nombArch);
void realizarCorreciones(class Alumno *alumnos,const char *nombArch);
void imprimirAlumnos(class Alumno *alumnos,const char *nombArch);
int buscarAlumno(class Alumno *alumnos,int codigo);
int buscarCurso(int dato, int *cursos);

#endif /* FUNCIONESAUXILIARES_H */

