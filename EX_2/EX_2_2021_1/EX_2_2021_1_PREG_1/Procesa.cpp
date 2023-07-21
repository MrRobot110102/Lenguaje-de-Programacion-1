/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.cpp
 * Author: Sebastian
 * 
 * Created on 1 de julio de 2023, 13:29
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <list>
#include <iterator>
using namespace std;
#include "Procesa.h"


void Procesa::lee() {
    ifstream arch("Conductores.csv",ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Conductores.csv"<<endl;
        exit(1);
    }
    class Nodo nuevo;
    while(true){
        nuevo.leer(arch);
        if(arch.eof()) break;
        //cout<<nuevo.getLicencia()<<endl;
        lrenueva.push_back(nuevo);
    }
}

void Procesa::imprime() {
    ofstream arch("ReporteConductores.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ReporteConductores.txt"<<endl;
        exit(1);
    }
    lrenueva.sort();
    for (list<Nodo>::iterator it = lrenueva.begin(); it != lrenueva.end(); it++)
        it->imprimir(arch);
}



