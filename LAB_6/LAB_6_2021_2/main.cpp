/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 21 de mayo de 2023, 20:12
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "BibGenerica.h"
#include "FunConEnteros.h"
#include "FunConRegistro.h"

int main(int argc, char** argv) {
    void *cola;
    creacola(cola,leenumero,prioridadnumero,"numeros.txt");
    imprimeCola(cola,imprimirnum,imprimeprioridadnumero,"Reporte.txt");
    descargarcola(cola,muestranumero,"Orden.txt");
    
    creacola(cola,leepedido,prioridadpedido,"Pedidos.csv");
    imprimeCola(cola,imprimereg,imprimeprioridadpedido,"Reppedidos.txt");
    descargarcola(cola,muestrapedido,"Ordenpedidos.txt");
    return 0;
}

