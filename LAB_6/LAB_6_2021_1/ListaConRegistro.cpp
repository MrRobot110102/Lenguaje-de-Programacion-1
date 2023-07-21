/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ListaConRegistro.h"

void *leeregistro(ifstream &arch){
    void **registro = new void*[4];
    int cod,dd,mm,aa;
    int *codigo = new int;
    int *fecha = new int;
    char *placa,car;
    int *infraccion = new int;
    arch>>cod;
    if(arch.eof()) return nullptr;
    arch.get();
    *codigo = cod;
    placa = leerCadena(arch,',');
    arch>>dd>>car>>mm>>car>>aa>>car;
    *fecha = aa * 10000 + mm * 100 + dd;
    arch>>*infraccion;
    registro[0] = codigo;
    registro[1] = placa;
    registro[2] = fecha;
    registro[3] = infraccion;
    return registro;
}

char *leerCadena(ifstream &arch,char car){
    char *aux, buff[200];
    arch.getline(buff,200,car);
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

int cmpregistro(const void *a,const void *b){
    void **ai = (void **)a, **bi = (void **)b;
    int *fechaA = (int *)ai[2], *fechaB = (int *)bi[2];
    return *fechaA - *fechaB;
}

void imprimeregistro(void *reg, ofstream &arch, void *&regAnt){
    void **registro = (void **)reg;
    int *codigo = (int *)registro[0];
    char *placa = (char *)registro[1], *nombre;
    int *fecha = (int *)registro[2];
    int *infraccion = (int *)registro[3];
    int dd,mm,aa,fechaInf,flag=1;
    fechaInf = *fecha;
    aa = fechaInf/10000;
    fechaInf = fechaInf % 10000;
    mm = fechaInf/100;
    dd = fechaInf%100;
    
    if(regAnt == nullptr){
        regAnt = reg;
        flag = 0;
    }
    void **registroAnt = (void **)regAnt;
    int *fechaAnt = (int *)registroAnt[2];
    
    if((*fecha)/100 != (*fechaAnt)/100 or flag == 0){
        if(flag != 0)imprimeLinea(arch,100,'=');
        arch<<left<<"Anio: "<<aa<<"    "<<"Mes: "<<right<<setfill('0')<<setw(2)<<mm<<setfill(' ')<<left<<endl<<endl;
        arch<<setw(12)<<left<<"FECHA"<<setw(30)<<left<<"LICENCIA"<<setw(38)
            <<left<<"NOMBRE"<<"FALTA"<<endl;
        imprimeLinea(arch,100,'=');
        regAnt = reg;
    }
    nombre = obtenerNombre(*codigo);
    arch<<right<<setfill('0')<<setw(4)<<aa<<'/'<<setw(2)<<mm<<'/'<<setw(2)<<dd
            <<left<<setfill(' ')<<"  "<<setw(10)<<*codigo<<setw(60)<<nombre<<setw(10)<<*infraccion<<endl;
    delete nombre;
}

void imprimeLinea(ofstream &arch,int cant,char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}

char *obtenerNombre(int codigo){
    ifstream archConductores("Conductores.csv",ios::in);
    if(not archConductores.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Conductores.csv"<<endl;
        exit(1);
    }
    int cod;
    char *nombre;
    while(true){
        archConductores>>cod;
        if(archConductores.eof()) break;
        archConductores.get();
        nombre = leerCadena(archConductores,'\n');
        if(cod == codigo) return nombre;
    }
}