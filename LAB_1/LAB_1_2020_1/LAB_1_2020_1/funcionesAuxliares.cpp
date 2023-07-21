/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "funcionesAuxiliares.h"

void imprimirLinea(char car, int cantidad){
    for (int i = 0; i < cantidad; i++) cout<<car;
    cout<<endl;
}

void generarEncabezado(){
    cout<< setw(60) << " " <<"REPORTE KARDEX"<<endl;
    
}

void imprimirNombre(int dato,char *nombreEmpresa){
    imprimirLinea('=',100);
    cout << dato << " " <<nombreEmpresa<<endl;
    imprimirLinea('=',100);
    cout << left << setw(15) << "FECHA" << setw(15) << "CODIGO" 
         << setw(47) << "DESCRIPCION" << setw(17) << "CANTIDAD" 
         << setw(15) << "UNIDAD" << endl;
    imprimirLinea('-',100);
}

void imprimirDetalleProducto(int dd,int mm,int yyyy,int codProd,char *producto,
                             double cant,char *unidad,int tipoMov){
    int signo=1;
    cout.fill('0');
    cout << right << setw(2) << dd << "/" << setw(2) << mm << "/" << setw(4) << yyyy << left;
    cout << "     ";
    cout << right << setw(8) << codProd;
    cout.fill(' ');
    cout << "       " << left << setw(45) << producto;
    if (tipoMov/100 == 3) signo = -1;
    cout << right << setw(10) << cant*signo;
    cout << setw(15) << unidad << endl;
}