/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 7 de mayo de 2023, 21:04
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerMedicos(char **&codMed,char **&nombMed,double *&tarifas);
char *leerCadena(ifstream &arch);

void repMedicos(char **codMed,char **nombMed,double *tarifas);

void leerAtenciones(char **codMed,int **&codPac,char ***&nombPac,double **&porcPac,int **&veces);
char *leerMedico(ifstream &arch);
int obtenerPosicionMedico(char *codMedico,char **codMed);
void agregarPaciente(int *&codPac,int codPaciente,char **&nombPaciente,char *nomb,double *&porcPac,double porcentaje,int *&veces,int &numPaciente,int &capPaciente);
int obtenerPosicionPaciente(int codPaciente, int *codPac);
void aumentarEspacios(int *&codPac,char **&nombPaciente,double *&porcPac,int *&veces,int &numDatos,int &cap);

void repDeIngresos(char **codMed,char **nombMed,double *tarifas,int **codPac,char ***nombPac,double **porcPac,int **veces);
void imprimirPacientes(int *codPac,char **nombPac,double *porcPac,int *veces,double tarifa,ofstream &arch);
void imprimirLinea(char car, int cantidad, ofstream &arch);

#endif /* FUNCIONESAUXILIARES_H */

