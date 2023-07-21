/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 1 de junio de 2023, 18:49
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "FuncionesAuxiliares.h"

int main(int argc, char** argv) {
    void * lista;
    void * lista_reg;
    ifstream arch("datos.txt", ios::in);
    ifstream arch_registros("personal.csv", ios::in);
    
    //Forma 1 de insercion
    crear_lista(arch, lista, leer_entero);
    imprimir_lista(lista, imprimir_entero);
    
    //Forma 2 insertar ordenado
    crear_lista(arch_registros, lista_reg, leer_registro, cmp_registro_multi_criterio);
    imprimir_lista(lista_reg, imprimir_registro);
    eliminar_lista(lista_reg, eliminar_registro);
    return 0;
}

