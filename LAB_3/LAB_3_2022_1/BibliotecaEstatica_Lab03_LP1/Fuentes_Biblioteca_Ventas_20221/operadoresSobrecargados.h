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

ifstream & operator >>(ifstream &arch,struct Estructura_ClienteRegistrado &cliente);
char obtenerCategoria(char *nombre);
void operator +=(struct Estructura_ClienteRegistrado *arregloCli,struct Estructura_ClienteRegistrado &cliente);
void operator +=(struct Estructura_ClienteRegistrado &cliente,struct Estructura_PedidoRealizado &pedido);
void operator +=(struct Estructura_ProductosEnAlmacen *arregloProducto,struct Estructura_ProductosEnAlmacen &producto);
void obtenerMonto(struct Estructura_ClienteRegistrado &cliente,char *codigoProducto,int cantProducto);
ofstream & operator <<(ofstream &arch,struct Estructura_ClienteRegistrado &cliente);
ofstream & operator <<(ofstream &arch,struct Estructura_ProductosEnAlmacen *arregloProd);

#endif /* OPERADORESSOBRECARGADOS_H */

