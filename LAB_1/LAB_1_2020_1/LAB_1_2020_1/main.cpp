/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 25 de marzo de 2023, 11:38
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "funcionesAuxiliares.h"

int main(int argc, char** argv) {
    int dato,dd,mm,aa,tipoMov,codProd;
    char nombre[100],car,unidad[10];
    double cant;
    
    cout<<setprecision(2)<<fixed;generarEncabezado();
    
    while(1){
        cin>>dato;
        if(cin.eof())break;
        if(dato> 9999){
            cin>>nombre;
            imprimirNombre(dato,nombre);
        }else{
            dd = dato;
            cin>>car>>mm>>car>>aa>>tipoMov>>codProd>>nombre>>cant;
            if(cin.fail()){
                cin.clear();
                cant = 1;
            }
            cin>>unidad;
            if(tipoMov/100 == 5 or tipoMov/100==3){
                imprimirDetalleProducto(dd,mm,aa,codProd,nombre,cant,unidad,tipoMov);
            }
        }
    }
    return 0;
}

