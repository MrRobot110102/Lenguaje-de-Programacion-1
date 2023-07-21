/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaRegistros.h
 * Author: Sebastian
 *
 * Created on 24 de mayo de 2023, 21:21
 */

#ifndef COLAREGISTROS_H
#define COLAREGISTROS_H

void *leeregistro(ifstream &arch);

char *leecadena(ifstream &arch);

int prioridadregistro(void *reg);
void imprimeregistro(void *reg,ofstream &arch);
int existeMedico(int codigo, const char *nombArch,double &tarifa);
void imprimirLinea(char car, int cantidad, ofstream &arch);
#endif /* COLAREGISTROS_H */

