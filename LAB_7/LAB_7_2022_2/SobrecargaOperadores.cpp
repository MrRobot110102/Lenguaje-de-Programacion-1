    /*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>  
using namespace std;
#include "SobrecargaOperadores.h"
#include "medico.h"
#include "cita.h"
#include "paciente.h"

ifstream & operator >>(ifstream &arch, class medico &med){
    int codigo;
    char nomb[300];
    double tarifa;  
    arch>>codigo;
    if(arch.eof()) return arch;
    arch.get();
    arch.getline(nomb,300,',');
    arch>>tarifa;
    med.SetCodigo(codigo);
    med.SetNombre(nomb);
    med.SetTarifa(tarifa);
    return arch;
}

ifstream &operator >>(ifstream &arch,class paciente &pac){
    int dni,telefono;
    char nomb[100];
    arch>>dni;
    if(arch.eof()) return arch;
    arch.get();
    arch.getline(nomb,100,',');
    arch>>telefono;
    pac.SetDni(dni);
    pac.SetNombre(nomb);
    pac.SetTelefono(telefono);
    return arch;
}

ifstream &operator >>(ifstream &arch,class cita &cit){
    int dni,codigo,dd,mm,aa;
    char car;
    arch>>dni;
    if(arch.eof()) return arch;
    arch.get();
    arch>>codigo;
    arch.get();
    arch>>dd>>car>>mm>>car>>aa;
    int fecha = aa * 10000 + mm * 100 + dd;
    cit.SetDni(dni);
    cit.SetCodigo(codigo);
    cit.SetFecha(fecha);
    return arch;
}

ofstream & operator <<(ofstream &arch,const class medico &med){
    char nomb[300];
    arch.precision(2);arch<<fixed;
    med.GetNombre(nomb);
    arch<<left<<setw(25)<<med.GetCodigo()<<setw(50)<<nomb<<right<<setw(10)<<med.GetTarifa()<<endl;  
}

ofstream & operator <<(ofstream &arch,const class paciente &pac){
    char nomb[200];
    arch.precision(2);arch<<fixed;
    pac.GetNombre(nomb);
    arch<<left<<setw(25)<<"DNI"<<setw(25)<<"NOMBRE"<<"TELEFONO"<<endl;
    arch<<left<<setw(25)<<pac.GetDni()<<setw(25)<<nomb<<pac.GetTelefono()<<endl;
    arch<<"RELACION DE CITAS"<<endl;
    arch<<left<<setw(6)<<"No."<<setw(19)<<"FECHA"<<setw(25)<<"CODIGO DEL MEDICO"<<"TARIFA"<<endl;
    pac.imprimeCitas(arch);
    arch<<"MONTO TOTAL GASTADO:"<<pac.GetTotalgastado()<<endl;
}

ofstream & operator <<(ofstream &arch,const class cita &cit){
    arch.precision(2);arch<<fixed;
    int fech,dd,mm,aa;
    fech = cit.GetFecha();
    aa = fech/10000;
    fech %= 10000;
    mm = fech/100;
    dd = fech%100;
    arch<<setfill('0')<<right<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa
        <<setfill(' ')<<setw(15)<<left<<"   "<<cit.GetCodigo()<<right<<setw(19)<<cit.GetTarifa()<<endl;
}


