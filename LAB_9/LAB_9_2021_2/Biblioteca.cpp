/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Sebastian
 * 
 * Created on 21 de junio de 2023, 21:05
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Biblioteca.h"
#include "FuncionesFecha.h"

void Biblioteca::GeneraCopias(){
    ifstream arch("libros2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo libros2.csv"<<endl;
        exit(1);
    }
    int numLibros = 0,aa,numero,zona,ant = 0;
    char cod[100],tit[100],aut[100],car;
    double precio;
    while(true){
        arch.getline(cod,100,',');
        if(arch.eof()) break;
        arch.getline(tit,100,',');
        arch.getline(aut,100,',');
        arch>>aa>>car>>numero>>car>>precio>>car>>zona;
        arch.get();
        int j = 0;
        for (int i = ant; i < ant + numero; i++) {
            llibros[i].SetEstado("Disponible");
            llibros[i].SetNumero(j+1);
            llibros[i].asignaLibro(zona,cod,tit,aut,aa,numero,precio);
            j++;
        }
        ant = ant + numero;
    }
    llibros[ant].SetNumero(0);
}

void Biblioteca::ActualizaLibros(){
    ifstream arch("RegistroDePrestamos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RegistroDePrestamos2.csv"<<endl;
        exit(1);
    }
    int fecha = 20211115,codUsuario,numCopia,dd,mm,aa;
    char car,codigo[100];
    while(true){
        arch>>codUsuario;
        if(arch.eof()) break;
        arch>>car>>car;
        arch.getline(codigo,100,',');
        arch>>numCopia>>car>>dd>>car>>mm>>car>>aa;
        int pos = buscarLibro(codigo);
        if(pos != -1){
            int dias  = numeroDeDias(aa*10000 + mm * 100 + dd,fecha);
            llibros[pos + numCopia - 1].asignaPrestamoPerdida(dias,aa*10000 + mm * 100 + dd);
        }
    }
}

int Biblioteca::buscarLibro(char *cod){
    char codigo[100];
    for (int i = 0; llibros[i].GetNumero(); i++) {
        llibros[i].GetCodigo(codigo);
        if(strcmp(cod,codigo) == 0) return i;
    }
    return -1;
}

void Biblioteca::ImprimeCopias(){
    ofstream archReporte("Reporte.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    char cod[10],codigo[10] = "0",est[100];
    for (int i = 0; llibros[i].GetNumero(); i++) {
        llibros[i].GetCodigo(cod);
        if(strcmp(cod,codigo) != 0){
            llibros[i].imprimirEncabezado(archReporte);
            imprimeLinea(archReporte,100,'-');
            strcpy(codigo,cod);
        }
        llibros[i].GetEstado(est);
        archReporte<<right<<setw(2)<<llibros[i].GetNumero()<<left<<"    "<<setw(15)<<est;
        llibros[i].imprime(archReporte);
    }
}

void Biblioteca::imprimeLinea(ofstream &arch,int cantidad, char car){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}