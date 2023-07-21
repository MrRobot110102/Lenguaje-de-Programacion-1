/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 25 de mayo de 2023, 17:04
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "ClRectangulo.h"

int main(int argc, char** argv) {
    ClRectangulo rectangulo,rect01("Segundo rectangulo",5.9,18.75);
//    ClRectangulo *ptR;

    rectangulo.SetNombre("Primer rectangulo");
    rectangulo.SetBase(14.76);
    rectangulo.SetAltura(25.98);
    rectangulo.imprimeResultados();
    rect01.imprimeResultados();
//  ptR = new ClRectangulo ("PT Rectangulo",1,2);
//  ptR->imprimeResultados();
//    ptR = new ClRectangulo[5];
//   delete []ptR;
    ClRectangulo rectangulo02 = rect01;
    rectangulo02.imprimeResultados();
    rectangulo.imprimeResultados();
    rect01.imprimeResultados();
    return 0;
}

