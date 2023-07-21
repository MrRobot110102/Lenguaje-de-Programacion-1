/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 21:16
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
#include "Persona.h"
// **************************************
// USAR el estándar C++14
// **************************************

int main(int argc, char** argv) {
    vector<int> vInt={23,56,12,83,102,66,45,19};
    //vector<int> vInt(10);
    //vector<int> vInt(10,33);
    
    //Tamanio y capacidad del vector
    cout<<"Numero de elementos: "<<vInt.size()<<endl;
    cout<<"Capacidad inicial  : "<<vInt.capacity()<<endl;
    //agregar elementos
    vInt.push_back(99);
    vInt.push_back(33);
    vInt.push_back(22);
    vInt.push_back(88);
    vInt.push_back(77);
    vInt.push_back(11);
    
    cout<<"Numero de elementos: "<<vInt.size()<<endl;
    cout<<"Capacidad inicial  : "<<vInt.capacity()<<endl;
    //Imprimir elementos del vector
    for (int i = 0; i < vInt.size(); i++) cout<<setw(5)<<vInt[i];
    cout<<endl;
    
    //misma capacidad que cantidad de elementos
    vInt.shrink_to_fit();
    cout<<"Numero de elementos: "<<vInt.size()<<endl;
    cout<<"Capacidad inicial  : "<<vInt.capacity()<<endl;
    
    //sacar un elemento
    vInt.pop_back();
    vInt.shrink_to_fit();
    cout<<"Numero de elementos: "<<vInt.size()<<endl;
    cout<<"Capacidad inicial  : "<<vInt.capacity()<<endl;
    for (int i = 0; i < vInt.size(); i++) cout<<setw(5)<<vInt[i];
    cout<<endl;
    
    int dato;
    //devolver una copia de la cabeza del vector
    dato = vInt.front();
    cout<<"Dato = "<<dato<<endl;
    //devolver una copia de la cola del vector
    dato = vInt.back();
    cout<<"Dato = "<<dato<<endl;
    
    //imprimir con iteradores
    for(vector<int>::iterator it=vInt.begin(); it!=vInt.end();it++) cout<<setw(5)<<*it;
    cout<<endl<<endl;
    for(vector<int>::iterator it=vInt.end(); it!=vInt.begin();){
        it--;
        cout<<setw(5)<<*it;
    }
    cout<<endl;
    
    //parte de iteradores 
    vector<int>::iterator itt=vInt.begin();
    cout<<*itt<<endl;
    //itt+=3;
    //cout<<*itt<<endl;
    
    vInt.erase(vInt.begin()+3);
    for (int i = 0; i < vInt.size(); i++) cout<<setw(5)<<vInt[i];
    cout<<endl;
    
    vInt.insert(vInt.begin()+3,777);
    for (int i = 0; i < vInt.size(); i++) cout<<setw(5)<<vInt[i];
    cout<<endl;
    
    sort(vInt.begin(),vInt.end());
    for (int i = 0; i < vInt.size(); i++) cout<<setw(5)<<vInt[i];
    cout<<endl;
    
    //vInt.clear(); //ELIMINA TODO EL ARREGLO
    //cout<<vInt.empty(); // Devuelve verdadero si el arreglo está vacío
    cout<<vInt.size()<<endl;
    vInt.erase(vInt.begin()+3,vInt.end()-5); //borra un rango de datos
    cout<<vInt.size()<<endl;
    for (int i = 0; i < vInt.size(); i++) cout<<setw(5)<<vInt[i];
    cout<<endl;

    
    vector<class Persona>vPer;
    class Persona per;
    
    ifstream arch("personal.csv", ios::in);
    if( not arch.is_open()){
        cout<<"ERROR: no se pudo abrir personal.csv"<<endl;
        exit(1);
    }
    
    while(true){
        arch>>per;
        if(arch.eof()) break;
        vPer.push_back(per);
    }
    
    for(vector<class Persona>::iterator it=vPer.begin(); it!=vPer.end();it++) cout<<*it;
    cout<<endl;
    per = vPer.front();
    cout<<per;
    per = vPer.back();
    cout<<per;
    cout<<endl;
    //debe sobrecargar <
    sort(vPer.begin(),vPer.end());
    for(vector<class Persona>::iterator it=vPer.begin(); it!=vPer.end();it++) cout<<*it;
    cout<<endl;
    vPer.erase(vPer.begin()+=3,vPer.end()-=5);
    for (int i = 0; i < vPer.size(); i++) cout<<vPer[i];
    return 0;
}

