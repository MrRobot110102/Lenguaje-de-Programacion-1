/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 22 de mayo de 2023, 16:26
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"
#include "PilaConRegistros.h"

int main(int argc, char** argv) {
    void *arreglo, *pilaini, *pilafin;
    
    cargaarreglo(arreglo,cmpnumero,leenumero,"Numeros.txt");
    cargapila(pilaini,arreglo);
    muevepila(pilaini,pilafin);
    imprimepila(pilafin,imprimenumero,"repnumeros.txt");
    
    cargaarreglo(arreglo,cmpregistro,leeregistro,"medicinas.csv");
    cargapila(pilaini,arreglo);
    muevepila(pilaini,pilafin);
    imprimepila(pilafin,imprimeregistro,"repmedicinas.txt");
    
    return 0;
}

