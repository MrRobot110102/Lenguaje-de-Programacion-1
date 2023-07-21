/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 9 de junio de 2023, 18:29
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
//#include "ClaseCirculo.h"
//#include "ClaseCilindro.h"
#include "ClaseTuberia.h"

int main(int argc, char** argv) {
//    class ClaseCirculo circulo;
//    circulo.SetRadio(24.83);
//    circulo.mostrarResultados();
    //class ClaseCilindro cilindro{12.67,11.23};
    //cilindro.SetRadio(12.67);
    //cilindro.SetAltura(11.23);
    //cilindro.mostrarResultados();
    //cilindro.ClaseCirculo::mostrarResultados();
    class ClaseTuberia tuberia{10.5,11.45,10.2};
//    tuberia.SetRadio(10.5);
//    tuberia.SetAltura(31.67);
//    tuberia.SetRadioInterior(10.2);
    tuberia.mostrarResultados();
    tuberia.ClaseCilindro::mostrarResultados();
    tuberia.ClaseCirculo::mostrarResultados();
    
    return 0;
}

