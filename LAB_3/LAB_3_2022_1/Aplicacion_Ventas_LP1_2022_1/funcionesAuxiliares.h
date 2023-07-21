/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 25 de abril de 2023, 16:22
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void leerClientes(Estructura_ClienteRegistrado *clientes,int &numClientes);
void leerPedidos(Estructura_ClienteRegistrado *clientes,
                 Estructura_ProductosEnAlmacen *productos,int numClientes);
void emitirReporte(Estructura_ClienteRegistrado *clientes,
                   Estructura_ProductosEnAlmacen *productos,int numClientes);

#endif /* FUNCIONESAUXILIARES_H */

