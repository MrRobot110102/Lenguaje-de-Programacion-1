/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

//20190638
//Sebastian Moises Esquivel Barreto
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"
#include "BibliotecaCargaLibros_Y_Usuarios.h"
#include "FuncionesFecha.h"
#define FECHA 20211019
//    char **codLibro, *tipoUs, **nombreUs, ***codLibPrest;
//    int *cantLibros, *carneUs, **fechPrest;
void cargarPrestamos(int **&fechPrest,char ***&codLibPrest,int *carneUs){
    ifstream archPrestamos("RegistroDePrestamos.csv",ios::in);
    if(not archPrestamos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo RegistroDePrestamos.csv"<<endl;
        exit(1);
    }
    int i,codUsuario,fecha,dd,mm,aa,posUsuario;
    char tipo,*codLibro,car;
    for (i = 0;carneUs[i]; i++);
    fechPrest = new int*[i+1]{};
    codLibPrest = new char**[i+1]{};
    int numLibros[i+1]{};    
    for (int j = 0; j < i; j++) {
        fechPrest[j] =  new int[50];
        codLibPrest[j] = new char*[50];
    }    
    while (true) {
        archPrestamos>>codUsuario;
        if(archPrestamos.eof()) break;
        archPrestamos>>tipo>>car;
        codLibro = leerCadena(archPrestamos);
        archPrestamos>>dd>>car>>mm>>car>>aa;
        fecha = aa * 10000 + mm * 100 + dd;
        posUsuario = obtenerPosicionUsuario(carneUs,codUsuario);
        if(posUsuario != -1)
            agregarPrestamoUsuario(fechPrest[posUsuario],fecha,codLibPrest[posUsuario],codLibro,numLibros[posUsuario]);
    }
    for (int i = 0; carneUs[i]; i++)
        if(fechPrest[i]) espaciosExactos(fechPrest[i],codLibPrest[i],numLibros[i]);
}

void espaciosExactos(int *&fechPrest, char **&codLibPrest,int numLibros){
    int *buffFechPrest;
    char **buffCodLibPrest;
    if(numLibros == 0){
        delete fechPrest;
        delete codLibPrest;
        fechPrest = nullptr;
        codLibPrest = nullptr;
    }else{// 0 1 2 3 (4)
        buffFechPrest = new int[numLibros+1];
        buffCodLibPrest = new char*[numLibros+1];
        for (int i = 0; i < numLibros; i++) {
            buffFechPrest[i] = fechPrest[i];
            buffCodLibPrest[i] = codLibPrest[i];
        }
        buffFechPrest[numLibros] = 0;
        buffCodLibPrest[numLibros] = nullptr;
        delete fechPrest;
        delete codLibPrest;
        fechPrest = buffFechPrest;
        codLibPrest = buffCodLibPrest;
    }
}

void agregarPrestamoUsuario(int *&fechPrest,int  fecha,char **&codLibPrest,char *codLibro,int &numLibros){
    fechPrest[numLibros] = fecha;
    codLibPrest[numLibros] = codLibro;
    numLibros++;
    //0 -> 1
    //1 -> 2
    //2 -> 3
}

int obtenerPosicionUsuario(int *carneUs,int codUsuario){
    for (int i = 0; carneUs[i]; i++) if(carneUs[i] == codUsuario) return i;
    return -1;
}

char *leerCadena(ifstream &arch){
    char *aux, buff[300];
    arch.getline(buff,300,',');
    aux =  new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}
    
void mostrarLibrosPrestados(int **fechPrest,char ***codLibPrest,int *carneUs,char *tipoUs,const char *nombArch){
    ofstream archReporte(nombArch,ios::out);
    for (int i = 0; carneUs[i]; i++) {
        archReporte<<left<<setw(10)<<carneUs[i]<<setw(10)<<tipoUs[i]<<endl;
        if(fechPrest[i]) imprimirPrestamos(fechPrest[i],codLibPrest[i],archReporte);
    }
}

void imprimirPrestamos(int *fechPrest,char **codLibPrest,ofstream &archReporte){
    for (int i = 0; fechPrest[i]; i++) archReporte<<setw(10)<<fechPrest[i]<<codLibPrest[i]<<endl;
}
    
void procesarSolicitudes(int *carneUs,char *tipoUs,char **nombreUs,int **&fechPrest,char ***&codLibPrest,char **codLibro,int *&cantLibros){
    ifstream archSolicitudes("PedidosYDevoluciones.csv",ios::in);
    ofstream archReporte("ReporteSolicitudesPrestamo.txt",ios::out);
    if(not archSolicitudes.is_open()){
        cout<<"ERROR: No se pudo abirir el archivo PedidosYDevoluciones.csv"<<endl;
        exit(1);
    }
    int i,numeral = 0;
    for (i = 0;carneUs[i]; i++);
    int numeroPrestamos[i+1]{};
    int codUsuario,posUsuario;
    char tipo, solicitud,car, *codigoLibro,*nombUsuario;
    for (int i = 0;carneUs[i]; i++)
        if(fechPrest[i]) obtenerCantidadLibros(fechPrest[i],numeroPrestamos[i]);
    archReporte<<"RESPUESTA A LAS SOLICITUDES DE PRESTAMO"<<endl;
    while (true) {
        archSolicitudes>>codUsuario;
        if(archSolicitudes.eof()) break;
        archSolicitudes>>tipo>>car>>solicitud>>car;
        codigoLibro = leerLibro(archSolicitudes);
        posUsuario = obtenerPosicionUsuario(carneUs,codUsuario);
        if(posUsuario != -1){
            archReporte<<left<<setw(5)<<(numeral+1)<<nombreUs[posUsuario]<<endl;
            procesarSolicitud(solicitud,codLibro,cantLibros,codigoLibro,fechPrest[posUsuario],
                    codLibPrest[posUsuario],tipo,numeroPrestamos[posUsuario],archReporte);
            archReporte<<endl;
            numeral++;
        }
    }
}

char *leerLibro(ifstream &arch){
    char *aux, buff[10];
    arch.getline(buff,10);
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

void obtenerCantidadLibros(int *fechPrest, int &numPrestamos){
    for (int i = 0; fechPrest[i]; i++) numPrestamos++;
}

void procesarSolicitud(char solicitud,char **codLibro,int *&cantLibros,char *codigoLibro,int *&fechPrest,char **&codLibPrest,char tipoUs,int &numPrestamos,
                       ofstream &archReporte){
    int existeStock,noExcedePrestamos,noExisteRetraso,noTieneLibro,posLibro,tieneLibro;
    posLibro = obtenerPosicionLibro(codLibro,codigoLibro);
    tieneLibro = obtenerPosicion(codLibPrest,codigoLibro);
    if(solicitud == 'P'){//prestamos
        existeStock = cantLibros[posLibro] > 0;
        noExcedePrestamos = noExcedePrestamosPermitidos(numPrestamos,tipoUs);
        noExisteRetraso = noHayRetrasosDevolucion(fechPrest,codLibPrest,tipoUs);
        noTieneLibro = (tieneLibro == -1);
        // cout<<existeStock<<" "<<noExcedePrestamos<<" "<<noExisteRetraso<<" "<<noTieneLibro<<endl;
        gestionarPrestamo(archReporte,codigoLibro,existeStock,noExcedePrestamos,noExisteRetraso,noTieneLibro,
                fechPrest,codLibPrest,numPrestamos,cantLibros[posLibro]);
    }else{//devolucion
        int existeLibro = (tieneLibro != -1);
        gestionarDevolucion(archReporte,codigoLibro,existeLibro,tieneLibro,fechPrest,codLibPrest,numPrestamos,cantLibros[posLibro]);
    }
}

void gestionarPrestamo(ofstream &archReporte,char *codigoLibro,int existeStock,int noExcedePrestamos,int noExisteRetraso,int noTieneLibro,
        int *&fechPrest,char **&codLibPrest,int &numPrestamos, int &cantLibros){
    if(existeStock and noExcedePrestamos and noExisteRetraso and noTieneLibro){
        archReporte<<setw(5)<<left<<" "<<"Sin restricciones, se le entrego el libro No. :"<<codigoLibro<<endl;
        int fecha = FECHA;
        espaciosExactosPrestamo(fechPrest,codLibPrest,numPrestamos,fecha,codigoLibro);
        cantLibros--;
    }else{
        archReporte<<setw(5)<<left<<" "<<"No se le entrego el libro porque:"<<endl;
        if(not existeStock)
            archReporte<<setw(5)<<left<<" "<<"No existe stock del libro"<<endl;
        if(not noExcedePrestamos)
            archReporte<<setw(5)<<left<<" "<<"Excede la cantidad de prestamos maxima"<<endl;
        if(not noExisteRetraso)
            archReporte<<setw(5)<<left<<" "<<"Debe libros"<<endl;
        if(not noTieneLibro)
            archReporte<<setw(5)<<left<<" "<<"Ya se retiro el libro pedido No."<<codigoLibro<<endl;
    }
}

void espaciosExactosPrestamo(int *&fechPrest,char **&codLibPrest,int &numPrestamos, int fecha, char *codigoLibro){
    int *buffFechPrest;
    char **buffCodLibPrest;
    numPrestamos++;//4
    buffFechPrest = new int[numPrestamos+1];
    buffCodLibPrest = new char*[numPrestamos+1];
    for (int i = 0; i < numPrestamos-1; i++) {
        buffFechPrest[i] = fechPrest[i];
        buffCodLibPrest[i] = codLibPrest[i];
    }
    buffFechPrest[numPrestamos-1] = fecha;
    buffCodLibPrest[numPrestamos-1] = codigoLibro; 
    buffFechPrest[numPrestamos] = 0;
    buffCodLibPrest[numPrestamos] = nullptr;
    delete fechPrest;
    delete codLibPrest;
    fechPrest = buffFechPrest;
    codLibPrest = buffCodLibPrest;
    
}

void gestionarDevolucion(ofstream &archReporte,char *codigoLibro,int existeLibro,int posLibro,
        int *&fechPrest,char **&codLibPrest,int &numPrestamos, int &cantLibros){
    if(existeLibro){
        archReporte<<setw(5)<<left<<" "<<"Sin restricciones, se pudo devolver el libro No. :"<<codigoLibro<<endl;
        fechPrest[posLibro] = -1;
        espaciosExactosDevolucion(fechPrest,codLibPrest,numPrestamos);
        cantLibros ++;
    }else{
        archReporte<<setw(5)<<left<<" "<<"No se pudo devolver el libro porque:"<<endl;
        archReporte<<setw(5)<<left<<" "<<"Usuario no tiene libro en su poder"<<endl;
    }
}

void espaciosExactosDevolucion(int *&fechPrest,char **&codLibPrest,int &numPrestamos){
    int *buffFechPrest;
    char **buffCodLibPrest;
    int i;
    int numDatos = 0;
    buffFechPrest = new int[numPrestamos-1];
    buffCodLibPrest = new char*[numPrestamos-1];
    for (i = 0; i < numPrestamos; i++) {
        if(fechPrest[i] != -1){
            buffFechPrest[numDatos] = fechPrest[i];
            buffCodLibPrest[numDatos] = codLibPrest[i];
            numDatos++;
        }
    }
    numPrestamos--;
    buffFechPrest[numPrestamos] = 0;
    buffCodLibPrest[numPrestamos] = nullptr;
    delete fechPrest;
    delete codLibPrest;
    fechPrest = buffFechPrest;
    codLibPrest = buffCodLibPrest;
}

int noHayRetrasosDevolucion(int *fechPest,char **codLibPrest,char tipo){
    int diferencia;
    for(int i=0;fechPest[i];i++){
        if(fechPest[i]!=-1){
            diferencia = numeroDeDias(FECHA,fechPest[i]);
            if(tipo=='E'){
                if(diferencia > 7)return 0;
            }else if(tipo=='A'){
                if(diferencia > 3)return 0;
            }else if(tipo=='D'){
                if(diferencia > 15)return 0;
            }
        }
    }
    return 1;
}
int noExcedePrestamosPermitidos(int nd,char tipo){
    if(tipo=='E'){
        if(nd<7)return 1;
        else return 0;
    }else if(tipo=='A'){
        if(nd<5)return 1;
        else return 0;
    }else if(tipo=='D'){
        if(nd<12)return 1;
        else return 0;
    }
}

int obtenerPosicion(char **codLibPrest,char *codigoLibro){
    for (int i = 0; codLibPrest[i]; i++) {
        if(strcmp(codLibPrest[i],codigoLibro) == 0) return i;
    }
    return -1;
}

int obtenerPosicionLibro(char **codLibro,char *codigoLibro){
    for (int i = 0; codLibro[i]; i++) {
        if(strcmp(codLibro[i],codigoLibro) == 0) return i;
    }
    return -1;
}