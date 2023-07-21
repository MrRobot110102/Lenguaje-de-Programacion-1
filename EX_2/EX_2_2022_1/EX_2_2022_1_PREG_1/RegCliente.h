/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   RegCliente.h
 * Author: Sebastian
 *
 * Created on 27 de junio de 2023, 20:38
 */

#ifndef REGCLIENTE_H
#define REGCLIENTE_H
#include <list>
#include "Cliente.h"
#include "Pedido.h"

class RegCliente {
private:
    class Cliente cliente;
    list<class Pedido> pedidos;
public:
    void leerDatos(ifstream &arch);
    void imprimirDatos(ofstream &arch);
    double getDescuentoCliente();
    int getDni();
    void agregarPedido(const class Pedido &ped);
    void ordenar();
};

#endif /* REGCLIENTE_H */

