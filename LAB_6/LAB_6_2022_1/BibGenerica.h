/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibGenerica.h
 * Author: Sebastian
 *
 * Created on 22 de mayo de 2023, 22:13
 */

#ifndef BIBGENERICA_H
#define BIBGENERICA_H

void creaarbol(void *&arbol,void *(*leenumero)(ifstream &),int (*cmpnumero)(const void *,const void *),const char *nombArch);
void insertanodo(void *&arbol,void *dato,int (*cmpnumero)(const void *,const void *));
int arbolvacio(void *arbol);
void muestraarbol(void *arbol,void (*imprimenumero)(void *,ofstream &,int &),const char *nombArch);
void enorden(void *arbol,void (*imprimenumero)(void *,ofstream &,int &),ofstream &arch,int &cabecera);

#endif /* BIBGENERICA_H */

