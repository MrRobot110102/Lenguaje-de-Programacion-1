/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 15:40
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "ClLista.h"

int main(int argc, char** argv) {
    class ClLista lista;
    lista.crear("datos.txt");
    lista.imprimir("reporte.txt");
    lista.imprimirR("reporteRecursivo.txt"); 
    return 0;
}

