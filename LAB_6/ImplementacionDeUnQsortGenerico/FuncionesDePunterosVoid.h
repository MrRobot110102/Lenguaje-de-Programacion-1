/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesDePunterosVoid.h
 * Author: Sebastian
 *
 * Created on 20 de mayo de 2023, 23:38
 */

#ifndef FUNCIONESDEPUNTEROSVOID_H
#define FUNCIONESDEPUNTEROSVOID_H

void leerDatos(void *&personal, int &nd);
void *leerRegistro(ifstream &arch);
char *leerCadena(ifstream &arch,char car);
void imprimirPersonal(void *pers);
void imprimirDatos(void *pers);

#endif /* FUNCIONESDEPUNTEROSVOID_H */

