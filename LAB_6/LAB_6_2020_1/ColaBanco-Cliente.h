/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaBanco-Cliente.h
 * Author: Sebastian
 *
 * Created on 23 de mayo de 2023, 17:51
 */

#ifndef COLABANCO_CLIENTE_H
#define COLABANCO_CLIENTE_H

void *leeregistro(ifstream &arch);
char *leerCadena(ifstream &arch,char car);
void imprimeregistro(void *reg,ofstream &arch);
void atiendeCola(void *&cola,int hhabierto,int mmabierto,int ssabierto);
void imprimeLinea(ofstream &arch,int cant, char c);
int horaASegundos(int hora);
void imprimirHoras(int totalSegundos,ofstream &arch);


#endif /* COLABANCO_CLIENTE_H */

