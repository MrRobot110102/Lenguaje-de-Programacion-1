/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 27 de junio de 2023, 20:35
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Empresa.h"

int main(int argc, char** argv) {
    class Empresa empresa;
    empresa.leerClientes("Clientes.csv");
    empresa.imprimirClientes("PruebaClientes.txt");
    empresa.leerPedidos("Pedidos.csv");
    empresa.ordenarPedidos();
    empresa.imprimirProductos("ReporteDeProductos.txt");
    empresa.imprimirClientes("ReporteDeClientes.txt");
    return 0;
}

