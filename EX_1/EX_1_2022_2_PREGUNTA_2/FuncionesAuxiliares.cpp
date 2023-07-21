/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncionesAuxiliares.cpp
 * Author: cueva
 * 
 * Created on 8 de octubre de 2022, 09:46 PM
 */


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "FuncionesAuxiliares.h"

using namespace std;

void implinea(ofstream &arch,char c,int n){
    int i;
    for(i=0;i<n;i++)
        arch.put(c);
    arch << endl;
}

void imprimelinea(ofstream &arch,void*linea,int n){
    void **llinea = (void**)linea;
    int i,*cant,*codigo;
    char *estado;
    
    for(i=0;i<n;i++){
        void**reg=(void**)llinea[i];
        codigo=(int*)reg[0];
        cant=(int*)reg[1];
        estado=(char*)reg[2];
        arch << setw(2) << i+1<<setw(10)<<*codigo<<setw(5)<<*cant
                <<setw(2)<<*estado<<endl; 
        
    }
    arch << endl;    
}


void imprimecitareg(ofstream &arch,void *registro){
    void **laux = (void**)registro;
    char *nombre;
    int *dni,*fecha,*cant;
    double *precio;
   
    dni = (int*)laux[0];
    nombre = (char*)laux[1];
    cant = (int*)laux[2];
    fecha = (int*)laux[4];

    arch <<left<<setw(20)<< *dni << setw(50)<< nombre << 
        setw(10)<< *fecha<<setw(5)<<*cant<<endl;
    
    imprimelinea(arch,laux[3],*cant);
}


void imprimeconsultas(void *consultas){
    int i=0;
    void **laux = (void**)consultas;
    ofstream arch("repconsultas.txt",ios::out);
    if(!arch){
        cout << "No se puede leer";
        exit(1);
    }

    while(1){
        if(laux[i]==NULL) break; 
        imprimecitareg(arch,laux[i]);
        i++;
    }
      
}


void imprimeprodreg(ofstream &arch,void *registro){
    void **laux = (void**)registro;
    char *nombre;
    int *codigo,*cantidad,*reserva;
    double *precio;
   
    codigo = (int*)laux[0];
    nombre = (char*)laux[1];
    precio = (double*)laux[2];
    cantidad = (int*)laux[3];
    reserva = (int*)laux[4];
    
    arch <<left<<setw(20)<< *codigo << setw(50)<< nombre << 
        setw(10)<<setprecision(2)<<fixed<< *precio <<
        setw(10)<< *cantidad<<setw(10)<<*reserva<<endl;
    
}

void imprimemedicinas(void *medicinas){
    int i=0;
    void **laux = (void**)medicinas;
    ofstream arch("repmedicinas.txt",ios::out);
    if(!arch){
        cout << "No se puede leer el archivo de medicinas";
        exit(1);
    }

    while(1){
        if(laux[i]==NULL) break; 
        imprimeprodreg(arch,laux[i]);
        i++;
    }
      
}

void imprimedetalle(ofstream &arch,void *registro){
    void **laux = (void**)registro;    
    char *estado;
    int *codigo,*cantidad;
    int i=0;
   
    codigo = (int*)laux[0];
    cantidad = (int*)laux[1];
    estado = (char*)laux[2];
    
    if(*estado=='R')
        arch<<left <<setw(10)<<*codigo<<
                setw(10)<< *cantidad <<setw(10)<<"Reservado"<< endl;
    else
        arch<<left <<setw(10)<<*codigo<<
                setw(10)<< *cantidad <<setw(10)<<"Solicitado"<< endl;
}

void imprimepedcab(ofstream &arch,void *registro){
    void **laux = (void**)registro;
    char *nombre,*estado;
    int *codigo,*dni,*fecha,*cantidad,*n,aa,mm,dd;
    int i=0;
   
    
    codigo = (int*)laux[0];
    nombre = (char*)laux[1];
    n = (int*)laux[2];
    fecha = (int*)laux[4];
    implinea(arch,'=',100);
    aa=(*fecha)/10000;
    mm=((*fecha)%10000)/100;
    dd=(*fecha)%100;
    arch <<left<<setw(12)<<"Fecha"<<setw(30)<< "DNI" << setw(50)<< "Nombre" << endl;
    arch <<right<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<aa<<setfill(' ')<<left<<"  "<<setw(30)<< *codigo << setw(50)<< nombre << endl;
    implinea(arch,'-',100);
    arch <<"Medicinas Solicitadas:"<<endl;
    implinea(arch,'-',100);
    arch <<left<<setw(10)<<"Codigo" <<
                setw(10)<< "Cantidad" <<
                setw(20)<<"Estado"<< endl;       
    implinea(arch,'-',100);  
    
    void **raux = (void**)laux[3];
    
    for(i=0;i<*n;i++){
        imprimedetalle(arch,raux[i]);
    }
    arch << endl;
}


void imprimerepfinal(void *citas){
    int i=0;
    void **laux = (void**)citas;
    ofstream arch("repfinal.txt",ios::out);
    if(!arch){
        cout << "No se puede leer reporte final";
        exit(1);
    }

    while(1){
        if(laux[i]==NULL) break; 
        imprimepedcab(arch,laux[i]);
        i++;
    }    
    
}

////////////////////////////////////////////////

void cambiar(void *&usI, void *&usK){
    void *aux;
    aux = usI;
    usI = usK;
    usK = aux;
}
int compararc(void *pI, void *pK){
    void **listaI = (void**)pI,**listaK = (void**)pK;
    int *fechaI = (int*)(listaI[4]),*fechaK = (int*)(listaK[4]);
    return (*fechaI-*fechaK);
}

void qsortvoidc(void **lista,int izq,int der){
    int limite;
    if(izq>=der) return;
    cambiar(lista[izq], lista[(izq+der)/2]);
    limite = izq;
    for(int i= izq+1; i<=der;i++)
    if(compararc(lista[i], lista[izq])<0)
        cambiar(lista[++limite], lista[i]);
    cambiar(lista[izq], lista[limite]);
    qsortvoidc(lista,izq, limite-1);
    qsortvoidc(lista,limite+1, der);
}

void ordenareservas(void *reservas){
    void**lped = (void**)reservas;
    int i;
    for(i=0;lped[i];i++);
    qsortvoidc(lped,0,i-1);
}