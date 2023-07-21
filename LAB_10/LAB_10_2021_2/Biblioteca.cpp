/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Sebastian
 * 
 * Created on 25 de junio de 2023, 19:27
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Biblioteca.h"
#include "ALibro.h"

void Biblioteca::LeeLibros(){
    ifstream arch("Libros.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros.csv"<<endl;
        exit(1);
    }
    AStock.crear(arch);
}
    
void Biblioteca::ActualizaLibros(){
    ifstream arch("RegistroDePrestamos.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RegistroDePrestamos.csv"<<endl;
        exit(1);
    }
    AStock.actualizar(arch);
}
    
void Biblioteca::ImprimeLibros(){
    ofstream arch("reporte.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo reporte.txt"<<endl;
        exit(1);
    }
    AStock.imprimir(arch);
}

