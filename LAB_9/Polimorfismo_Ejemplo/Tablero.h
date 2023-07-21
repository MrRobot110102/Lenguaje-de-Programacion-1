/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tablero.h
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 14:16
 */

#ifndef TABLERO_H
#define TABLERO_H
#include <fstream>
using namespace std;

class Tablero {
private:
    class Ficha *fichas[100];
    int numFichas;
public:
    Tablero();
    virtual ~Tablero();
    void SetNumFichas(int numFichas);
    int GetNumFichas() const;
    void leerFichas(ifstream &);
    void colocarFicha(char*, char, int, int);
    void leerMovimientos(ifstream &);
    void moverFicha(char*, char, int);
    void imprimeDatos(ofstream &);  
};

#endif /* TABLERO_H */

