/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 2 de mayo de 2023, 19:06
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void lecturaDeMedicos(const char *nombArch,int *&med_Codigo,char **&med_Nombre,
        char **&med_Especialidad,double *&med_Tarifa);
char *obtenerEspecialidad(char *nombre);
void pruebaDeLecturaDeMedicos(const char *nombArch,int *med_Codigo,
        char **med_Nombre,char **med_Especialidad,double *med_Tarifa);
void lecturaDeCitas(const char *nombArch,int *&pac_Dni,char **&pac_Nombre,
        int **&pac_Citas);
int buscarPaciente(int *buffDni,int dni,int numDatos);
void agregarCitasPaciente(int *&pac_Citas,int *&buffCitas,int numCitas);
void agregarCitas(int *&buffCitas,int codMedico,int fecha,int &numCitas);
void leerDatos(ifstream &arch,char *&nombre,int &codMedico, int &fecha);
char *leerNombre(ifstream &arch);
void imprimirCitas(int *pac_Citas,ofstream &arch);
void pruebaDeLecturaDeCitas(const char *nombArch,int *pac_Dni,
        char **pac_Nombre,int **pac_Citas);

    
void reporteDeIngresosMedicosYGastosDeLosPacientes(const char *nombArch,
            int *med_Codigo,char **med_Nombre,char **med_Especialidad,
            double *med_Tarifa,int *pac_Dni,char **pac_Nombre,int **pac_Citas);

#endif /* FUNCIONESAUXILIARES_H */

