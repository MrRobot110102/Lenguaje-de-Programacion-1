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

void leerDatos(char **&personas, int &nd){
    ifstream arch("personas.txt",ios::in);
    char *buffPersonas[30];
    while(true){
        buffPersonas[nd] = leerCadena(arch);
        if(arch.eof()) break;
        nd++;
    }
    personas = new char *[nd+1]{};
    for (int i = 0; i < nd; i++) personas[i] = buffPersonas[i];
}

char *leerCadena(ifstream &arch){
    char *aux, buff[100];
    arch.getline(buff,100);
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

void imprimirPersonas(char **personas){
    for (int i = 0; personas[i]; i++)cout<<personas[i]<<endl;
}