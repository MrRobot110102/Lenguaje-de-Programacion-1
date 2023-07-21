/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   SobrecargaOperadores.h
 * Author: Sebastian
 *
 * Created on 5 de junio de 2023, 18:42
 */

#ifndef SOBRECARGAOPERADORES_H
#define SOBRECARGAOPERADORES_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

ifstream & operator >>(ifstream &arch,class Libro &libro);
ifstream & operator >>(ifstream &arch,class Usuario &usuario);
ifstream & operator >>(ifstream &arch,class LibroPrestado &libPrestado);
ofstream & operator <<(ofstream &arch,const class Libro &libro);
ofstream & operator <<(ofstream &arch,const class Usuario &usuario);
ofstream & operator <<(ofstream &arch,const class LibroPrestado &libPrestado);
void imprimirLinea(ofstream &arch,int cantidad, char car);

    
#endif /* SOBRECARGAOPERADORES_H */

