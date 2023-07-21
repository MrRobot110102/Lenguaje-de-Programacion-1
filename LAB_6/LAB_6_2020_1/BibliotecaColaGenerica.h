/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaColaGenerica.h
 * Author: Sebastian
 *
 * Created on 23 de mayo de 2023, 15:11
 */

#ifndef BIBLIOTECACOLAGENERICA_H
#define BIBLIOTECACOLAGENERICA_H

void creaCola(void *&cola,void *(*leenumero)(ifstream &),const char *);
void encola(void *&cola, void *dato);
void *desencola(void *cola);
int colavacia(void *cola);
void imprimir(void *cola,void (*imprimenumero)(void *,ofstream &),const char *nombArch);


#endif /* BIBLIOTECACOLAGENERICA_H */

