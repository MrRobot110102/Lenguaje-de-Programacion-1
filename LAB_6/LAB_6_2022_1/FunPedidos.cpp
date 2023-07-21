/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FunPedidos.h"
enum arbolGenerico {DATO,IZQ,DER};

void *leepedido(ifstream &arch){
    void **registro = new void*[5];
    int cod,dd,mm,aa;
    int *fecha = new int;
    int *dni = new int;
    int *codigo = new int;
    int *cantidad = new int;
    char *descripcion,car;
    arch>>cod;
    if(arch.eof()) return nullptr;
    arch.get();
    *codigo = cod;
    descripcion = leerCadena(arch,',');
    arch>>*cantidad>>car>>*dni>>car>>dd>>car>>mm>>car>>aa;
    *fecha = aa * 10000 + mm * 100 + dd;
        
    registro[0] = fecha;
    registro[1] = dni;
    registro[2] = codigo;
    registro[3] = descripcion;
    registro[4] = cantidad;
    return registro;
}

char *leerCadena(ifstream &arch,char car){
    char *aux, buff[200];
    arch.getline(buff,200,car);
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

int cmppedido(const void *a,const void *b){
    void **ai = (void **)a, **bi = (void **)b;
    int *fechaA = (int *)ai[0], *fechaB = (int *)bi[0];
    int *dniA = (int *)ai[1], *dniB = (int *)bi[1];
    if(*fechaA == *fechaB) return *dniA - *dniB;
    return (*fechaA - *fechaB);
}

void imprimepedido(void *reg,ofstream &arch,int &cabecera){
    if(cabecera == 0) imprimecabecera(arch,cabecera);
    void **registro = (void **)reg;
    int dd,mm,aa,fech;
    int *fecha = (int *)registro[0];
    int *dni = (int *)registro[1];
    int *codigo = (int *)registro[2];
    int *cantidad = (int *)registro[4];
    char *descripcion = (char *)registro[3];
    fech = *fecha;
    aa = fech/10000;
    fech = fech%10000;
    mm = fech/100;
    dd = fech%100;
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)
            <<right<<aa<<setfill(' ')<<"    ";
    arch<<left<<setw(10)<<*dni<<setw(10)<<*codigo<<setw(60)<<descripcion<<right<<setw(10)<<*cantidad<<left<<endl;
}

void imprimecabecera(ofstream &arch,int &cabecera){
    arch<<setw(13)<<left<<"Fecha"<<setw(14)<<left<<"DNI"<<setw(10)<<left
            <<"Codigo"<<setw(50)<<left<<"Descripcion del Producto"
            <<setw(5)<<right<<"Cantidad"<<endl;
    imprimeLinea(arch,100,'=');
    cabecera = 1;
}

void imprimeLinea(ofstream &arch,int cant, char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}