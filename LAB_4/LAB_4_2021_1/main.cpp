/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 2 de mayo de 2023, 20:47
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    char **conductor,*gravedad;
    int *licencia, *infraccion;
    double *multa;
    cargarConductores(licencia,conductor);
    reporteConductores(licencia,conductor);
    cargarInfracciones(infraccion,gravedad,multa);
    reporteInfracciones(infraccion,gravedad,multa);
    reporteDeFaltas(licencia,conductor,infraccion,gravedad,multa);
    return 0;
}

