/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 13 de abril de 2023, 16:04
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerCategorias(double &porA,double &porB,double &porC,char car,char *prodVeri);
void imprimirLinea(char car,int cantidad);
void imprimirEncabezado();
void darFormatoNombre(char *nombre);
int cantidadPalabras(char *nombre);
char asignarCategoria(char *nombre);
void imprimirTotales(double totalPagar,double totalDesc,double &mayorDescuento,
                     char *nombre,char *nombreMasDesc);
void imprimirDetalle(int dni,char *nombre,int telefono,char car,double desc);
void imprimirEncabezadoCliente(int dni,char *nombre,int telefono,double porA,
                               double porB,double porC,double &,
                               int &i, double &totalPagar,double &totalDesc,
                               double &mayorDescuento,char *nombreMasDesc);
void imprimirProducto(int &i,char *codProd,char *nomProd,double preUni,
                      double cantidad,double desc,int dd,int mm,int aa,double,
                      double &totalPagar,double &totalDesc,char *prodVeri,
                      char *nombreProdVeri,double &totalInProd);
void imprimirResumenFinal(double mayorDescuento,char *nombreMasDesc,char *prodVeri,
                          char *nombreProdVeri,double totalInProd);
void copiarPalabra(char *nombre,char *nombreMasDesc);
int compararPalabras(char *codProd,char *prodVeri);


#endif /* FUNCIONESAUXILIARES_H */

