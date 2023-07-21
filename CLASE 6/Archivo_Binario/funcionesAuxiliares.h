/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 7 de abril de 2023, 9:19
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void crearBinario(const char *nomArchText,const char *nomArchBin);
void leerBinarioV1(const char *nomArchBin,const char *nomArchText);
void leerBinarioV2(const char *nomArchBin,const char *nomArchText);
void accesoDirectoV1(const char *nombArchBin);
void accesoDirectoV2(const char *nombArchBin);
void accesoDirectoV3(const char *nombArchBin);
void accesoDirectoV4(const char *nombArchBin);
void generarEncabezado(ofstream &reporte);
void imprimirLinea(char car, int cantidad,ofstream &reporte);
void imprimirDetalle(int dd,int mm,int aa,char *codCli,char tipoDoc,int serie,
                     int secuencia,double monto,int referencia,ofstream &reporte);

#endif /* FUNCIONESAUXILIARES_H */

