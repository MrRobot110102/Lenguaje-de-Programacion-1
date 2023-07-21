/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 25 de abril de 2023, 20:49
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesDePunteros.h"

int main(int argc, char** argv) {
    char **nombres;
    int numDatos;
    
    leerNombres(nombres,numDatos);
    ordenar(nombres,0,numDatos-1);
    imprimir(nombres,numDatos);
    
    
    return 0;
}

