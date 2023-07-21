/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 13 de mayo de 2023, 20:41
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void cargaproductos(void *&productos);
void *leerRegistro(ifstream &arch);
char *leerCadena(ifstream &arch);

void cargapedidos(void *&pedidos);
void *leerDatos(ifstream &arch);

void procesaclientes(void *&productos,void *&pedidos,void *&clientes);
void actualizarEstadosPedidos(void *&prod,void *&ped);
void atenderPedido(void *&ped,void *&prod);
int obtenerPosicionProducto(void *prod,int codProducto, int &cantidadProductos);
int compararProductos(void *prod,int codProducto, int &cant);
void actualizarPedido(void *&ped,void *&prod,int cantSolicitada);
void cargaCliente(void *&clientes, void *pedidos);
void cargaCliente(void *&clientes, void *pedidos);
void *leerRegistro(ifstream &arch, void *pedidos);
void *cargarPedidos(void *ped, int codigoCliente);
void *leePedido(void *ped);
int compararPedidos(void *ped, int codigoCliente);
char *leerNombre(ifstream &arch);
void ordenarQS(void *clientes);
void qsortFechas(void **clientes,int izq, int der);
void cambiar(void *&clientesI,void *&clienteK);
bool enDesorden(void *cli1,void *cli2);
void imprimereporte(void *clientes);

#endif /* FUNCIONESAUXILIARES_H */

