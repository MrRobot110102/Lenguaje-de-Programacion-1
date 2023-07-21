/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   operadoresSobrecargados.h
 * Author: Sebastian
 *
 * Created on 25 de abril de 2023, 0:03
 */

#ifndef OPERADORESSOBRECARGADOS_H
#define OPERADORESSOBRECARGADOS_H
#include "AperturaDeArchivos.h"
#include "Estructuras.h"

ifstream & operator >>(ifstream &arch,Estructura_ClienteRegistrado &cliente);
char obtenerCategoria(char *nombre);
void operator +=(Estructura_ClienteRegistrado *arregloCli,Estructura_ClienteRegistrado &cliente);
void operator +=(Estructura_ClienteRegistrado &cliente,Estructura_PedidoRealizado &pedido);
void operator +=(Estructura_ProductosEnAlmacen *arregloProducto,Estructura_ProductosEnAlmacen &producto);
void obtenerMonto(Estructura_ClienteRegistrado &cliente,char *codigoProducto,int cantProducto);
ofstream & operator <<(ofstream &arch,Estructura_ClienteRegistrado &cliente);
ofstream & operator <<(ofstream &arch,Estructura_ProductosEnAlmacen *arregloProd);

#endif /* OPERADORESSOBRECARGADOS_H */

