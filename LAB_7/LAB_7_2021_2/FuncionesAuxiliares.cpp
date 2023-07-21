/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "FuncionesAuxiliares.h"
#include "SobrecargaOperadores.h"
#include "Usuario.h"
#include "LibroPrestado.h"
#include "Libro.h"

void leerUsuarios(class Usuario *usuarios,const char *nombArch){
    ifstream archUsuarios(nombArch,ios::in);
    if(not archUsuarios.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numUsuarios = 0;
    while(true){
        archUsuarios>>usuarios[numUsuarios];
        if(archUsuarios.eof()) break;
        numUsuarios++;
    }
}
    
void leerLibros(class Libro *libros,const char *nombArch){
    ifstream archLibro(nombArch,ios::in);
    if(not archLibro.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numLibros = 0;
    while(true){
        archLibro>>libros[numLibros];
        if(archLibro.eof()) break;
        numLibros++;
    }
}
    
void agregarLibrosPrestados(class Usuario *usuarios,class Libro *libros,const char *nombArch){
    ifstream archLibPrestado(nombArch,ios::in);
    if(not archLibPrestado.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class LibroPrestado libPrestado;
    while(true){
        archLibPrestado>>libPrestado;
        if(archLibPrestado.eof()) break;
        int posUsuario = buscarUsuario(usuarios,libPrestado.GetCarne(),libPrestado.GetTipo());
        char cod[10];
        libPrestado.GetCodigoLib(cod);
        int posLibro = buscarLibro(libros,cod);
        if(posUsuario != -1) usuarios[posUsuario] += libPrestado;
        if(posLibro != -1) libros[posLibro] += libPrestado;
    }
}
    
void determinarDeudas(class Usuario *usuarios,int fecha){
    for (int i = 0; usuarios[i].GetCarne(); i++) usuarios[i] * fecha;
}
    
void imprimirUsuarios(class Usuario *usuarios,const char *nombArch){
    ofstream archReporteUsuarios(nombArch,ios::out);
    if(not archReporteUsuarios.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for (int i = 0; usuarios[i].GetCarne(); i++) archReporteUsuarios<<usuarios[i];
}
    
void imprimirLibros(class Libro *libros,const char *nombArch){
    ofstream archReporteLibros(nombArch,ios::out);
    if(not archReporteLibros.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char cod[10];
    libros[0].GetCodigo(cod);
    for (int i = 0;strcmp(cod,"0"); i++){
        archReporteLibros<<libros[i];
        libros[i+1].GetCodigo(cod);
    }
}

int buscarUsuario(class Usuario *usuarios,int carne,char tipo){
    for (int i = 0; usuarios[i].GetCarne(); i++) 
        if(usuarios[i].GetCarne() == carne and usuarios[i].GetTipo() == tipo) return i;
    return -1;
}

int buscarLibro(class Libro *libros,char *cod){
    char codLibro[10];
    libros[0].GetCodigo(codLibro);
    for (int i = 0;strcmp(codLibro,"0"); i++){
        if(strcmp(codLibro,cod) == 0) return i;
        libros[i+1].GetCodigo(codLibro);
    }
    return -1;
}
    