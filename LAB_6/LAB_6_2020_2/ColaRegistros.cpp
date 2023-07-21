/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "ColaRegistros.h"

void *leeregistro(ifstream &arch){
    int *dni = new int,*codigo = new int,dato;
    char *nombre,car,*tipo = new char;
    arch>>dato;
    if(arch.eof()) return nullptr;
    arch.get();
    *dni = dato;
    nombre = leecadena(arch);
    arch>>*tipo>>car>>*codigo;
    if(*tipo == 'A'){
        double *porcentaje = new double;
        arch>>car>>*porcentaje;
        void **registro = new void *[5];
        registro[0] = dni;
        registro[1] = nombre;
        registro[2] = tipo;
        registro[3] = codigo;
        registro[4] = porcentaje;
        arch.get();
        return registro;
    }else if(*tipo == 'U'){
        double *porcentaje = new double;
        double *porcentajeAdicional = new double;
        arch>>car>>*porcentaje>>car>>*porcentajeAdicional;
        void **registro = new void *[6];
        registro[0] = dni;
        registro[1] = nombre;
        registro[2] = tipo;
        registro[3] = codigo;
        registro[4] = porcentaje;
        registro[5] = porcentajeAdicional;
        arch.get();
        return registro;
    }else if(*tipo == 'E'){
        void **registro = new void *[4];
        registro[0] = dni;
        registro[1] = nombre;
        registro[2] = tipo;
        registro[3] = codigo;
        arch.get();
        return registro;
    }
}

char *leecadena(ifstream &arch){
    char *aux, buff[200];
    arch.getline(buff,200,',');
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

int prioridadregistro(void *reg){
    void **registro = (void **)reg;
    char *tipo = (char *)registro[2];
    if(*tipo == 'A') return  1;
    else if(*tipo == 'U') return 2;
    else if(*tipo == 'E') return 3;
}

void imprimeregistro(void *reg,ofstream &arch){
    void **registro = (void **)reg;
    int *dni = (int *)registro[0];
    char *nombre = (char *)registro[1];
    char *tipo = (char *)registro[2];
    int *codigo = (int *)registro[3];
    double pago = 0.0;
    double tarifa;
    arch<<left<<setw(10)<<*dni<<setw(60)<<nombre<<setw(10)<<*codigo;
    if(*tipo == 'A'){
        double *porcentaje = (double *)registro[4];
        if(existeMedico(*codigo,"Tarifas.txt",tarifa))
            pago = tarifa * (*porcentaje)/100;
        arch<<right<<setw(10)<<pago<<left<<setw(5)<<" "<<"Ambulatorio"<<endl;
    }else if(*tipo == 'U'){
        double *porcentaje = (double *)registro[4];
        double *porcentajeAdicional = (double *)registro[5];
        if(existeMedico(*codigo,"Tarifas.txt",tarifa))
            pago = tarifa * (*porcentaje + *porcentajeAdicional)/100;
        arch<<right<<setw(10)<<pago<<left<<setw(5)<<" "<<"Urgencia"<<endl;
    }else if(*tipo == 'E')
        arch<<right<<setw(10)<<pago<<left<<setw(5)<<" "<<"Emergencia"<<endl;
}

int existeMedico(int codigo, const char *nombArch,double &tarifa){
    ifstream arch(nombArch,ios::in);
    int cod;
    double tar;
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch>>tar;
        if(cod == codigo){
            tarifa = tar;
            return 1;
        }
    }
    return 0;
}

void imprimirLinea(char car, int cantidad, ofstream &arch){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}

