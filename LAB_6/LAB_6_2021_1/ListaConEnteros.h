/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaConEnteros.h
 * Author: Sebastian
 *
 * Created on 21 de mayo de 2023, 16:41
 */

#ifndef LISTACONENTEROS_H
#define LISTACONENTEROS_H

void *leenum(ifstream &arch);
int cmpnum(const void *a,const void *b);
void imprimenum(void *d,ofstream &arch,void *&dAnterior);

#endif /* LISTACONENTEROS_H */

