/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibGenerica.h
 * Author: Sebastian
 *
 * Created on 21 de mayo de 2023, 20:32
 */

#ifndef BIBGENERICA_H
#define BIBGENERICA_H

void creacola(void *&cola,void *(*leenumero)(ifstream &),int (*prioridadnumero) (void *),const char *nombArch);
void encolar(void *&cola,void *dato,int (*prioridadnumero) (void *));
void imprimeCola(void *cola,void (*imprimenum)(void *,ofstream &),void (*imprimeprioridad)(void *,void *,void *,ofstream &),const char *nombArch);
int colaVacia(void *cola);
void *desencola(void *cola);
void descargarcola(void *&cola,void (*muestranumero)(int,void *,ofstream &),const char *nombArch);

#endif /* BIBGENERICA_H */

