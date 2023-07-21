/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaConRegistrosVoid.h
 * Author: Sebastian
 *
 * Created on 21 de mayo de 2023, 13:23
 */

#ifndef LISTACONREGISTROSVOID_H
#define LISTACONREGISTROSVOID_H

void *leeRegistro(ifstream &arch);
int cmpRegCodigo(const void *a,const void *b);
int cmpRegNombre(const void *a,const void *b);
int cmpRegSueldo(const void *a,const void *b);
char *leeNomb(ifstream &arch);
void imprimeRegistro(void *reg);
void eliminaRegistro(void *reg);
#endif /* LISTACONREGISTROSVOID_H */

