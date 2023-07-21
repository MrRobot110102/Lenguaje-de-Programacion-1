/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 23 de abril de 2023, 23:27
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "StUsuario.h"
#include "StLibroPrestado.h"
#include "StLibro.h"
#include "StUsuarioPrestamo.h"
#include "operadoresSobrecargados.h"
#include "funcionesFecha.h"

int main(int argc, char** argv) {
    ifstream archUsuarios("Usuarios.txt",ios::in);
    if(not archUsuarios.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Usuarios.txt"<<endl;
        exit(1);
    }
    ifstream archLibros("Libros.txt",ios::in);
    if(not archLibros.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros.txt"<<endl;
        exit(1);
    }
    ifstream archPrestamos("RegistroDePrestamos.txt",ios::in);
    if(not archPrestamos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RegistroDePrestamos.txt"<<endl;
        exit(1);
    }
    ofstream archReporte("ReporteUsuarios.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    ofstream archReporteLibros("ReporteLibros.txt",ios::out);
    if(not archReporteLibros.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    
    T_St_Usuario usuarios[100];
    T_St_Libro libros[150];
    T_St_LibroPrestado libPrestado;
    T_St_UsuarioPrestamo usuPrestamo;
    int numUsuarios = 0,numLibros = 0,fecha,carne,dd,mm,aa;
    char car,tipo,codigoLib[15];
    
    
    //PARTE A
    while(true){
        archUsuarios>>usuarios[numUsuarios];
        if(archUsuarios.eof()) break;
        numUsuarios++;
    }
    
    //PARTE B
    while(true){
        archLibros>>libros[numLibros];
        if(archLibros.eof()) break;
        numLibros++;
    }
    
    //PARTE C
    while(true){
        archPrestamos>>carne;
        if(archPrestamos.eof()) break;
        archPrestamos>>tipo>>codigoLib>>dd>>car>>mm>>car>>aa;
        strcpy(libPrestado.codigoLib,codigoLib);
        fecha = aa * 10000 + mm * 100 + dd;
        libPrestado.fechaDeRetiro = fecha;
        usuPrestamo.carne = carne;
        usuPrestamo.tipo = tipo;
        usuPrestamo.fechaDeRetiro = fecha;
        for (int i = 0; i < numUsuarios; i++) {
            if(carne == usuarios[i].carne) usuarios[i] += libPrestado;
        }
        for (int i = 0; i < numLibros; i++) {
            if(strcmp(libros[i].codigo,codigoLib) == 0) libros[i] += usuPrestamo;
        }
    }
    
    //PARTE D
    fecha = 20210913;
    for (int i = 0; i < numUsuarios; i++) usuarios[i] <= fecha;
    for (int i = 0; i < numLibros; i++) libros[i] <= fecha;
    
    //PARTE E
    for (int i = 0; i < numUsuarios; i++) archReporte<<usuarios[i];
    for (int i = 0; i < numLibros; i++) archReporteLibros<<libros[i];
    
    return 0;
}

