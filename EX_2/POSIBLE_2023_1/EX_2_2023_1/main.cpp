/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Sebastian
 *
 * Created on 6 de julio de 2023, 22:56
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "Tesoreria.h"
/*
 * 20190638 - Esquivel Barreto Sebastian Moises
 */
int main(int argc, char** argv) {
    Tesoreria teso;
    
    teso.cargaAlumnos();
    teso.imprimeAlumnos("ReporteAlumnos.txt");
    teso.cargaCursos();
    teso.imprimeAlumnos("ReporteAlumnosConCursos.txt");
    teso.ordenarCursos();
    teso.imprimeAlumnos("ReporteAlumnosCursosOrdenados.txt");
    teso.borrarCurso("INF263");
    teso.imprimeAlumnos("ReporteAlumnosConEliminacion.txt");
    teso.eliminaAlumnosSinCursos();
    teso.imprimeAlumnos("ReporteDespuesDeEliminar.txt");
    teso.eliminaUnAlumno(202111260);
    teso.imprimeAlumnos("ReporteDespuesDeEliminarUnAlumno.txt");
    teso.eliminaRangoCursos(202201);
    teso.imprimeAlumnos("ReporteDespuesDeEliminarRangoCursos.txt");
    teso.actualizar(2021,50);
    teso.imprimeAlumnos("ReporteActualizado.txt");
    return 0;
}

