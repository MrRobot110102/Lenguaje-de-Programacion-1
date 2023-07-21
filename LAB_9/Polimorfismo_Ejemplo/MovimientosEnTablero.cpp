/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   MovimientosEnTablero.cpp
 * Author: Sebastian
 * 
 * Created on 13 de junio de 2023, 14:43
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "MovimientosEnTablero.h"

void MovimientosEnTablero::cargar_Y_MoverFichas(const char*nombArchFichas,const char*nombArchMovimientos,const char*nombArchReporte){
    ifstream archFichas(nombArchFichas,ios::in);
    if(not archFichas.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchFichas<<endl;
        exit(1);
    }
    ifstream archMovimientos(nombArchMovimientos,ios::in);
    if(not archMovimientos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchMovimientos<<endl;
        exit(1);
    }
    ofstream archReporte(nombArchReporte,ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArchReporte<<endl;
        exit(1);
    }
    tablero.leerFichas(archFichas);
    archReporte << "Posiciones iniciales de las fichas:" << endl;
    tablero.imprimeDatos(archReporte);
    archReporte << endl << endl;
    tablero.leerMovimientos(archMovimientos);
    archReporte << "Posiciones finales: " << endl;
    tablero.imprimeDatos(archReporte);
}
