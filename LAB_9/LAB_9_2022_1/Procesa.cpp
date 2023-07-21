/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Procesa.cpp
 * Author: Sebastian
 * 
 * Created on 13 de junio de 2023, 18:10
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Procesa.h"

void Procesa::carga(){
    ifstream archPedidos("pedidos4.csv",ios::in);
    if(not archPedidos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo pedidos4.csv"<<endl;
        exit(1);
    }
    ifstream archClientes("clientes3.csv",ios::in);
    if(not archClientes.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo clientes3.csv"<<endl;
        exit(1);
    }
    cargaPedidos(archPedidos);
    cargaClientes(archClientes);
}

void Procesa::cargaPedidos(ifstream &arch){
    int cod,cant,dni,dd,mm,aa,numPedidos = 0;
    double monto;
    char car;
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch>>car>>cant>>car>>monto>>car>>dni>>car>>dd>>car>>mm>>car>>aa;
        lpedidos[numPedidos].SetCodigo(cod);
        lpedidos[numPedidos].SetCantidad(cant);
        lpedidos[numPedidos].SetDni(dni);
        lpedidos[numPedidos].SetFecha(aa * 10000 + mm * 100 + dd);
        lpedidos[numPedidos].SetTotal(monto);
        numPedidos++;
    }
    lpedidos[numPedidos].SetCodigo(0);
}

void Procesa::cargaClientes(ifstream &arch){
    char tipo,car;
    int numDeudores = 0;
    while(true){
        arch>>tipo>>car;
        if(arch.eof()) break;
        ldeudor[numDeudores].leer(arch,tipo);
        numDeudores++;
    }
    ldeudor[numDeudores] = nullptr;
}

void Procesa::actualiza(){
    double monto;
    int cantidad;
    for (int i = 0; ldeudor[i].validaDeudor(); i++){
        actualizarCantidadMontos(ldeudor[i].obtenerDniDeudor(),cantidad,monto);
        ldeudor[i].asignarMontosYCantidades(monto,cantidad);
        ldeudor[i].calcular();
    }
}

void Procesa::actualizarCantidadMontos(int dni,int &cantidad,double &monto){
    monto = 0.0;
    cantidad = 0;
    for (int i = 0; lpedidos[i].GetCodigo(); i++) {
        if(lpedidos[i].GetDni() == dni){
            monto += lpedidos[i].GetTotal();
            cantidad++;
        }
    }
}

void Procesa::muestra(){
    ofstream archReporte("Reporte.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    archReporte<<right<<setw(35)<<"REPORTE DE DEUDAS"<<left<<endl;
    for (int i = 0; ldeudor[i].validaDeudor(); i++) ldeudor[i].imprimir(archReporte);
}