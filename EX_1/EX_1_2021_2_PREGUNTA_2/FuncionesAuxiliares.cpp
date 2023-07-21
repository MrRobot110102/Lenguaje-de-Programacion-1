/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

//20190638
//Sebastian Moises Esquivel Barreto

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"
#include "imprimevoid.h"
#define MAX_CAR 120

//    void *stock;
void cargalibros(void *&stock){
    ifstream archLibros("Libros2.csv",ios::in);
    if(not archLibros.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros2.csv"<<endl;
        exit(2);
    }
    void *buffStock[100], **stockFinal;
    int numDatos = 0;
    while(true){
        buffStock[numDatos] = leeRegistro(archLibros);
        if(buffStock[numDatos] == nullptr) break;
        numDatos++;
    }
    stockFinal =  new void*[numDatos + 1]{};
    for (int i = 0; i < numDatos; i++) stockFinal[i] = buffStock[i];
    stock = stockFinal;
    imprimelibros(stock);
}

void *leeRegistro(ifstream &arch){
    char *codigo, *titulo, *autor,car;
    int *edicion,*stock,*cantidad;
    double *precio;
    void **registro;
    edicion = new int;
    stock = new int;
    precio = new double;
    cantidad = new int;
    codigo = leerCadena(arch);
    if(arch.eof()) return nullptr;
    titulo = leerCadena(arch);
    autor = leerCadena(arch);
    arch>>*edicion>>car>>*stock>>car>>*precio;
    arch.get();
    *cantidad = *stock;
    registro = new void*[7];
    registro[0] = codigo;
    registro[1] = titulo;
    registro[2] = autor;
    registro[3] = cantidad;
    registro[4] = stock;
    registro[5] = leeCopias(*cantidad);
    registro[6] = precio;
    return registro;
}

void *leeCopias(int cantidad){
    int *numCopia;
    char *estado;
    int *fecha;
    double *valorLibro;
    void **detalleCopia;
    void **registro = new void*[cantidad+1]{};
    if(cantidad == 0) return nullptr;
    
    for (int i = 0; i < cantidad; i++) {
        detalleCopia = new void*[4];
        numCopia = new int;
        fecha = new int;
        valorLibro = new double;
        *numCopia = i+1;
        *fecha = 0;
        *valorLibro = 0.0;
        estado = leerEstado('D');//D -> disponible, P->Prestamo, R -> Perdida
        detalleCopia[0] = numCopia;
        detalleCopia[1] = estado;
        detalleCopia[2] = fecha;
        detalleCopia[3] = valorLibro;
        registro[i] = detalleCopia;
    }
    return registro;
}

char *leerEstado(char car){
    char *aux;
    if(car == 'D'){
        aux = new char[11];
        strcpy(aux,"Disponible");
        return aux;
    }else if(car == 'P'){
        aux = new char[8];
        strcpy(aux,"Prestamo");
        return aux;
    }else if(car == 'R'){
        aux = new char[8];
        strcpy(aux,"Perdida");
        return aux;
    }
}

char *leerCadena(istream &arch){
    char *aux, buff[100];
    arch.getline(buff,100,',');
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}
    
void actualiza(void *&stock){
    ifstream archPrestamos("RegistroDePrestamos2.csv",ios::in);
    if(not archPrestamos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RegistroDePrestamos2.csv"<<endl;
        exit(1);
    }
    void **stockFinal = (void **)stock;
    int codigo,numCopia,dd,mm,aa,posicionLibro;
    char tipo, *codLibro,car;
    int *cantidad;
    while(true){
        archPrestamos>>codigo;
        if(archPrestamos.eof()) break;
        archPrestamos>>tipo>>car;
        codLibro = leerCadena(archPrestamos);
        archPrestamos>>numCopia>>car>>dd>>car>>mm>>car>>aa;
        posicionLibro = buscarLibro(stock,codLibro,mm,cantidad);
        if(posicionLibro != -1 and (*cantidad)>0){
            (*cantidad)--;
            actualizarCopias(stockFinal[posicionLibro],numCopia,dd,mm,aa);
        }
    }
}

void actualizarCopias(void *&stock,int numCopia,int dd,int mm,int aa){
    void **stockFinal = (void **)stock;
    double *precio = (double *)stockFinal[6];
    actualizar(stockFinal[5],numCopia,dd,mm,aa,*precio);
}

void actualizar(void *&stock, int numCopia,int dd,int mm,int aa,double precio){
    void **stockFinal = (void **)stock;
    actualizarDatos(stockFinal[numCopia-1],dd,mm,aa,precio);
}

void actualizarDatos(void *&stock,int dd,int mm,int aa,double precio){
    void **stockFinal = (void **)stock;
    int fecha = aa*10000 + mm *100 + dd;
    char *estado = (char *)stockFinal[1];
    int *fechaPrestamo = (int *)stockFinal[2];
    if((10 - mm) > 2){//perdida
        double *prec = (double *)stockFinal[3];
        *prec = precio;
        *fechaPrestamo = fecha;
        strcpy(estado,"Perdida");
    }else{
        *fechaPrestamo = fecha;
        strcpy(estado,"Prestamo");
    }
}

int buscarLibro(void *stock,char *codLibro,int mm,int *&cantidad){
   void **stockFinal = (void **)stock;
   for (int i = 0; stockFinal[i]; i++)
       if(compararLibros(stockFinal[i],codLibro,mm, cantidad)) return i;
    return -1;
}

int compararLibros(void *stock,char *codLibro, int mm, int *&cantidad){
    void **stockFinal = (void **)stock;
    char *codigoLibro = (char *)stockFinal[0];
    cantidad = (int *)stockFinal[4];
    if(strcmp(codigoLibro,codLibro) == 0) return 1;
    else return 0;
}
    
void imprimestock(void *stock){
    ofstream archReporte("ReporteStock.txt",ios::out);
    archReporte<<"  "<<setw(15)<<left<<"COD: DE LIB"<<"  "<<setw(40)<<left<<
            "Titulo"<<setw(40)<<left<<"Autor"<<setw(24)<<left
            <<"# Copias"<<left<<"Stock"<<endl;
    void **stockFinal=(void **)stock;
    for(int i=0;stockFinal[i];i++){
        imprimeStockLibro(stockFinal[i],archReporte);
    }
}

void imprimeStockLibro(void *&st,ofstream &arch){
    void **stock=(void **)st;
    char *cod,*titulo,*autor;
    int *ncopia,*cantstock;
    cod = (char *)stock[0];
    titulo = (char *)stock[1];
    autor = (char *)stock[2];
    ncopia = (int *)stock[3];
    cantstock = (int *)stock[4];
    arch<<"  "<<setw(15)<<left<<cod<<"  "<<setw(40)<<left<<
            titulo<<setw(44)<<left<<autor<<setw(22)<<left
            <<*ncopia<<left<<*cantstock<<endl;
    imprimeDetalleCopias(stock[5],arch);
}
void imprimeDetalleCopias(void *st,ofstream &arch){
    void **stock=(void **)st;
    arch<<"Detalle de copias"<<endl;
    for(int i=0;stock[i];i++){
        imprimeDetalleUnaCopia(stock[i],i,arch);
    }
    arch<<endl;
}

void imprimeDetalleUnaCopia(void *st,int i,ofstream &arch){
    void **stock=(void **)st;
    char *estado=(char *)stock[1];
    int *fecha=(int *)stock[2];
    double *monto=(double *)stock[3];
    arch<<"      "<<setw(7)<<left<<i+1;
    arch<<setw(40)<<left<<estado;
    cout<<estado<<endl;
    if(*fecha==0){
        arch<<endl;
    }else{
        imprimeFecha(*fecha,arch);
        if(*monto>0){
            arch<<setw(15)<<right<<setprecision(2)<<fixed<<*monto<<endl;
        }else{
            arch<<endl;
        }
    } 
    
}

void imprimeFecha(int fecha,ofstream &arch){
    int dd,mm,aa;
    char c;
    dd=fecha%100;
    fecha/=100;
    mm=fecha%100;
    aa=fecha/100;
    arch<<setfill('0')<<setw(2)<<right<<dd<<"/"<<setw(2)<<right<<mm<<"/"<<setw(4)
            <<right<<aa<<setfill(' ');
}