/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FunConEnteros.h
 * Author: Sebastian
 *
 * Created on 21 de mayo de 2023, 22:04
 */

#ifndef FUNCONENTEROS_H
#define FUNCONENTEROS_H

void *leenumero(ifstream &arch);
void imprimirnum(void *d,ofstream &arch);
int prioridadnumero(void *d);
void muestranumero(int i,void *d,ofstream &arch);
void imprimeprioridadnumero(void *prioridad1,void *prioridad2, void *prioridad3,ofstream &archReporte);

#endif /* FUNCONENTEROS_H */

