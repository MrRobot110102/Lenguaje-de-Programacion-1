/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FunNumeros.h
 * Author: Sebastian
 *
 * Created on 22 de mayo de 2023, 22:31
 */

#ifndef FUNNUMEROS_H
#define FUNNUMEROS_H

void *leenumero(ifstream &arch);

int cmpnumero(const void *a,const void *b);

void imprimenumero(void *d,ofstream &arch, int &cabecera);

#endif /* FUNNUMEROS_H */

