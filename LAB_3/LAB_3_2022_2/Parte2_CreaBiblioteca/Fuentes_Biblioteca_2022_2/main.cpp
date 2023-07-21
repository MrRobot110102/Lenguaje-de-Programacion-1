/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 27 de abril de 2023, 22:44
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Estructuras.h"
#include "operadoresSobrecargados.h"
#include "AperturaDeArchivos.h"
#include "funcionesAuxiliares.h"

int main(int argc, char** argv) {
    struct StPaciente pacientes[150];
    struct StMedico medicos[50];
    int numPacientes=0,numMedicos=0;
    
    leerMedicos(medicos,numMedicos);
    leerPacientes(pacientes,numPacientes);
    leerCitas(medicos,pacientes,numPacientes);
    emitirReporte(pacientes,numPacientes);
    
    return 0;
}

