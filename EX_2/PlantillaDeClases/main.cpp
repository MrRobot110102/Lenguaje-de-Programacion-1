/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 20:32
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
#include "Plantilla.h"
#include "Persona.h"

int main(int argc, char** argv) {
//    class Plantilla<int> objInt;
//    objInt.SetDato(456);
//    objInt.imprimirDato();
    
//    class Plantilla<string> objStr;
//    objStr.leerDato();
//    objStr.imprimirDato();
    
    class Plantilla<class Persona> objPersona;
    objPersona.leerDato();
    objPersona.imprimirDato();
    return 0;
}

