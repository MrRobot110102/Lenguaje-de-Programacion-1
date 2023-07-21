/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 1 de julio de 2023, 13:25
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Procesa.h"

/*
 * 20190638 - Esquivel Barreto Sebastian Moises
 */
int main(int argc, char** argv) {
    Procesa pro;
    
    pro.lee();
    pro.imprime();
    return 0;
}

