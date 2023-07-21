/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

//20190638
//Esquivel Barreto Sebastian Moises
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "MuestraPunteros.h"
#include "FuncionesAuxiliares.h"

//void *productos, *pedidos, *clientes;
    
void cargaproductos(void *&productos){
    ifstream archProductos("productos2.csv",ios::in);
    void *buffProductos[300],**producto;
    int numDatos = 0;
    while (true) {
        buffProductos[numDatos] = leerRegistro(archProductos);
        if(buffProductos[numDatos] == nullptr) break;
        numDatos++;
    }
    producto = new void *[numDatos + 1]{};
    for (int i = 0; i < numDatos; i++) producto[i] = buffProductos[i];
    productos = producto;
    imprimeproductos(productos);
}

void *leerRegistro(ifstream &arch){
    void **registro;
    int *codigo, *cantidad,cod;
    char *descripcion;
    double *precio;
    
    codigo = new int;
    cantidad = new int;
    precio = new double;
    arch>>cod;
    if(arch.eof()) return nullptr;
    arch.get();
    descripcion = leerCadena(arch);
    arch>>*precio;
    arch.get();
    arch>>*cantidad;
    *codigo = cod;
    registro = new void*[4];
    registro[0] = codigo;
    registro[1] = descripcion;
    registro[2] = precio;
    registro[3] = cantidad;
    return registro;
}

char *leerCadena(ifstream &arch){
    char *aux,buff[300];
    arch.getline(buff,300,',');
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}
    
void cargapedidos(void *&pedidos){
    ifstream archPedidos("pedidos2.csv",ios::in);
    if(not archPedidos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo pedidos2.csv"<<endl;
        exit(1);
    }
    void *buffPedidos[300], **pedido;
    int numDatos = 0;
    while(true){
        buffPedidos[numDatos] = leerDatos(archPedidos);
        if(buffPedidos[numDatos] == nullptr) break;
        numDatos++;
    }
    pedido = new void *[numDatos+1]{};
    for (int i = 0; i < numDatos; i++) pedido[i] = buffPedidos[i];
    pedidos = pedido;
    imprimepedidos(pedidos);
}

void *leerDatos(ifstream &arch){
    void **registro;
    int *codigo, *cantSolicitada, *dniCliente,*fechaPedido,dd,mm,aa,cod;
    char *descripcion,car,*estado;
    codigo = new int;
    cantSolicitada = new int;
    dniCliente = new int;
    fechaPedido = new int;
    estado = new char[2]{};
    arch>>cod;
    if(arch.eof()) return nullptr;
    arch.get();
    descripcion = leerCadena(arch);
    arch>>*cantSolicitada;
    arch.get();
    arch>>*dniCliente;
    arch.get();
    arch>>dd>>car>>mm>>car>>aa;
    *fechaPedido = aa*10000 + mm * 100 + dd;
    *codigo = cod;
    *estado = 'N';
    registro = new void *[6];
    registro[0] = codigo;
    registro[1] = descripcion;
    registro[2] = cantSolicitada;
    registro[3] = dniCliente;
    registro[4] = fechaPedido;
    registro[5] = estado;
    return registro;
}
    
void procesaclientes(void *&productos,void *&pedidos,void *&clientes){
    ordenarQS(pedidos);
    imprimepedidos(pedidos);
    actualizarEstadosPedidos(productos,pedidos);
    imprimepedidos(pedidos);
    imprimeproductos(productos);
    cargaCliente(clientes,pedidos);
    imprimerepfinal(clientes);
}

void cargaCliente(void *&clientes, void *pedidos){
    ifstream archClientes("Clientes2.csv",ios::in);
    if(not archClientes.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Clientes2.csv"<<endl;
        exit(1);
    }
    void *buffClientes[100], **cliente;
    int numDatos = 0;
    while(true){
        buffClientes[numDatos] = leerRegistro(archClientes,pedidos);
        if(buffClientes[numDatos] == nullptr) break;
        numDatos++;
    }
    cliente = new void*[numDatos + 1]{};
    for (int i = 0; i < numDatos; i++) {
        cliente[i] = buffClientes[i];
    }
    clientes = cliente;
}

void *leerRegistro(ifstream &arch, void *pedidos){
    int *codCliente,cod;
    char *nombre;
    void **registro;
    codCliente = new int;
    arch>>cod;
    if(arch.eof()) return nullptr;
    arch.get();
    nombre = leerNombre(arch);
    *codCliente = cod;
    registro = new void*[3];
    registro[0] = codCliente;
    registro[1] = nombre;
    registro[2] = cargarPedidos(pedidos,cod);
    return registro;
}

void *cargarPedidos(void *ped, int codigoCliente){
    void **pedido = (void **)ped;
    void *buffPedidos[100], **pedidos;
    int numDatos = 0;
    
    for (int i = 0; pedido[i]; i++) {
        if(compararPedidos(pedido[i],codigoCliente)){
           buffPedidos[numDatos] = leePedido(pedido[i]);
           numDatos++;
        }
    }
    pedidos = new void*[numDatos+1]{};
    for (int i = 0; i < numDatos; i++) {
        pedidos[i] = buffPedidos[i];
    }
    return pedidos;
}

void *leePedido(void *ped){
    void **pedido = (void **)ped;
    int *fecha = (int *)pedido[4];
    int *codProducto = (int *)pedido[0];
    char *descripcion = (char *)pedido[1];
    int *cant = (int *)pedido[2];
    void **registro;
    registro = new void *[3];
    registro[0] = fecha;
    registro[1] = codProducto;
    registro[2] = descripcion;
    registro[3] = cant;
    return registro;
}

int compararPedidos(void *ped, int codigoCliente){
    void **pedido = (void **)ped;
    int *codCliente = (int *)pedido[3];
    char *estado = (char *)pedido[5];
    if(*codCliente == codigoCliente and estado[0] == 'A') return 1;
    return 0;
}

char *leerNombre(ifstream &arch){
    char *aux, buff[300];
    arch.getline(buff,300);
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

void actualizarEstadosPedidos(void *&prod,void *&ped){
    void **pedidos;
    pedidos = (void **)ped;
    for (int i = 0; pedidos[i]; i++) atenderPedido(pedidos[i],prod);   
}

void atenderPedido(void *&ped,void *&prod){
    void **pedido = (void **)ped;
    void **productos = (void **)prod;
    int *codProd = (int *)pedido[0];
    int *cantSolicitada = (int *)pedido[2];
    int cantidadProductos;
    int posProducto = obtenerPosicionProducto(prod,*codProd, cantidadProductos);
    if(posProducto != -1)
        if(cantidadProductos >= *cantSolicitada) actualizarPedido(ped,productos[posProducto],*cantSolicitada);
}

void actualizarPedido(void *&ped,void *&prod,int cantSolicitada){
    void **pedido = (void **)ped;
    void **productos = (void **)prod;
    int *cantidad = (int *)productos[3];
    char *estado =  (char *)pedido[5];
    *cantidad = *cantidad - cantSolicitada;
    estado[0] = 'A';
}

int obtenerPosicionProducto(void *prod,int codProducto, int &cantidadProductos){
    void **productos = (void **)prod;
    int *cant;
    for (int i = 0; productos[i]; i++) {
        if(compararProductos(productos[i],codProducto,cantidadProductos)) return i;
    }
    return -1;
}

int compararProductos(void *prod,int codProducto, int &cant){
    void **productos = (void **)prod;
    int *codProd = (int *)productos[0];
    int *cantidad = (int *)productos[3];
    cant = *cantidad;
    if(codProducto == *codProd) return 1;
    else return 0;
}

void ordenarQS(void *clientes){
    void **cliente = (void **)clientes;
    int numDatos = 0;
    for (numDatos = 0; cliente[numDatos]; numDatos++) {
        qsortFechas(cliente,0,numDatos);
    }
}

void qsortFechas(void **clientes,int izq, int der){
    int limite;
    if(izq >= der) return;
    cambiar(clientes[izq], clientes[(izq+der)/2]);
    limite = izq;
    for(int i = izq+1; i<=der; i++)
        if(enDesorden(clientes[i],clientes[izq]))
            cambiar(clientes[++limite], clientes[i]);
    cambiar(clientes[izq], clientes[limite]);
    qsortFechas(clientes,izq,limite-1);
    qsortFechas(clientes,limite+1,der);
}

void cambiar(void *&clientesI,void *&clienteK){
    void *aux;
    aux = clientesI;
    clientesI = clienteK;
    clienteK = aux;
}

bool enDesorden(void *cli1,void *cli2){
    void **clienteI = (void **)cli1, **clienteK = (void **)cli2;
    int *cliI = (int *)clienteI[4], *cliK = (int *)clienteK[4];
    return *cliI < *cliK;
}
    
void imprimereporte(void *clientes){
        
}