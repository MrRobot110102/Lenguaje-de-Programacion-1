/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 24 de mayo de 2023, 15:06
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "PriorityQueu.h"
#include "ColaEnteros.h"
#include "ColaRegistros.h"

int main(int argc, char** argv) {
    void *cola;
    creacola(cola,leenumero,prioridadnumero,"datos.txt");
    prueba(cola,imprimenumero,"repnumeros.txt");
    descargacola(cola,imprimenumero,"reportenumeros.txt");
    
    creacola(cola,leeregistro,prioridadregistro,"Pacientes.csv");
    prueba(cola,imprimeregistro,"repPacientes.txt");
    descargacola(cola,imprimeregistro,"reportePacientes.txt");
    
    return 0;
}

