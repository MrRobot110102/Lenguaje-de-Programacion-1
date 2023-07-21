/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <memory>
using namespace std;
#include "funcionesAuxiliares.h"

int cantidadPalabras(char *nombre){
    int i=0;
    while(nombre[i]) i++;
    return i;
}

char asignarCategoria(char *nombre){
    int cantPal = cantidadPalabras(nombre);
    char car;
    if(nombre[cantPal-2] == '-'){
        car = nombre[cantPal-1];
        nombre[cantPal-2] = nombre[cantPal];
    }else car = 'D';
    return car;
}

void crearBinarios(){
    int dato,dni,telefono,dniOrden,dd,mm,aa;
    double descuento,cantidad,precioUnit;
    char car,nombre[70],codProd[10],desc[100];
    
    
    ifstream archCompras("Bin_ComprasPorCliente.txt",ios::in);
    if(not archCompras.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Bin_ComprasPorCliente.txt"<<endl;
        exit(1);
    }
    ofstream archClientesBin("Clientes.bin",ios::out | ios::binary);
    if(not archClientesBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Clientes.bin"<<endl;
        exit(1);
    }
    ofstream archProductosBin("Productos.bin",ios::out | ios::binary);
    if(not archProductosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Productos.bin"<<endl;
        exit(1);
    }
    ofstream archPedidosBin("Pedidos.bin",ios::out | ios::binary);
    if(not archPedidosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pedidos.bin"<<endl;
        exit(1);
    }
    
    while(true){
        archCompras>>dni;
        if(archCompras.eof()) break;
        if(not archCompras.fail()){
           archCompras>>nombre>>telefono;
           insertarClientes(archClientesBin,dni,nombre,telefono);
        }else{
            archCompras.clear();
            archCompras>>codProd>>desc>>cantidad;
            if(archCompras.fail()){
                archCompras.clear();
                archCompras>>car>>descuento>>cantidad>>precioUnit>>dniOrden>>dd>>car>>mm>>car>>aa;
            }else{
                descuento = 0.0;
                archCompras>>precioUnit>>dniOrden>>dd>>car>>mm>>car>>aa;
            }
            insertarProductos(codProd,desc,descuento,precioUnit,archProductosBin);
            insertarPedidos(dniOrden,codProd,cantidad,dd,mm,aa,archPedidosBin);
        }
    }
}

void darFormato(char *nombre){
    int i=0;
    while(nombre[i]){
        if(nombre[i] == '_' or nombre[i] == '-') nombre[i] = ' ';
        i++;
    }
}

void insertarClientes(ofstream &archCliBin,int dni, char *nombre,int telefono){
    double montoGastado = 0.0;
    char cat;
    cat = asignarCategoria(nombre);
    darFormato(nombre);
    archCliBin.write(reinterpret_cast<const char *> (&dni),sizeof(int));
    archCliBin.write(reinterpret_cast<const char *> (nombre),sizeof(char)*70);
    archCliBin.write(reinterpret_cast<const char *> (&cat),sizeof(char));
    archCliBin.write(reinterpret_cast<const char *> (&telefono),sizeof(int));
    archCliBin.write(reinterpret_cast<const char *> (&montoGastado),sizeof(double));
}

void insertarProductos(char *codProd,char *desc,double descuento,
                       double precioUnit,ofstream &archProductosBin){
    int duplicado = verificarDuplicado(codProd);
    if(not duplicado){
        archProductosBin.write(reinterpret_cast<const char *>(codProd),sizeof(char) * 10);
        archProductosBin.write(reinterpret_cast<const char *>(desc),sizeof(char) * 100);
        archProductosBin.write(reinterpret_cast<const char *>(&descuento),sizeof(double));
        archProductosBin.write(reinterpret_cast<const char *>(&precioUnit),sizeof(double));
        archProductosBin.flush();
    }
}

int compararCadenas(char *cadena1,char *cadena2){
    int i=0;
    while(cadena1[i]){
        if(cadena1[i] != cadena2[i]) return 0;
        i++;
    }
    return 1;
}

int verificarDuplicado(char *codProd){
    char codigoProducto[10];
    
    ifstream archProductosBin("Productos.bin",ios::in | ios::binary);
    if(not archProductosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Productos.bin"<<endl;
        exit(1);
    }
    archProductosBin.seekg(0,ios::beg);
    while(true){
        archProductosBin.read(reinterpret_cast<char *>(&codigoProducto),sizeof(char) * 10);
        if(archProductosBin.eof()) return 0;
        if(compararCadenas(codProd,codigoProducto)) return 1;
        else archProductosBin.seekg(sizeof(double) * 2 + sizeof(char) * 100,ios::cur);
    }
}
void insertarPedidos(int dniOrden,char *codProd,double cantidad,
                     int dd,int mm,int aa,ofstream &archPedidosBin){
    int fecha = aa*10000 + mm * 100 + dd;
    archPedidosBin.write(reinterpret_cast<const char *>(&dniOrden),sizeof(int));
    archPedidosBin.write(reinterpret_cast<const char *>(codProd),sizeof(char)*10);
    archPedidosBin.write(reinterpret_cast<const char *>(&cantidad),sizeof(double));
    archPedidosBin.write(reinterpret_cast<const char *>(&fecha),sizeof(int));
}

void mostrarClientesBin(){
    int dni,telefono;
    double montoGastado;
    char cat,nombre[70];
    
    ifstream archClientesBin("Clientes.bin",ios::in | ios::binary);
    if(not archClientesBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Clientes.bin"<<endl;
        exit(1);
    }
    ofstream archCliMuestra("ClientesMuestra.txt",ios::out);
    if(not archCliMuestra.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ClientesMuestra.txt"<<endl;
        exit(1);
    }
    
    while(true){
        archClientesBin.read(reinterpret_cast<char *>(&dni),sizeof(int));
        if(archClientesBin.eof()) break;
        archClientesBin.read(reinterpret_cast<char *>(nombre),sizeof(char)*70);
        archClientesBin.read(reinterpret_cast<char *>(&cat),sizeof(char));
        archClientesBin.read(reinterpret_cast<char *>(&telefono),sizeof(int));
        archClientesBin.read(reinterpret_cast<char *>(&montoGastado),sizeof(double));
        archCliMuestra<<left<<setw(10)<<dni<<setw(50)<<nombre<<setw(5)<<cat<<setw(10)<<telefono<<setw(5)<<montoGastado<<endl;
    }
}

void mostrarProductosBin(){
    double descuento,precioUnit;
    char codProd[10],desc[100];
    
    ifstream archProductosBin("Productos.bin",ios::in | ios::binary);
    if(not archProductosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Productos.bin"<<endl;
        exit(1);
    }
    ofstream archProdMuestra("ProductosMuestra.txt",ios::out);
    if(not archProdMuestra.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ProductosMuestra.txt"<<endl;
        exit(1);
    }
    
    while(true){
        archProductosBin.read(reinterpret_cast< char *>(codProd),sizeof(char) * 10);
        if(archProductosBin.eof()) break;
        archProductosBin.read(reinterpret_cast< char *>(desc),sizeof(char) * 100);
        archProductosBin.read(reinterpret_cast< char *>(&descuento),sizeof(double));
        archProductosBin.read(reinterpret_cast< char *>(&precioUnit),sizeof(double));
        archProdMuestra<<left<<setw(10)<<codProd<<setw(70)<<desc
        <<setw(10)<<descuento<<setw(10)<<precioUnit<<endl;
    }
}

void mostrarPedidosBin(){
    int dniOrden,fecha,dd,mm,aa;
    double cantidad;
    char codProd[10];
    
    ifstream archPedidosBin("Pedidos.bin",ios::in | ios::binary);
    if(not archPedidosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pedidos.bin"<<endl;
        exit(1);
    }
    ofstream archPedMuestra("PedidosMuestra.txt",ios::out);
    if(not archPedMuestra.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo PedidosMuestra.txt"<<endl;
        exit(1);
    }
    while(true){
        archPedidosBin.read(reinterpret_cast< char *>(&dniOrden),sizeof(int));
        if(archPedidosBin.eof()) break;
        archPedidosBin.read(reinterpret_cast< char *>(codProd),sizeof(char)*10);
        archPedidosBin.read(reinterpret_cast< char *>(&cantidad),sizeof(double));
        archPedidosBin.read(reinterpret_cast< char *>(&fecha),sizeof(int));
        aa = fecha/10000;
        fecha = fecha%10000;
        mm= fecha/100;
        dd = fecha % 100;
        archPedMuestra<<left<<setw(10)<<dniOrden<<setw(10)<<codProd
        <<setw(10)<<cantidad<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aa<<endl;
    }
    
}