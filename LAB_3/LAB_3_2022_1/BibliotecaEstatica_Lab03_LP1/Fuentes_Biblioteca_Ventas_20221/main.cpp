/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 25 de abril de 2023, 0:03
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "operadoresSobrecargados.h"


int main(int argc, char** argv) {
    ifstream archClientes,archPedidos;
    ofstream archReporte;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.txt");
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos,"Pedidos.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"ReportePrueba.txt");
    
    struct Estructura_ClienteRegistrado cliente,clientes[30];
    struct Estructura_PedidoRealizado pedido;
    struct Estructura_ProductosEnAlmacen producto,productos[150];
    int bandera=0;
    int dni,dd,mm,aa;
    double cantidad;
    char car,codigo[7];
    
    //PARTE A
    clientes[0].dni = 0;
    while(true){
        archClientes>>cliente;
        if(archClientes.eof()) break;
        clientes += cliente;
    }
    //PARTE B
    strcpy(productos[0].codigo,"X");
    while(true){
        archPedidos>>codigo;
        if(archPedidos.eof()) break;
        archPedidos>>producto.descripcion>>cantidad;
        if(archPedidos.fail()){
            archPedidos.clear();
            archPedidos>>car>>producto.descuento>>pedido.cantidad>>producto.precioUnitario>>dni>>dd>>car>>mm>>car>>aa;
        }else{
            archPedidos>>producto.precioUnitario>>dni>>dd>>car>>mm>>car>>aa;
            pedido.cantidad = cantidad;
            producto.descuento = 0.0;
        }
        pedido.fecha = aa * 10000 + mm * 100 + dd;
        strcpy(producto.codigo,codigo);
        strcpy(pedido.codigo,codigo);
        productos += producto;
        for (int i = 0; clientes[i].dni != 0; i++) 
            if(dni == clientes[i].dni) clientes[i] += pedido;
    }
    
    //PARTE C
    archReporte<<right<<setw(65)<<"EMPRESA COMERCIALIZADORE ABC"<<left<<endl;
    archReporte<<productos;
    archReporte<<right<<setw(65)<<"PEDIDOS POR CLIENTE"<<left<<endl;
    for (int i = 0; clientes[i].dni != 0; i++) archReporte<<clientes[i];
    
    return 0;
}

