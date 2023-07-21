/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
//Sebastian Moises Esquivel Barreto
//20190638
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ClientesPreg1.h"
#include "FuncionesAuxiliares.h"
#define INCREMENTO 5
#define MAX_CAR 120
//char ***cli_NombreCategoria, **pro_Descripcion;
//int ***cli_DniTelPed, **pro_Informacion, **ped_Todo;
void CargarProductosPedidos(int **&pro_Informacion,char **&pro_Descripcion,int **&ped_Todo,const char *nombArch){
    ifstream archProductosPedidos(nombArch,ios::in);
    if(not archProductosPedidos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    int *buffPro_Informacion[300],*buffPed_Todo[300],numProductos = 0,numPedidos = 0,codProducto,dniCliente,fecha,posProducto;
    char *buffPro_Descripcion[300], *descripcion,car;
    double descuento,precio,stock,cantidad;
    
    while(true){
        archProductosPedidos>>codProducto;
        if(archProductosPedidos.eof()) break;
        archProductosPedidos.get();
        leerDatosRestantes(descripcion,descuento,cantidad,precio,stock,dniCliente,fecha,archProductosPedidos);
        posProducto = obtenerPosicionProducto(buffPro_Informacion,codProducto,numProductos);
        if(posProducto == -1){
            agregarProducto(buffPro_Informacion[numProductos],codProducto,descuento,precio,stock,buffPro_Descripcion[numProductos],descripcion);
            numProductos++;
        }else delete descripcion;
        agregarPedido(buffPed_Todo[numPedidos],dniCliente,fecha,cantidad,codProducto);
        numPedidos++;
    }
    buffPro_Informacion[numProductos] = nullptr;
    buffPro_Descripcion[numProductos] = nullptr;
    buffPed_Todo[numPedidos] = nullptr;
    numPedidos++;
    numProductos++;
    pro_Informacion = new int*[numProductos];
    pro_Descripcion = new char*[numProductos];
    ped_Todo = new int*[numPedidos];
    for (int i = 0; i < numProductos; i++) {
        pro_Informacion[i] = buffPro_Informacion[i];
        pro_Descripcion[i] = buffPro_Descripcion[i];
    }
    for (int i = 0; i < numPedidos; i++) ped_Todo[i] = buffPed_Todo[i];
    
}

void agregarPedido(int *&buffPed_Todo,int dniCliente, int fecha, double cantidad,int codProducto){
    buffPed_Todo = new int[4];
    buffPed_Todo[0] = dniCliente;
    buffPed_Todo[1] = fecha;
    buffPed_Todo[2] = (int)(cantidad * 100);
    buffPed_Todo[3] = codProducto;
}

int obtenerPosicionProducto(int **buffPro_Informacion, int codProducto, int numDatos){
    for (int i = 0; i < numDatos; i++) if(*(buffPro_Informacion[i]) == codProducto) return i;
    return -1;
}

void agregarProducto(int *&buffPro_Informacion,int codProducto,double descuento,double precio,double stock,char *&buffPro_Descripcion,char *descripcion){
    buffPro_Informacion = new int[4];
    buffPro_Informacion[0] = codProducto;
    buffPro_Informacion[1] = (int)(descuento * 100);
    buffPro_Informacion[2] = (int)(precio * 100);
    buffPro_Informacion[3] = (int)(stock * 100);
    buffPro_Descripcion = descripcion;
}

void leerDatosRestantes(char *&descripcion, double &descuento, double &cantidad, double &precio, double &stock, int &dniCliente, int &fecha,ifstream &arch){
    int dd,mm,aa;
    char car;
    descripcion = leerCadena(arch);
    arch>>cantidad;
    arch.get();
    arch>>precio;
    if(arch.fail()){
        arch.clear();
        descuento = cantidad;
        arch.get();
        arch>>cantidad;
        arch.get();
        arch>>precio;
    }else descuento = 0;
    arch.get();
    arch>>stock;
    arch.get();
    arch>>dniCliente;
    arch.get();
    arch>>dd>>car>>mm>>car>>aa;
    fecha = aa * 10000 + mm * 100 + dd;
}

char *leerCadena(ifstream &arch){
    char *aux,buff[300];
    arch.getline(buff,300,',');
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}
    
void PruebaProductosPedidos(int **pro_Informacion,char **pro_Descripcion,int **ped_Todo,const char *nombArch){
    ofstream archReporte(nombArch,ios::out);
    archReporte.precision(2);archReporte<<fixed;
    archReporte<<setw(10)<<left<<"CODIGO"<<setw(10)<<left<<"DESCUENTO"<<setw(10)<<left
            <<"PRECIO"<<setw(10)<<left<<"STOCK"<<endl;
    for(int i=0;pro_Informacion[i];i++)
        imprimeProducto(pro_Informacion[i],pro_Descripcion[i],archReporte);
    archReporte<<endl;
    
    archReporte<<setw(10)<<left<<"DNI"<<setw(10)<<left<<"FECHA"<<setw(10)<<left
            <<"CANTIDAD"<<setw(10)<<left<<"CODIGO"<<endl;
    for(int i=0;ped_Todo[i];i++) imprimePedido(ped_Todo[i],archReporte);
}

void imprimePedido(int *ped_Todo,ofstream &arch){
    arch<<setw(10)<<left<<ped_Todo[0]<<setw(10)<<left<<ped_Todo[1]<<setw(10)<<left
            <<ped_Todo[2]<<setw(10)<<left<<ped_Todo[3]<<endl;
}

void imprimeProducto(int *informacion,char *descripcion,ofstream &arch){
    double aux1=(double)((double)informacion[1]/100);
    double aux2=(double)informacion[2]/100;
    double aux3=(double)informacion[3]/100;
    arch<<setw(10)<<left<<informacion[0]<<setw(10)<<left<<aux1<<setw(10)<<left
            <<aux2<<setw(10)<<left<<aux3<<endl;
}

void ordenarPedidos(int **&ped_Todo){
    int numDatos;
    for (numDatos = 0; ped_Todo[numDatos]; numDatos++) qSort(ped_Todo,0,numDatos-1);
    cout<<numDatos<<endl;
}

void qSort(int **&ped_Todo,int izq, int der){
    int limite;
    if(izq >= der) return;
    cambiar(ped_Todo[izq], ped_Todo[(izq+der)/2]);
    limite = izq;
    for(int i = izq+1; i<=der; i++)
        if(enDesorden(ped_Todo[i],ped_Todo[izq]))
            cambiar(ped_Todo[++limite], ped_Todo[i]);
    cambiar(ped_Todo[izq], ped_Todo[limite]);
    qSort(ped_Todo,izq,limite-1);
    qSort(ped_Todo,limite+1,der);
}

void cambiar(int *&ped_TodoI,int *&ped_TodoK){
    int *aux;
    aux = ped_TodoI;
    ped_TodoI = ped_TodoK;
    ped_TodoK = aux;
}

bool enDesorden(int *ped1,int *ped2){
    return ped1[1] < ped2[1] or ped1[1] == ped2[1] and ped1[0] < ped2[0];
}

void asignarPedidos(int ***&cli_DniTelPed,int **&pro_Informacion,int **ped_Todo){
    int dniCliente,fecha,codProducto,cantidad;
    int posCliente,i,posProducto;
    for(i=0;cli_DniTelPed[i];i++);
    int numPedidos[i+1]{},capPedidos[i+1]{};
   
    for (int i = 0; ped_Todo[i]; i++) {
        dniCliente = obtenerDniCliente(ped_Todo[i],cantidad,fecha,codProducto);
        posCliente = obtenerPosicionCliente(dniCliente,cli_DniTelPed);
        if(posCliente != -1 and existeStock(codProducto,cantidad,pro_Informacion)){
            agregarPedido(cli_DniTelPed[posCliente],cantidad,fecha,codProducto,numPedidos[posCliente],capPedidos[posCliente]);
        }
    }
}

void agregarPedido(int **&cli_DniTelPed, int cantidad,int fecha, int codProducto, int &numPedidos, int &capPedidos){
    if(numPedidos == capPedidos) aumentarEspacios(cli_DniTelPed[2],numPedidos,capPedidos);
    agregarPedidoCliente(cli_DniTelPed[2],numPedidos,cantidad,fecha,codProducto);
    numPedidos++;
}

void agregarPedidoCliente(int *&cli_DniTelPed, int numPedidos, int cantidad, int fecha, int codProducto){
    cli_DniTelPed[(numPedidos*3)] = 0;
    cli_DniTelPed[(numPedidos-1)*3] = fecha;
    cli_DniTelPed[(numPedidos*3) + 1] = 0;
    cli_DniTelPed[((numPedidos-1)*3)+1] = cantidad;
    cli_DniTelPed[(numPedidos*3) + 2] = 0;
    cli_DniTelPed[((numPedidos-1)*3)+2] = codProducto;   
}

void aumentarEspacios(int *&cli_DniTelPed, int &numPedidos, int &cap){
    int *aux;
    cap += INCREMENTO;
    if(cli_DniTelPed == nullptr){
        cli_DniTelPed = new int[cap*3];
        cli_DniTelPed[0] =  0;
        cli_DniTelPed[1] =  0;
        cli_DniTelPed[2] =  0;
        numPedidos = 1;
    }else{
        aux = new int[cap*3];
        for(int i=0;i<numPedidos;i++){
            aux[(i*3)]=cli_DniTelPed[(i*3)];
            aux[(i*3) + 1]=cli_DniTelPed[(i*3) + 1];
            aux[(i*3) + 2]=cli_DniTelPed[(i*3) + 2];
        }
        delete cli_DniTelPed;
        cli_DniTelPed=aux;
    }
}

int obtenerDniCliente(int *ped_Todo,int &cantidad, int &fecha, int &codProducto){
    cantidad = ped_Todo[2];
    fecha = ped_Todo[1];
    codProducto = ped_Todo[3];
    return ped_Todo[0];
}

int obtenerPosicionCliente(int dniCliente,int ***cli_DniTelPed){
    for (int i = 0; cli_DniTelPed[i]; i++)
        if(dniCliente == obtieneDni(cli_DniTelPed[i])) return i;
    return -1;
}

int obtieneDni(int **cli_DniTelPed){
    return *(cli_DniTelPed[0]);
}

int existeStock(int codProducto, int cantidad, int **&pro_Informacion){
    for (int i = 0; pro_Informacion[i]; i++){
        if(*(pro_Informacion[i]) == codProducto){
            if(pro_Informacion[i][3] >= cantidad){
                pro_Informacion[i][3] = pro_Informacion[i][3] - cantidad;
                return 1;
            }else return 0;
        }
    }
}


