/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 11 de junio de 2023, 13:16
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Procesa.h"

int main(int argc, char** argv) {
    Procesa pro;
    
    pro.lee();
    pro.imprime();
    pro.procesa();
    
    return 0;
}

