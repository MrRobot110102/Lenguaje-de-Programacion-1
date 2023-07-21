/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 30 de marzo de 2023, 0:31
 */

#include <iostream>
#include <iomanip>
using namespace std;
#include "funcionesAuxiliares.h"

int main(int argc, char** argv) {
    int codigo, anio_ingreso,nota,dd,mm,aa,cant_cursos=0,bandera=0,errores=0,cant_alumnos=0;
    char car,nombre[100],curso[8];
    double creditos,total_creditos = 0,total_creditos_aprob = 0,
           total_creditos_desaprob = 0,promedio_general = 0, promedio_aprob = 0;
    
    cout.precision(2); cout << fixed;
    imprimirEncabezado();
    
    while(1){
        cin>>codigo;
        if(cin.eof()){
            imprimirResumenAlumno(cant_cursos,errores,total_creditos,
                                  total_creditos_aprob,
                                  total_creditos_desaprob,cant_alumnos,
                                    promedio_general, promedio_aprob);
            break;
        }
        if(not cin.fail()){
            cin>>car>>anio_ingreso>>nombre;
            if(bandera != 0) imprimirResumenAlumno(cant_cursos,errores,total_creditos,
                                                   total_creditos_aprob,
                                                   total_creditos_desaprob,cant_alumnos,
                                                    promedio_general,promedio_aprob);
            imprimirEncabezadoAlumno(codigo,anio_ingreso,nombre,cant_cursos,
                                     bandera,errores,total_creditos,
                                     total_creditos_aprob,total_creditos_desaprob,
                                      promedio_general, promedio_aprob);
        }else{
            cin.clear();
            cin>>curso>>creditos>>nota>>dd>>car>>mm>>car>>aa;
            clasificarImprimirCursos(anio_ingreso,cant_cursos,curso,creditos,
                                     nota,dd,mm,aa,errores,total_creditos,
                                     total_creditos_aprob,total_creditos_desaprob,
                                        promedio_general, promedio_aprob);
        }      
    }
    cout<<"Total alumnos registrados:  "<<cant_alumnos<<endl;
    return 0;
}

