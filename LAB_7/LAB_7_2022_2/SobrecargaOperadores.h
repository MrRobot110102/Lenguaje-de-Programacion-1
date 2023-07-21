/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   SobrecargaOperadores.h
 * Author: Sebastian
 *
 * Created on 4 de junio de 2023, 0:03
 */

#ifndef SOBRECARGAOPERADORES_H
#define SOBRECARGAOPERADORES_H

ifstream & operator >>(ifstream &arch, class medico &med);
ifstream &operator >>(ifstream &arch,class paciente &pac);
ifstream &operator >>(ifstream &arch,class cita &cit);
ofstream & operator <<(ofstream &arch,const class medico &med);
ofstream & operator <<(ofstream &arch,const class paciente &pac);
ofstream & operator <<(ofstream &arch,const class cita &cit);


#endif /* SOBRECARGAOPERADORES_H */

