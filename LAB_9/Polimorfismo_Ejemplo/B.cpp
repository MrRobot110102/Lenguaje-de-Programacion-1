/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   B.cpp
 * Author: Sebastian
 * 
 * Created on 13 de junio de 2023, 14:07
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "B.h"

void B::mover(char direccion, int cantidad){
    switch(direccion){
        case 'P'://ARRIBA - IZQUIERDA
            SetFil(GetFil()-cantidad);
            SetCol(GetCol()-cantidad);
            break;
        case 'R'://ABAJO - DERECHA
            SetFil(GetFil()+cantidad);
            SetCol(GetCol()+cantidad);
            break;
        case 'Q'://ARRIBA - DERECHA
            SetFil(GetFil()-cantidad);
            SetCol(GetCol()+cantidad);
            break;
        case 'S'://ABAJO - IZQUIERDA
            SetFil(GetFil()+cantidad);  
            SetCol(GetCol()-cantidad);
            break;    
    }
}

void B::imprime(ofstream &arch){
    char ident[10];
    GetId(ident);
    arch<<"Tipo B:"<<left<<setw(5)<<ident<<right<<setw(5)<<GetFil()<<setw(5)<<GetCol()<<endl;
}
