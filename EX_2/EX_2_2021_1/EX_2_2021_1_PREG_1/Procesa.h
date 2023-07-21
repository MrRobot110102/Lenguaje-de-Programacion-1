/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Procesa.h
 * Author: Sebastian
 *
 * Created on 1 de julio de 2023, 13:29
 */

#ifndef PROCESA_H
#define PROCESA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <list>
using namespace std;
#include "Nodo.h"

class Procesa {
public:
    void lee();
    void imprime();
private:
    list<class Nodo>lrenueva;
};

#endif /* PROCESA_H */

