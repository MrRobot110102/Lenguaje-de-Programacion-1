/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   LFalta.h
 * Author: Sebastian
 *
 * Created on 26 de junio de 2023, 16:09
 */

#ifndef LFALTA_H
#define LFALTA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "NFalta.h"

class LFalta {
private:
    class NFalta *lini;
    class NFalta *lfin;
    void insertar(class NFalta *nuevo);
public:
    LFalta();
    virtual ~LFalta();
    void leer(const char *nombArch);
    void unir(class LFalta &lista2);
    void imprimir(const char *nombArch);
    void imprimeLinea(ofstream &arch,int cant,char c);
};

#endif /* LFALTA_H */

