/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 9 de junio de 2023, 19:13
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Tienda.h"

int main(int argc, char** argv) {
    Tienda tien;
    
    tien.carga();
    tien.actualiza(20);
    tien.muestra();
    return 0;
}

