/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 14 de mayo de 2023, 1:41
 */
//20190638
//Sebastian Moises Esquivel Barreto
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"
#include "BibliotecaCargaLibros_Y_Usuarios.h"
#include "FuncionesFecha.h"


int main(int argc, char** argv) {
    char **codLibro, *tipoUs, **nombreUs, ***codLibPrest;
    int *cantLibros, *carneUs, **fechPrest;
    cargarLibros(codLibro,cantLibros);
    mostrarLibros(codLibro,cantLibros,"ReporteLibros1.txt");
    cargarUsuarios(carneUs,tipoUs,nombreUs);
    //mostrarUsuarios(carneUs,tipoUs,nombreUs);
    cargarPrestamos(fechPrest,codLibPrest,carneUs);
    mostrarLibrosPrestados(fechPrest,codLibPrest,carneUs,tipoUs,"ReporteDePrestamos1.txt");
    procesarSolicitudes(carneUs,tipoUs,nombreUs,fechPrest,codLibPrest,codLibro,cantLibros);
    mostrarLibrosPrestados(fechPrest,codLibPrest,carneUs,tipoUs,"ReporteDePrestamos2.txt");
    mostrarLibros(codLibro,cantLibros,"ReporteLibros2.txt");
    return 0;
}

