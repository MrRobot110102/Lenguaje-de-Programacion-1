/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include <cstring>
#include "StConductor.h"
#include "StFalta.h"
#include "StInfraccion.h"
#include "StInfraccionEstab.h"
#include "operadoresSobrecargados.h"
#define MAX_LINEA 120

bool operator >>(ifstream &arch,TconductorSt &conductor){
    arch>>conductor.licencia;
    if(arch.eof()) return false;
    arch>>conductor.nombre;
    conductor.numFaltas = 0;
    conductor.numFaltasLeves = 0;
    conductor.numFaltasGraves = 0;
    conductor.numFaltasMuyGraves = 0;
    conductor.montoFaltasLeves = 0.0;
    conductor.montoFaltasGraves = 0.0;
    conductor.montoFaltasMuyGraves = 0.0;
    return true;
}

bool operator >>(ifstream &arch,TInfraccionSt &infraccion){
    int dd,mm,aa;
    char car;
    arch>>infraccion.licencia;
    if(arch.eof()) return false;
    arch>>infraccion.placa;
    arch>>dd>>car>>mm>>car>>aa;
    infraccion.fecha = aa * 10000 + mm * 100 + dd;
    arch>>infraccion.codInf;
    return true;
}

void darformato(char *gravedad){
    int i=0;
    while(gravedad[i]){
        if(gravedad[i] == '_') gravedad[i] = ' ';
        else if(gravedad[i] >= 'a' and gravedad[i] <= 'z') gravedad[i] = gravedad[i] - ('a'-'A');
        i++;
    }
}

bool operator >>(ifstream &arch,TInfraccionEstabSt &infraccionEstab){
    char desc[250];
    arch>>infraccionEstab.codigo;
    if(arch.eof()) return false;
    arch>>desc>>infraccionEstab.gravedad>>infraccionEstab.multa;
    darformato(infraccionEstab.gravedad);
    return true;
}

void operator +(TconductorSt &conductor,const TInfraccionSt &infraccion){
    if(conductor.licencia == infraccion.licencia){
        conductor.faltas[conductor.numFaltas].codInf = infraccion.codInf;
        conductor.faltas[conductor.numFaltas].fecha = infraccion.fecha;
        strcpy(conductor.faltas[conductor.numFaltas].placa,infraccion.placa);
        conductor.numFaltas++;
    }
}

void operator +(TconductorSt &conductor,const TInfraccionEstabSt &infraccionEstab){
    for (int i = 0; i < conductor.numFaltas; i++) {
        if(conductor.faltas[i].codInf == infraccionEstab.codigo){
            strcpy(conductor.faltas[i].gravedad,infraccionEstab.gravedad);
            conductor.faltas[i].multa = infraccionEstab.multa;
        }
    }
}

void operator ++(TconductorSt  &conductor){
    conductor.numFaltasLeves = 0;
    conductor.numFaltasGraves = 0;
    conductor.numFaltasMuyGraves = 0;
    conductor.montoFaltasLeves = 0.0;
    conductor.montoFaltasGraves = 0.0;
    conductor.montoFaltasMuyGraves = 0.0;
    for (int i = 0; i < conductor.numFaltas; i++) {
        if(strcmp(conductor.faltas[i].gravedad,"LEVE") == 0){
            conductor.numFaltasLeves++;
            conductor.montoFaltasLeves += conductor.faltas[i].multa;
        }
        else if(strcmp(conductor.faltas[i].gravedad,"GRAVE") == 0){
            conductor.numFaltasGraves++;
            conductor.montoFaltasGraves += conductor.faltas[i].multa;
        }
        else if(strcmp(conductor.faltas[i].gravedad,"MUY GRAVE") == 0){
            conductor.numFaltasMuyGraves++;
            conductor.montoFaltasMuyGraves+= conductor.faltas[i].multa;
        }
    }
}

void operator *(TconductorSt &conductor, const int fecha){
    for (int i = 0; i < conductor.numFaltas; i++) {
        if(conductor.faltas[i].fecha < fecha){
            if(strcmp(conductor.faltas[i].gravedad,"LEVE") == 0){
                eliminarInfraccion(conductor,i);
                i--;
            }
            else if(strcmp(conductor.faltas[i].gravedad,"GRAVE") == 0)
                conductor.faltas[i].multa *= 0.75;
            else if(strcmp(conductor.faltas[i].gravedad,"MUY GRAVE") == 0)
                conductor.faltas[i].multa *= 0.92;
        }
    }
    
}

void eliminarInfraccion(TconductorSt &conductor,const int posicion){
    for (int i = posicion; i < conductor.numFaltas-1; i++) {
        conductor.faltas[i] = conductor.faltas[i+1];
    }
    conductor.numFaltas--;
    conductor.numFaltasLeves--;

}

ofstream & operator<<(ofstream &arch,const TconductorSt &conductor){
    int dd,mm,aa,fechaAux;
    
    arch.precision(2);arch<<fixed;

    arch<<"Conductor: "<<conductor.nombre<<endl;
    arch<<"Licencia No.: "<<conductor.licencia<<endl;
    imprimirLinea('=',MAX_LINEA,arch);
    arch<<"Infracciones cometidas: "<<endl;
    imprimirLinea('-',MAX_LINEA,arch);
    arch<<"No."<<setw(15)<<"Fecha"<<setw(20)<<"Placa"<<setw(20)<<"Infraccion"<<setw(20)<<"Gravedad"<<setw(20)<<"Multa"<<endl;
    for(int i=0;i<conductor.numFaltas;i++){
        aa=conductor.faltas[i].fecha/10000;
        fechaAux=conductor.faltas[i].fecha%10000;
        mm=fechaAux/100;
        dd=fechaAux%100;
        arch<<setw(2)<<i+1<<")"<<setw(10)<<" "<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<aa<<setfill(' ')<<setw(17)<<conductor.faltas[i].placa
                <<setw(14)<<conductor.faltas[i].codInf<<setw(17)<<" "<<left<<setw(20)<<conductor.faltas[i].gravedad<<right<<setw(8)<<conductor.faltas[i].multa<<endl;
    }
    imprimirLinea('=',MAX_LINEA,arch);
    arch<<setw(35)<<"Cantidad"<<setw(15)<<"Total"<<endl;
    arch<<left<<setw(25)<<"Infracciones leves: "<<right<<setw(8)<<conductor.numFaltasLeves<<setw(17)<<conductor.montoFaltasLeves<<endl;
    arch<<left<<setw(25)<<"Infracciones graves: "<<right<<setw(8)<<conductor.numFaltasGraves<<setw(17)<<conductor.montoFaltasGraves<<endl;
    arch<<left<<setw(25)<<"Infracciones muy graves: "<<right<<setw(8)<<conductor.numFaltasMuyGraves<<setw(17)<<conductor.montoFaltasMuyGraves<<endl;
    imprimirLinea('=',MAX_LINEA,arch);
    return arch;
}

void imprimirLinea(char car, int cantidad, ofstream &arch){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}