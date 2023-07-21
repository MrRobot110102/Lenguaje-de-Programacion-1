/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 13 de mayo de 2023, 20:37
 */
//20190638
//Esquivel Barreto Sebastian Moises
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "MuestraPunteros.h"
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    void *productos, *pedidos, *clientes;
    
    cargaproductos(productos);
    cargapedidos(pedidos);
    procesaclientes(productos,pedidos,clientes);
    imprimereporte(clientes);
    
    return 0;
}

