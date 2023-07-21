/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 24 de marzo de 2023, 21:37
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "funcionesAuxiliares.h"

int main(int argc, char** argv) {
    int dd,mm,aa,serie,sec,referencia;
    char car,cliente[9],doc;
    double monto,totalFac=0,totalN=0;
    
    generarEncabezado();
    cout.precision(2);
    cout<<fixed;
    
    while(1){
        cin>>dd;
        if(cin.eof()) break;
        cin>>car>>mm>>car>>aa>>cliente>>doc>>serie>>car>>sec>>monto>>referencia;
        if(doc == 'F') totalFac = totalFac + monto;
        else totalN = totalN + monto;
        
        imprimirDetalle(dd,mm,aa,cliente,doc,serie,sec,monto,referencia);
    }
    generarResumen(totalFac,totalN);
    
    return 0;
}

