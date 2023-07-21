/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 2 de mayo de 2023, 21:03
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void cargarConductores(int *&licencia,char **&conductor);
char *leerNombre(ifstream &archConductores);
void reporteConductores(int *licencia,char **conductor);
char leerGravedad(ifstream &arch);
void cargarInfracciones(int *&infraccion,char *&gravedad,double *&multa);
    
void reporteInfracciones(int *infraccion,char *gravedad,double *multa);
    
void reporteDeFaltas(int *licencia,char **conductor,int *infraccion,char *gravedad,double *multa);
void reporteSegunTipo(int *infraccion,char *gravedad,double *multa,char tipo,ofstream &arch);
int existeConductor(int *buffLicencia,int licen,char **buffPlaca,char *placa,int numDatos);
int obtenerTipoInfraccion(int infracc,int *infraccion,char *gravedad);
char *leerPlaca(ifstream &arch);
void imprimirReporte(int *licencia,char **placa,int *cantidad,double *monto,ofstream &arch);

#endif /* FUNCIONESAUXILIARES_H */

