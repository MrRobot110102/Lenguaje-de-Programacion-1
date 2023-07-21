/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
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

void leerClientes(class Cliente *cliente,const char *nombArch){
    ifstream archClientes(nombArch,ios::in);
    if(not archClientes.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numCli = 0;
    while(true){
        archClientes>>cliente[numCli];
        if(archClientes.eof()) break;
        numCli++;
    }
}

void leerPedidos(class Pedido *pedido,const char *nombArch){
    ifstream archPedidos(nombArch,ios::in);
    if(not archPedidos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numPed = 0;
    while(true){
        archPedidos>>pedido[numPed];
        if(archPedidos.eof()) break;
        numPed++;
    }
}

void agregarPedidos(class Cliente *cliente, class Pedido *pedido){
    int pos;
    for (int i = 0; pedido[i].GetCodigo(); i++){
        pos = buscarCliente(pedido[i].GetDni(),cliente);
        if(pos != -1) cliente[pos] = pedido[i];
    }
}

void eliminarPedidos(class Cliente *cliente,const char *nombArch){
    ifstream archEliminar(nombArch,ios::in);
    if(not archEliminar.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Pedido aux;
    int pos;
    while(true){
        archEliminar>>aux;
        if(archEliminar.eof()) break;
        pos = buscarCliente(aux.GetDni(),cliente);
        if(pos != -1) cliente[pos] -= aux;
    }
}
    
void aplicarDescuento(class Cliente *cliente){
    for (int i = 0; cliente[i].GetDni(); i++)
        if(cliente[i].GetCategoria() == 'A') cliente[i]/10;
}
    
void imprimirClientes(class Cliente *cliente,const char *nombArch){
    ofstream archReporteClientes(nombArch,ios::out);
    if(not archReporteClientes.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for (int i = 0; cliente[i].GetDni(); i++) archReporteClientes<<cliente[i];
}

void imprimirPedidos(class Pedido *pedido,const char *nombArch){
    ofstream archReportePedidos(nombArch,ios::out);
    if(not archReportePedidos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for (int i = 0; pedido[i].GetCodigo(); i++) archReportePedidos<<pedido[i];
}

int buscarCliente(int dni,class Cliente *cliente){
    for(int i=0; cliente[i].GetDni(); i++) if (dni == cliente[i].GetDni()) return i;
    return -1;
}