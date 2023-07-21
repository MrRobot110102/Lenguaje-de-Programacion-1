/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FunConRegistro.h
 * Author: Sebastian
 *
 * Created on 21 de mayo de 2023, 23:35
 */

#ifndef FUNCONREGISTRO_H
#define FUNCONREGISTRO_H

void *leepedido(ifstream &arch);
char *leerCadena(ifstream &arch,char car);
int prioridadpedido(void *reg);
void imprimereg(void *reg,ofstream &arch);
void muestrapedido(int i,void *d,ofstream &arch);
void imprimeprioridadpedido(void *prioridad1,void *prioridad2, void *prioridad3,ofstream &archReporte);

#endif /* FUNCONREGISTRO_H */

