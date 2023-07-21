/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 17 de abril de 2023, 18:54
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "funcionesAuxiliares.h"

int main(int argc, char** argv) {
    crearArchAlumnosBin();
    crearArchConsolidadoBin();
    mostrarArchConsolidadoBin();
    actualizarArchConsolidadoBin();
    mostrarArchConsolidadoBin();
    mostrarArchReporteFinal();
    
    return 0;
}

