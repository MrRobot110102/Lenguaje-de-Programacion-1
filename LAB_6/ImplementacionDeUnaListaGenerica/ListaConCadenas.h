/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ListaConCadenas.h
 * Author: Sebastian
 *
 * Created on 21 de mayo de 2023, 13:12
 */

#ifndef LISTACONCADENAS_H
#define LISTACONCADENAS_H

void *leeNombre(ifstream &arch);
char *leeCadena(ifstream &arch);
int cmpNombre(const void *a,const void *b);
void imprimeNombre(void *n);
void eliminaNombre(void *n);
#endif /* LISTACONCADENAS_H */

