/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 29 de abril de 2023, 15:02
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void CargaDeClientes(int *&cli_DNI,char **&cli_Nombre,char *&cli_Categoria);
char asignarCategoria(char *nombre);
void ReporteDeClientes(int *cli_DNI,char **cli_Nombre,char *cli_Categoria);
void CargaDePedidosYProductos(int *cli_DNI,int *&pro_Codigo,
        char **&pro_Descripcion,double *&pro_Descuento,double *&pro_Precio,
        int **&cli_CodigoProFechaPedido,double **&cli_CantidadPedido);
void leerValores(char *&descripcion,double &descuento,double &cantidad,
                 double &precio,int &dniCliente,int &fecha,ifstream &arch);
char *leerDescripcion(ifstream &arch);
int buscarCliente(int *cli_DNI,int dni);
int buscarProd(int *buffProCod,int codProd,int numDatos);
void ReporteDePedidosYProductos(int *cli_DNI,int *pro_Codigo,
        char **pro_Descripcion,double *pro_Descuento,double *pro_Precio,
        int **cli_CodigoProFechaPedido,double **cli_CantidadPedido);
void asignarValoresCliente(int *&buffCodProdFechaPedido,int codProd,int fecha,
        double *&buffCantPedida,double cantidad,int &numPedidos);
void agregarPedidosCliente(int *&buffCodProdFechaPedido,double *&buffCantPedida,
        int *&cli_CodigoProFechaPedido,double *&cli_CantidadPedido,int numPedidos);
void imprimePedidos(int *codFecha,double *cant,ofstream &archRep2);
void ReporteRelacionDePedidos(int *cli_DNI,char **cli_Nombre,char *cli_Categoria,
                              int **cli_CodigoProFechaPedido,double **cli_CantidadPedido,
        int *pro_Codigo,char **pro_Descripcion,double *pro_Descuento,double *pro_Precio);
void imprimirLinea(char car, int cantidad, ofstream &arch);
void imprimirProductosCliente(int *cli_CodigoProFechaPedido,double *cli_CantidadPedido,
                              int *pro_Codigo,char **pro_Descripcion,
                              double *pro_Descuento,double *pro_Precio,ofstream &archReporte);
void imprimirCabeceraCliente(int cli_DNI,char *cli_Nombre,char cli_Categoria,ofstream &arch);
void hallarDatosProd(int cod_Prod,int *pro_Codigo,char **pro_Descripcion,
                    double *pro_Descuento,double *pro_Precio,char *&descripcion,
                    double &precio,double  &descuento);

#endif /* FUNCIONESAUXILIARES_H */

