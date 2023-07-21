/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 21 de mayo de 2023, 12:42
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "BibliotecaListaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConCadenas.h"
#include "ListaConRegistrosVoid.h"

int main(int argc, char** argv) {
    void *lista;
    //******************************
    // LISTA CON ENTEROS
    //******************************
    ifstream archEnteros("Datos.txt",ios::in);
    if(not archEnteros.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo datos.txt"<<endl;
        exit(1);
    }
    crearLista(archEnteros,lista,leeEntero,cmpEntero);
    imprimirLista(lista,imprimeEntero);
    eliminarLista(lista,eliminaEntero);
    
    //******************************
    // LISTA CON NOMBRES
    //******************************
    ifstream archNombres("personas.txt",ios::in);
    if(not archNombres.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo personas.txt"<<endl;
        exit(1);
    }
    crearLista(archNombres,lista,leeNombre,cmpNombre);
    imprimirLista(lista,imprimeNombre);
    eliminarLista(lista,eliminaNombre);
    
    //******************************
    // LISTA CON REGISTROS
    //******************************
    ifstream archRegistros("personal.csv",ios::in);
    if(not archRegistros.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo personal.csv"<<endl;
        exit(1);
    }
    crearLista(archRegistros,lista,leeRegistro,cmpRegNombre);
    imprimirLista(lista,imprimeRegistro);
    eliminarLista(lista,eliminaRegistro);
    
    return 0;
}

