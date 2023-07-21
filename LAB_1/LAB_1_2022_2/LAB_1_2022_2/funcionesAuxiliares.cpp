/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include <iomanip>
#include <iostream>
#include <cstring>


using namespace std;

#include "funcionesAuxiliares.h"

int cmpEsp(char *especialidad1, char *especialidad2, char *especialidad, int cantEsp1, int cantEsp2){
    if((strncmp(especialidad1, especialidad, cantEsp1) == 0) or 
        (strncmp(especialidad2, especialidad, cantEsp2) == 0)){
        return 1;
    }else return 0;
}

int cantidadLetras(char *palabra){
    int i=0;
    while(palabra[i]){
        i++;
    }
    return i;
}


void obtenerEspecialidad(char *palabra, char *especialidad,int cantidad){
    int aux,i,j=0;
    for(i=cantidad-1;i>0;i--){
        if(palabra[i] == '_'){
            aux = i+1;
            break;
        }else if(palabra[i] >= 'a' and palabra[i] <= 'z'){
            palabra[i] = palabra[i] - ('a' - 'A');
        }
                 
    }
    while(aux <= cantidad){
        especialidad[j] = palabra[aux];
        j++;
        aux++;	
    }
    palabra[i] = palabra[cantidad];
}

void imprimirLinea(char car, int cantidad){
    for (int i = 0; i < cantidad; i++) cout<<car;
    cout<<endl;
}

void leerImprimirEspecialidadesFechaVenc(char *especialidad1,char *especialidad2,
                                 int &ddven,int &mmven,int &aaven){
    char car;
    cin>>especialidad1>>especialidad2>>ddven>>car>>mmven>>car>>aaven;
    cout<<right<<setw(65)<<"EMPRESA PRESTADORA DE SALUD"<<endl;
    imprimirLinea('=',100);
    cout<<left<<"ESPECIALIDADES A VERIFICAR: "<<" "<<especialidad1<<" Y "
        <<especialidad2<<endl;
    cout<<"FECHA DEL PROCESO: "<<right<<setfill('0')<<setw(2)<<ddven<<'/'
        <<setw(2)<<mmven<<'/'<<aaven<<left<<setfill(' ')<<endl;
}

int convertirFecha(int dd, int mm, int aa){
    return (aa * 10000 + mm * 100 + dd);
}

void procesarPacientes(char *especialidad, char *especialidad1,
                       char *especialidad2, int ddven, int mmven, 
                       int aaven, int cantEsp1, int cantEsp2){
    int dni,cantMedicamentos,codMedicamento,dd,mm,aa;
    char nombre[20],descripcion[50],car;
    int fecha_vencimiento = convertirFecha(ddven,mmven,aaven);
    while(1){
        cin>>dni;
        if(cin.eof()) break;
        if(cin.fail()){
            cin.clear();
            break;
        }else{
            cin>>nombre>>cantMedicamentos;
            if(cmpEsp(especialidad1, especialidad2,especialidad,cantEsp1,cantEsp2))
                cout<<left<<setw(12)<<dni<<setw(20)<<nombre<<setw(5)<<cantMedicamentos;
            for (int i = 0; i < cantMedicamentos; i++){
                cin>>codMedicamento>>descripcion>>dd>>car>>mm>>car>>aa;
                if(cmpEsp(especialidad1, especialidad2, especialidad, cantEsp1,
                          cantEsp2)){
                    if(i == 0) cout<<setw(8)<<codMedicamento<<setw(32)
                               <<descripcion<<right<<setfill('0')<<setw(2)<<dd
                               <<'/'<<setw(2)<<mm<<'/'<<aa<<setfill(' ');
                    else cout<<right<<setw(42)<<codMedicamento<<left<<"   "
                         <<setw(32)<<descripcion<<right<<setfill('0')<<setw(2)
                         <<dd<<'/'<<setw(2)<<mm<<'/'<<aa<<setfill(' ');
                    if(convertirFecha(dd,mm,aa)<fecha_vencimiento){
                        cout<<left<<setw(5)<<" "<<"VENCIDA"<<endl;
                    }else cout<<endl;
                }
            }
        }
    }
}

void leerMedico(char *codigo, char *dato,char *especialidad1,char *especialidad2,int ddven,int mmven,int aaven){
    char especialidad[20];
    int cantPal, cantEsp1, cantEsp2,ret;
    cin>>codigo>>dato;
    
    cantPal = cantidadLetras(dato);
    obtenerEspecialidad(dato,especialidad,cantPal);
    cantEsp1 = cantidadLetras(especialidad1);
    cantEsp2 = cantidadLetras(especialidad2);
    if(cmpEsp(especialidad1, especialidad2, especialidad,cantEsp1, cantEsp2)){
        imprimirLinea('=',100);
        cout<<"Medico: "<<dato<<" ["<<codigo<<"] "<<right<<setw(20)
            <<"Especialidad: "<<setw(15)<<especialidad<<endl;
        imprimirLinea('-',100);
        cout<<right<<setfill(' ')<<setw(35)<<"Pacientes atendidos"<<setw(40)<<"Medicinas recibidas"<<endl;
        imprimirLinea('-',100);
        cout<<setw(10)<<"DNI"<<setw(15)<<"Nombre"<<setw(25)<<"Cantidad"
            <<setw(10)<<"Codigo"<<setw(15)<<"Descripcion"<<setw(25)
            <<"F. de V"<<setw(15)<<"Observacion"<<endl;
        imprimirLinea('-',100);
    }
    procesarPacientes(especialidad, especialidad1,especialidad2, ddven, mmven,
                      aaven, cantEsp1, cantEsp2);
}




