/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   C.cpp
 * Author: Sebastian
 * 
 * Created on 13 de junio de 2023, 14:13
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "C.h"

void C::mover(char direccion, int cantidad){
    switch(direccion){
        case 'P'://ARRIBA - IZQUIERDA
            SetFil(GetFil()-2);
            SetCol(GetCol()+1);
            break;
        case 'R'://ABAJO - DERECHA
            SetFil(GetFil()+2);
            SetCol(GetCol()-1);
            break;
        case 'Q'://ARRIBA - DERECHA
            SetFil(GetFil()+1);
            SetCol(GetCol()+2);
            break;
        case 'S'://ABAJO - IZQUIERDA
            SetFil(GetFil()-1);  
            SetCol(GetCol()-2);
            break;    
    }
}

void C::imprime(ofstream &arch){
    char ident[10];
    GetId(ident);
    arch<<"Tipo C:"<<left<<setw(5)<<ident<<right<<setw(5)<<GetFil()<<setw(5)<<GetCol()<<endl;
}
