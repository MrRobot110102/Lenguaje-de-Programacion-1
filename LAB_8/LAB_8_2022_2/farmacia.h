/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   farmacia.h
 * Author: Sebastian
 *
 * Created on 9 de junio de 2023, 21:46
 */

#ifndef FARMACIA_H
#define FARMACIA_H
#include "medico.h"
#include "sinreceta.h"
#include "conreceta.h"

class farmacia {
private:
    class medico lmedico[100];
    class sinreceta lsinreceta[1000];
    class conreceta lconreceta[1000];
public:
    void cargamedico();
    void leerecetas();
    void asignarConReceta(int codMedico,char *espec,int medicamento, char *nombMed,double precio,int cantidad,int fecha,int &numConReceta);
    void asignarSinReceta(int dni,char *nomb,int medicamento, char *nombMed,double precio,int cantidad,int fecha,int &numSinReceta);
    int buscarMedicamento(int cod,char *nomMedicamento,double &precio);
    int buscarEspecialidad(int cod, char *espec);
    void imprimirrecetas();
    void imprimeLinea(ofstream &arch,int cantidad, char car);
};

#endif /* FARMACIA_H */

