/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 20 de junio de 2023, 22:06
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Arbol.h"

int main(int argc, char** argv) {
    class Arbol arbol;
    arbol.crear("personalLL.csv");
    arbol.mostrarEnOrden("ABBPersonalReporte.txt");
    arbol.buscar(250612);
    return 0;
}

