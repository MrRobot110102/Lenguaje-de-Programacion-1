/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaListaGenerica.h
 * Author: Sebastian
 *
 * Created on 21 de mayo de 2023, 15:59
 */

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H

void creaLista(void *&lista1,void *(*leenum)(ifstream &),int (*cmpnum)(const void *,const void *),const char *nombArch);
void insertarLista(void *&lista, void *dato,int (*cmpnum)(const void *,const void *));
int listaVacia(void *lista);
void uneLista(void *&lista1,void *&lista2);
void imprimeLista(void *lista,void (*imprimenum)(void *,ofstream &,void *&),const char *nombArch);


#endif /* BIBLIOTECALISTAGENERICA_H */

