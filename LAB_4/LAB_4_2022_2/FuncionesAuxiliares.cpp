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

void lecturaDeMedicos(const char *nombArch,int *&med_Codigo,char **&med_Nombre,
        char **&med_Especialidad,double *&med_Tarifa){
    int buffCodigo[100],cod,numDatos=0;
    char nombre[100],*buffNombre[100],*buffEspecialidad[100];
    double buffTarifa[100],tarifa;
    ifstream archMedicos(nombArch,ios::in);
    if(not archMedicos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    while(true){
        archMedicos>>cod;
        if(archMedicos.eof()) break;
        archMedicos.get();
        archMedicos.getline(nombre,100,',');
        archMedicos>>tarifa;
        buffCodigo[numDatos] = cod;
        buffEspecialidad[numDatos] = obtenerEspecialidad(nombre);
        buffTarifa[numDatos] = tarifa;
        buffNombre[numDatos] = new char[strlen(nombre) + 1];
        strcpy(buffNombre[numDatos],nombre);
        numDatos++;
    }
    buffCodigo[numDatos] = 0;
    buffNombre[numDatos] = nullptr;
    buffEspecialidad[numDatos] = nullptr;
    buffTarifa[numDatos] = 0;
    numDatos++;
    med_Codigo = new int[numDatos];
    med_Nombre = new char*[numDatos];
    med_Especialidad = new char*[numDatos];
    med_Tarifa = new double[numDatos];
    for (int i = 0; i < numDatos; i++) {
        med_Codigo[i] = buffCodigo[i];
        med_Nombre[i] = buffNombre[i];
        med_Especialidad[i] = buffEspecialidad[i];
        med_Tarifa[i] = buffTarifa[i];
    }
}

char *obtenerEspecialidad(char *nombre){
    char *especialidad,espec[100];
    int aux,i,j=0,k=0;
    int cantidad = strlen(nombre);
    for (i = cantidad-1; i > 0 ; i--) {
        if(nombre[i] == ' '){
            aux = i+1;
            break;
        }else k++;
    }
    while(aux <= cantidad){
        espec[j] = nombre[aux];
        j++;
        aux++;
    }
    especialidad = new char[k+1];
    strcpy(especialidad,espec);
    nombre[i] = nombre[cantidad];
    return especialidad;
}

void pruebaDeLecturaDeMedicos(const char *nombArch,int *med_Codigo,
        char **med_Nombre,char **med_Especialidad,double *med_Tarifa){
    ofstream archReporte(nombArch,ios::out);
    for (int i = 0; med_Codigo[i]; i++) {
        archReporte<<left<<setw(10)<<med_Codigo[i]<<setw(80)<<med_Nombre[i]
                <<setw(30)<<med_Especialidad[i]<<right<<setw(10)<<med_Tarifa[i]<<left<<endl;
    }
}

int buscarPaciente(int *buffDni,int dni,int numDatos){
    for (int i = 0; i < numDatos; i++) if(buffDni[i] == dni) return i;
    return -1;
}
    
void lecturaDeCitas(const char *nombArch,int *&pac_Dni,char **&pac_Nombre,
        int **&pac_Citas){
    int posicionPaciente,dni,buffDni[100], *buffCitas[100],numDatos = 0,numCitas[100]{},codMedico,fecha;
    char *buffNombre[100],*nombre;
    
    ifstream archCitas(nombArch,ios::in);
    for (int i = 0; i<100; i++) buffCitas[i] = new int[50];
    
    while(true){
        archCitas>>dni;
        if(archCitas.eof()) break;
        leerDatos(archCitas,nombre,codMedico,fecha);
        posicionPaciente = buscarPaciente(buffDni,dni,numDatos);
        if(posicionPaciente == -1){//nueva entrada
            buffDni[numDatos] = dni;
            buffNombre[numDatos] = nombre;
            agregarCitas(buffCitas[numDatos],codMedico,fecha,numCitas[numDatos]);
            numDatos++;
        }else{
            agregarCitas(buffCitas[posicionPaciente],codMedico,fecha,numCitas[posicionPaciente]);
        }
    }
    buffDni[numDatos] = 0;
    buffNombre[numDatos] = nullptr;
    numDatos++;
    pac_Dni = new int[numDatos];
    pac_Nombre = new char*[numDatos];
    pac_Citas = new int*[numDatos];
    for (int i = 0; i < numDatos; i++) {
        pac_Dni[i] = buffDni[i];
        pac_Nombre[i] = buffNombre[i];
        agregarCitasPaciente(pac_Citas[i],buffCitas[i],numCitas[i]);
    }
    for (int i = 0; i<100; i++) delete buffCitas[i];
}

void agregarCitasPaciente(int *&pac_Citas,int *&buffCitas,int numCitas){
    if(numCitas == 0){
        delete pac_Citas;
        pac_Citas = nullptr;
    }else{
        pac_Citas = new int[(numCitas*2)+2];
        for (int i = 0; i < numCitas; i++) {
            pac_Citas[2*i] = buffCitas[2*i];
            pac_Citas[(2*i)+1] = buffCitas[(2*i)+1];
        }
        pac_Citas[2*numCitas] = 0;
        pac_Citas[(2*numCitas)+1] = 0;
    }
}
void agregarCitas(int *&buffCitas,int codMedico,int fecha,int &numCitas){
    buffCitas[numCitas*2] = codMedico;
    buffCitas[(numCitas*2) + 1] = fecha;
    numCitas++;
}

void leerDatos(ifstream &arch,char *&nombre,int &codMedico, int &fecha){
    int dd,mm,aa;
    char car;
    arch.get();
    nombre = leerNombre(arch);
    arch>>codMedico>>car>>dd>>car>>mm>>car>>aa;
    fecha = aa * 10000 + mm * 100 + dd;
}

char *leerNombre(ifstream &arch){
    char *aux,nom[100];
    arch.getline(nom,100,',');
    aux = new char[strlen(nom) + 1];
    strcpy(aux,nom);
    return aux;
}
    
void pruebaDeLecturaDeCitas(const char *nombArch,int *pac_Dni,char **pac_Nombre,
        int **pac_Citas){
    ofstream archReporte(nombArch,ios::out);
    for (int i = 0; pac_Dni[i]; i++) {
        archReporte<<left<<setw(10)<<pac_Dni[i]<<setw(50)<<pac_Nombre[i]<<left<<endl;
        imprimirCitas(pac_Citas[i],archReporte);
    }
}

void imprimirCitas(int *pac_Citas,ofstream &arch){
    for(int i=0;pac_Citas[2*i];i++){
        arch<<setw(10)<<left<<pac_Citas[2*i]<<setw(10)<<pac_Citas[2*i+1]<<endl;
    }
}
    
void reporteDeIngresosMedicosYGastosDeLosPacientes(const char *nombArch,
            int *med_Codigo,char **med_Nombre,char **med_Especialidad,
            double *med_Tarifa,int *pac_Dni,char **pac_Nombre,int **pac_Citas){
    
}