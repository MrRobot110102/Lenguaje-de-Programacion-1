/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Programa.h
 * Author: Sebastian
 *
 * Created on 27 de junio de 2023, 23:05
 */

#ifndef PROGRAMA_H
#define PROGRAMA_H
#include <vector>
#include <iterator>
using namespace std;
#include "Lista.h"
#include "NProductos.h"

class Programa {
private:
    class Lista lpedidos;
    vector<class NProductos> vproductos;
public:
    void carga();
    void CargaProductos();
    void CargaLista();
    void actualiza();
    void muestra();
    void ImprimeProductos();
    void ImprimeLista();
};

#endif /* PROGRAMA_H */

