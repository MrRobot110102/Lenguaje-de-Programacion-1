/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FunPedidos.h
 * Author: Sebastian
 *
 * Created on 22 de mayo de 2023, 22:38
 */

#ifndef FUNPEDIDOS_H
#define FUNPEDIDOS_H

void *leepedido(ifstream &arch);
char *leerCadena(ifstream &arch,char car);
int cmppedido(const void *a,const void *b);
void imprimepedido(void *reg,ofstream &arch,int &cabecera);
void imprimecabecera(ofstream &arch,int &cabecera);
void imprimeLinea(ofstream &arch,int cant, char c);

#endif /* FUNPEDIDOS_H */

