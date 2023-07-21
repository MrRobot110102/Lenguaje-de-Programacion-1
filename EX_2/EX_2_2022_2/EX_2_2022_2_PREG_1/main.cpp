/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 28 de junio de 2023, 16:18
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "ServicioDeSalud.h"

int main(int argc, char** argv) {
    class ServicioDeSalud servicioDeSalud;
    
    servicioDeSalud.leerMedicinas("Medicinas-Preg01.csv");
    servicioDeSalud.imprimirMedicinas("PruebaMedicinas.txt");
    servicioDeSalud.leerConsultas("Consultas-Preg01.csv");
    servicioDeSalud.imprimirPacientes("PruebaConsultas.txt");
    servicioDeSalud.totalizar();
    servicioDeSalud.imprimirPacientes("PruebaConsultasTotal.txt");
    return 0;
}

