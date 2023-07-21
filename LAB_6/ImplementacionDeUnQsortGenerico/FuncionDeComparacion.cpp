/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "FuncionesDeCadenas.h"
#include "FuncionesDePunterosVoid.h"
#include "FuncionDeOrdenaGenerico.h"

int cmpEnteros(const void *a,const void *b){
    int ai = (int)a, bi = (int)b;
    return ai - bi;
}

int cmpCadenas(const void *a,const void *b){
    char *ai = (char *)a, *bi = (char *)b;
    return strcmp(ai,bi);
}

int cmpPunterosVoidSueldo(const void *a,const void *b){
    void **regA = (void **)a, **regB = (void **)b;
    double *sueldoA = (double *)regA[2], *sueldoB = (double *)regB[2];
    return *sueldoA - *sueldoB;
}

int cmpPunterosVoidCodigo(const void *a,const void *b){
    void **regA = (void **)a, **regB = (void **)b;
    int *codA = (int *)regA[0], *codB = (int *)regB[0];
    return *codA - *codB;
}

int cmpPunterosVoidNombre(const void *a,const void *b){
    void **regA = (void **)a, **regB = (void **)b;
    char *nombreA = (char *)regA[1], *nombreB = (char *)regB[1];
    return strcmp(nombreA,nombreB);
}