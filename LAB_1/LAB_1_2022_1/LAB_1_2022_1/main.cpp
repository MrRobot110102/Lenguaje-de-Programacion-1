/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 13 de abril de 2023, 16:02
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "funcionesAuxiliares.h"

int main(int argc, char** argv) {
    int dni, telefono,dd,mm,aa,dato,i=1;
    double porA,porB,porC,desc,cantidad,preUni,descCategoria,totalPagar,totalDesc,
            mayorDescuento=0.0,totalInProd=0.0;
    char car,prodVeri[10],nombre[80],codProd[8],nomProd[50],nombreMasDesc[80],
         nomProdVeri[50];
    
    cout.precision(2); cout << fixed;
    leerCategorias(porA,porB,porC,car,prodVeri);
    
    while(true){
        cin>>dni;
        if(cin.eof()){
            imprimirTotales(totalPagar,totalDesc,mayorDescuento,nombre,nombreMasDesc);
            break;
        }
        if(not cin.fail()){
            if(i != 1) imprimirTotales(totalPagar,totalDesc,mayorDescuento,nombre,nombreMasDesc);
            cin>>nombre>>telefono;
            imprimirEncabezadoCliente(dni,nombre,telefono,porA,porB,porC,descCategoria,i,totalPagar,totalDesc,mayorDescuento,nombreMasDesc);
        }else{
            cin.clear();
            cin>>codProd>>nomProd>>cantidad;
            if(not cin.fail()){
                desc = 0.0;
                cin>>preUni>>dd>>car>>mm>>car>>aa;
            }else{
                cin.clear();
                cin>>car>>desc>>cantidad>>preUni>>dd>>car>>mm>>car>>aa; 
            }
            imprimirProducto(i,codProd,nomProd,preUni,cantidad,desc,dd,mm,aa,descCategoria,totalPagar,totalDesc,prodVeri,nomProdVeri,totalInProd);
        }
    }
    imprimirResumenFinal(mayorDescuento,nombreMasDesc,prodVeri,nomProdVeri,totalInProd);
    return 0;
}

