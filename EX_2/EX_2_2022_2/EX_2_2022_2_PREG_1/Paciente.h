/* 
 * Proyecto: Pregunta01_Examen02_2022-2
 * Archivo:  Paciente.h
 * Autor:    J. Miguel Guanira E.
 *
 * Created on 23 de noviembre de 2022, 07:38 PM
 */


#ifndef PACIENTE_H
#define PACIENTE_H
#include <fstream>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

class Paciente {
private:
    int dni;
    char *nombre;
    int fechaUltimaConsulta;
    char *codigoDelMedicoDeUltimaConsulta;
public:
    Paciente();
    Paciente(const Paciente& orig);
    virtual ~Paciente();
    void SetFechaUltimaConsulta(int fechaUltimaConsulta);
    int GetFechaUltimaConsulta() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*) const;
    void SetDni(int dni);
    int GetDni() const;
    void SetCodigoDelMedicoDeUltimaConsulta(const char*);
    void GetCodigoDelMedicoDeUltimaConsulta(char*) const;
    void operator = (const Paciente& orig);
    void leerDatos(ifstream&arch);
    void imprimirDatos(ofstream&arch);
};

#endif /* PACIENTE_H */

