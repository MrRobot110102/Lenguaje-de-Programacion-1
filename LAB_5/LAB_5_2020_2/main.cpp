/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 7 de mayo de 2023, 21:03
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    char **codMed,**nombMed, ***nombPac;
    int **codPac, **veces;
    double *tarifas, **porcPac;
    leerMedicos(codMed,nombMed,tarifas);
    repMedicos(codMed,nombMed,tarifas);
    leerAtenciones(codMed,codPac,nombPac,porcPac,veces);
    repDeIngresos(codMed,nombMed,tarifas,codPac,nombPac,porcPac,veces);
    return 0;
}

