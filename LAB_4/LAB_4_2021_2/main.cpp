/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 30 de abril de 2023, 17:25
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    char **codigo,**titulo,*tipo,**nombre;
    int *carne,*cantEnBibl;
    double *precio;
    
    estructurasParaLosLibros_CargaDeDatos(codigo,titulo,cantEnBibl,precio);
    estructurasParaLosLibros_Reporte(codigo,titulo,cantEnBibl,precio);
    usuariosDeLaBiblioteca_CargaDeDatos(carne,tipo,nombre);
    usuariosDeLaBiblioteca_Reporte(carne,tipo,nombre);
    librosYUsuariosInhabilitados_Reporte(codigo,titulo,cantEnBibl,precio,carne,tipo,nombre);
    return 0;
}

