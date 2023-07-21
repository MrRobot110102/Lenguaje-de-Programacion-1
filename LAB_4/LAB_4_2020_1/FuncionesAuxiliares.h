/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 4 de mayo de 2023, 0:18
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerAlumnos(int *&codigos,char **&nombres,char ***&cursos);
char *leerNombre(ifstream &arch);
void imprimirAlumnos(int *codigos,char **nombres);
void leerCursos(int *codigos,char ***&cursos);
int obtenerPosicionAlumno(int *codigos,int cod);
void colocarCurso(char *curso,char **&cursos,int &numDatos);
void espaciosExactos(char **&cursos,int numDatos);
void imprimirReporte(int *codigos,char **nombres,char ***cursos);
void imprimeCursos(char **cursos,ofstream &arch);
void imprimeLinea(ofstream &arch,int cant,char c);


#endif /* FUNCIONESAUXILIARES_H */

