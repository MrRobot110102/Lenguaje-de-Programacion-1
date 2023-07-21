/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <iomanip>
using namespace std;

#include "funcionesAuxiliares.h"

void generarEncabezado(){
    cout<<"REGISTRO DE VENTAS"<<endl;
    imprimirLinea('=',100);
    cout<<left<<setw(15)<<"FECHA"<<setw(14)<<"CLIENTE"<<setw(17)<<"TIPO"
              <<setw(12)<<"SECUENCIA"<<setw(9)<<"SERIE"<<setw(14)<<"FACTURAS"
              <<setw(8)<<"N/C"<<"REFERENCIA"<<endl;
    imprimirLinea('-',100);
}


void imprimirLinea(char car, int cantidad){
    for (int i = 0; i < cantidad; i++) cout<<car;
    cout<<endl;
}

void imprimirDetalle(int dd,int mm,int aa,char *cliente,char doc,int serie,
                     int sec,double monto,int referencia){
    cout<<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aa<<setfill(' ');
    cout<<setw(13)<<cliente;
    cout<<left<<setw(5)<<" "<<setw(20);
    
    if(doc == 'F') cout<<"FACTURA";
    else cout<<"NOTA DE CREDITO";
    
    cout<<right<<setfill('0')<<setw(5)<<sec<<setfill(' ')<<setw(5)<<" ";
    cout<<setfill('0')<<setw(4)<<serie<<left<<setfill(' ')<<setw(5)<<" "<<right;
    
    if(doc == 'F') cout<<setw(8)<<monto<<setw(11)<<" ";
    else cout<<setw(11)<<" "<<setw(8)<<monto;
    
    cout<<setw(5)<<" "<<setfill('0')<<setw(5)<<referencia<<setfill(' ')<<endl;
}

void generarResumen(double totalFac,double totalN){
    double  total;
    imprimirLinea('=',100);
    cout<<left<<setw(63)<<"TOTALES:"<<right<<setw(12)<<totalFac<<setw(11)<<totalN<<endl;
    cout<<"SALDO FINAL:"<<setw(12)<<(totalFac - totalN)<<endl;
}