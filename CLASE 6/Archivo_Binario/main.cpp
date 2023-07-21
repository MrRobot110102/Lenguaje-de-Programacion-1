/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 7 de abril de 2023, 9:18
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "funcionesAuxiliares.h"

int main(int argc, char** argv) {
    //crearBinario("Registro.txt","Registro.bin");
    leerBinarioV1("Registro.bin","Reporte.txt");
    //leerBinarioV2("Registro.bin","Reporte.txt");
    //accesoDirectoV1("Registro.bin");
    //accesoDirectoV2("Registro.bin");
    //accesoDirectoV3("Registro.bin");
    //accesoDirectoV4("Registro.bin");
    return 0;
}

