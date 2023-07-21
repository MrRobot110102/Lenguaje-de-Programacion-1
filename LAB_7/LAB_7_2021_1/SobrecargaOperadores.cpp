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
#include "Conductor.h"
#include "FaltaCond.h"
#include "Falta.h"
#include "Infraccion.h"

ifstream & operator >>(ifstream &arch,class Conductor &conductor){
    int licencia;
    char nomb[300];
    arch>>licencia;
    if(arch.eof()) return arch;
    arch.get();
    arch.getline(nomb,300);
    conductor.SetLicencia(licencia);
    conductor.SetNombre(nomb);
    return arch;
}

ifstream & operator >>(ifstream &arch,class Falta &falta){
    int licencia,dd,mm,aa,codInfrac;
    char plac[10],car;
    arch>>licencia;
    if(arch.eof()) return arch;
    arch.get();
    arch.getline(plac,10,',');
    arch>>dd>>car>>mm>>car>>aa>>car>>codInfrac;
    int fecha = aa * 10000 + mm * 100 + dd;
    falta.SetLicencia(licencia);
    falta.SetPlaca(plac);
    falta.SetFecha(fecha);
    falta.SetCodInf(codInfrac);
    return arch;
}

ifstream & operator >>(ifstream &arch,class Infraccion &infraccion){
    int codigo;
    char desc[500],grav[15];
    double multa;
    arch>>codigo;
    if(arch.eof()) return arch;
    arch.get();
    arch.getline(desc,500,',');
    arch.getline(grav,15,',');
    arch>>multa;
    infraccion.SetCodigo(codigo);
    infraccion.SetDescripcion(desc);
    infraccion.SetGravedad(grav);
    infraccion.SetMulta(multa);
    return arch;
}

ofstream & operator <<(ofstream &arch,const class Conductor &conductor){
    arch.precision(2);arch<<fixed;
    char nomb[300];
    conductor.GetNombre(nomb);
    arch<<left<<"Conductor:   "<<nomb<<endl;
    arch<<left<<"Licencia No.:"<<conductor.GetLicencia()<<endl;
    imprimirLinea(arch,74,'=');
    arch<<"Infracciones cometidas:"<<endl;
    imprimirLinea(arch,74,'-');
    conductor.imprimeFaltas(arch);
    imprimirLinea(arch,74,'=');
    arch<<right<<setw(35)<<"Cantidad"<<setw(15)<<"Total"<<endl;
    arch<<left<<"Total de infracciones:"<<right<<setw(10)<<conductor.GetNumFaltas()
        <<setw(19)<<conductor.GetMontoTotal()<<endl;
    imprimirLinea(arch,74,'=');
}

ofstream & operator <<(ofstream &arch,const class Falta &falta){
    arch.precision(2);arch<<fixed;
    char plac[15];
    int fech,dd,mm,aa;
    fech = falta.GetFecha();
    aa = fech/10000;
    fech %= 10000;
    mm = fech/100;
    dd = fech%100;
    falta.GetPlaca(plac);
    arch<<left<<setw(15)<<falta.GetLicencia()<<setw(15)<<plac<<setfill('0')<<right<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa
        <<setfill(' ')<<"   "<<left<<setw(15)<<falta.GetCodInf()<<endl;
}

ofstream & operator <<(ofstream &arch,const class FaltaCond &falta){
    arch.precision(2);arch<<fixed;
    char plac[15],grav[15];
    int fech,dd,mm,aa;
    fech = falta.GetFecha();
    aa = fech/10000;
    fech %= 10000;
    mm = fech/100;
    dd = fech%100;
    falta.GetPlaca(plac);
    falta.GetGravedad(grav);
    arch<<setfill('0')<<right<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa
        <<setfill(' ')<<"   "<<left<<setw(15)<<plac<<setw(15)<<falta.GetCodInf()<<setw(15)<<grav<<right<<setw(10)<<falta.GetMulta()<<left<<endl;
}

void imprimirLinea(ofstream &arch, int cantidad, char car){
    for (int i = 0; i < cantidad; i++) arch<<car;
    arch<<endl;
}

int buscarConductor(class Conductor *conductores,int licencia){
    for(int i=0; conductores[i].GetLicencia(); i++) if (licencia == conductores[i].GetLicencia()) return i;
    return -1;
}