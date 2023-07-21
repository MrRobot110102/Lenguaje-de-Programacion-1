/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 21 de mayo de 2023, 15:58
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "BibliotecaListaGenerica.h"
#include "ListaConEnteros.h"
#include "ListaConRegistro.h"

int main(int argc, char** argv) {
    void *lista1,*lista2;
    creaLista(lista1,leenum,cmpnum,"RegistroDeFaltas1.csv");
    creaLista(lista2,leenum,cmpnum,"RegistroDeFaltas2.csv");
    uneLista(lista1,lista2);
    imprimeLista(lista1,imprimenum,"Repnum.txt");
    
    creaLista(lista1,leeregistro,cmpregistro,"RegistroDeFaltas1.csv");
    creaLista(lista2,leeregistro,cmpregistro,"RegistroDeFaltas2.csv");
    uneLista(lista1,lista2);
    imprimeLista(lista1,imprimeregistro,"Repfalta.txt");
    
    return 0;
}

