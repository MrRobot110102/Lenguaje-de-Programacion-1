/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tienda.cpp
 * Author: Sebastian
 * 
 * Created on 9 de junio de 2023, 19:18
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Tienda.h"

void Tienda::carga(){
    ifstream archPedidos("pedidos3.csv",ios::in);
    if(not archPedidos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo pedidos3.csv"<<endl;
        exit(1);
    }
    ifstream archClientes("clientes2.csv",ios::in);
    if(not archClientes.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo clientes2.csv"<<endl;
        exit(1);
    }
    cargaPedidos(archPedidos);
    cargaClientes(archClientes);
}

void Tienda::cargaPedidos(ifstream &arch){
    int codigo,cantSolicitada,dni,dd,mm,aa,numpedidos = 0,stock;
    double precio;
    char car,nomb[100];
    while(true){
        arch>>codigo;
        if(arch.eof()) break;
        arch>>car>>cantSolicitada>>car>>dni>>car>>dd>>car>>mm>>car>>aa;
        lpedidos[numpedidos].SetCodigo(codigo);
        lpedidos[numpedidos].SetCantidad(cantSolicitada);
        lpedidos[numpedidos].SetDni(dni);
        lpedidos[numpedidos].SetFecha(aa * 10000 + mm * 100 + dd);
        if(buscarProducto(codigo,nomb,stock,precio)){
            lpedidos[numpedidos].SetCodprod(codigo);
            lpedidos[numpedidos].SetPrecio(precio);
            lpedidos[numpedidos].SetStock(stock);
            lpedidos[numpedidos].SetNombre(nomb);
            lpedidos[numpedidos].SetTotal(lpedidos[numpedidos].GetPrecio() 
                                            * lpedidos[numpedidos].GetCantidad());
        }
        numpedidos++;
    }
    lpedidos[numpedidos].SetCodigo(0);
}

void Tienda::cargaClientes(ifstream &arch){
    int dni,numClientes = 0;
    char nomb[100],categ,car;
    while(true){
        arch>>dni;
        if(arch.eof()) break;
        arch>>car;
        arch.getline(nomb,100,',');
        arch>>categ;
        lclientes[numClientes].SetDni(dni);
        lclientes[numClientes].SetNombre(nomb);
        lclientes[numClientes].SetCategoria(categ);
        numClientes++;
    }
    lclientes[numClientes].SetDni(0);
}

int Tienda::buscarProducto(int cod,char *nomb,int &stock,double &precio){
    ifstream archProductos("productos3.csv",ios::in);
    if(not archProductos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo productos3.csv"<<endl;
        exit(1);
    }
    int codigoProd;
    char car;
    while(true){
        archProductos>>codigoProd;
        if(archProductos.eof()) break;
        archProductos>>car;
        archProductos.getline(nomb,100,',');
        archProductos>>precio>>car>>stock;
        if(codigoProd == cod) return 1;
    }
    return 0;
}

void Tienda::actualiza(int cantidad){
    char categ;
    for (int i = 0; lpedidos[i].GetCodigo(); i++) {
        if(lpedidos[i].GetCodprod()/100000 == 4 and lpedidos[i].GetStock() >= cantidad){
            categ = obtenerCategoriaCliente(lpedidos[i].GetDni());
            if(categ == 'A'){
                lpedidos[i].SetTotal(lpedidos[i].GetTotal() * 0.50);
                lpedidos[i].SetObs("Descuento Especial de 50%");
            }else if(categ == 'B'){
                lpedidos[i].SetTotal(lpedidos[i].GetTotal() * 0.70);
                lpedidos[i].SetObs("Descuento Especial de 30%");
            }else if(categ == 'C'){
                lpedidos[i].SetTotal(lpedidos[i].GetTotal() * 0.90);
                lpedidos[i].SetObs("Descuento Especial de 10%");
            }
        }
    }
}

char Tienda::obtenerCategoriaCliente(int dni){
    for (int i = 0; lclientes[i].GetDni(); i++) if(lclientes[i].GetDni() == dni) return lclientes[i].GetCategoria();
    return 'N';
}

void Tienda::muestra(){
    ofstream archReporte("Reporte.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    archReporte<<left<<setw(12)<<"Fecha"<<setw(8)<<"Codigo"
    <<setw(45)<<"Descripcion del Prod."<<setw(7)<<"Cant."
    <<setw(8)<<"Precio"<<setw(8)<<"Total"<<"Observaciones"<<endl;
    int fech, dd,mm,aa;
    char nomb[100], ob[100];
    archReporte.precision(2);archReporte<<fixed;
    for(int i=0; lpedidos[i].GetCodigo(); i++){
        fech = lpedidos[i].GetFecha();
        lpedidos[i].GetNombre(nomb);
        lpedidos[i].GetObs(ob);
        aa = fech/10000;
        fech %= 10000;
        mm = fech/100;
        dd = fech%100;
        archReporte<<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'
        <<setw(4)<<aa<<setfill(' ')<<setw(8)<<lpedidos[i].GetCodigo()<<" "
        <<left<<setw(40)<<nomb<<right<<setw(6)<<lpedidos[i].GetCantidad()
        <<setw(10)<<lpedidos[i].GetPrecio()<<setw(8)<<lpedidos[i].GetTotal()<<" "<<left<<ob<<endl;
    }
}