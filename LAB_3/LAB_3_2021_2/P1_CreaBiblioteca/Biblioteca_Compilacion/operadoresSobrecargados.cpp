/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "StUsuario.h"
#include "StLibroPrestado.h"
#include "StLibro.h"
#include "StUsuarioPrestamo.h"
#include "operadoresSobrecargados.h"
#include "funcionesFecha.h"

bool operator >>(ifstream &arch,T_St_Libro &libro){
    arch>>libro.codigo;
    if(arch.eof()) return false;
    arch>>libro.titulo>>libro.stock>>libro.precio;
    libro.cantAdm = 0;
    libro.cantEst = 0;
    libro.cantDoc = 0;
    libro.prestados = 0;
    return true;
}

bool operator >>(ifstream &arch,T_St_Usuario &usuario){
    char tipo;
    arch>>usuario.carne;
    if(arch.eof()) return false;
    arch>>tipo>>usuario.nombre;
    if(tipo == 'E') strcpy(usuario.tipo,"ESTUDIANTE");
    else if(tipo == 'D') strcpy(usuario.tipo,"DOCENTE");
    else if(tipo == 'A') strcpy(usuario.tipo,"ADMINISTRATIVO");
    usuario.numLibPrest = 0;
    return true;
}

void operator +=(T_St_Usuario &usuario,const T_St_LibroPrestado &libPrestamo){
    strcpy(usuario.libPrest[usuario.numLibPrest].codigoLib,libPrestamo.codigoLib);
    usuario.libPrest[usuario.numLibPrest].fechaDeRetiro = libPrestamo.fechaDeRetiro;
    usuario.numLibPrest++;
}

void operator +=(T_St_Libro &libro,const T_St_UsuarioPrestamo &usuPrestamo){
    if(usuPrestamo.tipo == 'E'){
        libro.estudiantes[libro.cantEst].carne = usuPrestamo.carne;
        libro.estudiantes[libro.cantEst].fechaDeRetiro = usuPrestamo.fechaDeRetiro;
        libro.estudiantes[libro.cantEst].tipo = usuPrestamo.tipo;
        libro.cantEst++;
        libro.prestados++;
    }
    else if(usuPrestamo.tipo == 'D'){
        libro.docentes[libro.cantDoc].carne = usuPrestamo.carne;
        libro.docentes[libro.cantDoc].fechaDeRetiro = usuPrestamo.fechaDeRetiro;
        libro.docentes[libro.cantDoc].tipo = usuPrestamo.tipo;
        libro.cantDoc++;
        libro.prestados++;
    }
    else if(usuPrestamo.tipo == 'A'){
        libro.administrativos[libro.cantAdm].carne = usuPrestamo.carne;
        libro.administrativos[libro.cantAdm].fechaDeRetiro = usuPrestamo.fechaDeRetiro;
        libro.administrativos[libro.cantAdm].tipo = usuPrestamo.tipo;
        libro.cantAdm++;
        libro.prestados++;
    }
}

void operator <=(T_St_Usuario &usuario,const int fecha){
    int numDias,cantDeudas=0;
    for (int i = 0; i < usuario.numLibPrest; i++) {
        if(fecha < usuario.libPrest[i].fechaDeRetiro){
            numDias = numeroDeDias(fecha,usuario.libPrest[i].fechaDeRetiro);
            if(strcmp(usuario.tipo,"ESTUDIANTE") == 0){
                if(numDias > 7){
                    usuario.libPrest[i].deuda = true;
                    cantDeudas++;
                } else usuario.libPrest[i].deuda = false;
            }
            else if(strcmp(usuario.tipo,"DOCENTE") == 0){
                if(numDias > 15){
                    usuario.libPrest[i].deuda = true;
                    cantDeudas++;
                } else usuario.libPrest[i].deuda = false;
            }
            else if(strcmp(usuario.tipo,"ADMINISTRATIVO") == 0){
                if(numDias > 3){
                    usuario.libPrest[i].deuda = true;
                    cantDeudas++;
                } else usuario.libPrest[i].deuda = false;
            }
        }
    }
    if(cantDeudas != 0) strcpy(usuario.condicion,"INHABILITADO");
    else strcpy(usuario.condicion,"HABILITADO");
}

void operator <=(T_St_Libro &libro,const int fecha){
    int numDias;
    for (int i = 0; i < libro.cantDoc; i++) {
        if(fecha < libro.docentes[i].fechaDeRetiro){
            numDias = numeroDeDias(fecha,libro.docentes[i].fechaDeRetiro);
            if(numDias > 15) libro.docentes[i].deuda = true;
            else libro.docentes[i].deuda = false;
        }
    }
    for (int i = 0; i < libro.cantEst; i++) {
        if(fecha < libro.estudiantes[i].fechaDeRetiro){
            numDias = numeroDeDias(fecha,libro.estudiantes[i].fechaDeRetiro);
            if(numDias > 7) libro.estudiantes[i].deuda = true;
            else libro.estudiantes[i].deuda = false;
        }
    }
    for (int i = 0; i < libro.cantAdm; i++) {
        if(fecha < libro.administrativos[i].fechaDeRetiro){
            numDias = numeroDeDias(fecha,libro.administrativos[i].fechaDeRetiro);
            if(numDias > 3) libro.administrativos[i].deuda = true;
            else libro.administrativos[i].deuda = false;
        }
    }

}

ofstream & operator<<(ofstream &arch,const T_St_Usuario &usuario){
    int fecha,dd,mm,aa;
    arch<<left<<usuario.carne<<endl;
    arch<<usuario.nombre<<endl;
    arch<<usuario.tipo<<endl;
    arch<<usuario.condicion<<endl;
    for (int i = 0; i < usuario.numLibPrest; i++) {
        fecha = usuario.libPrest[i].fechaDeRetiro;
        //20210102
        aa = fecha / 10000;
        fecha = fecha % 10000;
        mm = fecha/100;
        dd = fecha % 100;
        arch<<left<<setw(20)<<usuario.libPrest[i].codigoLib
            <<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aa
            <<left<<setfill(' ')<<setw(10)<<" ";
        if(usuario.libPrest[i].deuda == true) arch<<"Deuda"<<endl;
        else arch<<endl;
    }
    arch<<endl<<endl<<endl;
    return arch;
}

ofstream & operator <<(ofstream &arch,const T_St_Libro &libro){
    int fecha,dd,mm,aa;
    
    arch.precision(2);arch<<fixed;
    
    arch<<left<<"Titulo   :  "<<libro.titulo<<endl;
    arch<<left<<"Codigo   :  "<<libro.codigo<<right<<setw(20)<<"Precio   :  "<<setw(8)<<libro.precio<<endl;
    arch<<left<<"Stock   :  "<<libro.stock<<right<<setw(20)<<"Prestados   :  "<<setw(8)<<libro.prestados<<endl;
    imprimirLinea('=',100,arch);
    arch<<left<<"Usuarios que lo tienen en su poder:"<<endl;
    
    imprimirLinea('-',100,arch);
    arch<<"DOCENTES:"<<endl;
    imprimirLinea('-',100,arch);
    
    arch<<left<<setw(10)<<"No."<<setw(20)<<"Carne"
        <<setw(20)<<"Fecha de retiro"<<setw(20)<<"Observacion"<<endl;
    
    for (int i = 0; i < libro.cantDoc; i++){
        fecha = libro.docentes[i].fechaDeRetiro;
        aa = fecha / 10000;
        fecha = fecha % 10000;
        mm = fecha/100;
        dd = fecha % 100;
        
        arch<<right<<setw(2)<<(i+1)<<')'<<setw(8)<<" "
            <<left<<setw(20)<<libro.docentes[i].carne<<right<<setfill('0')
            <<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aa<<left<<setfill(' ')<<setw(10)<<" ";
        if(libro.docentes[i].deuda == true) arch<<"Deuda"<<endl;
        else arch<<endl;
    }
        
    
    imprimirLinea('-',100,arch);
    arch<<"ESTUDIANTES:"<<endl;
    imprimirLinea('-',100,arch);
    
    arch<<left<<setw(10)<<"No."<<setw(20)<<"Carne"
        <<setw(20)<<"Fecha de retiro"<<setw(20)<<"Observacion"<<endl;
    
    for (int i = 0; i < libro.cantEst; i++){
        fecha = libro.estudiantes[i].fechaDeRetiro;
        aa = fecha / 10000;
        fecha = fecha % 10000;
        mm = fecha/100;
        dd = fecha % 100;
        
        arch<<right<<setw(2)<<(i+1)<<')'<<setw(8)<<" "
            <<left<<setw(20)<<libro.estudiantes[i].carne<<right<<setfill('0')
            <<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aa<<left<<setfill(' ')<<setw(10)<<" ";
        if(libro.estudiantes[i].deuda == true) arch<<"Deuda"<<endl;
        else arch<<endl;
    }
    
    imprimirLinea('-',100,arch);
    arch<<"ADMINISTRATIVOS:"<<endl;
    imprimirLinea('-',100,arch);
    
    arch<<left<<setw(10)<<"No."<<setw(20)
        <<"Carne"<<setw(20)<<"Fecha de retiro"<<setw(20)<<"Observacion"<<endl;
    
    for (int i = 0; i < libro.cantAdm; i++){
        fecha = libro.administrativos[i].fechaDeRetiro;
        aa = fecha / 10000;
        fecha = fecha % 10000;
        mm = fecha/100;
        dd = fecha % 100;
        
        arch<<right<<setw(2)<<(i+1)<<')'<<setw(8)<<" "
            <<left<<setw(20)<<libro.administrativos[i].carne<<right<<setfill('0')
            <<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<aa<<left<<setfill(' ')<<setw(10)<<" ";
        if(libro.administrativos[i].deuda == true) arch<<"Deuda"<<endl;
        else arch<<endl;
    }
    
    imprimirLinea('=',100,arch);
}

void imprimirLinea(char car, int cantidad, ofstream &arch){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}


