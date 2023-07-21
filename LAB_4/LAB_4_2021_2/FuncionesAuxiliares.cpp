/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesFecha.h"
#include "FuncionesAuxiliares.h"


void estructurasParaLosLibros_CargaDeDatos(char **&codigo,char **&titulo,int *&cantEnBibl,double *&precio){
    ifstream archLibros("Libros.csv",ios::in);
    if(not archLibros.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros.csv"<<endl;
        exit(1);
    }
    char *buffCodigo[100],*buffTitulo[100],buff[100],car;
    int buffCantEnBiblio[100],numDatos = 0,edicion,stock;
    double buffPrecio[100],preci;
    while(true){
        buffCodigo[numDatos] = leerCadena(archLibros);
        if(archLibros.eof()) break;
        buffTitulo[numDatos] = leerCadena(archLibros);
        archLibros.getline(buff,100,',');
        archLibros>>edicion>>car>>stock>>car>>preci;
        archLibros.get();
        buffCantEnBiblio[numDatos] = stock;
        buffPrecio[numDatos] = preci;
        numDatos++;
    }
    buffCodigo[numDatos] = nullptr;
    buffTitulo[numDatos] = nullptr;
    buffCantEnBiblio[numDatos] = 0;
    buffPrecio[numDatos] = 0;
    numDatos++;
    codigo = new char*[numDatos];
    titulo = new char*[numDatos];
    cantEnBibl = new int[numDatos];
    precio = new double[numDatos];
    for (int i = 0; i < numDatos; i++){
        codigo[i] = buffCodigo[i];
        titulo[i] = buffTitulo[i];
        cantEnBibl[i] = buffCantEnBiblio[i];
        precio[i] = buffPrecio[i];
    }
}

char *leerCadena(ifstream &arch){
    char buff[100],*aux;
    arch.getline(buff,100,',');
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}
    
void estructurasParaLosLibros_Reporte(char **codigo,char **titulo,int *cantEnBibl,double *precio){
    ofstream arch("ReporteLibros.txt",ios::out);
    for (int i = 0; codigo[i]; i++) {
         arch<<setw(10)<<left<<codigo[i]<<setw(40)<<left<<titulo[i]<<setw(10)
                <<right<<cantEnBibl[i]<<setw(12)<<right<<setprecision(2)
                <<fixed<<precio[i]<<endl;
    }
}

void usuariosDeLaBiblioteca_CargaDeDatos(int *&carne,char *&tipo,char **&nombre){
    ifstream archUsuarios("Usuarios.csv",ios::in);
    int buffCarne[100],cod,numDatos=0;
    char buffTipo[100],*buffNombre[100],tip;
    while(true){
        archUsuarios>>cod;
        if(archUsuarios.eof()) break;
        archUsuarios>>tip;
        archUsuarios.get();
        buffNombre[numDatos] = leerNombre(archUsuarios);
        buffCarne[numDatos] = cod;
        buffTipo[numDatos] = tip;
        numDatos++;
    }
    buffNombre[numDatos] = nullptr;
    buffCarne[numDatos] = 0;
    buffTipo[numDatos] = 0;
    numDatos++;
    carne = new int[numDatos];
    tipo = new char[numDatos];
    nombre = new char*[numDatos];
    for (int i = 0; i < numDatos; i++) {
        carne[i] = buffCarne[i];
        tipo[i] = buffTipo[i];
        nombre[i] = buffNombre[i];
    }
}

char *leerNombre(ifstream &arch){
    char buff[100],*aux;
    arch.getline(buff,100);
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

void usuariosDeLaBiblioteca_Reporte(int *carne,char *tipo,char **nombre){
    ofstream arch("ReporteUsuarios.txt",ios::out);
    for (int i = 0; carne[i]; i++) {
         arch<<setw(15)<<left<<carne[i]<<setw(5)<<left<<tipo[i]<<left<<nombre[i]<<endl;
    }
}

void librosYUsuariosInhabilitados_Reporte(char **codigo,char **titulo,int *cantEnBibl,
                                          double *precio,int *carne,char *tipo,char **nombre){
    ofstream archReporte("Reporte_Deudores.txt",ios::out);
    imprimirReporteTipo(codigo,titulo,cantEnBibl,precio,carne,tipo,nombre,'E',archReporte);
    imprimirReporteTipo(codigo,titulo,cantEnBibl,precio,carne,tipo,nombre,'D',archReporte);
    imprimirReporteTipo(codigo,titulo,cantEnBibl,precio,carne,tipo,nombre,'A',archReporte);
    imprimirLibros(codigo,titulo,cantEnBibl,precio,archReporte);
}

void imprimirLibros(char **codigo,char **titulo,int *cantEnBibl,double *precio,ofstream &arch){
    for (int i = 0; codigo[i]; i++) {
         arch<<setw(10)<<left<<codigo[i]<<setw(40)<<left<<titulo[i]<<setw(10)
                <<right<<cantEnBibl[i]<<setw(12)<<right<<setprecision(2)
                <<fixed<<precio[i]<<endl;
    }
}

void imprimirReporteTipo(char **codigo,char **titulo,int *cantEnBibl,
                         double *precio,int *carne, char *tipo, char **nombre, char tip,ofstream &arch){
    ifstream archPrestamos("RegistroDePrestamos.csv",ios::in);
    int *carneDeuda,buffCarneDeuda[100],*cantDeuda,buffCantDeuda[100],numDatos=0;
    int cod,dd,mm,aa,fecha,datoFecha = 20210924,posCliente,posLibro;
    char tipoUsuario,car,buff[15];
    double *montoDeuda,buffMontoDeuda[100],penalidad;
    char **nombreDeuda,*buffNombreDeuda[100];
    
    while(true){
        archPrestamos>>cod;
        if(archPrestamos.eof()) break;
        archPrestamos>>tipoUsuario>>car;
        archPrestamos.getline(buff,15,',');
        archPrestamos>>dd>>car>>mm>>car>>aa;
        fecha = aa*10000 + mm*100 + dd;
        if((tipoUsuario == tip) and existeDeuda(fecha,datoFecha,penalidad,tip)){
            posCliente = existeCliente(buffCarneDeuda,cod,numDatos);
            posLibro = posicionLibro(buff,codigo);
            if(posCliente == -1){//no existe en el arreglo nueva entrada
                posCliente = posicionCliente(carne,cod);//posicion en carne y nombre
                buffCarneDeuda[numDatos] = carne[posCliente];
                buffNombreDeuda[numDatos] = nombre[posCliente];
                buffCantDeuda[numDatos] = 1;
                buffMontoDeuda[numDatos] = (precio[posLibro] * (penalidad/100));
                numDatos++;
            }else{//ya existe
                buffCantDeuda[posCliente]++;
                buffMontoDeuda[posCliente] += (precio[posLibro] * (penalidad/100));
            }
            cantEnBibl[posLibro]--;
        }
    }
    buffCarneDeuda[numDatos] = 0;
    buffNombreDeuda[numDatos] = nullptr;
    buffCantDeuda[numDatos] = 0;
    buffMontoDeuda[numDatos] = 0;
    numDatos++;
    carneDeuda = new int[numDatos];
    nombreDeuda = new char*[numDatos];
    cantDeuda = new int[numDatos];
    montoDeuda = new double[numDatos];
    for (int i = 0; i < numDatos; i++) {
        carneDeuda[i] = buffCarneDeuda[i];
        nombreDeuda[i] = buffNombreDeuda[i];
        cantDeuda[i] = buffCantDeuda[i];
        montoDeuda[i] = buffMontoDeuda[i];
    }
    imprimirReporte(carneDeuda,nombreDeuda,cantDeuda,montoDeuda,arch);
    delete carneDeuda;
    delete nombreDeuda;
    delete cantDeuda;
    delete montoDeuda;
}

void imprimirReporte(int *carneDeuda,char **nombreDeuda,int *cantDeuda,double *montoDeuda,ofstream &arch){
    for (int i = 0; carneDeuda[i]; i++) {
        arch<<setw(2)<<right<<i+1<<")    "<<setw(12)<<left<<carneDeuda[i]<<
                setw(60)<<left<<nombreDeuda[i]<<setw(12)<<left<<cantDeuda[i]
                <<setw(18)<<right<<setprecision(2)<<fixed<<montoDeuda[i]<<endl;
    }
    imprimirLinea('=',100,arch);
}

void imprimirLinea(char car, int cantidad, ofstream &arch){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}

int existeCliente(int *buffCarneDeuda,int cod,int numDatos){
    for (int i = 0; i < numDatos; i++) if(cod == buffCarneDeuda[i]) return i;
    return -1;
}

int posicionCliente(int *carne,int cod){
    for (int i = 0; carne[i]; i++) if(cod == carne[i]) return i;
}

int posicionLibro(char *buff,char **codigo){
    for (int i = 0; codigo[i]; i++) if(strcmp(buff,codigo[i]) == 0) return i;
}

int existeDeuda(int fecha, int datoFecha,double &penalidad,char tipo){
    if(tipo == 'A'){
        if(numeroDeDias(datoFecha,fecha) > 3){
            penalidad = 1.5;
            return 1;
        }
        else return 0;
    }
    else if(tipo == 'D'){
        if(numeroDeDias(datoFecha,fecha) > 15){
            penalidad = 2.25;
            return 1;
        }
        else return 0;
    }
    else if(tipo == 'E'){
        if(numeroDeDias(datoFecha,fecha) > 7){
            penalidad = 1;
            return 1;
        }
        else return 0;
    }
}