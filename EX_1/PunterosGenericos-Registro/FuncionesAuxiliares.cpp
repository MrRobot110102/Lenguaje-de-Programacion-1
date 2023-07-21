/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

//Sebastian Moises Esquivel Barreto
//2019038
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "FuncionesAuxiliares.h"
#define INCREMENTO 5
enum EAlumno {COD, NOM, NOT, PRO};

void cargarAlumnos(void *&alumno){
    ifstream archAlumnos("Alumnos.csv",ios::in);
    if(not archAlumnos.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Alumnos.csv"<<endl;
        exit(1);
    }
    void **alumnos,*alum;
    int numDatos = 0,cap = 0;
    alumnos = nullptr;
    while(true){
        alum = leerRegistro(archAlumnos);
        if(alum == nullptr) break;
        if(numDatos == cap) aumentarEspacios(alumnos,numDatos,cap);
        alumnos[numDatos] = nullptr;
        alumnos[numDatos - 1] = alum;
        numDatos++;
    }
    //IMPORTANTE
    alumno = alumnos;
}

void aumentarEspacios(void **&alumnos,int &numDatos,int &cap){
    void **aux;
    cap += INCREMENTO;
    if(alumnos == nullptr){
        alumnos = new void*[cap];
        alumnos[0] = nullptr;
        numDatos = 1;
    }else{
        aux = new void*[cap];
        for (int i = 0; i < numDatos; i++) {
            aux[i] = alumnos[i];
        }
        delete alumnos;
        alumnos = aux;
    }
}

void *leerRegistro(ifstream &arch){
    int *codigo,cod;
    char *nombre;
    void **registro;
    arch>>cod;
    if(arch.eof()) return nullptr;
    arch.get();
    codigo = new int;
    *codigo = cod;
    nombre = leerCadena(arch,'\n');
    registro = new void*[4];
    registro[COD] = codigo;
    registro[NOM] = nombre;
    registro[NOT] = nullptr;
    registro[PRO] = nullptr;
    return registro;
}

char *leerNombre(ifstream &arch){
    char *aux,buff[200];
    arch.getline(buff,200);
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}

char *leerCadena(ifstream &arch,char separador){
    char *aux,buff[200];
    arch.getline(buff,200,separador);
    aux = new char[strlen(buff) + 1];
    strcpy(aux,buff);
    return aux;
}
    
void reporteAlumnos(void *alumno){
    void **alum = (void **)alumno;
    for (int i = 0; alum[i]; i++) imprimirAlumno(alum[i]);
    cout<<endl<<endl;
}

void imprimirAlumno(void *alumno){
    void **alum = (void **)alumno;
    int *codigo = (int *)alum[COD];
    char *nombre = (char *)alum[NOM];
    double *promedio = (double *)alum[PRO];
    cout.precision(2);cout<<fixed;
    cout<<left<<setw(10)<<*codigo<<setw(60)<<nombre<<endl;
    if(alum[NOT]) imprimirCursos(alum[NOT]);
    if(alum[PRO]) cout<<" Promedio: "<<right<<setw(10)<<*promedio<<endl;
}

void imprimirCursos(void *alumno){
    void **alum = (void **)alumno;
    for (int i = 0; alum[i]; i++) imprimirCurso(alum[i]);
}

void imprimirCurso(void *alumno){
    void **alum = (void **)alumno;
    int *nota = (int *)alum[1];
    char *codigo = (char *)alum[0];
    cout<<right<<setw(15)<<codigo<<setw(5)<<*nota<<left<<endl;
}
    
void cargarCursos(void *&alumno){
    ifstream archCursos("CursosNotas.csv",ios::in);
    void **alumnos = (void **)alumno;
    int codigoAlumno,posAlumno,numDatos[50]{},cap[50]{};
    while(true){
        archCursos>>codigoAlumno;
        if(archCursos.eof()) break;
        archCursos.get();
        posAlumno = obtenerPosicionAlumno(codigoAlumno,alumnos);
        if(posAlumno != -1){
            colocarCurso(archCursos,alumnos[posAlumno],numDatos[posAlumno],cap[posAlumno]);
        }
    }
}

void colocarCurso(ifstream &arch,void *&alumnos,int &numDatos, int &cap){
    void **alumno = (void **)alumnos;
    void *curso;
    curso = leerCurso(arch);
    if(numDatos == cap) aumentarEspacios(alumno[NOT],numDatos,cap);
    agregarCurso(curso, alumno[NOT],numDatos);
    numDatos++;
}

void agregarCurso(void *curso, void *&alumno_cursos,int numDatos){
    void **alumnoCursos = (void **)alumno_cursos;
    alumnoCursos[numDatos] = nullptr;
    alumnoCursos[numDatos -1] = curso;
}

void aumentarEspacios(void *&alumnos, int &numDatos, int &cap){
    void**alumno = (void**)alumnos, **aux;
    cap += INCREMENTO;
    if(alumno == nullptr){
        alumno = new void*[cap];
        alumno[0] = nullptr;
        numDatos = 1;
    }else{
        aux = new void*[cap];
        for (int i = 0; i < numDatos; i++) aux[i] = alumno[i];
        delete alumno;
        alumno = aux;
    }
    alumnos = alumno;
}

void *leerCurso(ifstream &arch){
    char *codigo;
    int *nota = new int;
    void **registro;
    codigo = leerCadena(arch,',');
    arch>>*nota;
    registro = new void*[2];
    registro[0] = codigo;
    registro[1] = nota;
    return registro;
}

int obtenerPosicionAlumno(int codigoAlumno,void *alumnos){
    void **alumno = (void **)alumnos;
    for (int i = 0; alumno[i]; i++) if(sonIguales(codigoAlumno,alumno[i])) return i;
    return -1;
}

bool sonIguales(int codigoAlumno,void *alumnos){
    void **alumno = (void **)alumnos;
    int *codigo = (int *)alumno[COD];
    return codigoAlumno == *codigo;
}

void calcularPromedios(void *&alumno){
    void **alum = (void **)alumno;
    for (int i = 0; alum[i]; i++) promedioAlumno(alum[i]);
}

void promedioAlumno(void *&alumno){
    void **alum = (void **)alumno;
    if(alum[NOT]) alum[PRO] = promedio(alum[NOT]);
}

void *promedio(void *&alumno){
    void **alum = (void **)alumno;
    int suma = 0, numDato = 0;
    double *promedio;
    for (int i = 0; alum[i]; i++) {
        suma += notaCurso(alum[i]);
        numDato++;
    }
    promedio = new double;
    *promedio = (double)suma/numDato;
    return promedio;
}

int notaCurso(void *&alumno){
    void **alum = (void **)alumno;
    int *nota = (int *)alum[1];
    return *nota;
}

