/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 31 de mayo de 2023, 22:45
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "FuncionesAuxiliares.h"
#include "SobrecargaOperadores.h"
#include "Cliente.h"
#include "Pedido.h" 

int main(int argc, char** argv) {
    class Cliente cliente[50];
    class Pedido pedido[200];
    leerClientes(cliente,"clientes2.csv");//a
    leerPedidos(pedido,"pedidos2.csv");//b
    agregarPedidos(cliente,pedido);//c
    eliminarPedidos(cliente,"eliminar2.csv");//d
    aplicarDescuento(cliente);//e
    imprimirClientes(cliente,"clientes.txt");//f
    imprimirPedidos(pedido,"pedidos.txt");//f
    
    return 0;
}

