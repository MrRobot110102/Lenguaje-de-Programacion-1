/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funcionesAuxiliares.h
 * Author: Sebastian
 *
 * Created on 20 de abril de 2023, 16:24
 */

#ifndef FUNCIONESAUXILIARES_H
#define FUNCIONESAUXILIARES_H

void crearArchivos();
void insertarMedicos(ofstream &archMedicos,char *codMedico,char *nombreMedico);
int cantidadPalabra(char *palabra);
void obtenerEspecialidad(char *nombre,char *especialidad);
void darFormato(char *nombre);
int duplicado(int dni,const char *nombreArch);
void insertarPacientes(ofstream &archPacientesBin,int dniPaciente,char *nombrePaciente);
void insertarConsultas(ofstream &archConsultas,int dniPaciente,char *codMedico,
                       int dd,int mm, int aa, int cantMedicamentos);
void insertarMedicinas(ofstream &archMedicinasBin,int codMedicamento,char *desc,double precio);
void insertarConsultasMedicinas(ofstream &archConsultas,int codMedicamento);
void mostrarArchivos();
void imprimirLinea(char car, int cantidad,ofstream &archReporte);
void mostrarMedicos(ifstream &archMedicos,ofstream &archReporte);
void mostrarPacientesBin(ifstream &archPacientesBin,ofstream &archReporte);
void mostrarMedicinas(ifstream &archMedicinasBin,ofstream &archReporte);
void mostrarConsultas(ifstream &archConsultas,ofstream &archReporte);
void actualizaPacienteBin();
double obtenerPrecioMedicamento(int codMedicamento,ifstream &archMedicinasBin);
void actualizarGastoPaciente(int dni,double gasto_total,fstream &archPacienteBin,int numRegistros,int tamDelRegistro);

#endif /* FUNCIONESAUXILIARES_H */

