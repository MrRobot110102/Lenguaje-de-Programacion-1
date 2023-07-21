/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 6 de junio de 2023, 14:07
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"
#include "Medico.h"
#include "Paciente.h"

int main(int argc, char** argv) {
    class Medico medico[100];
    
    leerMedicos(medico,"Medicos.txt");
    leerYAgregarPacientes(medico,"AtencionPacientes.txt");
    imprimirMedicos(medico,"MedicosReporte.txt");

    return 0;
}

