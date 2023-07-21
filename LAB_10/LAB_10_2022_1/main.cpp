/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 23 de junio de 2023, 22:01
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Promociones.h"

int main(int argc, char** argv) {
    Promociones pro;
    pro.leepedidos();
    pro.actualizapedidos();
    pro.imprimepedidos();
    return 0;
}

