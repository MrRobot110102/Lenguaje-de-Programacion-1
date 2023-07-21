/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 3 de junio de 2023, 22:02
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>  
using namespace std;
#include "Funciones Auxiliares.h"
#include "SobrecargaOperadores.h"
#include "medico.h"
#include "cita.h"
#include "paciente.h"

int main(int argc, char** argv) {
    class medico medicos[100];
    class paciente pacientes[100];
    
    leerMedicos(medicos,"medicos.csv");//a
    leerPacientes(pacientes,"pacientes.csv");//b
    agregarCitas(pacientes,"citas.csv");//c
    actualizarTarifas(pacientes,medicos);//d
    imprimirMedicos(medicos,"medicos.txt");//e
    imprimirPacientes(pacientes,"pacientes.txt");//e
    
    return 0;
}

