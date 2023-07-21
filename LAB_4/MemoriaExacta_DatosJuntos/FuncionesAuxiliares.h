/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 28 de abril de 2023, 23:11
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void cargarAlumnos(int *&codigo,char **&nombre,char ***&cursos);
char *leerNombre(ifstream &arch);
char **leerCursos(ifstream &arch);
char *leerCurso(ifstream &arch);
void imprimirAlumnos(int *codigo,char **nombre,char ***cursos);
void imprimeCursos(char **cursos);

#endif /* FUNCIONESAUXILIARES_H */

