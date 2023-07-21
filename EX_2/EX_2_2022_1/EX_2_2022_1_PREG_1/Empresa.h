/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Empresa.h
 * Author: Sebastian
 *
 * Created on 27 de junio de 2023, 20:40
 */

#ifndef EMPRESA_H
#define EMPRESA_H
#include <list>
#include <iterator>
#include "Producto.h"
#include "RegCliente.h"

class Empresa {
private:
    list<class Producto> lstProductos;
    list<class RegCliente> lstClientes;
public:
    void leerClientes(const char *);
    void imprimirClientes(const char *);
    void leerPedidos(const char *);
    void ordenarPedidos();
    void imprimirProductos(const char *);
    list<class Producto>::iterator buscarProducto(int codigo);
    list<class RegCliente>::iterator buscarCliente(int dni);
};

#endif /* EMPRESA_H */

