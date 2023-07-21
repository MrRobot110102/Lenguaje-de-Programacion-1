/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   NLibro.h
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 19:27
 */

#ifndef NLIBRO_H
#define NLIBRO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Libro.h"
#include "ALibro.h"

class NLibro {
private:
    class Libro dlibro;
    class NLibro *izq; 
    class NLibro *der; 
public:
    NLibro();
    friend class ALibro;
};

#endif /* NLIBRO_H */

