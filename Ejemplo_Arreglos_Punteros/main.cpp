/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 19 de abril de 2023, 23:42
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include <cstring>

int main(int argc, char** argv) {
 char nombre[60],*especialidad;
 int pos;
 //strcpy(nombre,"Juan Lopez_Cirujano");
 // cout<<nombre<<endl;
 // nombre[4]=0;
 // cout<<nombre<<endl;
 // nombre[4]='X';
 // cout<<nombre<<endl;
 // for(int i=strlen(nombre); i>0; i--)
 // if(nombre[i]=='_'){
 // pos = i;
 // break;
 // }
 // nombre[pos]=0;
 // especialidad = &nombre[pos+1];
 // cout<<nombre<<endl;
 // cout<<especialidad<<endl;

 especialidad = "Juan Lopez_Cirujano";
 especialidad[5] = 'H'; //ERROR

 especialidad ="Maria";

 cout<<especialidad<<endl;

    return 0;
}

