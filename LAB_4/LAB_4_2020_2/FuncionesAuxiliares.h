/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 4 de mayo de 2023, 16:37
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void cargarMedicos(char **&codigoMed, char **&medicos, double *&tarifas);
char *leerCadena(ifstream &arch);
void reporteMedicos(char **codigoMed, char **medicos, double *tarifas);
void reporteDeIngresos(char **codigoMed, char **medicos, double *tarifas);
void cargarPacientes(char *codMed,int *&codigoPac, char **&pacientes, double *&porcentajes,int *&veces);
void reporteDelMedico(char *codMed, char **codigoMed, char **medicos, double *tarifas,
        int *codigoPac, char **pacientes,double *porcentajes,int  *veces,ofstream &archReporte);
int existePaciente(int codPaciente,int *buffCodigoPac,int numDatos);
void cargarPacientes(char *codMed,int *&codigoPac, char **&pacientes, double *&porcentajes,int *&veces);
void reporteDelMedico(char *codMed, char **codigoMed, char **medicos, double *tarifas,
        int *codigoPac, char **pacientes,double *porcentajes,int  *veces,ofstream &archReporte);
void liberarEspacios(int *&codigoPac, char **&pacientes,double *&porcentajes,int *&veces);
char *leerMedico(ifstream &arch);
int obtenerPosicionMedico(char *codMed,char **codigoMed);
void imprimirLinea(char car,int cantidad,ofstream &arch);

#endif /* FUNCIONESAUXILIARES_H */

