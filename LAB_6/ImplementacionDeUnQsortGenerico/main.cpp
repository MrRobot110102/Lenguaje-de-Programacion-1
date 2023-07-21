/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 21 de mayo de 2023, 0:06
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "FuncionesDeCadenas.h"
#include "FuncionesDePunterosVoid.h"
#include "FuncionDeOrdenaGenerico.h"
#include "FuncionDeComparacion.h"

int main(int argc, char** argv) {
    int a[50] = {10,25,7,15,8,33,45,1,19,10,6,16,41}, numeroDatos = 13;
    char **personas;
    int numeroPersonas = 0;
    void *personal;
    int numeroPersonal = 0;
    
    ordenarG(a,0,numeroDatos-1,cmpEnteros);
    for (int i = 0; i < numeroDatos; i++) cout<<left<<setw(4)<<a[i];
    cout<<endl;
    
    leerDatos(personas,numeroPersonas);
    ordenarG(personas,0,numeroPersonas - 1,cmpCadenas);
    imprimirPersonas(personas);
    
    leerDatos(personal,numeroPersonal);
    ordenarG(personal,0,numeroPersonal - 1,cmpPunterosVoidNombre);
    imprimirPersonal(personal);
    
    
    
    return 0;
}

