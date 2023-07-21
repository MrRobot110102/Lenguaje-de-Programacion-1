/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "funcionesAuxiliares.h"
#define MAX_CAR 145

void imprimirEncabezado(){
    cout<<right<<setw(65)<<"EMPRESA COMERCIALIZADORA DE ABARROTES"<<endl;
    imprimirLinea('=',MAX_CAR);
    cout<<left<<"GASTOS DE LOS CLIENTES REGISTRADOS: "<<endl;
}

void leerCategorias(double &porA,double &porB,double &porC,char car,char *prodVeri){
    cin>>car>>porA>>car>>car>>porB>>car>>car>>porC>>car>>prodVeri;
    imprimirEncabezado();
}

void imprimirLinea(char car,int cantidad){
    for (int i = 0; i < cantidad; i++) cout<<car;
    cout<<endl;
}

void darFormatoNombre(char *nombre){
    int i=0;
    while(nombre[i]){
        if(nombre[i] == '_' or nombre[i] == '/' or nombre[i] == '-') nombre[i] = ' ';
        i++;
    }
}

int cantidadPalabras(char *nombre){
    int i=0;
    while(nombre[i]) i++;
    return i;
}

char asignarCategoria(char *nombre){
    int cantPal = cantidadPalabras(nombre);
    char car;
    if(nombre[cantPal-2] == '-'){
        car = nombre[cantPal-1];
        nombre[cantPal-2] = nombre[cantPal];
    }else car = '-';
    return car;
}

void copiarPalabra(char *nombre,char *nombreMasDesc){
    int i =0;
    while(nombre[i]){
        nombreMasDesc[i] = nombre[i];
        i++;
    }
    nombreMasDesc[i] = nombre[i];
}

void imprimirTotales(double totalPagar,double totalDesc,double &mayorDescuento,char *nombre,char *nombreMasDesc){
    if(totalDesc>mayorDescuento){
        copiarPalabra(nombre,nombreMasDesc);
        mayorDescuento = totalDesc;
    }
    imprimirLinea('-',MAX_CAR);
    cout<<right<<setw(12)<<"TOTAL:"<<setw(109)<<totalPagar<<setw(10)<<totalDesc<<endl;
    imprimirLinea('=',MAX_CAR);
}

void imprimirDetalle(int dni,char *nombre,int telefono,char car,double desc){
    imprimirLinea('=',MAX_CAR);
    cout<<left<<dni<<"     "<<setw(50)<<nombre<<setw(20)<<telefono;
    if(car == '-') cout<<setw(10)<<'-'<<setw(10)<<"-.--%"<<endl;
    else cout<<setw(10)<<car<<desc<<'%'<<endl;   
    imprimirLinea('-',MAX_CAR);
    cout<<left<<"PRODUCTOS ADQUIRIDOS:"<<endl;
    imprimirLinea('-',MAX_CAR);
    cout<<setw(6)<<" "<<setw(9)<<"Codigo"<<setw(47)<<"Descripcion"
        <<setw(10)<<"P.U."<<setw(12)<<"Cantidad"<<setw(12)<<"Total"
        <<setw(19)<<"Descuentos %"<<setw(10)<<"A Pagar"<<setw(12)<<"Descuento"
        <<"Fecha"<<endl;
    imprimirLinea('-',MAX_CAR);
}

void imprimirEncabezadoCliente(int dni,char *nombre,int telefono,double porA,
                               double porB,double porC,double &descCategoria,
                               int &i, double &totalPagar,double &totalDesc,
                               double &mayorDescuento,char *nombreMasDesc){
    double desc=0.0;
    char car;
    car = asignarCategoria(nombre);
    darFormatoNombre(nombre);
    if(car == 'A') desc = porA;
    else if(car == 'B') desc = porB;
    else if(car == 'C') desc = porC;
    descCategoria = desc;
    cout<<left<<setw(13)<<"DNI"<<setw(50)<<"Nombre"<<setw(17)<<"Telefono"
        <<setw(10)<<"Categoria"<<setw(10)<<"Descuento"<<endl;
    imprimirDetalle(dni,nombre,telefono,car,desc);
    i=1;
    totalPagar = 0.0;
    totalDesc = 0.0;
}

int compararPalabras(char *codProd,char *prodVeri){
    int i=0;
    while(prodVeri[i]){
        if(codProd[i] != prodVeri[i]) return 0;
        i++;
    }
    return 1;
}

void imprimirProducto(int &i,char *codProd,char *nomProd,double preUni,
                      double cantidad,double desc,int dd,int mm,int aa,
                      double descCategoria,double &totalPagar,double &totalDesc,
                      char *prodVeri,char *nombreProdVeri, double &totalInProd){
    double total = preUni * cantidad;
    double aPagar = (total * (1-desc/100)) *(1-descCategoria/100);
    double descuento = total - aPagar;
    
    darFormatoNombre(nomProd);
    cout<<right<<setw(2)<<i<<setw(10)<<codProd<<left<<"   "<<setw(45)<<nomProd
        <<right<<setw(6)<<preUni<<setw(4)<<" "<<setw(7)<<cantidad<<setw(3)<<" "
        <<setw(10)<<total;
    if(desc == 0.0) cout<<setw(10)<<"-.--";
    else cout<<setw(10)<<desc;
    if(descCategoria == 0.0) cout<<'|'<<setw(6)<<"-.--";
    else cout<<'|'<<setw(6)<<descCategoria;
    cout<<"    "<<right<<setw(10)<<aPagar<<setw(10)<<descuento;
    cout<<"    "<<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)
        <<mm<<'/'<<aa<<setfill(' ')<<endl;
    totalPagar += aPagar;
    totalDesc += descuento;
    if(compararPalabras(codProd,prodVeri)){
        copiarPalabra(nomProd,nombreProdVeri);
        totalInProd = totalInProd + aPagar;
    }
    i++;
}

void imprimirResumenFinal(double mayorDescuento,char *nombreMasDesc,char *prodVeri,
                          char *nombreProdVeri,double totalInProd){
    cout<<left<<"CLIENTE QUE RECIBIO MAS DESCUENTO:"<<setw(50)<<nombreMasDesc
        <<"DESCUENTO TOTAL:  "<<mayorDescuento<<endl;
    cout<<left<<"PRODUCTO A VERIFICAR:  "<<nombreProdVeri<<'['<<prodVeri<<']';
    cout<<"   "<<"TOTAL INGRESADO POR EL PRODUCTO:  "<<totalInProd<<endl;
}