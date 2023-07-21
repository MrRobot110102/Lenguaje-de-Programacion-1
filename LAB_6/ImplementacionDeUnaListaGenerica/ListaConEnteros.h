/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaConEnteros.h
 * Author: Sebastian
 *
 * Created on 21 de mayo de 2023, 12:57
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

void *leeEntero(ifstream &arch);
int cmpEntero(const void *a,const void *b);
void imprimeEntero(void *d);
void eliminaEntero(void *d);
#endif /* LISTACONENTEROS_H */

