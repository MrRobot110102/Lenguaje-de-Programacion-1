/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ClNodo.h
 * Author: Sebastian
 *
 * Created on 17 de junio de 2023, 20:32
 */

#ifndef CLNODO_H
#define CLNODO_H
#include "ClLista.h"

template <typename T>class ClLista; //NO olvidar esto
template <typename T>
class ClNodo {
private:
    T dato;
    class ClNodo<T> *sig;
public:
    ClNodo();
    friend class ClLista<T>;
};

template <typename T>
ClNodo<T>::ClNodo(){
    sig = nullptr;
}

#endif /* CLNODO_H */

