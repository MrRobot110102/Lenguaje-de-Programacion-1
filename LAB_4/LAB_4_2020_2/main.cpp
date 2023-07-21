/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 4 de mayo de 2023, 16:36
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    char **codigoMed,**medicos;
    double *tarifas;
    cargarMedicos(codigoMed, medicos, tarifas);
    reporteMedicos(codigoMed, medicos, tarifas);
    reporteDeIngresos(codigoMed, medicos, tarifas);
    return 0;
}

