/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 25 de mayo de 2023, 16:23
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ClaseRectangulo.h"

int main(int argc, char** argv) {
    ClaseRectangulo rectangulo;
    rectangulo.asignarBase(14.76);
    rectangulo.asignarAltura(25.98);
    rectangulo.imprimeResultados();
    return 0;
}

