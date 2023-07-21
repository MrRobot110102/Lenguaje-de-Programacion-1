/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 20:52
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "ClLista.h"
#include "Persona.h"

int main(int argc, char** argv) {
    //class ClLista<int> lista;
    //lista.crear("datos.txt");
    //lista.imprimir("reporte.txt");
    //lista.imprimirR("reporte.txt");
    
    class ClLista<class Persona> lista;
    lista.crear("personal.csv");
    lista.imprimir("reporte.txt");
    return 0;
}

