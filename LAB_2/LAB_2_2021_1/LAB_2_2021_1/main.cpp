/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 7 de abril de 2023, 15:27
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "funcionesAuxiliares.h"

int main(int argc, char** argv) {
    crearArchConductoresBin();
    crearArchFaltasCometidasBin();
    mostrarConductoresBin();
    mostrarFaltasCometidasBin();
    crearArchListadoInfracciones();
    mostrarListadoInfracciones();
    actualizarArchivos();
    mostrarFaltasCometidasBin();
    mostrarConductoresBin();
    return 0;
}

