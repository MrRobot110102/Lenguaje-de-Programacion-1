/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 2 de mayo de 2023, 15:40
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"

void cargarAlumnos(int *&codigo,char **&nombre);
char *leeNombre(ifstream &arch);
void cargarCursos(int *codigo,char ***&cursos);
void espaciosExactos(char **&cursos,int numDatos);
int buscarAlumno(int *codigo,int cod);
void agregarCursoAlumno(ifstream &arch,char **cursos,int &numCursos);
char *leeCurso(ifstream &arch);
void reporteAlumnos(int *codigo,char **nombre,char ***cursos);
void imprimeCursos(char **cursos);

#endif /* FUNCIONESAUXILIARES_H */

