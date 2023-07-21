/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
using namespace std;

void imprimirLinea(char car, int cantidad){
    for (int i = 0; i < cantidad; i++) cout<<car;
    cout<<endl;
}

void imprimirEncabezado(){
    cout<<right<<setw(70)<<"INFORMACION ACADEMICA DE LOS ESTUDIANTES"<<endl;
}

void darFormatoNombre(char *nombre){
    int i = 0;
    while(nombre[i]){
        if(nombre[i] == '/' or nombre[i] == '-') nombre[i] = ' ';
        i++;
    }
}

void imprimirEncabezadoAlumno(int codigo,int anio_ingreso,char *nombre,
                              int &cant_cursos, int &bandera, int &errores,
                              double &total_creditos,double &cred_aprob,double &cred_desap,
                              double &promedio_general, double &promedio_aprob){
    darFormatoNombre(nombre);
    imprimirLinea('=',127);
    cout<<right<<setw(10)<<"Alumno: "<<left<<setw(50)<<nombre<<"Codigo: "
        <<anio_ingreso<<'-'<<right<<setfill('0')<<setw(6)<<codigo<<setfill(' ')<<endl;
    imprimirLinea('-',127);
    cout<<left<<setw(15)<<" "<<"CURSOS APROBADOS"<<setw(30)
        <<" "<<"CURSOS DESAPROBADOS"<<setw(36)<<" "<<"OBSERVACION"<<endl;
    cout<<left<<"No."<<"   "<<setw(8)<<"CODIGO"<<setw(15)<<"CREDITOS"<<setw(10)<<"NOTA"
        <<setw(20)<<"FECHA"<<setw(8)<<"CODIGO"<<setw(15)<<"CREDITOS"<<setw(10)<<"NOTA"
        <<setw(20)<<"FECHA"<<endl;
    imprimirLinea('-',127);
    cant_cursos = 0;
    bandera = 1;
    errores = 0;
    total_creditos = 0;
    cred_aprob = 0;
    cred_desap = 0;
    promedio_aprob = 0;
    promedio_general = 0;
}

void clasificarImprimirCursos(int anio_ingreso,int &cant_cursos,char *curso,
                              double creditos,int nota,int dd,int mm,int aa,
                              int &errores, double &total_creditos,double &cred_aprob,double &cred_desap,
                              double &promedio_general, double &promedio_aprob){
    int error=0;
    cout<<right<<setfill('0')<<setw(3)<<(cant_cursos+1);
    if(nota < 11) cout<<left<<setfill(' ')<<setw(53)<<" ";
    cout<<left<<setfill(' ')
        <<"   "<<setw(8)<<curso<<setw(15)<<creditos<<setw(10)<<nota
        <<right<<setfill('0')<<setw(4)<<aa<<'/'<<setw(2)<<mm<<'/'<<setw(2)
        <<dd<<left<<setfill(' ');
    if(aa<anio_ingreso){
        if(nota<11) cout<<setw(14)<<" "<<"ERROR FECHA"<<endl;
        else cout<<setw(67)<<" "<<"ERROR FECHA"<<endl;
        error = 1;
        errores++;
        
    }else cout<<endl;
    if(error == 0){
        total_creditos = total_creditos + creditos;
        if(nota <11) cred_desap = cred_desap + creditos;
        else{
            cred_aprob = cred_aprob + creditos;
            promedio_aprob = promedio_aprob + (nota * creditos);
        }
        promedio_general = promedio_general + (nota * creditos);
        cant_cursos++;  
    }   
}

void imprimirResumenAlumno(int cant_cursos, int errores, double total_creditos,
                           double cred_aprob,double cred_desap,int &cant_alumnos,
                            double promedio_general, double promedio_aprob){
    imprimirLinea('=',127);
    cout<<left<<"     "<<"RESUMEN:"<<endl;
    cout<<"     "<<"Cursos matriculados:  "<<cant_cursos<<setw(20)<<" "<<
        "Total de creditos:     "<<total_creditos<<endl;
    cout<<"     "<<"Creditos aprobados:  "<<cred_aprob<<setw(17)<<" "<<
        "Creditos desaprobados:     "<<cred_desap<<endl;
    double porcentaje = (cred_aprob/total_creditos) * 100;
    cout<<"     "<<"Creditos aprobados/matriculados:  "<<porcentaje<<'%'<<endl;
    imprimirLinea('-',127);
    cout<<left<<"     "<<"Promedio general:     "<<promedio_general/total_creditos<<endl;
    cout<<"     "<<"Promedio general de aprobados:     "<<promedio_aprob/cred_aprob<<endl;
    imprimirLinea('-',127);
    cout<<left<<"     "<<"Cursos con error no considerados:  "<<errores<<endl;
    imprimirLinea('=',127);
    cant_alumnos++;
}