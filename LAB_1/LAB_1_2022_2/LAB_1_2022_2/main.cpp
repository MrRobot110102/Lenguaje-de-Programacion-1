/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 26 de marzo de 2023, 16:50
 */

#include <iostream>
#include <iomanip>

using namespace std;
#include "funcionesAuxiliares.h"



int main(int argc, char** argv) {
    char especialidad1[15],especialidad2[15],codigo[8],dato[70];
    int ddven,mmven,aaven;
    
    leerImprimirEspecialidadesFechaVenc(especialidad1,especialidad2,
                                        ddven, mmven,aaven);
    while(1){
        if(cin.eof()) break;
        leerMedico(codigo,dato,especialidad1,especialidad2,ddven,mmven,aaven);
    }
    return 0;
}

