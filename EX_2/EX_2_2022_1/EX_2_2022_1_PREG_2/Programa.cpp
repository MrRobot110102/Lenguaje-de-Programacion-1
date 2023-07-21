/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Programa.cpp
 * Author: Sebastian
 * 
 * Created on 27 de junio de 2023, 23:05
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>
#include <iterator>
using namespace std;
#include "Programa.h"
#include "NProductos.h"

void Programa::carga() {
    CargaProductos();
    CargaLista();
}

void Programa::CargaProductos() {
    ifstream arch("Productos4.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Productos4.csv"<<endl;
        exit(1);
    }
    class NProductos producto;
    while(true){
        producto.leerProductos(arch);
        //cout<<producto.getCodigo()<<endl;
        if(arch.eof()) break;
        vproductos.push_back(producto);
    }
}

void Programa::CargaLista() {
    ifstream arch("Pedidos4.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pedidos4.csv"<<endl;
        exit(1);
    }
    lpedidos.llenarLista(arch);
}

void Programa::actualiza() {
    int codProductos[200],prioridades[200],n;
    lpedidos.obtenerCodigos(codProductos,n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vproductos.size(); j++) {
            if(codProductos[i] == vproductos[j].getCodigo()){
                prioridades[i] = vproductos[j].getPrioridad();
                //cout<<prioridades[i]<<endl;
                break;
            }
        }
    }
    lpedidos.reordena(prioridades);
}

void Programa::muestra() {
    ImprimeProductos();
    ImprimeLista();
}

void Programa::ImprimeProductos() {
    ofstream arch("ListaDeProductos.txt", ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ListaDeProductos.txt"<<endl;
        exit(1);
    }
    for (int i = 0; i < vproductos.size(); i++) vproductos[i].imprimirProductos(arch);
}

void Programa::ImprimeLista() {
    ofstream arch("ListaDePedidos.txt", ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ListaDePedidos.txt"<<endl;
        exit(1);
    }
    lpedidos.imprimirLista(arch);
}









