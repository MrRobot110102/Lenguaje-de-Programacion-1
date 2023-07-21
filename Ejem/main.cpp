/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 20 de abril de 2023, 0:08
 */

#include <iostream>
#include <iomanip>
using namespace std;


int main(int argc, char** argv) {
    int cod;
    bool bandera = false;
    char *nombre,*curso,car;
    nombre = new char[60];
    curso = new char[10];
    
    cout<<left<<setw(20)<<"Codigo"<<setw(50)<<"Nombre"<<setw(10)<<"Cursos"<<endl;
    
    while(true){
        cin>>cod;
        if(cin.eof()) break;
        if(not cin.fail()){
            cin>>car;
            cin.getline(nombre,60,',');
            if(bandera != false) cout<<endl; 
            cout<<setw(10)<<cod<<setw(60)<<nombre;
            bandera = true;
        }else{
           cin.clear();
           cin>>ws;
           cin.getline(curso,7);
           cout<<setw(10)<<curso;
        }
    }
    
    return 0;
}

