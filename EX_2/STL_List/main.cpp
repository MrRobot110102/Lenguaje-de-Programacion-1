/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 23:55
 */

#include <iostream>
#include <iomanip>
#include <list>
#include <iterator>
using namespace std;
#include "Persona.h"

int main(int argc, char** argv) {
//    list<double>lDbl;
//    if(lDbl.empty()) cout<<"Lista vacia"<<endl;
//    else cout<<"Lista no esta vacia"<<endl;
    list<double> listaDouble = {34.876,2.54,19.3,10.00,8.34,54.981};
//    if(listaDouble.empty()) cout<<"Lista vacia"<<endl;
//    else cout<<"Lista no esta vacia"<<endl;
//    cout<<listaDouble.size()<<endl;
    
//    list<double>lDbl(10);
//    list<double>lDbl(10,22.2);
//    lDbl.assign(10,22.2);
    
    cout.precision(2);cout<<fixed;
    for (list<double>::iterator it=listaDouble.begin(); it != listaDouble.end(); it++) cout<<setw(10)<<*it;
    cout<<endl;
    
    for (list<double>::iterator it=listaDouble.end(); it != listaDouble.begin();){
        it--;
        cout<<setw(10)<<*it;
    }
    cout<<endl<<endl;
    
    listaDouble.push_back(123.45);
    listaDouble.push_back(101.101);
    listaDouble.push_back(3.33);
    listaDouble.push_front(22.22);
    listaDouble.push_front(55.55);
    listaDouble.push_front(11.11);
    for (list<double>::iterator it=listaDouble.begin(); it != listaDouble.end(); it++) cout<<setw(10)<<*it;
    cout<<endl;
    
    double primero, ultimo;
    primero = listaDouble.front();
    ultimo = listaDouble.back();
    cout<<"Primero: "<<setw(10)<<primero<<endl;
    cout<<"Ultimo: "<<setw(10)<<ultimo<<endl;
    
    list<double>::iterator itt1= listaDouble.begin(),itt2= listaDouble.end();
    itt1++; itt1++;
    itt2--;itt2--;itt2--;
    
    listaDouble.insert(itt1,71.23);
    for (list<double>::iterator it=listaDouble.begin(); it != listaDouble.end(); it++) cout<<setw(10)<<*it;
    cout<<endl;
    
//   listaDouble.erase(itt1);
    listaDouble.erase(itt1,itt2);
    for (list<double>::iterator it=listaDouble.begin(); it != listaDouble.end(); it++) cout<<setw(10)<<*it;
    cout<<endl;
    
    list<double>lDbl2={1.1,2.2,3.3,4.4};
    listaDouble.merge(lDbl2);
    for (list<double>::iterator it=listaDouble.begin(); it != listaDouble.end(); it++) cout<<setw(10)<<*it;
    cout<<endl;
    
    listaDouble.sort();
    cout<<endl<<"Ordenados"<<endl;
    for (list<double>::iterator it=listaDouble.begin(); it != listaDouble.end(); it++) cout<<setw(10)<<*it;
    cout<<endl;
    
    list<class Persona> personas;
    class Persona per;
    ifstream arch("personal.csv", ios::in);
    if( not arch.is_open()){
        cout<<"ERROR: no se pudo abrir personal.csv"<<endl;
        exit(1);
    }
    cout<<"Cantidad inicial: "<<personas.size()<<endl;
    while(true){
        arch>>per;
        if(arch.eof()) break;
        personas.push_back(per);
    }
    cout<<"Cantidad final: "<<personas.size()<<endl;
    for (list<Persona>::iterator it=personas.begin(); it != personas.end(); it++) cout<<*it;
    cout<<endl;
    personas.sort();
    cout<<endl<<"Ordenados: "<<endl;
    for (list<Persona>::iterator it=personas.begin(); it != personas.end(); it++) cout<<*it;
    cout<<endl;
    return 0;
}

