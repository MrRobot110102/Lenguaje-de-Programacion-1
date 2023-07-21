/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 20 de mayo de 2023, 23:08
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "FuncionesDeEnteros.h"
#include "FuncionesDeCadenas.h"
#include "FuncionesDePunterosVoid.h"

int main(int argc, char** argv) {
    int a[50] = {10,25,7,15,8,33,45,1,19,10,6,16,41}, numeroDatos = 13;
    char **personas;
    int numeroPersonas = 0;
    void *personal;
    int numeroPersonal = 0;
    
    qsort(a,numeroDatos,sizeof(int),cmpEnteros);
    for (int i = 0; i < numeroDatos; i++) cout<<left<<setw(4)<<a[i];
    cout<<endl;
    
    leerDatos(personas,numeroPersonas);
    qsort(personas,numeroPersonas,sizeof(char *),cmpCadenas);
    imprimirPersonas(personas);
    
    leerDatos(personal,numeroPersonal);
    qsort(personal,numeroPersonal,sizeof(void *),cmpPunterosVoidSueldo);
    imprimirPersonal(personal);
    
    return 0;
}

