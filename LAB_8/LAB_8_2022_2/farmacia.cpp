/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   farmacia.cpp
 * Author: Sebastian
 * 
 * Created on 9 de junio de 2023, 21:46
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "farmacia.h"

void farmacia::cargamedico(){
    ifstream archMedicos("medicos.csv",ios::in);
    if(not archMedicos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo medicos.csv"<<endl;
        exit(1);
    }
    int cod,numMedicos = 0;
    char nomb[100],espec[100];
    while(true){
        archMedicos>>cod;
        if(archMedicos.eof()) break;
        archMedicos.get();
        archMedicos.getline(nomb,100,',');
        archMedicos.getline(espec,100);
        lmedico[numMedicos].SetCodigo(cod);
        lmedico[numMedicos].SetNombre(nomb);
        lmedico[numMedicos].SetEspecialidad(espec);
        numMedicos++;
    }
    lmedico[numMedicos].SetCodigo(0);
}

void farmacia::leerecetas(){
    ifstream archRecetas("recetas.csv",ios::in);
    if(not archRecetas.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo recetas.csv"<<endl;
        exit(1);
    }
    int dd,mm,aa,dni,codMedico,medicamento,cantidad,numSinReceta = 0,numConReceta = 0;
    char nomb[100],car,espec[100],nombMed[100];
    double precio;
    while(true){
        archRecetas>>dd;
        if(archRecetas.eof()) break;
        archRecetas>>car>>mm>>car>>aa>>car>>dni>>car;
        int fecha = aa * 10000 + mm * 100 + dd;
        archRecetas.getline(nomb,100,',');
        archRecetas>>codMedico>>car;
        while(true){
            archRecetas>>medicamento>>car>>cantidad;
            if((medicamento/10000) % 2 ==0)//par
                asignarConReceta(codMedico,espec,medicamento,nombMed,precio,cantidad,fecha,numConReceta);
            else//impar
                asignarSinReceta(dni,nomb,medicamento,nombMed,precio,cantidad,fecha,numSinReceta);
            if(archRecetas.get() == '\n') break;
        }
    }
    lsinreceta[numSinReceta].SetDni(0);
    lconreceta[numConReceta].SetCodmed(0);
}

void farmacia::asignarConReceta(int codMedico,char *espec,int medicamento, char *nombMed,
                                double precio,int cantidad,int fecha,int &numConReceta){
    lconreceta[numConReceta].SetCodmed(codMedico);
    if(buscarEspecialidad(codMedico,espec)) lconreceta[numConReceta].SetEspecialidad(espec);
    if(buscarMedicamento(medicamento,nombMed,precio)){
        lconreceta[numConReceta].SetCodigo(medicamento);
        lconreceta[numConReceta].SetNombre(nombMed);
        lconreceta[numConReceta].SetPrecio(precio);
        lconreceta[numConReceta].SetCantidad(cantidad);
        lconreceta[numConReceta].SetFecha(fecha);
    }
    numConReceta++;
}
    
void farmacia::asignarSinReceta(int dni,char *nomb,int medicamento, char *nombMed,
                                double precio,int cantidad,int fecha,int &numSinReceta){
    lsinreceta[numSinReceta].SetDni(dni);
    lsinreceta[numSinReceta].SetNombre(nomb);
    if(buscarMedicamento(medicamento,nombMed,precio)){
        lsinreceta[numSinReceta].SetCodigo(medicamento);
        lsinreceta[numSinReceta].medicamento::SetNombre(nombMed);
        lsinreceta[numSinReceta].SetPrecio(precio);
        lsinreceta[numSinReceta].SetCantidad(cantidad);
        lsinreceta[numSinReceta].SetFecha(fecha);
    }
    numSinReceta++;
}

int farmacia::buscarMedicamento(int cod,char *nomMedicamento,double &precio){
    ifstream archMedicamentos("medicamentos.csv",ios::in);
    if(not archMedicamentos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo medicamentos.csv"<<endl;
        exit(1);
    }
    int codMedicamento;
    while(true){
        archMedicamentos>>codMedicamento;
        if(archMedicamentos.eof()) break;
        archMedicamentos.get();
        archMedicamentos.getline(nomMedicamento,100,',');
        archMedicamentos>>precio;
        if(codMedicamento == cod) return 1;
    }
    return 0;
}

int farmacia::buscarEspecialidad(int cod, char *espec){
    for (int i = 0; lmedico[i].GetCodigo(); i++)
        if(cod == lmedico[i].GetCodigo()) {
            lmedico[i].GetEspecialidad(espec);
            return 1;
        }
    return 0;
}

void farmacia::imprimirrecetas(){
    ofstream archReporte("Reporte.txt",ios::out);
    if(not archReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Reporte.txt"<<endl;
        exit(1);
    }
    char nombreMedicamento[100],nombOEspec[100];
    archReporte<<left<<setw(10)<<"Codigo"<<setw(57)<<"Descripcion del Med."<<setw(10)
            <<"Cant."<<setw(15)<<"DNI"<<"Nombre"<<endl;
    imprimeLinea(archReporte,108,'=');
    for (int i = 0; lsinreceta[i].GetDni(); i++) {
        lsinreceta[i].medicamento::GetNombre(nombreMedicamento);
        lsinreceta[i].GetNombre(nombOEspec);
        archReporte<<left<<setw(10)<<lsinreceta[i].GetCodigo()<<setw(50)<<nombreMedicamento
                   <<right<<setw(10)<<lsinreceta[i].GetCantidad()<<left<<"    "
                   <<setw(15)<<lsinreceta[i].GetDni()<<nombOEspec<<endl;
    }
    archReporte<<endl<<endl;
    archReporte<<left<<setw(10)<<"Codigo"<<setw(57)<<"Descripcion del Med."<<setw(6)
            <<"Cant."<<setw(15)<<"Cod. Medico"<<"Especialidad"<<endl;
    imprimeLinea(archReporte,108,'=');
    for (int i = 0; lconreceta[i].GetCodmed(); i++) {
        lconreceta[i].GetNombre(nombreMedicamento);
        lconreceta[i].GetEspecialidad(nombOEspec);
        archReporte<<left<<setw(10)<<lconreceta[i].GetCodigo()<<setw(50)<<nombreMedicamento
                   <<right<<setw(10)<<lconreceta[i].GetCantidad()<<left<<"    "
                   <<setw(15)<<lconreceta[i].GetCodmed()<<nombOEspec<<endl;
    }
}

void farmacia::imprimeLinea(ofstream &arch,int cantidad, char car){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}
