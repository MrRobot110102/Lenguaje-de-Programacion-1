/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 10 de junio de 2023, 11:30
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Biblioteca.h"

int main(int argc, char** argv) {
    Biblioteca bib;
    
    bib.generaCopias();
    bib.actualizaLibros();
    bib.imprimeCopias();
    return 0;
}

