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
#include "FuncionesAuxiliares.h"
#define MAX_CAR 150
#define INCREMENTO 5

//    char ***cli_NombreCategoria, ***pro_CodigoDescripcion, ***ped_Codigo;
//    int **cli_DniTelefono, ***ped_FechaCantidad;
//    double **pro_PrecioDescuento;
void CargaDePedidosYProductos(int **cli_DniTelefono,char ***&pro_CodigoDescripcion,double **&pro_PrecioDescuento,
                             char ***&ped_Codigo,int ***&ped_FechaCantidad,const char*nomArch){
    ifstream archPedidos(nomArch,ios::in);
    if(not archPedidos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nomArch<<endl;
        exit(1);
    }
    int i,posProducto,posCliente,cantidad,dniCliente,fecha,numProductos=0,capProductos = 0;
    int numPedidos[100]{},capPedidos[100]{};
    double descuento,precioUnitario;
    char *codProducto,*descripcion;
    
    for (i = 0; cli_DniTelefono[i]; i++); 
    pro_CodigoDescripcion = nullptr;
    pro_PrecioDescuento = nullptr;
    ped_FechaCantidad = new int **[i+1]{};
    ped_Codigo = new char **[i+1]{};
    
    while(true){
        codProducto = leerCadena(archPedidos);
        if(archPedidos.eof()) break;
        leerDatosRestantes(archPedidos,descripcion,descuento,cantidad,precioUnitario,dniCliente,fecha);
        posProducto = obtenerPosicionProducto(codProducto,pro_CodigoDescripcion);
        posCliente = obtenerPosicionCliente(dniCliente,cli_DniTelefono);
        if(posProducto == -1)
            agregarProducto(pro_CodigoDescripcion,codProducto,descripcion,
                pro_PrecioDescuento,precioUnitario,descuento,numProductos,capProductos);
        agregarProductoCliente(ped_FechaCantidad[posCliente],fecha,cantidad,ped_Codigo[posCliente],codProducto,numPedidos[posCliente],capPedidos[posCliente]);
    }
}

int obtenerPosicionCliente(int dniCliente,int **cli_DniTelefono){
    for (int i = 0; cli_DniTelefono[i]; i++) if(*(cli_DniTelefono[i]) == dniCliente) return i;
}

void agregarProductoCliente(int **&ped_FechaCantidad,int fecha,int cantidad,char **&ped_Codigo,
                            char *codProducto,int &numPedidos,int &capPedidos){
    int *fechaCantidad;
    fechaCantidad = new int[2];
    fechaCantidad[0] = fecha;
    fechaCantidad[1] = cantidad;
    
    if(numPedidos == capPedidos)
        aumentarEspacios(ped_FechaCantidad,ped_Codigo,numPedidos,capPedidos);
    ped_FechaCantidad[numPedidos] = nullptr;
    ped_FechaCantidad[numPedidos - 1] = fechaCantidad;
    ped_Codigo[numPedidos] = nullptr;
    ped_Codigo[numPedidos - 1] = codProducto;
    numPedidos++;
}

void aumentarEspacios(int **&ped_FechaCantidad,char **&ped_Codigo,int &numPedidos,int &capPedidos){
    char **auxC;
    int **auxF;
    capPedidos += INCREMENTO;
    if(ped_FechaCantidad == nullptr or numPedidos == 0){
        ped_FechaCantidad = new int *[capPedidos];
        ped_Codigo = new char *[capPedidos];
        ped_FechaCantidad[0] = nullptr;
        ped_Codigo[0] = nullptr;
        numPedidos = 1;
    }else{
        auxF = new int *[capPedidos];
        auxC = new char *[capPedidos];
        for (int i = 0; i < numPedidos; i++) {
            auxC[i] = ped_Codigo[i];
            auxF[i] = ped_FechaCantidad[i];
        }
        delete ped_FechaCantidad;
        delete ped_Codigo;
        ped_Codigo = auxC;
        ped_FechaCantidad = auxF;
    }
}

void agregarProducto(char ***&pro_CodigoDescripcion,char *codProducto,char *descripcion,
                double **&pro_PrecioDescuento,double precioUnitario,double descuento,int &numProductos,int &capProductos){
    double *precioDescuento;
    char **codigoDescripcion;
    precioDescuento = new double[2];
    precioDescuento[0] = precioUnitario;
    precioDescuento[1] = descuento;
    codigoDescripcion = new char*[2];
    codigoDescripcion[0] = codProducto;
    codigoDescripcion[1] = descripcion;
    
    if(numProductos == capProductos)
        aumentarEspacios(pro_CodigoDescripcion,pro_PrecioDescuento,numProductos,capProductos);
    pro_CodigoDescripcion[numProductos] = nullptr;
    pro_CodigoDescripcion[numProductos -1] = codigoDescripcion;
    pro_PrecioDescuento[numProductos] = nullptr;
    pro_PrecioDescuento[numProductos -1] = precioDescuento;
    numProductos++;
}

void aumentarEspacios(char ***&pro_CodigoDescripcion,double **&pro_PrecioDescuento,int &numProductos,int &capProductos){
    char ***auxC;
    double **auxP;
    capProductos += INCREMENTO;
    if(pro_CodigoDescripcion == nullptr){
        pro_CodigoDescripcion = new char **[capProductos];
        pro_PrecioDescuento = new double *[capProductos];
        pro_CodigoDescripcion[0] = nullptr;
        pro_PrecioDescuento[0] = nullptr;
        numProductos = 1;
    }else{
        auxC = new char **[capProductos];
        auxP = new double *[capProductos];
        for (int i = 0; i < numProductos; i++) {
            auxC[i] = pro_CodigoDescripcion[i];
            auxP[i] = pro_PrecioDescuento[i];
        }
        delete pro_CodigoDescripcion;
        delete pro_PrecioDescuento;
        pro_CodigoDescripcion = auxC;
        pro_PrecioDescuento = auxP;
    }
}

void leerDatosRestantes(ifstream &archPedidos,char *&descripcion,double &descuento,
        int &cantidad,double &precioUnitario,int &dniCliente,int &fecha){
    char car;
    int dd,mm,aa;
    descripcion = leerCadena(archPedidos);
    archPedidos>>cantidad;
    if(archPedidos.fail()){
        archPedidos.clear();
        archPedidos.get();
        archPedidos>>descuento;
        archPedidos.get();
        archPedidos>>cantidad;
    }else descuento = 0.0;
    archPedidos.get();
    archPedidos>>precioUnitario;
    archPedidos.get();
    archPedidos>>dniCliente;
    archPedidos.get();
    archPedidos>>dd>>car>>mm>>car>>aa;
    archPedidos.get();
    fecha = aa * 10000 + mm * 100 + dd;
}

int obtenerPosicionProducto(char *codProducto, char ***pro_CodigoDescripcion){
    if( pro_CodigoDescripcion == nullptr) return -1;
    for (int i = 0; pro_CodigoDescripcion[i]; i++) 
        if(strcmp(*(pro_CodigoDescripcion[i]),codProducto)  == 0) return i;
    return -1;
}

char *leerCadena(ifstream &arch){
    char *aux,buff[200];
    arch.getline(buff,200,',');
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}
    
void ReporteDePedidosYProductos(int **cli_DniTelefono,char ***pro_CodigoDescripcion,double **pro_PrecioDescuento,
                             char ***ped_Codigo,int ***ped_FechaCantidad,const char*nomArch){
    ofstream archReporte(nomArch,ios::out);
    archReporte.precision(2);archReporte<<fixed;
    for (int i = 0; cli_DniTelefono[i]; i++) {
        archReporte<<left<<setw(10)<<cli_DniTelefono[i][0]<<setw(10)<<cli_DniTelefono[i][1]<<endl;
        if(ped_FechaCantidad[i])
            imprimirPedidos(archReporte, ped_Codigo[i], ped_FechaCantidad[i]);
        archReporte<<endl<<endl;
    }

    for (int i = 0; pro_CodigoDescripcion[i]; i++) {
        archReporte<<right<<setw(3)<<(i+1)<<')'<<"   ";
        imprimirProducto(pro_CodigoDescripcion[i],pro_PrecioDescuento[i],archReporte);
    }

}

void imprimirPedidos(ofstream &arch, char **ped_Codigo, int **ped_FechaCantidad){
    for(int i=0; ped_FechaCantidad[i]; i++){
        arch << right << setw(3) << i + 1 << ")  ";
        arch << setw(10) << ped_Codigo[i] << "  ";
        imprimeFecha(arch, ped_FechaCantidad[i][0]);
        arch << "   " <<right<< setw(5) << ped_FechaCantidad[i][1]<<left<<endl;
    }
}

void imprimeFecha(ofstream &arch, int fecha){
    int dd, mm, aa;
    dd = fecha%100;
    fecha /= 100;
    mm = fecha%100;
    aa = fecha/100;
    arch << right << setfill('0') << setw(2) << dd << "/" << 
            setw(2) << mm << "/" 
            << setw(4) << left << aa << setfill(' ');
}

void imprimirProducto(char **pro_CodigoDescripcion,double *pro_PrecioDescuento,ofstream &archReporte){
    archReporte<<left<<setw(10)<<pro_CodigoDescripcion[0]<<setw(50)<<pro_CodigoDescripcion[1]
               <<right<<setw(10)<<pro_PrecioDescuento[0]<<setw(10)<<pro_PrecioDescuento[1]<<left<<endl;
}
    
void ReporteRelacionDePedidos(int **cli_DniTelefono,char ***cli_NombreCategoria,char ***pro_CodigoDescripcion,double **pro_PrecioDescuento,
                             char ***ped_Codigo,int ***ped_FechaCantidad,const char *nomArch){
    ofstream archReporte(nomArch,ios::out);
    archReporte.precision(2);archReporte<<fixed;
    archReporte<<right<<setw(65)<<"EMPRESA COMERLCIALIZADORA DE ABARROTES"<<endl;
    imprimirLinea('=',MAX_CAR,archReporte);
    archReporte<<left<<"GASTOS DE LOS CLIENTES REGISTRADOS: "<<endl;
    for (int i = 0; cli_DniTelefono[i]; i++) {
        imprimirEncabezadoCliente(cli_DniTelefono[i],cli_NombreCategoria[i],archReporte);
        if(ped_FechaCantidad[i]) imprimirPedidos(ped_FechaCantidad[i],ped_Codigo[i],
                pro_CodigoDescripcion,pro_PrecioDescuento,archReporte);
    }
}

void imprimirEncabezadoCliente(int *cli_DniTelefono,char **cli_NombreCategoria,ofstream &arch){
    imprimirLinea('=',MAX_CAR,arch);
    arch<<left<<setw(15)<<"DNI"<<setw(57)<<"Nombre"<<setw(18)<<"Categoria"<<setw(15)<<"Telefono"<<endl;
    arch<<left<<setw(15)<<cli_DniTelefono[0]<<setw(60)<<cli_NombreCategoria[0]
        <<setw(15)<<cli_NombreCategoria[1][0]<<setw(15)<<cli_DniTelefono[1]<<endl;
    imprimirLinea('-',MAX_CAR,arch);
    arch<<right<<setw(10)<<"Codigo"<<"   "<<left<<setw(50)<<"Descripcion"
        <<setw(10)<<"P.U."<<setw(15)<<"Cantidad"<<setw(10)<<"Total"
        <<setw(15)<<"Descuento %"<<setw(10)<<"A Pagar"<<setw(15)<<"Descuento"<<setw(10)<<"Fecha"<<endl;
    imprimirLinea('-',MAX_CAR,arch);
}

void imprimirPedidos(int **ped_FechaCantidad,char **ped_Codigo,
                char ***pro_CodigoDescripcion,double **pro_PrecioDescuento,ofstream &arch){
    int posProducto;
    double total,pagar;
    double totalPagar = 0,totalDescuento = 0;
    for (int i = 0; ped_Codigo[i]; i++) {
        posProducto = obtenerPosicionProducto(ped_Codigo[i],pro_CodigoDescripcion);
        arch<<right<<setw(2)<<(i+1)<<"  "<<ped_Codigo[i]
            <<left<<setw(3)<<"   "<<setw(47)<<pro_CodigoDescripcion[posProducto][1]
            <<right<<setw(7)<<pro_PrecioDescuento[posProducto][0]
            <<setw(11)<<ped_FechaCantidad[i][1];
        total = pro_PrecioDescuento[posProducto][0] * ped_FechaCantidad[i][1];
        arch<<setw(15)<<total<<setw(12)<<pro_PrecioDescuento[posProducto][1];
        pagar = total * (1-pro_PrecioDescuento[posProducto][1]/100);
        arch<<setw(14)<<pagar
             <<setw(10)<<total * (pro_PrecioDescuento[posProducto][1]/100)<<setw(5)<<" ";
        imprimeFecha(arch,ped_FechaCantidad[i][0]);
        arch<<endl;
        totalPagar += pagar;
        totalDescuento += total * (pro_PrecioDescuento[posProducto][1]/100);
    }
    imprimirLinea('-',MAX_CAR,arch);
    arch<<right<<setw(110)<<"TOTAL:"<<setw(9)<<totalPagar<<setw(10)<<totalDescuento<<endl;
}

void imprimirLinea(char car, int cantidad, ofstream &arch){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}