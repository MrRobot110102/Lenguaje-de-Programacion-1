    /*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
#include "Cliente.h"
#include "Pedido.h"
#include "SobrecargaOperadores.h"

ifstream & operator >>(ifstream &arch,class Cliente &cli){
    int dni;
    char nomb[200],categoria;
    arch>>dni;
    if(arch.eof())return arch;
    arch.get();
    arch.getline(nomb,200,',');
    arch>>categoria;
    cli.SetDni(dni);
    cli.SetNombre(nomb);
    cli.SetCategoria(categoria);
    return arch;
}

ifstream & operator >>(ifstream &arch,class Pedido &ped){
    int codigo,cantidad,dni,dd,mm,aa;
    char nomb[200],car;
    double precio;
    arch>>codigo;
    if(arch.eof())return arch;
    arch.get();
    arch.getline(nomb,200,',');
    arch>>cantidad>>car>>precio>>car>>dni>>car>>dd>>car>>mm>>car>>aa;
    ped.SetCodigo(codigo);
    ped.SetNombre(nomb);
    ped.SetCantidad(cantidad);
    ped.SetPrecio(precio);
    ped.SetDni(dni);
    ped.SetFecha(aa * 10000 + mm * 100 + dd);
    return arch;
}

ofstream & operator <<(ofstream &arch,const class Cliente &cli){
    char nomb[200];
    arch.precision(2);arch<<fixed;
    cli.GetNombre(nomb);
    arch<<left<<setw(25)<<cli.GetDni()<<setw(50)<<nomb<<cli.GetCategoria()<<endl;
    cli.imprimeLinea(arch,100,'=');
    cli.imprimeProductos(arch);
    arch<<left<<"# de pedidos:"<<right<<setw(7)<<cli.GetNumped()<<endl;
    arch<<left<<"Monto Total: "<<right<<setw(10)<<cli.GetTotal()<<endl;
}

ofstream & operator <<(ofstream &arch,const class Pedido &ped){
    arch.precision(2);arch<<fixed;
    int fech,dd,mm,aa;
    char nomb[100];
    fech = ped.GetFecha();
    ped.GetNombre(nomb);
    fech = ped.GetFecha();
    aa = fech/10000;
    fech %= 10000;
    mm = fech/100;
    dd = fech%100;
    arch<<setfill('0')<<right<<setw(2)<<dd<<'/'<<setw(2)<<mm<<'/'<<setw(4)<<aa
        <<setfill(' ')<<setw(10)<<ped.GetCodigo()<<" "<<left<<setw(40)
        <<nomb<<right<<setw(10)<<ped.GetCantidad()<<setw(10)<<ped.GetPrecio()<<endl;
}

