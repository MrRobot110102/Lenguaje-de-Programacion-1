/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   SobrecargaOperadores.h
 * Author: Sebastian
 *
 * Created on 4 de junio de 2023, 16:04
 */

#ifndef SOBRECARGAOPERADORES_H
#define SOBRECARGAOPERADORES_H

ifstream & operator >>(ifstream &arch,class Conductor &conductor);
ifstream & operator >>(ifstream &arch,class Falta &falta);
ifstream & operator >>(ifstream &arch,class Infraccion &infraccion);
ofstream & operator <<(ofstream &arch,const class Conductor &conductor);
ofstream & operator <<(ofstream &arch,const class Falta &falta);
ofstream & operator <<(ofstream &arch,const class FaltaCond &falta);
void imprimirLinea(ofstream &arch, int cantidad, char car);
int buscarConductor(class Conductor *conductores,int licencia);


#endif /* SOBRECARGAOPERADORES_H */

