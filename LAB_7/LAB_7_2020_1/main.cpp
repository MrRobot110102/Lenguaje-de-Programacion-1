/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 7 de junio de 2023, 22:48
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Curso.h"
#include "Alumno.h"
#include "ACurso.h"
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    class Alumno alumnos[100];

    leerAlumnos(alumnos,"Alumnos.txt");//a
    agregarCursos(alumnos,"Cursos.txt");//b
    realizarCorreciones(alumnos,"Correcciones.txt");//c  
    imprimirAlumnos(alumnos,"AlumnosReporte.txt");//d

    return 0;
}

