/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"
#include "PunterosGenericos.h"
enum EMedicina {COD,NOM,PRE,STO,RES};

void cargaMedicinas(void *&medicinas){
    ifstream archMedicinas("Medicinas.csv",ios::in);
    void *buffMedicinas[300], **medicina;
    int numDatos = 0;
    while(true){
        buffMedicinas[numDatos] = leerRegistro(archMedicinas);
        if(buffMedicinas[numDatos] == nullptr) break;
        numDatos++;
    }
    medicina = new void*[numDatos+1]{};
    for (int i = 0; i < numDatos; i++) medicina[i] = buffMedicinas[i];
    medicinas = medicina;
    imprimemedicinas(medicinas);
}

void *leerRegistro(ifstream &arch){
    void **registro;
    int *codigo,cod,*stock,*reserva;
    char *nombre;
    double *precio;
    codigo = new int;
    stock = new int;
    reserva = new int;
    precio = new double;
    arch>>cod;
    if(arch.eof()) return nullptr;
    arch.get();
    nombre = leerCadena(arch);
    arch>>*precio;
    arch.get();
    arch>>*stock;
    *codigo = cod;
    *reserva = 0;
    registro = new void*[5];
    
    registro[COD] = codigo;
    registro[NOM] = nombre;
    registro[PRE] = precio;
    registro[STO] = stock;
    registro[RES] = reserva;
    
    return registro; 
}

char *leerCadena(ifstream &arch){
    char *aux,buff[200];
    arch.getline(buff,200,',');
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

void cargaConsultas(void *&citas){
    ifstream archConsultas("Consultas.csv",ios::in);
    if(not archConsultas.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Consultas.csv"<<endl;
        exit(1);
    }
    void *buffConsultas[300], **consultas;
    int numDatos = 0;
    
    while (true) {
        buffConsultas[numDatos] = leerConsulta(archConsultas);
        if(buffConsultas[numDatos] == nullptr) break;
        numDatos++;
    }
    consultas = new void*[numDatos+1]{};
    for (int i = 0; i < numDatos; i++) consultas[i] = buffConsultas[i];
    citas = consultas;
    imprimeconsultas(citas);
}

void *leerConsulta(ifstream &archConsultas){
    int dniPaciente,*dni,*cantidad,*fecha,dd,mm,aa;
    char *nombre,cod[10],car;
    void **registro;
    archConsultas.getline(cod,10,',');
    if(archConsultas.eof()) return nullptr;
    dni = new int;
    archConsultas>>*dni;
    archConsultas.get();
    nombre = leerCadena(archConsultas);
    archConsultas>>dd>>car>>mm>>car>>aa>>car;
    fecha = new int;
    *fecha = aa * 10000 + mm * 100 + dd;
    cantidad = new int;
    archConsultas>>*cantidad>>car;
    registro = new void*[5];
    registro[0] = dni;
    registro[1] = nombre;
    registro[2] = cantidad;
    registro[3] = cargarMedicamentos(archConsultas,*cantidad);
    registro[4] = fecha;
    return registro;
}

void *cargarMedicamentos(ifstream &arch, int cantidad){
    void **detalleMedicina, **medicinas;
    int *codMedicina,*cantSolicitada;
    char *estado,car;
    if(cantidad == 0) return nullptr;
    medicinas = new void*[cantidad]{};
    for (int i = 0; i < cantidad; i++) {
        detalleMedicina = new void*[3];
        codMedicina = new int;
        cantSolicitada = new int;
        estado = new char;
        arch>>*codMedicina>>car>>*cantSolicitada;
        arch.get();
        *estado = 'S';
        detalleMedicina[0] = codMedicina;
        detalleMedicina[1] = cantSolicitada;
        detalleMedicina[2] = estado;
        medicinas[i] = detalleMedicina;
    }
    return medicinas;
}
    
void actualizarReservas(void *&med,void *&cit){
    ordenareservas(cit);
    void **citas = (void **)cit;
    for (int i = 0; citas[i]; i++) actualizarCitas(citas[i],med);
}

void actualizarCitas(void *&cit,void *&med){
    void **citas = (void **)cit;
    int *cantidad = (int *)citas[2];
    int *fecha = (int *)citas[4];
    
    cout<<*fecha<<" "<<*cantidad<<endl;
    actualizar(*cantidad,citas[3],med);
}

void actualizar(int cantidad, void *&cit, void *&med){
    void **citas = (void **)cit;
    for (int i = 0; i < cantidad; i++) {
        actualizarMedicamento(citas[i],med);
    }
}

void actualizarMedicamento(void *&cit,void *&med){
    void **citas = (void **)cit;
    int *codMedicamento = (int *)citas[0];
    int *cantidadSolicitada = (int *)citas[1];
    char *estado = (char *)citas[2];
    int *stock, *reserva;
    int posMedicamento = obtenerPosicionMedicamento(med,*codMedicamento,stock,reserva);
    if(posMedicamento != -1 and ((*stock) >= (*cantidadSolicitada))){
        (*reserva) += (*cantidadSolicitada);
        (*stock) -= (*cantidadSolicitada);
        *estado = 'R';
    }
}

int obtenerPosicionMedicamento(void *med, int codMedicamento,int *&stock,int *&reserva){
    void **medicinas = (void **)med;
    for (int i = 0; medicinas[i]; i++) {
        if(compararMedicinas(medicinas[i],codMedicamento,stock,reserva)) return i;
    }
    return -1;
}

int compararMedicinas(void *med,int codMedicamento, int *&stock,int *&reserva){
    void **medicinas = (void **)med;
    int *codigoMedicina = (int *)medicinas[0];
    stock = (int *)medicinas[3];
    reserva = (int *)medicinas[4];
    if(*codigoMedicina == codMedicamento) return 1;
    else return 0;
}



