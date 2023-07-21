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
#include "FuncionDeOrdenaGenerico.h"

void ordenarG(void *arr,int izq, int der, int (*cmp)(const void*,const void *)){
    void **arreglo = (void**)arr;
    int limite;
    if(izq >=der) return;
    cambiarG(arreglo,izq,(izq+der)/2);
    limite = izq;
    for(int i=izq+1; i<=der; i++)
        if(cmp(arreglo[i],arreglo[izq])<0)
            cambiarG(arreglo,++limite,i);
    cambiarG(arreglo, izq,limite);
    ordenarG(arreglo,izq,limite-1,cmp);
    ordenarG(arreglo,limite+1,der,cmp);
}

void cambiarG(void**arreglo, int i,int k){
    void *aux;
    aux = arreglo[i];
    arreglo[i] = arreglo[k];
    arreglo[k] = aux;
}