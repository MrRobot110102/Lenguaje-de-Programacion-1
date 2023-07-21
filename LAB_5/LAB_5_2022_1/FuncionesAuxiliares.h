/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 5 de mayo de 2023, 22:59
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void CargaDePedidosYProductos(int **cli_DniTelefono,char ***&pro_CodigoDescripcion,double **&pro_PrecioDescuento,
                             char ***&ped_Codigo,int ***&ped_FechaCantidad,const char*nomArch);
char *leerCadena(ifstream &arch);
void leerDatosRestantes(ifstream &archPedidos,char *&descripcion,double &descuento,
        int &cantidad,double &precioUnitario,int &dniCliente,int &fecha);
int obtenerPosicionProducto(char *codProducto, char ***pro_CodigoDescripcion);
void aumentarEspacios(char ***&pro_CodigoDescripcion,double **&pro_PrecioDescuento,int &numProductos,int &capProductos);
void agregarProducto(char ***&pro_CodigoDescripcion,char *codProducto,char *descripcion,
                double **&pro_PrecioDescuento,double precioUnitario,double descuento,int &numProductos,int &capProductos);

void ReporteDePedidosYProductos(int **cli_DniTelefono,char ***pro_CodigoDescripcion,double **pro_PrecioDescuento,
                             char ***ped_Codigo,int ***ped_FechaCantidad,const char*nomArch);
void imprimirProducto(char **pro_CodigoDescripcion,double *pro_PrecioDescuento,ofstream &archReporte);
int obtenerPosicionCliente(int dniCliente,int **cli_DniTelefono);
void agregarProductoCliente(int **&ped_FechaCantidad,int fecha,int cantidad,char **&ped_Codigo,char *codProducto,int &numPedidos,int &capPedidos);
void aumentarEspacios(int **&ped_FechaCantidad,char **&ped_Codigo,int &numPedidos,int &capPedidos);
void ReporteRelacionDePedidos(int **cli_DniTelefono,char ***cli_NombreCategoria,char ***pro_CodigoDescripcion,double **pro_PrecioDescuento,
                             char ***ped_Codigo,int ***ped_FechaCantidad,const char *nomArch);
void imprimirPedidos(ofstream &arch, char **ped_Codigo, int **ped_FechaCantidad);
void imprimeFecha(ofstream &arch, int fecha);
void imprimirLinea(char car, int cantidad, ofstream &arch);
void imprimirEncabezadoCliente(int *cli_DniTelefono,char **cli_NombreCategoria,ofstream &arch);
void imprimirPedidos(int **ped_FechaCantidad,char **ped_Codigo,
                char ***pro_CodigoDescripcion,double **pro_PrecioDescuento,ofstream &arch);

#endif /* FUNCIONESAUXILIARES_H */

