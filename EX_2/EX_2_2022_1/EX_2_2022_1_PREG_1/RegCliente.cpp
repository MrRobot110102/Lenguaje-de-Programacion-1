/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   RegCliente.cpp
 * Author: Sebastian
 * 
 * Created on 27 de junio de 2023, 20:38
 */
#include <iterator>
#include "RegCliente.h"
#include "Pedido.h"


void RegCliente::leerDatos(ifstream &arch){
    cliente.leerDatos(arch);
    if(cliente.GetTipo() == 'A') cliente.SetDescuento(23.5);
    else if(cliente.GetTipo() == 'B') cliente.SetDescuento(16.8);
    else if(cliente.GetTipo() == 'C') cliente.SetDescuento(8.3);
}

void RegCliente::imprimirDatos(ofstream &arch){
    cliente.imprimirDatos(arch);
    for (list<class Pedido>::iterator it=pedidos.begin(); it != pedidos.end(); it++)
        it->imprimirDatos(arch);
}

double RegCliente::getDescuentoCliente() {
    return cliente.GetDescuento();
}

int RegCliente::getDni() {
    return cliente.GetDni();
}

void RegCliente::agregarPedido(const class Pedido& ped) {
    pedidos.push_back(ped);
}

void RegCliente::ordenar() {
    pedidos.sort();
}





