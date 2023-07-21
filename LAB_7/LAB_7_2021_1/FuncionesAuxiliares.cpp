/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "SobrecargaOperadores.h"
#include  "FuncionesAuxiliares.h"
#include "Conductor.h"
#include "FaltaCond.h"
#include "Falta.h"
#include "Infraccion.h"

void leerConductores(class Conductor *conductores,const char *nombArch){
    ifstream archConductores(nombArch,ios::in);
    if(not archConductores.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int numCoductores = 0;
    while(true){
        archConductores>>conductores[numCoductores];
        if(archConductores.eof()) break;
        numCoductores++;
    }
}
    
void leerFaltasCometidas(class Conductor *conductores,const char *nombArch){
    ifstream archFaltas(nombArch,ios::in);
    if(not archFaltas.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Falta falta;
    while(true){
        archFaltas>>falta;
        if(archFaltas.eof()) break;
        int pos = buscarConductor(conductores,falta.GetLicencia());
        if(pos != -1) conductores[pos] + falta;
    }
}
    
void leerYAsignarInfracciones(class Conductor *conductores,const char *nombArch){
    ifstream archInfracciones(nombArch,ios::in);
    if(not archInfracciones.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Infraccion infraccion;
    while(true){
        archInfracciones>>infraccion;
        if(archInfracciones.eof()) break;
        for (int i = 0; conductores[i].GetLicencia(); i++) conductores[i] + infraccion;
    }
}
    
void calcularMontoTotal(class Conductor *conductores){
    for (int i = 0; conductores[i].GetLicencia(); i++) conductores[i]++;
}
    
void imprimirConductor(class Conductor *conductores,const char *nombArch){
    ofstream archConductoresReporte(nombArch,ios::out);
    if(not archConductoresReporte.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    for (int i = 0; conductores[i].GetLicencia(); i++) archConductoresReporte<<conductores[i];
}
    
void aplicarAmnistia(class Conductor *conductores,int fecha){
    for (int i = 0; conductores[i].GetLicencia(); i++){
        conductores[i]*fecha;
        conductores[i]++;
    }
}