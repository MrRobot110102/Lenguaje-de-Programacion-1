/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FunConRegistro.h"

void *leepedido(ifstream &arch){
    void **registro = new void*[4];
    int cod;
    int *codigo = new int;
    char *tipo = new char,car;
    char *nombre;
    char *libro;
    arch>>cod;
    if(arch.eof()) return nullptr;
    arch>>car;
    arch.get();
    *codigo = cod;
    *tipo = car;
    libro = leerCadena(arch,',');
    nombre = leerCadena(arch,'\n');
    registro[0] = codigo;
    registro[1] = tipo;
    registro[2] = libro;
    registro[3] = nombre;
    return registro;
}

char *leerCadena(ifstream &arch,char car){
    char *aux, buff[200];
    arch.getline(buff,200,car);
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

int prioridadpedido(void *reg){
    void **registro = (void **)reg;
    char *tipo = (char *)registro[1];
    if(*tipo == 'D') return  1;
    else if(*tipo == 'E') return 2;
    else if(*tipo == 'A') return 3;
}

void imprimereg(void *reg,ofstream &arch){
    void **registro = (void **)reg;
    int *codigo = (int *)registro[0];
    char *tipo = (char *)registro[1];
    char *libro = (char *)registro[2];
    char *nombre = (char *)registro[3];
    arch<<right<<setw(4)<<*tipo<<"   "<<left<<setw(10)<<*codigo<<setw(60)<<nombre<<setw(10)<<libro<<endl;
}

void imprimeprioridadpedido(void *prioridad1,void *prioridad2, void *prioridad3,ofstream &archReporte){
    void **registro = (void **)prioridad1;
    int *codigo = (int *)registro[0];
    char *tipo = (char *)registro[1];
    char *libro = (char *)registro[2];
    char *nombre = (char *)registro[3];
    archReporte<<left<<"Prioridad 1: "<<right<<setw(4)<<*tipo<<"   "<<left<<setw(10)<<*codigo<<setw(60)<<nombre<<setw(10)<<libro<<endl;
    registro = (void **)prioridad2;
    codigo = (int *)registro[0];
    tipo = (char *)registro[1];
    libro = (char *)registro[2];
    nombre = (char *)registro[3];
    archReporte<<left<<"Prioridad 2: "<<right<<setw(4)<<*tipo<<"   "<<left<<setw(10)<<*codigo<<setw(60)<<nombre<<setw(10)<<libro<<endl;
    registro = (void **)prioridad3;
    codigo = (int *)registro[0];
    tipo = (char *)registro[1];
    libro = (char *)registro[2];
    nombre = (char *)registro[3];
    archReporte<<left<<"Prioridad 3: "<<right<<setw(4)<<*tipo<<"   "<<left<<setw(10)<<*codigo<<setw(60)<<nombre<<setw(10)<<libro<<endl;
}

void muestrapedido(int i,void *reg,ofstream &arch){
    void **registro = (void **)reg;
    int *codigo = (int *)registro[0];
    char *tipo = (char *)registro[1];
    char *libro = (char *)registro[2];
    char *nombre = (char *)registro[3];
    arch<<right<<setw(2)<<i<<setw(4)<<*tipo<<"   "<<left<<setw(10)<<*codigo<<setw(60)<<nombre<<setw(10)<<libro<<endl;
    delete codigo;
    delete tipo;
    delete nombre;
    delete libro;
    delete registro;
}