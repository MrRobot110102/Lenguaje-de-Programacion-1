/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 12 de mayo de 2023, 18:22
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void cargarCursos(const char *nomArch,char ***&cursos_datos,int *&cursos_credito,char ****&cursos_alumnos,double **&cursos_informacion_economica);
char *leerCadena(ifstream &arch);
int verificarError(char *&nombre,char *&codigoCurso);
#endif /* FUNCIONESAUXILIARES_H */

