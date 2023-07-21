/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 14 de mayo de 2023, 1:42
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void cargarPrestamos(int **&fechPrest,char ***&codLibPrest,int *carneUs);
int obtenerPosicionUsuario(int *carneUs,int codUsuario);
char *leerCadena(ifstream &arch);
void espaciosExactos(int *&fechPrest, char **&codLibPrest,int numLibros);
void agregarPrestamoUsuario(int *&fechPrest,int  fecha,char **&codLibPrest,char *codLibro,int &numLibros);

void mostrarLibrosPrestados(int **fechPrest,char ***codLibPrest,int *carneUs,char *tipoUs,const char *nombArch);
void imprimirPrestamos(int *fechPrest,char **codLibPrest,ofstream &archReporte);

void procesarSolicitudes(int *carneUs,char *tipoUs,char **nombreUs,int **&fechPrest,char ***&codLibPrest,char **codLibro,int *&cantLibros);
void obtenerCantidadLibros(int *fechPrest, int &numPrestamos);
char *leerLibro(ifstream &arch);
void procesarSolicitud(char solicitud,char **codLibro,int *&cantLibros,char *codigoLibro,int *&fechPrest,char **&codLibPrest,char tipoUs,int &numPrestamos,
                       ofstream &archReporte);
int noHayRetrasosDevolucion(int *fechPest,char **codLibPrest,char tipo);
int noExcedePrestamosPermitidos(int nd,char tipo);
int obtenerPosicion(char **codLibPrest,char *codigoLibro);
int obtenerPosicionLibro(char **codLibro,char *codigoLibro);
void gestionarPrestamo(ofstream &archReporte,char *codigoLibro,int existeStock,int noExcedePrestamos,int noExisteRetraso,int noTieneLibro,
        int *&fechPrest,char **&codLibPrest,int &numPrestamos, int &cantLibros);
void gestionarDevolucion(ofstream &archReporte,char *codigoLibro,int existeLibro,int posLibro,
        int *&fechPrest,char **&codLibPrest,int &numPrestamos, int &cantLibros);
void espaciosExactosPrestamo(int *&fechPrest,char **&codLibPrest,int &numPrestamos, int fecha, char *codigoLibro);
void espaciosExactosDevolucion(int *&fechPrest,char **&codLibPrest,int &numPrestamos);


#endif /* FUNCIONESAUXILIARES_H */

