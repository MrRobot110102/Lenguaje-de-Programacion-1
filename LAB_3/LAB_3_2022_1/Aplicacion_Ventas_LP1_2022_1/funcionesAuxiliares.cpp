/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
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


void leerClientes(Estructura_ClienteRegistrado *clientes,int &numClientes){
    ifstream archClientes;
    struct Estructura_ClienteRegistrado cliente;
    
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.txt");
    
    while(true){
        archClientes>>cliente;
        if(archClientes.eof()) break;
        clientes += cliente;
        numClientes++;
    }
}

void leerPedidos(Estructura_ClienteRegistrado *clientes,
                 Estructura_ProductosEnAlmacen *productos,int numClientes){
    ifstream archPedidos;
    struct Estructura_PedidoRealizado pedido;
    struct Estructura_ProductosEnAlmacen producto;
    int bandera=0,dni,dd,mm,aa;
    double cantidad;
    char car,codigo[7];
    
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos,"Pedidos.txt");
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
        for (int i = 0; i < numClientes; i++) {
            if(dni == clientes[i].dni) clientes[i] += pedido;
        }
    }
}
    
void emitirReporte(Estructura_ClienteRegistrado *clientes,
                   Estructura_ProductosEnAlmacen *productos,int numClientes){
    ofstream archReporte;
    
    AperturaDeUnArchivoDeTextosParaEscribir(archReporte,"Reporte.txt");
    
    archReporte<<right<<setw(65)<<"EMPRESA COMERCIALIZADORE ABC"<<left<<endl;
    archReporte<<productos;
    archReporte<<right<<setw(65)<<"PEDIDOS POR CLIENTE"<<left<<endl;
    for (int i = 0; i < numClientes; i++) archReporte<<clientes[i];
}