/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "funcionesAuxiliares.h"

void crearLibrosBin(){
    int anioEdicion,cantLib,cantLibPres=0;
    double precio;
    char codigo[10],nombreLib[50],nombreAut[50];
    ofstream archLibrosBin("Biblioteca_Libros.bin",ios::out | ios::binary);
    if(not archLibrosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Biblioteca_Libros.bin"<<endl;
        exit(1);
    }
    ifstream archLibros("Libros.txt", ios::in);
    if(not archLibros.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Libros.txt"<<endl;
        exit(1);
    }
    
    
    while(true){
        archLibros>>codigo;
        if(archLibros.eof()) break;
        archLibros>>nombreLib>>nombreAut>>anioEdicion>>cantLib>>precio;
        archLibrosBin.write(reinterpret_cast<const char*> (codigo),sizeof(char)*10);
        archLibrosBin.write(reinterpret_cast<const char*> (nombreLib),sizeof(char)*50);
        archLibrosBin.write(reinterpret_cast<const char*> (nombreAut),sizeof(char)*50);
        archLibrosBin.write(reinterpret_cast<const char*> (&anioEdicion),sizeof(int));
        archLibrosBin.write(reinterpret_cast<const char*> (&cantLib),sizeof(int));
        archLibrosBin.write(reinterpret_cast<const char*> (&cantLibPres),sizeof(int));
        archLibrosBin.write(reinterpret_cast<const char*> (&precio),sizeof(double));
    }
}

void mostrarLibrosBin(){
    int anioEdicion,cantLib,cantLibPres;
    double precio;
    char codigo[10],nombreLib[50],nombreAut[50];
    ifstream archLibrosBin("Biblioteca_Libros.bin",ios::in | ios::binary);
    if(not archLibrosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Biblioteca_Libros.bin"<<endl;
        exit(1);
    }
    ofstream archLibMuestra("LIbrosMuestra.txt",ios::out);
    if(not archLibMuestra.is_open()){
        cout<<"ERROR: No se puede abrir el archivo LIbrosMuestra.txt"<<endl;
        exit(1);
    }
    
    archLibMuestra.precision(2); archLibMuestra<<fixed;
    
    while(true){
        archLibrosBin.read(reinterpret_cast< char*> (codigo),sizeof(char)*10);
        if(archLibrosBin.eof()) break;
        archLibrosBin.read(reinterpret_cast< char*> (nombreLib),sizeof(char)*50);
        archLibrosBin.read(reinterpret_cast< char*> (nombreAut),sizeof(char)*50);
        archLibrosBin.read(reinterpret_cast< char*> (&anioEdicion),sizeof(int));
        archLibrosBin.read(reinterpret_cast< char*> (&cantLib),sizeof(int));
        archLibrosBin.read(reinterpret_cast< char*> (&cantLibPres),sizeof(int));
        archLibrosBin.read(reinterpret_cast< char*> (&precio),sizeof(double));
        archLibMuestra<<left<<setw(10)<<codigo<<setw(50)<<nombreLib<<setw(50)<<nombreAut
                <<setw(8)<<anioEdicion<<right<<setw(5)<<cantLib<<setw(5)<<cantLibPres
                <<setw(10)<<precio<<endl;
    }
}

void crearUsuariosPrestamosBin(){
    int carne_aux,carne,dd,mm,aa,cantLibPres = 0,cantLibAde = 0,fecha;
    double multa = 0.0;
    char tipoUsuario,nombre[70],codigoLib[10],car;
    ofstream archUsuariosBin("Biblioteca_Usuarios.bin",ios::out | ios::binary);
    if(not archUsuariosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Biblioteca_Usuarios.bin"<<endl;
        exit(1);
    }
    ofstream archPrestamosBin("Biblioteca_Prestamos.bin",ios::out | ios::binary);
    if(not archPrestamosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Biblioteca_Prestamos.bin"<<endl;
        exit(1);
    }
    ifstream archPrestamos("RegistroDePrestamos.txt",ios::in);
    if(not archPrestamos.is_open()){
        cout<<"ERROR: No se puede abrir el archivo RegistroDePrestamos.txt"<<endl;
        exit(1);
    }
    
    while(true){
        archPrestamos>>carne;
        if(archPrestamos.eof()) break;
        if(not archPrestamos.fail()){
            archPrestamos>>tipoUsuario>>nombre;
            carne_aux = carne;
            archUsuariosBin.write(reinterpret_cast<const char*> (&carne),sizeof(int));
            archUsuariosBin.write(reinterpret_cast<const char*> (&tipoUsuario),sizeof(char));
            archUsuariosBin.write(reinterpret_cast<const char*> (nombre),sizeof(char)*70);
            archUsuariosBin.write(reinterpret_cast<const char*> (&cantLibPres),sizeof(int));
            archUsuariosBin.write(reinterpret_cast<const char*> (&cantLibAde),sizeof(int));
            archUsuariosBin.write(reinterpret_cast<const char*> (&multa),sizeof(double));
        }else{
            archPrestamos.clear();
            archPrestamos>>codigoLib>>dd>>car>>mm>>car>>aa;
            //20210101
            fecha = aa*10000+mm*100+dd;
            archPrestamosBin.write(reinterpret_cast<const char*> (&carne_aux),sizeof(int));
            archPrestamosBin.write(reinterpret_cast<const char*> (codigoLib),sizeof(char)*10);
            archPrestamosBin.write(reinterpret_cast<const char*> (&fecha),sizeof(int));
        }
    }
}

void mostrarPrestamosBin(){
    int carne_aux,carne,dd,mm,aa,cantLibPres,cantLibAde,fecha;
    double multa;
    char tipoUsuario,nombre[70],codigoLib[10],car;
    ifstream archPrestamosBin("Biblioteca_Prestamos.bin",ios::in | ios::binary);
    if(not archPrestamosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Biblioteca_Prestamos.bin"<<endl;
        exit(1);
    }
    ofstream archPrestamosMuestra("RegistroDePrestamosMuestra.txt",ios::out);
    if(not archPrestamosMuestra.is_open()){
        cout<<"ERROR: No se puede abrir el archivo RegistroDePrestamosMuestra.txt"<<endl;
        exit(1);
    }
    while(true){
        archPrestamosBin.read(reinterpret_cast< char*> (&carne),sizeof(int));
        if(archPrestamosBin.eof()) break;
        archPrestamosBin.read(reinterpret_cast< char*> (codigoLib),sizeof(char)*10);
        archPrestamosBin.read(reinterpret_cast< char*> (&fecha),sizeof(int));
        //20210102
        aa = fecha/10000;
        fecha = fecha % 10000;
        mm = fecha/100;
        dd = fecha % 100;
        archPrestamosMuestra<<left<<setw(10)<<carne<<setw(10)<<codigoLib<<"   "
                <<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa<<setfill(' ')<<endl;
    }   
    
    
}

void mostrarUsuariosBin(){
    int carne_aux,carne,dd,mm,aa,cantLibPres,cantLibAde,fecha;
    double multa;
    char tipoUsuario,nombre[70],codigoLib[10],car;
    ifstream archUsuariosBin("Biblioteca_Usuarios.bin",ios::in | ios::binary);
    if(not archUsuariosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Biblioteca_Usuarios.bin"<<endl;
        exit(1);
    }
    ofstream archUsuariosMuestra("UsuariosMuestra.txt",ios::out);
    if(not archUsuariosMuestra.is_open()){
        cout<<"ERROR: No se puede abrir el archivo UsuariosMuestra.txt"<<endl;
        exit(1);
    }
    
    archUsuariosMuestra.precision(2); archUsuariosMuestra<<fixed;
    
    while(true){
        archUsuariosBin.read(reinterpret_cast< char*> (&carne),sizeof(int));
        if(archUsuariosBin.eof()) break;
        archUsuariosBin.read(reinterpret_cast< char*> (&tipoUsuario),sizeof(char));
        archUsuariosBin.read(reinterpret_cast< char*> (nombre),sizeof(char)*70);
        archUsuariosBin.read(reinterpret_cast< char*> (&cantLibPres),sizeof(int));
        archUsuariosBin.read(reinterpret_cast< char*> (&cantLibAde),sizeof(int));
        archUsuariosBin.read(reinterpret_cast< char*> (&multa),sizeof(double));
        archUsuariosMuestra<<left<<setw(10)<<carne<<setw(5)<<tipoUsuario
                <<setw(50)<<nombre<<right<<setw(10)<<cantLibPres
                <<setw(10)<<cantLibAde<<setw(10)<<multa<<endl;
    }    
}

int compararCadenas(char *cadena1,char *cadena2){
    int i=0;
    while(cadena1[i]){
        if(cadena1[i] != cadena2[i]) return 0;
        i++;
    }
    return 1;
}

void actualizarArchLibrosBin(){
    char codLibro[10],codigoLibro[10];
    int cantLibPres,cod;
    fstream archLibrosBin("Biblioteca_Libros.bin",ios::in | ios::out | ios::binary);
    if(not archLibrosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Biblioteca_Libros.bin"<<endl;
        exit(1);
    }
    ifstream archPrestamosBin("Biblioteca_Prestamos.bin",ios::in | ios::binary);
    if(not archPrestamosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Biblioteca_Prestamos.bin"<<endl;
        exit(1);
    }
    
    int tamDelRegistro,tamDelArchivo,numRegistros;
    tamDelRegistro = sizeof(int) * 3 + sizeof(char) * 110 + sizeof(double);
    archLibrosBin.seekg(0,ios::end);
    tamDelArchivo = archLibrosBin.tellg();
    archLibrosBin.seekg(0,ios::beg);
    numRegistros = tamDelArchivo/tamDelRegistro;
    
    while(true){
        archPrestamosBin.read(reinterpret_cast<char *>(&cod),sizeof(int));
        if(archPrestamosBin.eof()) break;
        archPrestamosBin.read(reinterpret_cast<char *>(codLibro),sizeof(char)*10);
        archPrestamosBin.seekg(sizeof(int),ios::cur);
        archLibrosBin.seekg(0,ios::beg);
        for (int i = 0; i < numRegistros; i++) {
            archLibrosBin.read(reinterpret_cast<char *>(codigoLibro),sizeof(char)*10);
            if(compararCadenas(codLibro,codigoLibro)){
                archLibrosBin.seekg(sizeof(char) * 100 + sizeof(int)*2,ios::cur);
                archLibrosBin.read(reinterpret_cast<char *>(&cantLibPres),sizeof(int));
                cantLibPres = cantLibPres + 1;
                archLibrosBin.seekg(i*tamDelRegistro,ios::beg);
                archLibrosBin.seekg(sizeof(char) * 110 + sizeof(int)*2,ios::cur);
                archLibrosBin.write(reinterpret_cast<const char *>(&cantLibPres),sizeof(int));
                break;
            }else{
                archLibrosBin.seekg(sizeof(int)*3 + sizeof(double) + sizeof(char) * 100,ios::cur);
            }
        }
    }
}

void leerFecha(int &fechaD,int &fechaE,int &fechaA,ifstream &archFechas){
    int dd,mm,aa;
    char car;
    archFechas>>dd>>car>>mm>>car>>aa;
    fechaD = aa*10000 + mm*100 + dd;
    archFechas>>dd>>car>>mm>>car>>aa;
    fechaE = aa*10000 + mm*100 + dd;
    archFechas>>dd>>car>>mm>>car>>aa;
    fechaA = aa*10000 + mm*100 + dd;
}

int asignarRetraso(char tipo,int fecha,int fechaD,int fechaE,int fechaA){
    if(tipo == 'D') if(fecha<fechaD) return 1;
    else if(tipo == 'E') if(fecha<fechaE) return 1;
    else if(tipo == 'A') if(fecha<fechaA) return 1;
    return 0;
}

double asignarMulta(char tipo,char *codLib, ifstream &archLibBin){
    int anioEdicion,cantLib,cantLibPres;
    double precio;
    char codigo[10],nombreLib[50],nombreAut[50];
    
    archLibBin.seekg(0,ios::beg);
    
    while(true){
        archLibBin.read(reinterpret_cast<char *>(codigo),sizeof(char)*10);
        if(archLibBin.eof()) break;
        if(compararCadenas(codLib,codigo)){
           archLibBin.seekg(sizeof(char)*100 + sizeof(int)*3,ios::cur);
           archLibBin.read(reinterpret_cast<char *>(&precio),sizeof(double));
           if(tipo == 'D') return ((2.25/100) *precio);
           else if(tipo == 'E') return ((1/100) * precio);
           else if(tipo == 'A') return ((1.5/100) * precio);
        }else{
            archLibBin.seekg(sizeof(char)*100 + sizeof(int)*3 + sizeof(double),ios::cur);
        }
    }
}


void actualizarUsuariosBin(){
    int fechaD,fechaE,fechaA,cod,codUsuario,fecha,retraso,cantLibPres,cantLibAde;
    double mul,multa;
    char codLib[10],tipo;
    
    ifstream archFechas("Fechas.txt",ios::in);
    if(not archFechas.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Fechas.txt"<<endl;
        exit(1);
    }
    ifstream archPrestamosBin("Biblioteca_Prestamos.bin",ios::in | ios::binary);
    if(not archPrestamosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Biblioteca_Prestamos.bin"<<endl;
        exit(1);
    }
    ifstream archLibrosBin("Biblioteca_Libros.bin",ios::in | ios::binary);
    if(not archLibrosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Biblioteca_Libros.bin"<<endl;
        exit(1);
    }
    fstream archUsuariosBin("Biblioteca_Usuarios.bin",ios::in | ios::out | ios::binary);
    if(not archUsuariosBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Biblioteca_Usuarios.bin"<<endl;
        exit(1);
    }
    
    leerFecha(fechaD,fechaE,fechaA,archFechas);
    
    int tamDelRegistro,tamDelArchivo,numRegistros;
    tamDelRegistro = sizeof(int) * 3 + sizeof(char) * 71 + sizeof(double);
    archUsuariosBin.seekg(0,ios::end);
    tamDelArchivo = archUsuariosBin.tellg();
    archUsuariosBin.seekg(0,ios::beg);
    numRegistros = tamDelArchivo/tamDelRegistro;
    
    while(true){
        archPrestamosBin.read(reinterpret_cast<char *>(&cod),sizeof(int));
        if(archPrestamosBin.eof()) break;
        archPrestamosBin.read(reinterpret_cast<char *>(codLib),sizeof(char) * 10);
        archPrestamosBin.read(reinterpret_cast<char *>(&fecha),sizeof(int));

        archUsuariosBin.seekg(0,ios::beg);
        
        for (int i = 0; i < numRegistros; i++) {
            archUsuariosBin.read(reinterpret_cast<char *>(&codUsuario),sizeof(int));
            if(codUsuario == cod){
                archUsuariosBin.read(reinterpret_cast<char *>(&tipo),sizeof(char));
                archUsuariosBin.seekg(sizeof(char)*70,ios::cur);
                archUsuariosBin.read(reinterpret_cast< char*> (&cantLibPres),sizeof(int));
                archUsuariosBin.read(reinterpret_cast< char*> (&cantLibAde),sizeof(int));
                archUsuariosBin.read(reinterpret_cast< char*> (&mul),sizeof(double));
                retraso = asignarRetraso(tipo,fecha,fechaD,fechaE,fechaA);
                if(retraso){
                    multa = asignarMulta(tipo,codLib,archLibrosBin);
                    cantLibPres = cantLibPres + 1;
                    cantLibAde = cantLibAde + 1;
                    mul = mul + multa;
                    archUsuariosBin.seekg(i*tamDelRegistro,ios::beg);
                    archUsuariosBin.seekg(sizeof(int) + sizeof(char)*71,ios::cur);
                    archUsuariosBin.write(reinterpret_cast<const char*> (&cantLibPres),sizeof(int));
                    archUsuariosBin.write(reinterpret_cast<const char*> (&cantLibAde),sizeof(int));
                    archUsuariosBin.write(reinterpret_cast<const char*> (&mul),sizeof(double));
                    break;
                }else{
                    cantLibPres = cantLibPres + 1;
                    archUsuariosBin.seekg(i*tamDelRegistro,ios::beg);
                    archUsuariosBin.seekg(sizeof(int) + sizeof(char)*71,ios::cur);
                    archUsuariosBin.write(reinterpret_cast<const char*> (&cantLibPres),sizeof(int));
                    break;
                }
            }else{
                archUsuariosBin.seekg(sizeof(char)*71 + sizeof(int) *2 + sizeof(double),ios::cur);
            }
        }        
    }
}


