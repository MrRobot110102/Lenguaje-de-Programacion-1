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
#include "Persona.h"
#include "ClLista.h"

class ClNodo {
private:
    class Persona dato;
    class ClNodo *sig;
public:
    ClNodo();
    friend class ClLista;
};

#endif /* CLNODO_H */

