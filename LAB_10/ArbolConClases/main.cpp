/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 20 de junio de 2023, 21:16
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Arbol.h"

int main(int argc, char** argv) {
    class Arbol arbol;
    arbol.crear("DatosLL.txt");
    arbol.mostrarEnOrden("ABBReporte.txt");
    arbol.buscar(23);
    return 0;
}

