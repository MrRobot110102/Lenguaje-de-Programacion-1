/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 30 de marzo de 2023, 0:38
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void imprimirLinea(char car, int cantidad);
void imprimirEncabezado();
void darFormatoNombre(char *nombre);
void imprimirEncabezadoAlumno(int codigo,int anio_ingreso,char *nombre,
                              int &cant_cursos, int &bandera,int &errores,
                              double &total_creditos,double &cred_aprob,double &cred_desap,
                              double &promedio_general, double &promedio_aprob);
void clasificarImprimirCursos(int anio_ingreso,int &cant_cursos,char *curso,double creditos,
                              int nota,int dd,int mm,int aa, int &errores,
                              double &total_creditos,double &cred_aprob,double &cred_desap,
                              double &promedio_general, double &promedio_aprob);
void imprimirResumenAlumno(int cant_cursos, int errores,double total_creditos,
                           double cred_aprob,double cred_desap,int &cant_alumnos,
                            double promedio_general, double promedio_aprob);
#endif /* FUNCIONESAUXILIARES_H */

