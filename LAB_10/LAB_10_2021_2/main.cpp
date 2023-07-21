/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 19:26
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Biblioteca.h"

int main(int argc, char** argv) {
    Biblioteca bib;
    
    bib.LeeLibros();
    bib.ActualizaLibros();
    bib.ImprimeLibros();
    
    return 0;
}

