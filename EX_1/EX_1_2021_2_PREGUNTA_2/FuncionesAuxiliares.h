/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 14 de mayo de 2023, 17:46
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void cargalibros(void *&stock);
void *leeRegistro(ifstream &arch);
char *leerCadena(istream &arch);
void *leeCopias(int cantidad);
char *leerEstado(char car);

void actualiza(void *&stock);
int buscarLibro(void *stock,char *codLibro,int mm,int *&cantidad);
int compararLibros(void *stock,char *codLibro, int mm, int *&cantidad);
void actualizarCopias(void *&stock,int numCopia,int dd,int mm,int aa);
void actualizar(void *&stock, int numCopia,int dd,int mm,int aa,double precio);
void actualizarDatos(void *&stock,int dd,int mm,int aa,double precio);

void imprimestock(void *stock);
void imprimeFecha(int fecha,ofstream &arch);
void imprimeDetalleUnaCopia(void *st,int i,ofstream &arch);
void imprimeDetalleCopias(void *st,ofstream &arch);
void imprimeStockLibro(void *&st,ofstream &arch);


#endif /* FUNCIONESAUXILIARES_H */

