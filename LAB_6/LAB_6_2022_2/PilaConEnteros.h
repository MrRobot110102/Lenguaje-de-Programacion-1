/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PilaConEnteros.h
 * Author: Sebastian
 *
 * Created on 22 de mayo de 2023, 18:46
 */

#ifndef PILACONENTEROS_H
#define PILACONENTEROS_H

void *leenumero(ifstream &arch);
int cmpnumero(const void *a,const void *b);
void imprimenumero(void *d,ofstream &arch);

#endif /* PILACONENTEROS_H */

