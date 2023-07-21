/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaPilaGenerica.h
 * Author: Sebastian
 *
 * Created on 22 de mayo de 2023, 18:08
 */

#ifndef BIBLIOTECAPILAGENERICA_H
#define BIBLIOTECAPILAGENERICA_H

void cargaarreglo(void *&arreglo,int (*cmpnumero)(const void *,const void *),void *(*leenumero)(ifstream &),const char *nombArch);
void cargapila(void *&pilaini,void *arreglo);
void push(void *pilaini,void *d);
void *pop(void *pila);
int pilaVacia(void *pila);
void muevepila(void *&pilaini,void *&pilafin);
void hanoi(int n,void *&pilaini, void *&pilaAux, void *&pilafin);
void imprimepila(void *&pilafin,void (*imprimenumero)(void *,ofstream &),const char *nombArch);

#endif /* BIBLIOTECAPILAGENERICA_H */

