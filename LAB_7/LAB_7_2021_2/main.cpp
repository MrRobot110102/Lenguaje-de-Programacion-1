/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 5 de junio de 2023, 18:15
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

int main(int argc, char** argv) {
    class Libro libros[200];
    class Usuario usuarios[200];
    int fecha = 20210910;

    leerUsuarios(usuarios,"Usuarios.csv");//a
    leerLibros(libros,"Libros.csv");//b
    agregarLibrosPrestados(usuarios,libros,"RegistroDePrestamos.csv");//c
    determinarDeudas(usuarios,fecha);//d
    imprimirUsuarios(usuarios,"Usuarios.txt");//e
    imprimirLibros(libros,"Libros.txt");//f
    
    return 0;
}

