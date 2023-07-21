/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 7 de mayo de 2023, 18:53
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void cargarConductores(int *&licencia,char **&conductor);
char *leerCadena(ifstream &arch);
void aumentarEspacios(int *&licencia,char **&conductor,int &numDatos,int &cap);

void reporteConductores(int *licencia,char **conductor);

void cargarFaltas(int *licencia,char ***&placa,int **&falta);
char *leePlaca(ifstream &arch);
int obtenerPosicionConductor(int *licencia, int licen);
void agregarPlaca(char **&placa, char *plac,int *&falta, int infraccion,int &numPlacas,int &capPlacas);
void aumentarEspacios(char **&placa,int *&falta,int &numDatos,int &cap);

void reporteFaltas(int *licencia,char **conductor,char ***placa,int **falta);
void imprimirFaltas(char **placa,int *falta,ofstream &arch);

void resumenMultas(int *licencia,int **falta,double **&multa);
void actualizarMulta(int *falta,double *&multa);
char *obtenerGravedadYMonto(int falta,double &monto);

void reporteMultas(int *licencia,char **conductor,double **multa);
void imprimirMultas(double *multa, ofstream &archReporte);

#endif /* FUNCIONESAUXILIARES_H */

