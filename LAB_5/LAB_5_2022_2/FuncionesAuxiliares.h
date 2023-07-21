/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 6 de mayo de 2023, 18:11
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void cargarCitas(const char *nomArch,char ***&medicoDatos,
                 double *&medicoTarifaHora, char ****&citaPaciente,
                 int **&citaCantidad,double ***&citaTiempoYPago);
void leerDatosRestantes(char *&nombrePaciente, char *&codMedico, char *&nombreMedico, 
        double &tarifa,int &fecha,double &horasTotales,ifstream &arch);
char *leerCadena(ifstream &arch);
int obtenerPosicionMedico(char *codMedico,char ***medicoDatos);
void agregarMedico(char ***&medicoDatos,char *codMedico,char *nombreMedico, 
        double *&medicoTarifaHora,double tarifa,int &numMedicos,int &capMedicos);
void aumentarEspacios(char ***&medicoDatos,double *&medicoTarifaHora,char ****&citaPaciente,
             int **&citaCantidad,double ***&citaTiempoYPago,int &numMedicos,int &capMedicos);
void pruebaDeCargaDeCitas(const char *nomArch,char ***medicoDatos,
                 double *medicoTarifaHora, char ****citaPaciente,
                 int **citaCantidad,double ***citaTiempoYPago);
void reporteDeCitasPorMedico(const char *nomArch,char ***medicoDatos,
                 double *medicoTarifaHora, char ****citaPaciente,
                 int **citaCantidad,double ***citaTiempoYPago);
void agregarCitaMedico(char ***&citaPaciente,char *dniPaciente,char *nombrePaciente,int *&citaCantidad,
                       double **&citaTiempoYPago,double horasTotales,int &numCitas,int &capCitas,double medicoTarifaHora);
void aumentarEspacios(char ***&citaPaciente,int *&citaCantidad,double **&citaTiempo,int &numCitas,int &capCitas);
int obtenerPosicionPaciente(char *dniPaciente, char ***citaPaciente);
void imprimirCitas(ofstream &arch,char ***citaPaciente,int *citaCantidad,double **citaTiempoYPago);
void imprimirLinea(char car, int cantidad, ofstream &arch);
void imprimirCitasReporte(ofstream &arch,char ***citaPaciente,int *citaCantidad,double **citaTiempoYPago);

#endif /* FUNCIONESAUXILIARES_H */

