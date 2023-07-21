/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PilaConRegistros.h
 * Author: Sebastian
 *
 * Created on 22 de mayo de 2023, 20:37
 */

#ifndef PILACONREGISTROS_H
#define PILACONREGISTROS_H

void *leeregistro(ifstream &arch);

char *leerCadena(ifstream &arch,char car);

int cmpregistro(const void *a,const void *b);

void imprimeregistro(void *reg, ofstream &arch);

#endif /* PILACONREGISTROS_H */

