/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 5 de mayo de 2023, 22:59
 */
//Sebastian Moises Esquivel Barreto
//20190638
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"
#include "Clientes.h"

int main(int argc, char** argv) {
    char ***cli_NombreCategoria, ***pro_CodigoDescripcion, ***ped_Codigo;
    int **cli_DniTelefono, ***ped_FechaCantidad;
    double **pro_PrecioDescuento;
    CargaDeClientes(cli_DniTelefono,cli_NombreCategoria,"Clientes.csv");
    ReporteDeClientes(cli_DniTelefono,cli_NombreCategoria,"PruebaClientes.txt");
    CargaDePedidosYProductos(cli_DniTelefono,pro_CodigoDescripcion,pro_PrecioDescuento,
                             ped_Codigo,ped_FechaCantidad,"Pedidos.csv");
    ReporteDePedidosYProductos(cli_DniTelefono,pro_CodigoDescripcion,pro_PrecioDescuento,
                             ped_Codigo,ped_FechaCantidad,"PruebaProductosPedidos.txt");
    ReporteRelacionDePedidos(cli_DniTelefono,cli_NombreCategoria,pro_CodigoDescripcion,pro_PrecioDescuento,
                             ped_Codigo,ped_FechaCantidad,"ReporteDeRelacionDePedidos.txt");
    return 0;
}

