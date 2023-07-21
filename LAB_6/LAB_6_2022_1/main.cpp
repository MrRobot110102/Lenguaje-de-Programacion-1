/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 22 de mayo de 2023, 21:40
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "BibGenerica.h"
#include "FunNumeros.h"
#include "FunPedidos.h"

int main(int argc, char** argv) {
    void *arbol;
    creaarbol(arbol,leenumero,cmpnumero,"numeros.txt");
    muestraarbol(arbol,imprimenumero,"reporte.txt");
    
    creaarbol(arbol,leepedido,cmppedido,"pedidos2.csv");
    muestraarbol(arbol,imprimepedido,"reporteped.txt");
    return 0;
}

