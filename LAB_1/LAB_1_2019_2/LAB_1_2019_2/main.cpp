/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 13 de abril de 2023, 21:39
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    int dato,codigo,dd,mm,aa;
    double dolar,euro,saldoInicial,dinero;
    char nombre[50],car,tipoMov;
    cin>>dolar>>euro;
    cout<<"ESTADO DE CUENTAS DEL BANCO ABCD"<<endl;
    cout<<left<<setw(10)<<dolar<<setw(10)<<euro<<endl;
    
    while(true){
        cin>>dato;
        if(cin.eof()) break;
        if(cin.fail()){
            cin.clear();
            while(true){
                cin>>codigo;
                if (cin.fail()){
                cin.clear();
                cin >> nombre;
                cout<<left<<setw(10)<<nombre;
                } else break;
            }
            cin>>car>>saldoInicial;
            cout<<setw(20)<<codigo;
            if(car == '&') cout<<setw(20)<<"Euros";
            else if (car == '$') cout<<setw(20)<<"Dolar";
            else if (car == 'S') cout<<setw(20)<<"Soles";
            cout<<setw(20)<<saldoInicial<<endl;
        }else{
            dd = dato;
            cin>>car>>mm>>car>>aa;
            cout<<right<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aa<<left<<endl;
            while(true){
                cin>>dato;
                if(cin.eof()) break;
                if(cin.fail()){
                    cin.clear();
                    cin>>tipoMov;
                    cin>>dato;
                    if(cin.fail()){
                       cin.clear();
                       cin>>car>>dinero;
                    }else{
                        car=tipoMov;
                        dinero = dato;
                    }
                }else{
                    cin.clear();
                    break;
                }
            }
        }
    }
    return 0;
}

