/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 24 de marzo de 2023, 21:51
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H
void generarEncabezado();


void imprimirLinea(char car, int cantidad);
void imprimirDetalle(int dd,int mm,int aa,char *cliente,char doc,int serie,
                     int sec,double monto,int referencia);
void generarResumen(double totalFac,double totalN);


#endif /* FUNCIONESAUXILIARES_H */

