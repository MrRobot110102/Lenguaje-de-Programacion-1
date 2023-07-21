/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 10 de mayo de 2023, 21:52
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"
#include "PunterosGenericos.h"

int main(int argc, char** argv) {
    void *medicinas,*citas;
    
    cargaMedicinas(medicinas);
    cargaConsultas(citas);
    actualizarReservas(medicinas,citas);
    imprimerepfinal(citas);
    //imprimemedicinas(medicinas);
    
    return 0;
}

