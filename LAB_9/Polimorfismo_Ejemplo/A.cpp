/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   A.cpp
 * Author: Sebastian
 * 
 * Created on 13 de junio de 2023, 13:55
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "A.h"

void A::mover(char direccion, int cantidad){
    switch(direccion){
        case 'P'://ARRIBA
            SetFil(GetFil()-cantidad);
            break;
        case 'R'://ABAJO
            SetFil(GetFil()+cantidad);
            break;
        case 'Q'://DERECHA
            SetCol(GetCol()+cantidad);
            break;
        case 'S'://IZQUIERDA
            SetCol(GetCol()-cantidad);
            break;    
    }
}

void A::imprime(ofstream &arch){
    char ident[10];
    GetId(ident);
    arch<<"Tipo A:"<<left<<setw(5)<<ident<<right<<setw(5)<<GetFil()<<setw(5)<<GetCol()<<endl;
}

