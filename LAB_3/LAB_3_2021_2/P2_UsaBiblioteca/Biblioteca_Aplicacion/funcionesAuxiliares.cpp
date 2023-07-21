/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
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
#include "funcionesAuxiliares.h"

void leerUsuarios(T_St_Usuario *usuarios,int &numUsuarios){
    ifstream archUsuarios("Usuarios.txt",ios::in);
    if(not archUsuarios.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Usuarios.txt"<<endl;
        exit(1);
    }
    while(true){
        archUsuarios>>usuarios[numUsuarios];
        if(archUsuarios.eof()) break;
        numUsuarios++;
    }
}

void leerLibros(T_St_Libro *libros,int &numLibros){
    ifstream archLibros("Libros.txt",ios::in);
    if(not archLibros.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros.txt"<<endl;
        exit(1);
    }
    while(true){
        archLibros>>libros[numLibros];
        if(archLibros.eof()) break;
        numLibros++;
    }
}

void leerPrestamos(T_St_Usuario *usuarios,T_St_Libro *libros,
                   const int numUsuarios,const int numLibros){
    T_St_LibroPrestado libPrestado;
    T_St_UsuarioPrestamo usuPrestamo;
    int fecha,carne,dd,mm,aa;
    char car,tipo,codigoLib[15];
    
    ifstream archPrestamos("RegistroDePrestamos.txt",ios::in);
    if(not archPrestamos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RegistroDePrestamos.txt"<<endl;
        exit(1);
    }
    
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
            if(carne == usuarios[i].carne)
                usuarios[i] += libPrestado;
        }
        for (int i = 0; i < numLibros; i++) {
            if(strcmp(libros[i].codigo,codigoLib) == 0)
                libros[i] += usuPrestamo;
        }
    }
}

void determinarDeudas(T_St_Usuario *usuarios,T_St_Libro *libros,
                      const int numUsuarios,const int numLibros){
    int fecha = 20210913;
    for (int i = 0; i < numUsuarios; i++) usuarios[i] <= fecha;
    for (int i = 0; i < numLibros; i++) libros[i] <= fecha;
}

void emitirReporte(T_St_Usuario *usuarios,T_St_Libro *libros,
                   const int numUsuarios,const int numLibros){
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
    for (int i = 0; i < numUsuarios; i++) archReporte<<usuarios[i];
    for (int i = 0; i < numLibros; i++) archReporteLibros<<libros[i];
}