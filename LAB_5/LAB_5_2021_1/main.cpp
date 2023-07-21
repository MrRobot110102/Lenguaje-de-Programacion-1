/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 7 de mayo de 2023, 18:52
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    char **conductor, ***placa;
    int *licencia, **falta;
    double **multa;
    cargarConductores(licencia,conductor);
    reporteConductores(licencia,conductor);
    cargarFaltas(licencia,placa,falta);
    reporteFaltas(licencia,conductor,placa,falta);
    resumenMultas(licencia,falta,multa);
    reporteMultas(licencia,conductor,multa);
    return 0;
}

