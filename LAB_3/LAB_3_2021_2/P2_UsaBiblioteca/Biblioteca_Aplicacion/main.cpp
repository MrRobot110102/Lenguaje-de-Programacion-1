/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 24 de abril de 2023, 23:04
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

int main(int argc, char** argv) {
    T_St_Usuario usuarios[100];
    T_St_Libro libros[150];
    int numUsuarios = 0,numLibros = 0;
    
    //PARTE A
    leerUsuarios(usuarios,numUsuarios);
    //PARTE B
    leerLibros(libros,numLibros);
    //PARTE C
    leerPrestamos(usuarios,libros,numUsuarios,numLibros);
    //PARTE D
    determinarDeudas(usuarios,libros,numUsuarios,numLibros);
    //PARTE E
    emitirReporte(usuarios,libros,numUsuarios,numLibros);
    
    return 0;
}

