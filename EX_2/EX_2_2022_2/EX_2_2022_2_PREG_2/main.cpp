/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 29 de junio de 2023, 15:22
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "almacen.h"

int main(int argc, char** argv) {
    almacen alma;
    alma.carga(20220701,"M. GUANIRA");
    alma.actualiza(20221129,"S. ESQUIVEL");
    alma.imprime();
    return 0;
}

