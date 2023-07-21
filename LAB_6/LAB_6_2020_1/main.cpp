/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 23 de mayo de 2023, 15:05
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "BibliotecaColaGenerica.h"
#include "Funcioneslaboratorio1.h"
#include "ColaBanco-Cliente.h"

int main(int argc, char** argv) {
    void *cola;

    creaCola(cola,leenumero,"numeros.txt");
    imprimir(cola,imprimenumero,"repnumeros.txt");
    atiendeNumero(cola);
    
    creaCola(cola,leeregistro,"Banco-Clientes.csv");
    imprimir(cola,imprimeregistro,"repBanco-Clientes.txt");
    atiendeCola(cola,10,0,0);
    return 0;
}

