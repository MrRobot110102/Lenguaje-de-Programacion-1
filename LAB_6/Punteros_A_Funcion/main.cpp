/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 20 de mayo de 2023, 22:58
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

int suma(int x, int y){
    return x+y;
}

int multiplicacion(int x,int y){
    return x*y;
}

int cualquierCosa(int x,int y){
    return x*y-x*x+y;
}

int operacion(int p, int q, int (*ptrFunc) (int,int)){
    int t;
    t = ptrFunc(p,q);
    return t;
}

int main(int argc, char** argv) {
    int a=15,b=3,c;
    
    int (*ptrFun) (int,int);
    ptrFun = suma;
    c = ptrFun(a,b);
    cout<<c<<endl;
    //FUNCION GENERICA
    c = operacion(a,b,suma);
    cout<<c<<endl;
    c = operacion(a,b,multiplicacion);
    cout<<c<<endl;
    c = operacion(a,b,cualquierCosa);
    cout<<c<<endl;
    return 0;
}

