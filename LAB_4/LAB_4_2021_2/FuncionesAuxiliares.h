/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 30 de abril de 2023, 17:25
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void estructurasParaLosLibros_CargaDeDatos(char **&codigo,char **&titulo,int *&cantEnBibl,double *&precio);
char *leerCadena(ifstream &arch);
void estructurasParaLosLibros_Reporte(char **codigo,char **titulo,int *cantEnBibl,double *precio);
void usuariosDeLaBiblioteca_CargaDeDatos(int *&carne,char *&tipo,char **&nombre);
char *leerNombre(ifstream &arch);
void usuariosDeLaBiblioteca_Reporte(int *carne,char *tipo,char **nombre);
void librosYUsuariosInhabilitados_Reporte(char **codigo,char **titulo,int *cantEnBibl,
                                          double *precio,int *carne,char *tipo,char **nombre);
void imprimirReporteTipo(char **codigo,char **titulo,int *cantEnBibl,
                         double *precio,int *carne, char *tipo, char **nombre, char tip,ofstream &arch);
int existeCliente(int *buffCarneDeuda,int cod,int numDatos);
int posicionCliente(int *carne,int cod);
int posicionLibro(char *buff,char **codigo);
int existeDeuda(int fecha, int datoFecha,double &penalidad,char tipo);
void imprimirReporte(int *carneDeuda,char **nombreDeuda,int *cantDeuda,double *montoDeuda,ofstream &arch);
void imprimirLinea(char car, int cantidad, ofstream &arch);
void imprimirLibros(char **codigo,char **titulo,int *cantEnBibl,double *precio,ofstream &arch);

#endif /* FUNCIONESAUXILIARES_H */

