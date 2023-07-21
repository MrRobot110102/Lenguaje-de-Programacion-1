/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 9 de mayo de 2023, 16:02
 */

//Sebastian Moises Esquivel Barreto
//2019038
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    void *alumno;
    
    cargarAlumnos(alumno);
    //reporteAlumnos(alumno);
    cargarCursos(alumno);
    //reporteAlumnos(alumno);
    calcularPromedios(alumno);
    reporteAlumnos(alumno);
    
    return 0;
}

