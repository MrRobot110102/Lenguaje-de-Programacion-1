/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 14 de mayo de 2023, 17:45
 */
//20190638
//Sebastian Moises Esquivel Barreto

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    void *stock;
    cargalibros(stock);
    actualiza(stock);
    imprimestock(stock);
    return 0;
}

