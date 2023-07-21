/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 6 de mayo de 2023, 18:11
 */
//Sebastian Moises Esquivel Barreto
//20190638

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    char ***medicoDatos, ****citaPaciente;
    int **citaCantidad;
    double *medicoTarifaHora, ***citaTiempoYPago;
    cargarCitas("Citas.csv",medicoDatos,medicoTarifaHora,citaPaciente,citaCantidad,citaTiempoYPago);
    pruebaDeCargaDeCitas("PruebaDeCargaDeCitas.txt",medicoDatos,medicoTarifaHora,citaPaciente,citaCantidad,citaTiempoYPago);
    reporteDeCitasPorMedico("ReporteDeCitasPorMedico.txt",medicoDatos,medicoTarifaHora,citaPaciente,citaCantidad,citaTiempoYPago);
    return 0;
}

