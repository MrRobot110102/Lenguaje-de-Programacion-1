/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 9 de junio de 2023, 21:42
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "farmacia.h"

int main(int argc, char** argv) {
    farmacia ofarma;
    
    ofarma.cargamedico();
    ofarma.leerecetas();
    ofarma.imprimirrecetas();
    return 0;
}

