/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Ficha.h
 * Author: Sebastian
 *
 * Created on 13 de junio de 2023, 13:46
 */

#ifndef FICHA_H
#define FICHA_H
#include <fstream>
using namespace std;

class Ficha {
private:
    char *id;
    int fil;
    int col;
public:
    Ficha();
    virtual ~Ficha();
    void SetCol(int col);
    int GetCol() const;
    void SetFil(int fil);
    int GetFil() const;
    void SetId(const char* ident);
    void GetId(char *ident) const;
    void asigna(char *ident,int fil,int col);
    virtual void imprime(ofstream &) = 0;
    virtual void mover(char, int) = 0;
};

#endif /* FICHA_H */

