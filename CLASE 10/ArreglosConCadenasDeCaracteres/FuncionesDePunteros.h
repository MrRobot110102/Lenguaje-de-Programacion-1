/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesDePunteros.h
 * Author: Sebastian
 *
 * Created on 25 de abril de 2023, 20:50
 */

#ifndef FUNCIONESDEPUNTEROS_H
#define FUNCIONESDEPUNTEROS_H

void leerNombres(char **&nombres,int &numDatos);
char* leerCadena(ifstream &archPersonas);
void ordenar(char **nombres, int izq, int der);
void cambiar(char**nombres, int i,int k);
void imprimir(char **nombre,int numDatos);

#endif /* FUNCIONESDEPUNTEROS_H */

