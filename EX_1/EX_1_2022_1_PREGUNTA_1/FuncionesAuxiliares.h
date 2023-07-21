/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 11 de mayo de 2023, 19:26
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void CargarProductosPedidos(int **&pro_Informacion,char **&pro_Descripcion,int **&ped_Todo,const char *nombArch);
void leerDatosRestantes(char *&descripcion, double &descuento, double &cantidad, double &precio, double &stock, int &dniCliente, int &fecha,ifstream &arch);
char *leerCadena(ifstream &arch);
int obtenerPosicionProducto(int **buffPro_Informacion, int codProducto, int numDatos);
void agregarProducto(int *&buffPro_Informacion,int codProducto,double descuento,
        double precio,double stock,char *&buffPro_Descripcion,char *descripcion);
void agregarPedido(int *&buffPed_Todo,int dniCliente, int fecha, double cantidad,int codProducto);

void PruebaProductosPedidos(int **pro_Informacion,char **pro_Descripcion,int **ped_Todo,const char *nombArch);
void imprimePedido(int *ped_Todo,ofstream &arch);
void imprimeProducto(int *informacion,char *descripcion,ofstream &arch);

void ordenarPedidos(int **&ped_Todo);
void qSort(int **&ped_Todo,int izq, int der);
void cambiar(int *&ped_TodoI,int *&ped_TodoK);
bool enDesorden(int *ped1,int *ped2);

void asignarPedidos(int ***&cli_DniTelPed,int **&pro_Informacion,int **ped_Todo);
void agregarPedido(int **&cli_DniTelPed, int cantidad,int fecha, int codProducto, int &numPedidos, int &capPedidos);
void agregarPedidoCliente(int *&cli_DniTelPed, int numPedidos, int cantidad, int fecha, int codProducto);
void aumentarEspacios(int *&cli_DniTelPed, int &numPedidos, int &cap);
int obtenerDniCliente(int *ped_Todo,int &cantidad, int &fecha, int &codProducto);
int obtenerPosicionCliente(int dniCliente,int ***cli_DniTelPed);
int obtieneDni(int **cli_DniTelPed);
int existeStock(int codProducto, int cantidad, int **&pro_Informacion);

#endif /* FUNCIONESAUXILIARES_H */

