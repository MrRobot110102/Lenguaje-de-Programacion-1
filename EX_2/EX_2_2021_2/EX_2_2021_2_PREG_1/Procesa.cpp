/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.cpp
 * Author: Sebastian
 * 
 * Created on 30 de junio de 2023, 23:38
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <list>
#include <vector>
#include <iterator>
using namespace std;
#include "Procesa.h"
#include "Libro.h"

void Procesa::Carga() {
    CargaLibros();
    CargaUsuarios();
    LeeSolicitudes();
}

void Procesa::CargaLibros() {
    ifstream arch("Libros2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo libros2.csv"<<endl;
        exit(1);
    }
    class Libro libro;
    while(true){
        libro.leelibros(arch);
        if(arch.eof()) break;
        //cout<<libro.GetAnho()<<endl;
        llibros.push_back(libro);
    }
}

void Procesa::CargaUsuarios() {
    ifstream arch("Usuarios2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Usuarios2.csv"<<endl;
        exit(1);
    }
    class NUsuario usuario;
    while(true){
        usuario.leeUsuario(arch);
        if(arch.eof()) break;
        //cout<<usuario.getCarne()<<endl;
        vusuarios.push_back(usuario);
    }
}

void Procesa::LeeSolicitudes() {
    ifstream arch("SolicitudDePrestamos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo SolicitudDePrestamos2.csv"<<endl;
        exit(1);
    }
    cola.crearCola(arch);
}


void Procesa::Atiende() {
    char libro[20];
    int carne,n = cola.GetN();
    cout<<cola.GetN()<<endl;
    for (int i = 0; i < n; i++) {
        cola.atiendeCola(libro,carne);
        //cout<<carne<<'-'<<libro<<endl;
        Actualizar(libro,carne);
    }
    cout<<cola.GetN()<<endl;
}

void Procesa::Actualizar(char* libro, int carne) {
    char codLibro[20];
    for (list<Libro>::iterator it = llibros.begin(); it != llibros.end(); it++){
        (*it).GetCodigo(codLibro);
        if(strcmp(libro,codLibro) == 0){
            if((*it).GetStock() > 0) {
                (*it).SetStock((*it).GetStock() - 1);
                return;
            }else break;
        }
    }
    cola.ingresaCola(libro,carne);
}

void Procesa::Imprime() {
    Imprimelibros();
    ImprimeCola();
}

void Procesa::Imprimelibros() {
    ofstream arch("ReporteLibros.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReporteLibros.txt"<<endl;
        exit(1);
    }
    for (list<Libro>::iterator it = llibros.begin(); it != llibros.end(); it++)
        (*it).imprimelibro(arch);
}

void Procesa::ImprimeCola() {
    ofstream arch("ReporteCola.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReporteCola.txt"<<endl;
        exit(1);
    }
    char libro[20];
    int carne;
    while(not cola.colaVacia()){
        cola.atiendeCola(libro,carne);
        arch<<"Libro:"<<libro<<endl;
        ImprimeUsuario(carne,arch);
    }
}

void Procesa::ImprimeUsuario(int carne,ofstream &arch) {
    for (int i = 0; i < vusuarios.size(); i++)
        if(carne == vusuarios[i].getCarne()) vusuarios[i].imprimeUsuario(arch);
}






