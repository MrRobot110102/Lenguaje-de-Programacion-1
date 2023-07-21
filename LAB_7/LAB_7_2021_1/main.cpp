/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 4 de junio de 2023, 14:44
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "SobrecargaOperadores.h"
#include  "FuncionesAuxiliares.h"
#include "Conductor.h"
#include "FaltaCond.h"
#include "Falta.h"
#include "Infraccion.h"

int main(int argc, char** argv) {
    class Conductor conductores[200];
    int fecha = 20220101;
    
    leerConductores(conductores,"Conductores.csv");//a
    leerFaltasCometidas(conductores,"RegistroDeFaltas.csv");//b
    leerYAsignarInfracciones(conductores,"Infracciones.csv");//c
    calcularMontoTotal(conductores);//d
    imprimirConductor(conductores,"Conductores.txt");//e
    aplicarAmnistia(conductores,fecha);//f
    imprimirConductor(conductores,"ConductoresConAmnistia.txt");//g
    
    return 0;
}

