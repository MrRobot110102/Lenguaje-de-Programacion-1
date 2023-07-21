/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Plantilla.h
 * Author: Sebastian
 *
 * Created on 25 de junio de 2023, 20:33
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

#ifndef PLANTILLA_H
#define PLANTILLA_H


template <typename T>
class Plantilla {
private:
    T dato;
public:
    void SetDato(const T &d);
    T GetDato() const;
    void leerDato();
    void imprimirDato();
};

template <typename T>
void Plantilla<T>::SetDato(const T &d){
    dato = d;
}

template <typename T>
T Plantilla<T>::GetDato() const{
    return dato;
}

template <typename T>
void Plantilla<T>::leerDato(){
    cin>>dato;
}

template <typename T>
void Plantilla<T>::imprimirDato(){
    cout<<dato<<endl;
}

#endif /* PLANTILLA_H */

