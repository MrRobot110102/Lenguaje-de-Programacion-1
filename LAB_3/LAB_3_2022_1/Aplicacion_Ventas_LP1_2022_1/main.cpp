/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 25 de abril de 2023, 16:18
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "operadoresSobrecargados.h"
#include "funcionesAuxiliares.h"

int main(int argc, char** argv) {
    struct Estructura_ClienteRegistrado clientes[30];
    struct Estructura_ProductosEnAlmacen productos[150];
    int numClientes = 0;
    leerClientes(clientes,numClientes);
    leerPedidos(clientes,productos,numClientes);
    emitirReporte(clientes,productos,numClientes);
    return 0;
}

