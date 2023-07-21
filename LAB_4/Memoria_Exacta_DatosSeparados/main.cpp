/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 2 de mayo de 2023, 15:39
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    int *codigo;
    char **nombre, ***cursos;
    cargarAlumnos(codigo,nombre);
    cargarCursos(codigo,cursos);
    reporteAlumnos(codigo,nombre,cursos);
    return 0;
}

