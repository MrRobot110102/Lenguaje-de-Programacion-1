/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 26 de junio de 2023, 15:26
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <map>
#include <iterator>
using namespace std;
#include "Persona.h"

int main(int argc, char** argv) {
    map<int,double>mDbl;
    mDbl[3]=45.73;
    mDbl[8]=102.63;
    mDbl[2]=9.753;
    mDbl[10]=33.746;;
    mDbl[5]=374.76;
    mDbl[4]=1021.76;
    mDbl[2]=11.11;
    
    for(map<int,double>::iterator it=mDbl.begin();it!=mDbl.end(); it++)
        cout<<setw(4)<<it->first<<" - "<<setw(10)<<it->second<<endl;
    int p = 2;
    cout<<"Dato = "<<mDbl[p]<<endl;
    
    map<int,class Persona>personas;
    class Persona per;
    ifstream arch("personal.csv", ios::in);
    if( not arch.is_open()){
        cout<<"ERROR: no se pudo abrir personal.csv"<<endl;
        exit(1);
    }
    while(true){
        arch>>per;
        if(arch.eof()) break;
        personas[per.GetDni()] = per;
    }
    cout.precision(2);cout<<fixed;
    for (map<int,Persona>::iterator it=personas.begin(); it != personas.end(); it++){
        cout<<it->first<<'-'<<it->second;
    }
        
    cout<<endl;
    
    int dni = 378708;
    cout<<"El DNI "<<dni<<" pertenece a:"<<endl;
    cout<<personas[dni];
    return 0;
}

