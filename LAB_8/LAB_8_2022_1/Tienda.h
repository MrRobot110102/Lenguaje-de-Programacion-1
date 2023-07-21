/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Tienda.h
 * Author: Sebastian
 *
 * Created on 9 de junio de 2023, 19:18
 */

#ifndef TIENDA_H
#define TIENDA_H
#include "Pedido.h"
#include "Cliente.h"

class Tienda {
private:
    class Pedido lpedidos[150];
    class Cliente lclientes[50];
public:
    void carga();
    void cargaPedidos(ifstream &arch);
    void cargaClientes(ifstream &arch);
    int buscarProducto(int cod,char *nomb,int &stock,double &precio);
    void actualiza(int cantidad);
    void muestra();
    char obtenerCategoriaCliente(int dni);
};

#endif /* TIENDA_H */

