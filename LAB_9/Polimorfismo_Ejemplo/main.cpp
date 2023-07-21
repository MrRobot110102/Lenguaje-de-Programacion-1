/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 13:44
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "MovimientosEnTablero.h"

int main(int argc, char** argv) {
    class MovimientosEnTablero movEnTabl;
    movEnTabl.cargar_Y_MoverFichas("Fichas.txt","Movimientos.txt","Reporte.txt");
    return 0;
}

