/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FuncionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 8 de mayo de 2023, 19:40
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void CargarMedicamentos(int *&med_Codigo,char **&med_Descripcion,double *&med_Precio,const char *nombArch);
char *leerCadena(ifstream &arch);
void aumentarEspacios(int *&med_Codigo,char **&med_Descripcion,double *&med_Precio,int &numMedicamentos,int &capMedicamentos);
void PruebaDeCargaDeMedicamentos(int *med_Codigo,char **med_Descripcion,double *med_Precio,const char *nombArch);

void espaciosExactos(int **&consultas_int,int **&buffConsultas_int,int numDatos,
                     char **&consultas_char,char **&buffConsultas_char,int numMedicos);
void CargarConsultas(int ***&consultas_int,char ***&consultas_char,const char *nombArch);
void ingresarPaciente(int **&buffConsulta_int,int dni,int fecha, int codMedicamento,int cantidad,int &numMedicamentos,
                      char **&buffConsultas_char, char *nombPaciente, char *codMed,int &numMedicos);
int obtenerPosicionPaciente(int dni,int ***buffConsultas_int,int numDatos);
int obtenerPosicionMedicamento(int **buffConsulta_int,int codMedicamento,int numMedicamento);
void leerDatosRestantes(int &dniPaciente,char *&nombPaciente,int dd,int &fecha,char *&codMed, ifstream &arch);
void PruebaDeCargaDeConsultas(int ***consultas_int,char ***consultas_char,const char *nombArch);
void imprimirInformacion(int **consultas_int,char **consultas_char,ofstream &arch);
void cambiarFecha(int *&buffConsulta_int,int fecha);
bool existeMedico(char **buffConsultas_char,char *codMedico,int numMedicos);

void ReporteDeGastos_e_IngresosMedicos(int *med_Codigo,char **med_Descripcion,double *med_Precio,
        int ***consultas_int,char ***consultas_char,const char *nombArch);
void imprimirDetalle(int **consultas_int,char **consultas_char,int *med_Codigo,
        char **med_Descripcion,double *med_Precio,ofstream &arch,double &totalIngreso);
int posicionMedicamento(int codMedicamento, int *med_Codigo);

void imprimirLinea(char car, int cantidad, ofstream &arch);


#endif /* FUNCIONESAUXILIARES_H */

