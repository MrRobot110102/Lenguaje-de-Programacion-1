/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 1 de julio de 2023, 11:46
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"
/*
 * 20190638 - Esquivel Barreto Sebastian Moises
 */
int main(int argc, char** argv) {
    class Biblioteca biblioteca;
    biblioteca.leeLibros("Libros.csv");
    biblioteca.imprimeLibros("ReporteLibrosInicial.txt");
    biblioteca.leerUsuarios("Usuarios.csv");
    biblioteca.imprimeUsuarios("ReporteUsuariosInicial.txt");
    biblioteca.leerPrestamos("RegistroDePrestamos.csv");
    biblioteca.imprimeUsuarios("ReporteUsuariosFinal.txt");
    biblioteca.imprimeLibros("ReporteLibrosFinal.txt");
    biblioteca.imprimirSuspendidos("ReporteSuspendidos.txt",19,10,2021);
    return 0;
}

