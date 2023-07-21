/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PunterosGenericos.h
 * Author: Sebastian
 *
 * Created on 10 de mayo de 2023, 22:02
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

void cargaMedicinas(void *&medicinas);
void *leerRegistro(ifstream &arch);
char *leerCadena(ifstream &arch);
void cargaConsultas(void *&citas);
void *leerConsulta(ifstream &archConsultas);
void *cargarMedicamentos(ifstream &arch, int cantidad);
void actualizarReservas(void *&medicinas,void *&citas);
void actualizarCitas(void *&cit,void *&med);
void actualizar(int cantidad, void *&cit, void *&med);
void actualizarMedicamento(void *&cit,void *&med);
int obtenerPosicionMedicamento(void *med, int codMedicamento,int *&stock,int *&reserva);
int compararMedicinas(void *med,int codMedicamento, int *&stock,int *&reserva);



#endif /* PUNTEROSGENERICOS_H */

