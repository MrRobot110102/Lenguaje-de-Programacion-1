/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Registro.h
 * Author: Sebastian
 *
 * Created on 11 de junio de 2023, 13:27
 */

#ifndef REGISTRO_H
#define REGISTRO_H
#include "Conductor.h"
#include "Leve.h"
#include "Grave.h"
#include "MuyGrave.h"

class Registro : public Conductor{
private:
    class Leve lleve;
    class Grave lgrave;
    class MuyGrave lmgrave;
public:
    Registro();
    virtual ~Registro();
    void agregarRegistroLeve(int codFalta, char *plac, int fecha);
    void agregarRegistroGrave(int codFalta, char *plac, int fecha);
    void agregarRegistroMuyGrave(int codFalta, char *plac, int fecha);
    void buscarInfraccion(int codFalta);
    void imprimirRegistro(ofstream &arch);
    void procesaSanciones(double &montoMulta, int &puntosPerdidos, int &mesesSancionado);
};

#endif /* REGISTRO_H */

