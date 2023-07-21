/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "SobrecargaOperadores.h"
#include "Usuario.h"
#include "LibroPrestado.h"
#include "Libro.h"

ifstream & operator >>(ifstream &arch,class Libro &libro){
    char cod[10],tit[200],aut[200];
    int anio,stock;
    double precio;
    arch.getline(cod,10,',');
    if(arch.eof()) return arch;
    arch.getline(tit,200,',');
    arch.getline(aut,200,',');
    arch>>anio;
    arch.get();
    arch>>stock;
    arch.get();
    arch>>precio;
    arch.get();
    libro.SetAutor(aut);
    libro.SetCodigo(cod);
    libro.SetTitulo(tit);
    libro.SetPrecio(precio);
    libro.SetStock(stock);
    return arch;
}

ifstream & operator >>(ifstream &arch,class Usuario &usuario){
    int carne;
    char tip,nomb[300];
    arch>>carne;
    if(arch.eof()) return arch;
    arch>>tip;
    arch.get();
    arch.getline(nomb,300);
    usuario.SetCarne(carne);
    usuario.SetTipo(tip);
    usuario.SetNombre(nomb);
    return arch;
} 

ifstream & operator >>(ifstream &arch,class LibroPrestado &libPrestado){
    int carne,dd,mm,aa,fecha;
    char tip,cod[10],car;
    arch>>carne;
    if(arch.eof()) return arch;
    arch>>tip;
    arch.get();
    arch.getline(cod,10,',');
    arch>>dd>>car>>mm>>car>>aa;
    fecha = aa * 10000 + mm * 100 + dd;
    libPrestado.SetCarne(carne);
    libPrestado.SetCodigoLib(cod);
    libPrestado.SetFechaDeRetiro(fecha);
    libPrestado.SetTipo(tip);
    return arch;
}

ofstream & operator <<(ofstream &arch,const class Libro &libro){
    char cod[10],tit[200],aut[200];
    libro.GetAutor(aut);
    libro.GetCodigo(cod);
    libro.GetTitulo(tit);
    arch<<left<<"Codigo:   "<<cod<<endl;
    arch<<left<<"Titulo:   "<<tit<<endl;
    arch<<left<<"Autor:    "<<aut<<endl;
    arch<<left<<"Stock:    "<<libro.GetStock()<<endl;
    imprimirLinea(arch,100,'=');
    arch<<"Prestamo a docentes:"<<libro.GetCantDoc()<<endl;
    arch<<"Prestamo a alumnos:"<<libro.GetCantEst()<<endl;
    arch<<"Prestamo a administrativos:"<<libro.GetCantAdm()<<endl;
    imprimirLinea(arch,100,'-');
    arch<<"Total de prestamos:"<<libro.GetPrestados()<<endl;
    imprimirLinea(arch,100,'=');
}

ofstream & operator <<(ofstream &arch,const class Usuario &usuario){
    char tip,nomb[300];
    arch<<left<<"Carne: "<<usuario.GetCarne()<<endl;
    usuario.GetNombre(nomb);
    arch<<nomb<<endl;
    if(usuario.GetTipo() == 'E') arch<<"Estudiante"<<endl;
    else if(usuario.GetTipo() == 'D') arch<<"Docente"<<endl;
    else if(usuario.GetTipo() == 'A') arch<<"Administrativo"<<endl;
    if(usuario.GetCondicion() == 0) arch<<"INHABILITADO"<<endl;
    else arch<<"HABILITADO"<<endl;
    usuario.imprimirLibrosPrestados(arch);
}

ofstream & operator <<(ofstream &arch,const class LibroPrestado &libPrestado){
    int dd,mm,aa,fecha;
    char tip,cod[10],car;
    libPrestado.GetCodigoLib(cod);
    fecha = libPrestado.GetFechaDeRetiro();
    aa = fecha/10000;
    fecha %= 10000;
    mm = fecha/100;
    dd = fecha%100;
    arch<<left<<setw(15)<<cod<<setfill('0')<<right<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa
        <<setfill(' ');
    if(libPrestado.GetDeuda() == 1) arch<<left<<"    "<<"Deuda"<<endl;
    else arch<<endl;
}

void imprimirLinea(ofstream &arch,int cantidad, char car){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}

