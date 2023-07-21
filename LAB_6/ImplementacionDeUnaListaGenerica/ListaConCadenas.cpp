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
#include "ListaConCadenas.h"

void *leeNombre(ifstream &arch){
    char *nombre;
    nombre = leeCadena(arch);
    if(arch.eof()) return nullptr;
    return nombre;
}

char *leeCadena(ifstream &arch){
    char *aux,buff[200];
    arch.getline(buff,200);
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

int cmpNombre(const void *a,const void *b){
    char *ai = (char *)a, *bi = (char *)b;
    return strcmp(ai,bi);
}

void imprimeNombre(void *n){
    char *nombre = (char *)n;
    cout<<left<<nombre<<endl;
}

void eliminaNombre(void *n){
    char *nombre = (char *)n;
    delete nombre;
}