/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesDePunteros.h"


void leerNombres(char **&nombres,int &numDatos){
    char *buffer[500],*nombre;
    numDatos = 0;
    ifstream archPersonas("personas.txt",ios::in);
    if(not archPersonas.is_open()){
        cout<<"ERROR: No se puede abrir el archivo personas.txt"<<endl;
        exit(1);
    }
    while(true){
        nombre = leerCadena(archPersonas);
        if(nombre == nullptr) break;
        buffer[numDatos] = nombre;
        numDatos++;
    }
    nombres = new char *[numDatos];
    for (int i = 0; i < numDatos; i++) nombres[i] = buffer[i];
}

char* leerCadena(ifstream &archPersonas){
    char cadena[500],*cad;
    archPersonas.getline(cadena,500);
    if(archPersonas.eof()) return  nullptr;
    cad = new char[strlen(cadena) + 1];
    strcpy(cad,cadena);
    return cad;
}

void ordenar(char **nombres, int izq, int der){
    int limite;
    if(izq >= der) return;
    cambiar(nombres,izq,(izq+der)/2);
    limite = izq;
    for(int i=izq+1; i<=der; i++)
    if(strcmp(nombres[i],nombres[izq])<0) cambiar(nombres,++limite,i);
    cambiar(nombres, izq,limite);
    ordenar(nombres,izq,limite-1);
    ordenar(nombres,limite+1,der);
}

void cambiar(char**nombres, int i,int k){
    char *aux;
    aux = nombres[i]; nombres[i] = nombres[k]; nombres[k] = aux;
}

void imprimir(char **nombre,int numDatos){
    ofstream archReporte("reporte.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se puede abrir el archivo reporte.txt"<<endl;
        exit(1);
    }
    for (int i = 0; i < numDatos; i++) archReporte<<left<<nombre[i]<<endl;
}