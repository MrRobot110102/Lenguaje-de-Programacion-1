/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Empresa.cpp
 * Author: Sebastian
 * 
 * Created on 27 de junio de 2023, 20:40
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <list>
#include <iterator>
using namespace std;
#include "Empresa.h"
#include "RegCliente.h"

void Empresa::leerClientes(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class RegCliente regCliente;
    while(true){
        regCliente.leerDatos(arch);
        if(arch.eof()) break;
        lstClientes.push_back(regCliente);
    }
}
    
void Empresa::imprimirClientes(const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for (list<class RegCliente>::iterator it=lstClientes.begin(); it != lstClientes.end(); it++)
        it->imprimirDatos(arch);
}
    
void Empresa::leerPedidos(const char *nombArch){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Producto producto;
    class Pedido pedido;
    list<class Producto>::iterator itProducto;
    list<class RegCliente>::iterator itCliente;
    while (true) {
        producto.leerDatos(arch);
        if(arch.eof()) break;
        itProducto = buscarProducto(producto.GetCodigo());
        if(itProducto == lstProductos.end()) lstProductos.push_back(producto);
        int dni = pedido.leerDatos(arch);
        itCliente = buscarCliente(dni);
        if(itCliente != lstClientes.end()){
            pedido.SetCodigo(producto.GetCodigo());
            pedido.SetSubTotal(pedido.GetCantidad() * producto.GetPrecioUnitario() * (1 - producto.GetDescuento()/100) * (1 - itCliente->getDescuentoCliente()/100));
        }
        itCliente->agregarPedido(pedido);
    }
}
    
void Empresa::ordenarPedidos(){
    for (list<class RegCliente>::iterator it=lstClientes.begin(); it != lstClientes.end(); it++)
        it->ordenar();   
}
    
void Empresa::imprimirProductos(const char *nombArch){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for (list<class Producto>::iterator it=lstProductos.begin(); it != lstProductos.end(); it++)
        it->imprimirDatos(arch);
}

list<Producto>::iterator Empresa::buscarProducto(int codigo) {
    for (list<class Producto>::iterator it=lstProductos.begin(); it != lstProductos.end(); it++)
        if(codigo == it->GetCodigo()) return it;
    return lstProductos.end();
}

list<RegCliente>::iterator Empresa::buscarCliente(int dni) {
    for (list<class RegCliente>::iterator it=lstClientes.begin(); it != lstClientes.end(); it++)
        if(dni ==it->getDni()) return it;
    return lstClientes.end();
}



