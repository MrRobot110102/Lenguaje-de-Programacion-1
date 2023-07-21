/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Registro.cpp
 * Author: Sebastian
 * 
 * Created on 11 de junio de 2023, 13:27
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Registro.h"

Registro::Registro() {
}

Registro::~Registro() {
}

void Registro::agregarRegistroLeve(int codFalta, char *plac, int fecha){
    lleve.SetFecha(fecha);
    lleve.SetCodigo(codFalta);
    lleve.SetPlaca(plac);
    lleve.SetGravedad("LEVE");
    buscarInfraccion(codFalta);
}
    
void Registro::agregarRegistroGrave(int codFalta, char *plac, int fecha){
    lgrave.SetFecha(fecha);
    lgrave.SetCodigo(codFalta);
    lgrave.SetPlaca(plac);
    lgrave.SetGravedad("GRAVE");
    buscarInfraccion(codFalta);
}
    
void Registro::agregarRegistroMuyGrave(int codFalta, char *plac, int fecha){
    lmgrave.SetFecha(fecha);
    lmgrave.SetCodigo(codFalta);
    lmgrave.SetPlaca(plac);
    lmgrave.SetGravedad("MUY GRAVE");
    buscarInfraccion(codFalta);
}

void Registro::buscarInfraccion(int codFalta){
    ifstream arch("Infracciones.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Infracciones.csv"<<endl;
        exit(1);
    }
    int cod,puntos,meses;
    double multa,porcentaje;
    char desc[500],car;
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        if(codFalta == cod){
            arch>>car;
            arch.getline(desc,500,',');
            arch.getline(desc,500,',');
            if(cod/100 == 1){//grave
                arch>>multa>>car>>porcentaje>>car>>puntos;
                lgrave.SetMulta(multa);
                lgrave.SetDescuento(porcentaje);
                lgrave.SetPuntos(puntos);
            }else if(cod/100 == 2){//leve
                arch>>multa>>car>>porcentaje;
                lleve.SetMulta(multa);
                lleve.SetDescuento(porcentaje);
            }else if(cod/100 == 3){//muy grave
                arch>>multa>>car>>puntos>>car>>meses;
                lmgrave.SetMulta(multa);
                lmgrave.SetPuntos(puntos);
                lmgrave.SetMeses(meses);
            }
        }else arch.getline(desc,500,'\n');
    }
}

void Registro::imprimirRegistro(ofstream &arch){
    int fecha,dd,mm,aa;
    char plac[10];
    if(lleve.GetCodigo() != 0){
        fecha = lleve.GetFecha();
        lleve.GetPlaca(plac);
        arch<<left<<setw(10)<<lleve.GetCodigo()<<setw(10)<<plac;
    }else if(lgrave.GetCodigo() != 0){
        fecha = lgrave.GetFecha();
        lgrave.GetPlaca(plac);
        arch<<left<<setw(10)<<lgrave.GetCodigo()<<setw(10)<<plac;
    }else if(lmgrave.GetCodigo() != 0){
        fecha = lmgrave.GetFecha();
        lmgrave.GetPlaca(plac);
        arch<<left<<setw(10)<<lmgrave.GetCodigo()<<setw(10)<<plac;
    }
    aa = fecha/10000;
    fecha = fecha % 10000;
    mm = fecha/100;
    dd = fecha%100;
    arch<<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa<<setfill(' ')<<left<<endl;
}

void Registro::procesaSanciones(double &montoMulta, int &puntosPerdidos, int &mesesSancionado){
    if(lleve.GetCodigo() != 0) montoMulta += (lleve.GetMulta() * (1-lleve.GetDescuento()));
    else if(lgrave.GetCodigo() != 0){
        montoMulta += (lgrave.GetMulta() * (1-lgrave.GetDescuento()));
        puntosPerdidos += lgrave.GetPuntos();
    }else if(lmgrave.GetCodigo() != 0){
        montoMulta += lmgrave.GetMulta();
        puntosPerdidos += lmgrave.GetPuntos();
        mesesSancionado += lmgrave.GetMeses();
    }
}
