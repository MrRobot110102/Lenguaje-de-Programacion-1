/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 16:41
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "LFalta.h"

int main(int argc, char** argv) {
    LFalta lf1,lf2;
    lf1.leer("RegistroDeFaltas1.csv");
    lf2.leer("RegistroDeFaltas2.csv");
    lf1.unir(lf2);
    lf1.imprimir("reporte.txt");
    return 0;
}

