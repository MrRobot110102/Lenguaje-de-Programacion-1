/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Sebastian
 * 
 * Created on 10 de junio de 2023, 11:38
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Biblioteca.h"
#include "FuncionesFecha.h"

void Biblioteca::generaCopias(){
    ifstream archLibros("Libros2.csv",ios::in);
    if(not archLibros.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros2.csv"<<endl;
        exit(1);
    }
    char cod[100],tit[100],aut[100],car;
    int aa,numero,zona,ant = 0;
    double precio;
    while(true){
        archLibros.getline(cod,100,',');
        if(archLibros.eof()) break;
        archLibros.getline(tit,100,',');
        archLibros.getline(aut,100,',');
        archLibros>>aa>>car>>numero>>car>>precio>>car>>zona;
        archLibros.get();
        int j = 0;
        for (int i = ant; i < ant + numero; i++) {
            llibros[i].SetAutor(aut);
            llibros[i].SetTitulo(tit);
            llibros[i].SetCodigo(cod);
            llibros[i].SetCantidad(numero);
            llibros[i].SetPrecio(precio);
            llibros[i].SetDisponible(zona);
            llibros[i].SetNumero(j+1);
            j++;
        }
        ant = ant + numero;
    }
    llibros[ant].SetNumero(0);
}

void Biblioteca::actualizaLibros(){
    ifstream archPrestamos("RegistroDePrestamos2.csv",ios::in);
    if(not archPrestamos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RegistroDePrestamos2.csv"<<endl;
        exit(1);
    }
    int fecha = 20211115,codUsuario,numCopia,dd,mm,aa;
    char car,codigo[100];
    while(true){
        archPrestamos>>codUsuario;
        if(archPrestamos.eof()) break;
        archPrestamos>>car>>car;
        archPrestamos.getline(codigo,100,',');
        archPrestamos>>numCopia>>car>>dd>>car>>mm>>car>>aa;
        int pos = buscarLibro(codigo);
        if(pos != -1){
            int dias  = numeroDeDias(aa*10000 + mm * 100 + dd,fecha);
            if(dias < 60) llibros[pos+numCopia-1].SetPrestamo(dias,aa*10000 + mm * 100 + dd);
            else llibros[pos+numCopia-1].SetPerdida(llibros[pos+numCopia-1].GetPrecio());
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

void Biblioteca::imprimeCopias(){
    ofstream archReporte("Reporte.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    archReporte.precision(2);archReporte<<fixed;
    char cod[10],codigo[10] = "0",tit[100],aut[100],est[100];
    for (int i = 0; llibros[i].GetNumero(); i++) {
        llibros[i].GetCodigo(cod);
        if(strcmp(cod,codigo) != 0){
            llibros[i].GetTitulo(tit);
            llibros[i].GetAutor(aut);
            archReporte<<"Codigo:   "<<cod<<endl;
            archReporte<<"Titulo:   "<<tit<<endl;
            archReporte<<"Autor:    "<<aut<<endl;
            archReporte<<"Cantidad: "<<llibros[i].GetCantidad()<<endl;
            imprimeLinea(archReporte,100,'-');
            strcpy(codigo,cod);
        }
        llibros[i].GetEstado(est);
        archReporte<<right<<setw(2)<<llibros[i].GetNumero()<<left<<"    "<<setw(15)<<est;
        if(strcmp(est,"Disponible") == 0) llibros[i].imprimeDisponible(archReporte);
        else if(strcmp(est,"Prestamo") == 0) llibros[i].imprimePrestamo(archReporte);
        else if(strcmp(est,"Perdida") == 0) llibros[i].imprimePerdida(archReporte);
    }
}

void Biblioteca::imprimeLinea(ofstream &arch,int cantidad, char car){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}



