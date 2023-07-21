/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 8 de mayo de 2023, 19:39
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
    int *med_Codigo, ***consultas_int;
    double *med_Precio;
    char **med_Descripcion, ***consultas_char;
    CargarMedicamentos(med_Codigo,med_Descripcion,med_Precio,"Medicinas-Preg01.csv");
    PruebaDeCargaDeMedicamentos(med_Codigo,med_Descripcion,med_Precio,"PruebaMedicinas.txt");
    CargarConsultas(consultas_int,consultas_char,"Consultas-Preg01.csv");
    PruebaDeCargaDeConsultas(consultas_int,consultas_char,"PruebaConsultas.txt");
    ReporteDeGastos_e_IngresosMedicos(med_Codigo,med_Descripcion,med_Precio,consultas_int,consultas_char,"Reporte-Gastos-Ingresos.txt");
    
    return 0;
}

