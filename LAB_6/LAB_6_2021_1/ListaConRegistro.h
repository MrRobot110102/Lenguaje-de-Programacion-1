/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaConRegistro.h
 * Author: Sebastian
 *
 * Created on 21 de mayo de 2023, 18:01
 */

#ifndef LISTACONREGISTRO_H
#define LISTACONREGISTRO_H

void *leeregistro(ifstream &arch);
char *leerCadena(ifstream &arch,char car);
int cmpregistro(const void *a,const void *b);
void imprimeregistro(void *registro, ofstream &arch, void *&registroAnt);
char *obtenerNombre(int codigo);
void imprimeLinea(ofstream &arch,int cant,char c);

#endif /* LISTACONREGISTRO_H */

