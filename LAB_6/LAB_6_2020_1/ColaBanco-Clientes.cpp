/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
#include "BibliotecaColaGenerica.h"
#include "ColaBanco-Cliente.h"

void *leeregistro(ifstream &arch){
    void **registro = new void*[4];
    int cod,hh,mm,ss;
    int *codigo = new int;
    int *horaLlegada = new int;
    double *temTranscurrido = new double;
    char *nombre,car;
    arch>>cod;
    if(arch.eof()) return nullptr;
    arch.get();
    *codigo = cod;
    nombre = leerCadena(arch,',');
    arch>>hh>>car>>mm>>car>>ss>>car>>*temTranscurrido;
    *horaLlegada = hh * 10000 + mm * 100 + ss;
    registro[0] = codigo;
    registro[1] = nombre;
    registro[2] = horaLlegada;
    registro[3] = temTranscurrido;
    return registro;
}

char *leerCadena(ifstream &arch,char car){
    char *aux, buff[200];
    arch.getline(buff,200,car);
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

void imprimeregistro(void *reg,ofstream &arch){
    void **registro = (void **)reg;
    int hh,mm,ss,horaLlegada;
    int *codigo = (int *)registro[0];
    int *hora = (int *)registro[2];
    char *nombre = (char *)registro[1];
    double *tiempo = (double *)registro[3];
    horaLlegada = *hora;
    hh = horaLlegada/10000;
    horaLlegada = horaLlegada%10000;
    mm = horaLlegada/100;
    ss = horaLlegada%100;
    arch<<left<<setw(10)<<*codigo<<setw(60)<<nombre;
    arch<<setfill('0')<<setw(2)<<right<<hh<<':'<<setw(2)<<right<<mm<<':'<<setw(2)
            <<right<<ss<<setfill(' ')<<"    ";
    arch<<right<<setw(15)<<*tiempo<<left;
}

void atiendeCola(void *&cola,int hhabierto,int mmabierto,int ssabierto){
    ofstream arch("Reporte.txt",ios::out);
    arch.precision(2);arch<<fixed;
    arch<<"Hora de apertura: "<<setfill('0')<<setw(2)<<right<<hhabierto<<':'<<setw(2)<<right<<mmabierto<<':'<<setw(2)
            <<right<<ssabierto<<setfill(' ')<<endl<<endl<<endl;
    arch<<left<<setw(10)<<"DNI"<<setw(60)<<"NOMBRE"<<setw(20)<<"HORA DE LLEGADA"<<setw(20)<<"TIEMPO DE ESPERA"<<setw(20)<<"HORA DE SALIDA"<<endl;
    imprimeLinea(arch,124,'=');
    int horaSalida = 0,horaApertura = hhabierto*10000 + mmabierto * 100 + ssabierto;
    void *sale;
    while(not colavacia(cola)){
        sale = desencola(cola);
        void **registro = (void **)sale;
        int *horaLlegada = (int *)registro[2];
        double *tiempoTransaccion = (double *)registro[3];
        int horLLegada = horaASegundos(*horaLlegada);
        if(*horaLlegada >= horaApertura){
            if(horaSalida > horLLegada){
                int aux = horaSalida;
                horaSalida = (horaSalida - horLLegada)+horLLegada + round(*tiempoTransaccion);
                *tiempoTransaccion = *tiempoTransaccion + (aux - horLLegada);
            }else horaSalida = horLLegada + round(*tiempoTransaccion);
            imprimeregistro(sale,arch);
            imprimirHoras(horaSalida,arch);
        }
        delete registro;
    }
}

int horaASegundos(int hora){
    int horaAux = hora;
    int hh,mm,ss;
    hh = horaAux/10000;
    horaAux = horaAux%10000;
    mm = horaAux/100;
    ss = horaAux%100;
    return hh * 3600 + mm * 60 + ss;
}

void imprimirHoras(int totalSegundos,ofstream &arch){
    int horas = totalSegundos / 3600;
    totalSegundos %= 3600;
    int minutos = totalSegundos / 60;
    int segundos = totalSegundos % 60;
    arch<<left<<setw(15)<<" "<<setfill('0')<<setw(2)<<right<<horas<<':'<<setw(2)<<right<<minutos<<':'<<setw(2)
            <<right<<segundos<<setfill(' ')<<endl;
}

void imprimeLinea(ofstream &arch,int cant, char c){
    for(int i=0;i<cant;i++)arch<<c;
    arch<<endl;
}
