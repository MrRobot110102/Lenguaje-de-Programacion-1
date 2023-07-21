/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   BibliotecaListaGenerica.h
 * Author: Sebastian
 *
 * Created on 21 de mayo de 2023, 12:45
 */

#ifndef BIBLIOTECALISTAGENERICA_H
#define BIBLIOTECALISTAGENERICA_H
#include <fstream>
using namespace std;

void crearLista(ifstream &arch,void *&lista,void *(*lee)(ifstream &),int (*comp)(const void *,const void *));
void insertarLista(void *&lista,void *dato,int (*comp)(const void *,const void *));
void imprimirLista(void *lista,void (*imprime)(void *)); 
void eliminarLista(void *lista,void (*elimina)(void *));

#endif /* BIBLIOTECALISTAGENERICA_H */

