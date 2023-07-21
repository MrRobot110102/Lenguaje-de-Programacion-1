/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Biblioteca.cpp
 * Author: Sebastian
 * 
 * Created on 1 de julio de 2023, 11:51
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <list>
#include <vector>
#include <iterator>
using namespace std;
#include "Libro.h"
#include "RegistroUsuario.h"
#include "Biblioteca.h"

void Biblioteca::leeLibros(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Libro libro;
    while(true){
        libro.leeDatos(arch);
        if(arch.eof()) break;
        //cout<<libro.GetAgno()<<endl;
        libros.push_back(libro);
    }
}

void Biblioteca::imprimeLibros(const char* nombArch) {
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for (list<Libro>::iterator it = libros.begin(); it != libros.end(); it++)
        it->imprimeDatos(arch);
}

void Biblioteca::leerUsuarios(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Usuario usuario;
    while(true){
        class RegistroUsuario regUsuario;
        usuario.leeDatos(arch);
        if(arch.eof()) break;
        regUsuario = usuario;
        //cout<<usuario.GetCodigo()<<endl;
        usuarios.push_back(regUsuario);
    }
}

void Biblioteca::leerPrestamos(const char* nombArch) {
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int codigo,posUsuario;
    char tipo,car,codLibro[20];
    class RegistroPrestamo regPrestamo;
    list<Libro>::iterator itLibro;
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        arch>>tipo>>car;
        regPrestamo.leeDatos(arch);
        regPrestamo.GetCodigoLibro(codLibro);
        itLibro = buscarLibro(codLibro);
        if(itLibro != libros.end())itLibro->SetPrestados(itLibro->GetPrestados() + 1);
        posUsuario = buscarUsu(codigo,tipo);
        if(posUsuario != -1) usuarios[posUsuario].agregarPrestamo(regPrestamo);
        //cout<<regPrestamo.GetFecha()<<endl;
    }
}

int Biblioteca::buscarUsu(int codigo, char tipo) {
    for (int i = 0; i < usuarios.size(); i++)
        if(usuarios[i].getCodigo() == codigo and usuarios[i].getTipo() == tipo) return i;
    return -1;
}

vector<RegistroUsuario>::iterator Biblioteca::buscarUsuario(int codigo, char tipo) {
    for (vector<RegistroUsuario>::iterator it = usuarios.begin();it != usuarios.end();it++)
        if((*it).getCodigo() == codigo and (*it).getTipo() == tipo) return it;
    return usuarios.end();
}

list<Libro>::iterator Biblioteca::buscarLibro(char* codLibro) {
    char codigoLibro[20];
    for (list<Libro>::iterator it = libros.begin(); it != libros.end(); it++){
        it->GetCodigo(codigoLibro);
        if(strcmp(codLibro,codigoLibro) == 0) return it;
    }
    return libros.end();
}

void Biblioteca::imprimeUsuarios(const char* nombArch) {
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for (int i = 0; i < usuarios.size(); i++) usuarios[i].imprimeUsuario(arch);
}

void Biblioteca::imprimirSuspendidos(const char* nombArch, int dd, int mm, int aa) {
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for (int i = 0; i < usuarios.size(); i++)
        if(usuarios[i].estaSuspendido(aa * 10000 + mm * 100 + dd)) usuarios[i].imprimeDatosPersonalesUsuario(arch);  
}






