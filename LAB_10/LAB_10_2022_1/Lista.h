/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Lista.h
 * Author: Sebastian
 *
 * Created on 23 de junio de 2023, 22:42
 */

#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Lista {
private:
    class Nodo *lini;
    class Nodo *lfin;
    void insertar(class Nodo *nodo);
public:
    Lista();
    virtual ~Lista();
    void crearLista(ifstream &arch);
    void actualizarLista(ifstream &arch);
    void actualizaCliente(int dni, int fecha);
    void imprimirLista(ofstream &arch);
};

#endif /* LISTA_H */

