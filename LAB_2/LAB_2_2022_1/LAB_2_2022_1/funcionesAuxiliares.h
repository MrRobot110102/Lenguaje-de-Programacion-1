/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 18 de abril de 2023, 18:40
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

int cantidadPalabras(char *nombre);
char asignarCategoria(char *nombre);
void crearBinarios();
void darFormato(char *nombre);
void insertarClientes(ofstream &archCliBin,int dni, char *nombre,int telefono);
void insertarProductos(char *codProd,char *desc,double descuento,
                       double precioUnit,ofstream &archProductosBin);
int compararCadenas(char *cadena1,char *cadena2);
int verificarDuplicado(char *codProd);
void insertarPedidos(int dniOrden,char *codProd,double cantidad,
                     int dd,int mm,int aa,ofstream &archPedidosBin);
void mostrarClientesBin();
void mostrarProductosBin();
void mostrarPedidosBin();


#endif /* FUNCIONESAUXILIARES_H */

