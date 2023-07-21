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


ifstream & operator >>(ifstream &arch,struct Estructura_ClienteRegistrado &cliente){
    char categoria;
    int telefono;
    arch>>cliente.dni>>cliente.nombre>>telefono;
    categoria = obtenerCategoria(cliente.nombre);
    if(categoria == 'A') strcpy(cliente.categoria,"Cliente muy frecuente");
    else if(categoria == 'B') strcpy(cliente.categoria,"Cliente frecuente");
    else if(categoria == 'C') strcpy(cliente.categoria,"Cliente ocasional");
    else if(categoria == '-') strcpy(cliente.categoria,"Cliente nuevo");
    cliente.numeroDePedidos = 0;
    cliente.montoTotalGastado = 0.0;
    return arch;
}

char obtenerCategoria(char *nombre){
    int cantPal = strlen(nombre);
    char car;
    if(nombre[cantPal-2] == '-'){
        car = nombre[cantPal-1];
        nombre[cantPal-2] = nombre[cantPal];
    }else car = '-';
    return car;
}

void operator +=(struct Estructura_ClienteRegistrado *arregloCli,struct Estructura_ClienteRegistrado &cliente){
    for (int i = 0; i < 30; i++) {
        if(arregloCli[i].dni == 0){
            arregloCli[i].dni = cliente.dni;
            strcpy(arregloCli[i].nombre,cliente.nombre);
            strcpy(arregloCli[i].categoria,cliente.categoria);
            arregloCli[i].montoTotalGastado = cliente.montoTotalGastado;
            arregloCli[i].numeroDePedidos = cliente.numeroDePedidos;
            arregloCli[i+1].dni = 0;
            break;
        }
    }
}

void operator +=(struct Estructura_ClienteRegistrado &cliente,struct Estructura_PedidoRealizado &pedido){
    strcpy(cliente.pedidosRealizados[cliente.numeroDePedidos].codigo,pedido.codigo);
    cliente.pedidosRealizados[cliente.numeroDePedidos].cantidad = pedido.cantidad;
    cliente.pedidosRealizados[cliente.numeroDePedidos].fecha = pedido.fecha;
    obtenerMonto(cliente,pedido.codigo,pedido.cantidad);
    cliente.numeroDePedidos++;
}

void obtenerMonto(struct Estructura_ClienteRegistrado &cliente,char *codigoProducto,int cantProducto){
    int dni,dd,mm,aa;
    double cantidad,descuento,precioUnitario;
    char car,codigo[7],descripcion[80];
    
    ifstream archPedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos,"Pedidos.txt");
    
    while(true){
        archPedidos>>codigo;
        if(archPedidos.eof()) break;
        archPedidos>>descripcion>>cantidad;
        if(archPedidos.fail()){
            archPedidos.clear();
            archPedidos>>car>>descuento>>cantidad>>precioUnitario>>dni>>dd>>car>>mm>>car>>aa;
        }else{
            archPedidos>>precioUnitario>>dni>>dd>>car>>mm>>car>>aa;
            descuento = 0.0;
        }
        if(strcmp(codigo,codigoProducto) == 0){
            cliente.montoTotalGastado += 
            ((cantProducto * precioUnitario)-((cantProducto * precioUnitario)*descuento/100));
        }
    }
}


void operator +=(struct Estructura_ProductosEnAlmacen *arregloProducto,struct Estructura_ProductosEnAlmacen &producto){
    for (int i = 0; i < 150; i++) {
        if(strcmp(arregloProducto[i].codigo, producto.codigo) == 0) break;
        if(strcmp(arregloProducto[i].codigo,"X") == 0){
            strcpy(arregloProducto[i].codigo,producto.codigo);
            strcpy(arregloProducto[i].descripcion,producto.descripcion);
            arregloProducto[i].precioUnitario = producto.precioUnitario;
            arregloProducto[i].descuento = producto.descuento;
            strcpy(arregloProducto[i+1].codigo,"X");
            break;
        }   
    }
}

ofstream & operator <<(ofstream &arch,struct Estructura_ClienteRegistrado &cliente){
    int fecha,dd,mm,aa;
    arch.precision(2);arch<<fixed;
    arch<<left<<setw(15)<<"   DNI"<<setw(42)<<"NOMBRE"<<endl;
    arch<<setw(15)<<cliente.dni<<setw(42)<<cliente.nombre<<endl;
    arch<<left<<cliente.categoria<<endl;
    arch<<setw(5)<<"No."<<setw(15)<<"CODIGO"<<setw(20)<<"CANTIDAD"<<setw(20)<<"FECHA"<<endl;
    for (int i = 0; i < cliente.numeroDePedidos; i++) {
        fecha = cliente.pedidosRealizados[i].fecha;
        aa = fecha/10000;
        fecha = fecha % 10000;
        mm = fecha/100;
        dd = fecha %100;
        arch<<right<<setw(2)<<i+1<<')'<<left<<setw(3)<<" "<<setw(15)<<cliente.pedidosRealizados[i].codigo
            <<right<<setw(10)<<cliente.pedidosRealizados[i].cantidad
            <<setw(10)<<" "<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aa
            <<left<<setfill(' ')<<endl;
    }
    arch<<left<<"Monto total comprado:"<<right<<setw(8)<<cliente.montoTotalGastado
        <<left<<endl<<endl;
    return arch;
}

ofstream & operator <<(ofstream &arch,struct Estructura_ProductosEnAlmacen *arregloProd){
    arch.precision(2);arch<<fixed;
    arch<<right<<setw(65)<<"PRODUCTOS ALMACENADOS"<<left<<endl;
    arch<<setw(5)<<"No."<<setw(15)<<"Codigo"<<setw(60)<<"Descripcion"
        <<setw(20)<<"Precio Unitario"<<setw(20)<<"Descuento"<<endl;
    for (int i = 0; i < 150; i++) {
        if(strcmp(arregloProd[i].codigo,"X") != 0){
            arch<<right<<setw(2)<<i+1<<')'<<left<<setw(3)<<" "<<setw(15)<<arregloProd[i].codigo
            <<setw(60)<<arregloProd[i].descripcion
            <<right<<setw(10)<<arregloProd[i].precioUnitario
            <<setw(10)<<" "<<setw(10)<<arregloProd[i].descuento<<left<<endl;
        }else break;
    }
    arch<<endl<<endl<<endl;
    return arch;
}
