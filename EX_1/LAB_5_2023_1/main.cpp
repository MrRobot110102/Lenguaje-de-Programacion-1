/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 12 de mayo de 2023, 18:21
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    char ***cursos_datos, ****cursos_alumnos;
    int *cursos_credito;
    double **cursos_informacion_economica;
    
    cargarCursos("matricula_ciclo_2023_1.csv",cursos_datos,cursos_credito,cursos_alumnos,cursos_informacion_economica);
    
    return 0;
}

