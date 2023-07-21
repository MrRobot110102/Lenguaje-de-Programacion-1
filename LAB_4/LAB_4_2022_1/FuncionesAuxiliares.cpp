/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include <valarray>
#include "FuncionesAuxiliares.h"

void CargaDeClientes(int *&cli_DNI,char **&cli_Nombre,char *&cli_Categoria){
    int buffCli[100],dni,numDatos = 0,telefono;
    char *buffNom[100], buffCategoria[100],nombre[100];
    ifstream archClientes("Clientes.csv",ios::in);
    if(not archClientes.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Clientes.csv"<<endl;
        exit(1);
    }
    while(true){
        archClientes>>dni;
        if(archClientes.eof()) break;
        archClientes.get();
        archClientes.getline(nombre,100,',');
        buffCli[numDatos] = dni;
        buffCategoria[numDatos] = asignarCategoria(nombre);
        buffNom[numDatos] = new char[strlen(nombre) + 1];
        strcpy(buffNom[numDatos],nombre);
        archClientes>>telefono;
        numDatos++;
    }
    buffCli[numDatos] = 0;
    buffNom[numDatos] = nullptr;
    buffCategoria[numDatos] = 0;
    numDatos++;
    cli_DNI = new int[numDatos];
    cli_Nombre = new char*[numDatos];
    cli_Categoria = new char[numDatos];
    for (int i = 0; i < numDatos; i++) {
        cli_DNI[i] = buffCli[i];
        cli_Nombre[i] = buffNom[i];
        cli_Categoria[i] = buffCategoria[i];
    }
}

char asignarCategoria(char *nombre){
    int cantPal = strlen(nombre);
    char car;
    if(nombre[cantPal-2] == ' '){
        car = nombre[cantPal-1];
        nombre[cantPal-2] = nombre[cantPal];
    }else car = '-';
    return car;
}

void ReporteDeClientes(int *cli_DNI,char **cli_Nombre,char *cli_Categoria){
    ofstream arch("ReporteClientes.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    for (int i = 0; cli_DNI[i]; i++) {
        arch<<setw(10)<<left<<cli_DNI[i]<<setw(50)<<left<<cli_Nombre[i]<<
                setw(4)<<left<<cli_Categoria[i]<<endl;
    }
}

void asignarValoresCliente(int *&buffCodProdFechaPedido,int codProd,int fecha,
                           double *&buffCantPedida,double cantidad,int &numPedidos){
    buffCodProdFechaPedido[numPedidos*2] = codProd;
    buffCodProdFechaPedido[(numPedidos*2)+1] = fecha;
    buffCantPedida[numPedidos] = cantidad;
    numPedidos++;
}
    
void CargaDePedidosYProductos(int *cli_DNI,int *&pro_Codigo,
        char **&pro_Descripcion,double *&pro_Descuento,double *&pro_Precio,
        int **&cli_CodigoProFechaPedido,double **&cli_CantidadPedido){
    int buffProCod[200],*buffCodProdFechaPedido[200],codProd,dniCliente,fecha,posCliente,numDatos = 0;
    double buffProDesc[200], *buffCantPedida[200],buffProPrecio[200],descuento,precio,cantidad;
    char *buffDescrip[200],*descripcion;
    int cantPedidos[200]{},i;
    
    ifstream archPedidos("Pedidos.csv",ios::in);
    if(not archPedidos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Pedidos.csv"<<endl;
        exit(1);
    }
    //cada codprofechaped y cantpedida esta apuntando a un arreglo de enteros
    for ( i=0; cli_DNI[i]; i++) {
        buffCodProdFechaPedido[i] = new int[50];
        buffCantPedida[i] = new double[25];
    }
    
    while(true){
        archPedidos>>codProd;
        if(archPedidos.eof()) break;
        leerValores(descripcion,descuento,cantidad,precio,dniCliente,fecha,archPedidos);
        posCliente = buscarCliente(cli_DNI,dniCliente);
        asignarValoresCliente(buffCodProdFechaPedido[posCliente],codProd,fecha,
                              buffCantPedida[posCliente],cantidad,cantPedidos[posCliente]);
        if(buscarProd(buffProCod,codProd,numDatos) == 1){
            buffProCod[numDatos] = codProd;
            buffDescrip[numDatos] = descripcion;
            buffProDesc[numDatos] = descuento;
            buffProPrecio[numDatos] = precio;
            numDatos++;
        }
    }
    buffProCod[numDatos] = 0;
    buffDescrip[numDatos] = nullptr;
    buffProDesc[numDatos] = 0;
    buffProPrecio[numDatos] = 0;
    numDatos++;
    pro_Codigo = new int[numDatos];
    pro_Descripcion = new char*[numDatos];
    pro_Descuento = new double[numDatos];
    pro_Precio = new double[numDatos];
    cli_CodigoProFechaPedido = new int*[i+1];
    cli_CantidadPedido = new double*[i+1];
    for (i = 0; i < numDatos; i++) {
        pro_Codigo[i] = buffProCod[i];
        pro_Descripcion[i] = buffDescrip[i];
        pro_Descuento[i] = buffProDesc[i];
        pro_Precio[i] = buffProPrecio[i];
    }
    for (i = 0; cli_DNI[i]; i++) {
        espaciosExactos(buffCodProdFechaPedido[i],buffCantPedida[i],
         cli_CodigoProFechaPedido[i],cli_CantidadPedido[i],cantPedidos[i]);
    }

    for ( i = 0; cli_DNI[i]; i++) {
        delete buffCodProdFechaPedido[i];
        delete buffCantPedida[i];
    }
}

void espaciosExactos(int *&buffCodProdFechaPedido,double *&buffCantPedida,
        int *&cli_CodigoProFechaPedido,double *&cli_CantidadPedido,int numPedidos){
    if(numPedidos == 0){
        delete cli_CodigoProFechaPedido;
        delete cli_CantidadPedido;
        cli_CodigoProFechaPedido = nullptr;
        cli_CantidadPedido = nullptr;
    }else{
        cli_CodigoProFechaPedido = new int[(numPedidos*2)+2];
        cli_CantidadPedido = new double[numPedidos+1];
        for (int i = 0; i < numPedidos; i++) {
            cli_CodigoProFechaPedido[2*i] = buffCodProdFechaPedido[2*i];
            cli_CodigoProFechaPedido[(2*i)+1] = buffCodProdFechaPedido[(2*i)+1];
            cli_CantidadPedido[i] = buffCantPedida[i];
        }
        cli_CodigoProFechaPedido[2*numPedidos] = 0;
        cli_CodigoProFechaPedido[(2*numPedidos)+1] = 0;
        cli_CantidadPedido[numPedidos] = 0;
    }
}

void leerValores(char *&descripcion,double &descuento,double &cantidad,
                 double &precio,int &dniCliente,int &fecha,ifstream &arch){
    int dd,mm,aa;
    char car;
    arch.get();
    descripcion = leerDescripcion(arch);
    arch>>cantidad;
    if(arch.fail()){
        arch.clear();
        arch>>car>>descuento>>car>>cantidad>>car>>precio>>car>>dniCliente>>car>>dd>>car>>mm>>car>>aa;
    }else{//sin descuento
        descuento = 0;
        arch>>car>>precio>>car>>dniCliente>>car>>dd>>car>>mm>>car>>aa;
    }
    fecha = aa * 10000 + mm * 100 + dd;
}

char *leerDescripcion(ifstream &arch){
    char desc[100], *aux;
    arch.getline(desc,100,',');
    aux = new char[strlen(desc) + 1];
    strcpy(aux,desc);
    return aux;
}

int buscarCliente(int *cli_DNI,int dni){
    for (int i = 0; cli_DNI[i]; i++) if(dni == cli_DNI[i]) return i;
}

int buscarProd(int *buffProCod,int codProd,int numDatos){
    for (int i = 0; i<numDatos; i++) if(codProd == buffProCod[i]) return -1;
    return 1;
}

void ReporteDePedidosYProductos(int *cli_DNI,int *pro_Codigo,
        char **pro_Descripcion,double *pro_Descuento,double *pro_Precio,
        int **cli_CodigoProFechaPedido,double **cli_CantidadPedido){
    ofstream arch("ReporteProductos.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    ofstream archPedidos("ReportePedidos.txt",ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    arch.precision(2);arch<<fixed;
    archPedidos.precision(2);archPedidos<<fixed;
    for (int i = 0; pro_Codigo[i]; i++) {
        arch<<setw(10)<<left<<pro_Codigo[i]<<setw(40)<<left
            <<pro_Descripcion[i]<<setw(12)<<right<<pro_Descuento[i]
            <<setw(12)<<right<<pro_Precio[i]<<endl;
    }
    for(int i=0;cli_DNI[i];i++){
        archPedidos<<setw(10)<<left<<cli_DNI[i]<<endl;
        imprimePedidos(cli_CodigoProFechaPedido[i],cli_CantidadPedido[i],archPedidos);
    }
}

void imprimePedidos(int *codFecha,double *cant,ofstream &archRep2){
    for(int i=0;codFecha[2*i];i++){
        archRep2<<setw(10)<<left<<codFecha[2*i]<<setw(10)<<left<<codFecha[2*i+1]
                <<setw(10)<<right<<setprecision(2)<<fixed<<cant[i]<<endl;
    }
}
    
void ReporteRelacionDePedidos(int *cli_DNI,char **cli_Nombre,char *cli_Categoria,int **cli_CodigoProFechaPedido,
                             double **cli_CantidadPedido,int *pro_Codigo,char **pro_Descripcion,double *pro_Descuento,double *pro_Precio){
    ofstream archReporte("PedidosPorCliente.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    
    archReporte.precision(2);archReporte<<fixed;
    archReporte<<right<<setw(65)<<"EMPRESA COMERCIALIZADORA DE ABARROTES"<<endl;
    imprimirLinea('=',144,archReporte);
    archReporte<<left<<"GASTOS DE LOS CLIENTES REGISTRADOS:"<<endl;
    
    for (int i = 0; cli_DNI[i]; i++) {
        imprimirCabeceraCliente(cli_DNI[i],cli_Nombre[i],cli_Categoria[i],archReporte);
        imprimirProductosCliente(cli_CodigoProFechaPedido[i],cli_CantidadPedido[i],
                                 pro_Codigo,pro_Descripcion,pro_Descuento,pro_Precio,archReporte);
    }
}

void imprimirLinea(char car, int cantidad, ofstream &arch){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}

void imprimirCabeceraCliente(int cli_DNI,char *cli_Nombre,char cli_Categoria,ofstream &arch){
    imprimirLinea('=',144,arch);
    arch<<left<<setw(10)<<"DNI"<<setw(60)<<"Nombre"<<setw(10)<<"Categoria"<<endl;
    arch<<setw(10)<<cli_DNI<<setw(60)<<cli_Nombre<<setw(10)<<cli_Categoria<<endl;
    imprimirLinea('-',144,arch);
    arch<<"PRODUCTOS ADQUIRIDOS"<<endl;
    imprimirLinea('-',144,arch);
    arch<<right<<setw(12)<<"Codigo"<<"    "<<left<<setw(50)<<"Descripcion"
        <<setw(8)<<"P.U."<<setw(12)<<"Cantidad"<<setw(8)<<"Total"
        <<setw(16)<<"Descuento %"<<setw(10)<<"A Pagar"<<setw(15)
        <<"Descuento"<<setw(10)<<"Fecha"<<endl;
    imprimirLinea('-',144,arch);
}

void imprimirProductosCliente(int *cli_CodigoProFechaPedido,double *cli_CantidadPedido,
                              int *pro_Codigo,char **pro_Descripcion,
                              double *pro_Descuento,double *pro_Precio,ofstream &archReporte){
    char *descripcion;
    double precio,descuento,total,totalPagar=0,totalDescuento=0;
    int dd,mm,aa,fecha;
    for (int i = 0; cli_CodigoProFechaPedido[i*2]; i++) {
        hallarDatosProd(cli_CodigoProFechaPedido[i*2],pro_Codigo,pro_Descripcion,
                        pro_Descuento,pro_Precio,descripcion,precio,descuento);
        total = cli_CantidadPedido[i] * precio;
        archReporte<<right<<setw(2)<<(i+1)<<')'<<"   "
                   <<left<<setw(10)<<cli_CodigoProFechaPedido[i*2]<<setw(45)<<descripcion
                   <<right<<setw(10)<<precio<<setw(10)<<cli_CantidadPedido[i]
                   <<setw(10)<<total;
        if(descuento == 0.0) archReporte<<setw(10)<<"-.--";
        else archReporte<<setw(10)<<descuento;
        archReporte<<setw(15)<<total * (100-descuento)/100<<setw(10)<<total * (descuento)/100;
        fecha = cli_CodigoProFechaPedido[(i*2)+1];
        aa = fecha /10000;
        fecha = fecha % 10000;
        mm = fecha/100;
        dd = fecha % 100;
        archReporte<<setw(8)<<" "<<setfill('0')<<setw(2)<<dd<<'/'
                   <<setw(2)<<mm<<'/'<<aa<<left<<setfill(' ')<<endl;
        totalPagar += (total * (100-descuento)/100);
        totalDescuento += (total * (descuento)/100);
    }
    imprimirLinea('-',144,archReporte);
    archReporte<<right<<setw(106)<<"TOTAL:"<<setw(10)<<totalPagar<<setw(10)<<totalDescuento<<endl;
    imprimirLinea('=',144,archReporte);
    
}

void hallarDatosProd(int cod_Prod,int *pro_Codigo,char **pro_Descripcion,
                    double *pro_Descuento,double *pro_Precio,char *&descripcion,
                    double &precio,double  &descuento){
    for (int i = 0; pro_Codigo[i]; i++) {
        if(pro_Codigo[i] == cod_Prod){
            descuento = pro_Descuento[i];
            precio = pro_Precio[i];
            descripcion = pro_Descripcion[i];
            break;
        }
    }
}