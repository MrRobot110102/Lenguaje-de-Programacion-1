/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "funcionesAuxiliares.h"

void crearArchConductoresBin(){
    int licencia,dd,mm,aa,codigoFalta,numFaltasLeves=0,numFaltasGraves=0,numFaltasMuyGraves=0;
    char nombre[50],placa[10],car,tipoFalta;
    double montoFaltasLeves=0.0,montoFaltasGraves=0.0,montoFaltasMuyGraves=0.0,totalMonto=0.0;
    
    ifstream archInfCond("Infracciones-Conductores.txt",ios::in);
    if(not archInfCond.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Infracciones-Conductores.txt"<<endl;
        exit(1);
    }
    ofstream archCondBin("Conductores.bin",ios::out | ios::binary);
    if(not archCondBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Conductores.bin"<<endl;
        exit(1);
    }
    
    while(true){
        archInfCond>>licencia;
        if(archInfCond.eof()) break;
        if(not archInfCond.fail()){
            archInfCond>>nombre;
            archCondBin.write(reinterpret_cast<const char *> (&licencia),sizeof(int));
            archCondBin.write(reinterpret_cast<const char *> (nombre),sizeof(char)*50);
            archCondBin.write(reinterpret_cast<const char *> (&numFaltasLeves),sizeof(int));
            archCondBin.write(reinterpret_cast<const char *> (&numFaltasGraves),sizeof(int));
            archCondBin.write(reinterpret_cast<const char *> (&numFaltasMuyGraves),sizeof(int));
            archCondBin.write(reinterpret_cast<const char *> (&montoFaltasLeves),sizeof(double));
            archCondBin.write(reinterpret_cast<const char *> (&montoFaltasGraves),sizeof(double));
            archCondBin.write(reinterpret_cast<const char *> (&montoFaltasMuyGraves),sizeof(double));
            archCondBin.write(reinterpret_cast<const char *> (&totalMonto),sizeof(double));
        }else{
            archInfCond.clear();
            archInfCond>>placa>>dd>>car>>mm>>car>>aa>>tipoFalta>>codigoFalta;
        }
    }
}

void mostrarConductoresBin(){
    int licencia,dd,mm,aa,codigoFalta,numFaltasLeves,numFaltasGraves,numFaltasMuyGraves;
    char nombre[50],placa[10],car,tipoFalta;
    double montoFaltasLeves,montoFaltasGraves,montoFaltasMuyGraves,totalMonto;
    
    ifstream archCondBin("Conductores.bin",ios::in | ios::binary);
    if(not archCondBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Conductores.bin"<<endl;
        exit(1);
    }
    ofstream archCondMuestra("Muestra-Conductores.txt",ios::out);
    if(not archCondMuestra.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Muestra-Conductores.txt"<<endl;
        exit(1);
    }
    
    archCondMuestra.precision(2);
    archCondMuestra<<fixed;
    
    while(true){
        archCondBin.read(reinterpret_cast<char *> (&licencia),sizeof(int));
        if(archCondBin.eof()) break;
        archCondBin.read(reinterpret_cast<char *> (nombre),sizeof(char)*50);
        archCondBin.read(reinterpret_cast<char *> (&numFaltasLeves),sizeof(int));
        archCondBin.read(reinterpret_cast<char *> (&numFaltasGraves),sizeof(int));
        archCondBin.read(reinterpret_cast<char *> (&numFaltasMuyGraves),sizeof(int));
        archCondBin.read(reinterpret_cast<char *> (&montoFaltasLeves),sizeof(double));
        archCondBin.read(reinterpret_cast<char *> (&montoFaltasGraves),sizeof(double));
        archCondBin.read(reinterpret_cast<char *> (&montoFaltasMuyGraves),sizeof(double));
        archCondBin.read(reinterpret_cast<char *> (&totalMonto),sizeof(double));
        archCondMuestra<<left<<licencia<<setw(5)<<" "<<setw(65)<<nombre
                       <<right<<setw(5)<<numFaltasLeves<<setw(5)<<numFaltasGraves
                       <<setw(5)<<numFaltasMuyGraves<<setw(8)<<montoFaltasLeves
                       <<setw(8)<<montoFaltasGraves<<setw(8)<<montoFaltasMuyGraves
                       <<setw(10)<<totalMonto<<endl;
    }
}

void crearArchFaltasCometidasBin(){
    int licencia,dd,mm,aa,codigoFalta,licencia_aux,fecha;
    char nombre[50],placa[10],car,tipoFalta,leve[20] = "LEVE",grave[20] ="GRAVE",
         muy_grave[20] = "MUY GRAVE";
    double montoFalta=0.0;
    
    ifstream archInfCond("Infracciones-Conductores.txt",ios::in);
    if(not archInfCond.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Infracciones-Conductores.txt"<<endl;
        exit(1);
    }
    ofstream archFalComBin("FaltasCometidas.bin",ios::out | ios::binary);
    if(not archFalComBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo FaltasCometidas.bin"<<endl;
        exit(1);
    }
    
    while(true){
        archInfCond>>licencia;
        if(archInfCond.eof()) break;
        if(not archInfCond.fail()){
            archInfCond>>nombre;
            licencia_aux = licencia;
        }else{
            archInfCond.clear();
            archInfCond>>placa>>dd>>car>>mm>>car>>aa>>tipoFalta>>codigoFalta;
            fecha = aa*10000+mm*100+dd;
            archFalComBin.write(reinterpret_cast<const char *> (placa),sizeof(char) * 10);
            archFalComBin.write(reinterpret_cast<const char *> (&licencia_aux),sizeof(int));
            archFalComBin.write(reinterpret_cast<const char *> (&fecha),sizeof(int));
            if(tipoFalta == 'L') 
                archFalComBin.write(reinterpret_cast<const char *> (leve),sizeof(char) * 20);
            else if(tipoFalta == 'G') 
                archFalComBin.write(reinterpret_cast<const char *> (grave),sizeof(char) * 20);
            else if(tipoFalta == 'M') 
                archFalComBin.write(reinterpret_cast<const char *> (muy_grave),sizeof(char) * 20);
            archFalComBin.write(reinterpret_cast<const char *> (&codigoFalta),sizeof(int));
            archFalComBin.write(reinterpret_cast<const char *> (&montoFalta),sizeof(double));
        }
    }
}

void convertirFecha(int fecha, int &dd,int &mm,int &aa){
    aa = fecha/10000;
    fecha = fecha%10000;
    mm = fecha/100;
    dd = fecha%100;
}

void mostrarFaltasCometidasBin(){
    int licencia,dd,mm,aa,codigoFalta,fecha;
    char nombre[50],placa[10],car,tipoFalta,tipoInfraccion[20];
    double montoFalta;
    
    ifstream archFalComBin("FaltasCometidas.bin",ios::in | ios::binary);
    if(not archFalComBin.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo FaltasCometidas.bin"<<endl;
        exit(1);
    }
    ofstream archFalComMuestra("Muestra-FaltasCometidas.txt",ios::out);
    if(not archFalComMuestra.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Muestra-FaltasCometidas.txt"<<endl;
        exit(1);
    }
    
    archFalComMuestra.precision(2);
    archFalComMuestra<<fixed;
    
    while(true){
        archFalComBin.read(reinterpret_cast<char *> (placa),sizeof(char) * 10);
        if(archFalComBin.eof()) break;
        archFalComBin.read(reinterpret_cast<char *> (&licencia),sizeof(int));
        archFalComBin.read(reinterpret_cast<char *> (&fecha),sizeof(int));
        convertirFecha(fecha,dd,mm,aa);
        archFalComBin.read(reinterpret_cast<char *> (tipoInfraccion),sizeof(char) * 20);
        archFalComBin.read(reinterpret_cast<char *> (&codigoFalta),sizeof(int));
        archFalComBin.read(reinterpret_cast<char *> (&montoFalta),sizeof(double));
        archFalComMuestra<<left<<placa<<setw(5)<<" "<<setw(20)<<licencia
                       <<right<<setfill('0')<<setw(2)<<dd<<'/'<<setw(2)<<mm
                       <<'/'<<aa<<setfill(' ')<<left<<setw(5)<<" "
                       <<setw(20)<<tipoInfraccion<<setw(5)<<codigoFalta
                       <<right<<setw(8)<<montoFalta<<endl;
    }
}

void crearArchListadoInfracciones(){
    int codigo;
    char descripcion[500],gravedad[20];
    double monto;
    
    ifstream archInf("Infracciones.txt",ios::in);
    if(not archInf.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Infracciones.txt"<<endl;
        exit(1);
    }
    ofstream archListInf("ListadoDeInfracciones.bin",ios::out | ios::binary);
    if(not archListInf.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ListadoDeInfracciones.bin"<<endl;
        exit(1);
    }
    
    while(true){
        archInf>>codigo;
        if(archInf.eof()) break;
        archInf>>descripcion>>gravedad>>monto;
        archListInf.write(reinterpret_cast<const char *> (&codigo),sizeof(int));
        archListInf.write(reinterpret_cast<const char *> (descripcion),sizeof(char) * 500);
        archListInf.write(reinterpret_cast<const char *> (gravedad),sizeof(char) * 20);
        archListInf.write(reinterpret_cast<const char *> (&monto),sizeof(double));
    }
}
void mostrarListadoInfracciones(){
    int codigo;
    char descripcion[500],gravedad[20];
    double monto;
    
    ifstream archListInf("ListadoDeInfracciones.bin",ios::in | ios::binary);
    if(not archListInf.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ListadoDeInfracciones.bin"<<endl;
        exit(1);
    }
    ofstream archMuestra("ListadoDeInfracciones-Muestra.txt",ios::out | ios::binary);
    if(not archMuestra.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ListadoDeInfracciones-Muestra.bin"<<endl;
        exit(1);
    }
    
    archMuestra.precision(2);
    archMuestra<<fixed;
    
    while(true){
        archListInf.read(reinterpret_cast<char *> (&codigo),sizeof(int));
        if(archListInf.eof()) break;
        archListInf.read(reinterpret_cast<char *> (descripcion),sizeof(char) * 500);
        archListInf.read(reinterpret_cast<char *> (gravedad),sizeof(char) * 20);
        archListInf.read(reinterpret_cast<char *> (&monto),sizeof(double));
        
        archMuestra<<left<<setw(10)<<codigo<<setw(195)<<descripcion<<setw(15)
                   <<gravedad<<right<<setw(10)<<monto<<endl;
    }
}

int obtenerMonto(int codigoFalta,fstream &archListInf){
    int codigo;
    char descripcion[500],gravedad[20];
    double monto;
    
    archListInf.seekg(0,ios::beg);
    
    while(true){
        archListInf.read(reinterpret_cast<char *> (&codigo),sizeof(int));
        if(archListInf.eof()) break;
        archListInf.read(reinterpret_cast<char *> (descripcion),sizeof(char) * 500);
        archListInf.read(reinterpret_cast<char *> (gravedad),sizeof(char) * 20);
        archListInf.read(reinterpret_cast<char *> (&monto),sizeof(double));
        if(codigo == codigoFalta) return monto;
    }
}

void actualizarRegistro(int &numFaltasLeves,int &numFaltasGraves,int &numFaltasMuyGraves,
                        double &montoFaltasLeves,double &montoFaltasGraves,
                        double &montoFaltasMuyGraves,double &totalMonto,
                        fstream &archCond,char *gravedad,int tamDelRegistro,
                        double montoFalta,int i){
    if(strcmp(gravedad,"LEVE")==0){
        numFaltasLeves++;
        montoFaltasLeves+=montoFalta;
    }
    else if(strcmp(gravedad,"GRAVE")==0){
        numFaltasGraves++;
        montoFaltasGraves+=montoFalta;
    }
    else if(strcmp(gravedad,"MUY GRAVE")==0){
        numFaltasMuyGraves++;
        montoFaltasMuyGraves+=montoFalta;
    }
    totalMonto+=montoFalta;
    archCond.seekg(i*tamDelRegistro,ios::beg);
    archCond.seekg(sizeof(int)+sizeof(char)*50,ios::cur);
    archCond.write(reinterpret_cast<const char*> (&numFaltasLeves),sizeof(int));
    archCond.write(reinterpret_cast<const char*> (&numFaltasGraves),sizeof(int));
    archCond.write(reinterpret_cast<const char*> (&numFaltasMuyGraves),sizeof(int));
    archCond.write(reinterpret_cast<const char*> (&montoFaltasLeves),sizeof(double));
    archCond.write(reinterpret_cast<const char*> (&montoFaltasGraves),sizeof(double));
    archCond.write(reinterpret_cast<const char*> (&montoFaltasMuyGraves),sizeof(double));
    archCond.write(reinterpret_cast<const char*> (&totalMonto),sizeof(double));
}

void actualizarConductores(int licencia, char *gravedad,double montoFalta,
                           fstream &archCond,int tamDelRegistro,
                           int tamDelArchivo,int numRegistros){
    int numLicencia,numFaltasLeves,numFaltasGraves,numFaltasMuyGraves;
    double montoFaltasLeves,montoFaltasGraves,montoFaltasMuyGraves,totalMonto;
    archCond.seekg(0,ios::beg);
    for (int i = 0; i < numRegistros; i++) {
        archCond.read(reinterpret_cast<char *>(&numLicencia),sizeof(int));
        if(licencia == numLicencia){
            archCond.seekg(sizeof(char) * 50,ios::cur);
            archCond.read(reinterpret_cast<char *>(&numFaltasLeves),sizeof(int));
            archCond.read(reinterpret_cast<char *>(&numFaltasGraves),sizeof(int));
            archCond.read(reinterpret_cast<char *>(&numFaltasMuyGraves),sizeof(int));
            archCond.read(reinterpret_cast<char *>(&montoFaltasLeves),sizeof(double));
            archCond.read(reinterpret_cast<char *>(&montoFaltasGraves),sizeof(double));
            archCond.read(reinterpret_cast<char *>(&montoFaltasMuyGraves),sizeof(double));
            archCond.read(reinterpret_cast<char *>(&totalMonto),sizeof(double));
            actualizarRegistro(numFaltasLeves,numFaltasGraves,numFaltasMuyGraves,
                               montoFaltasLeves,montoFaltasGraves,montoFaltasMuyGraves,
                               totalMonto,archCond,gravedad,tamDelRegistro,montoFalta,i);
            break;
        }else{
            archCond.seekg(sizeof(int)*3+sizeof(double)*4+sizeof(char)*50,ios::cur);
        }
    }
}

void actualizarArchivos(){
    int licencia,dd,mm,aa,codigoFalta,licencia_aux,fecha;
    char nombre[50],placa[10],car,tipoFalta,gravedad[20];
    double montoFalta;
    fstream archCond("Conductores.bin", ios::in | ios ::out | ios::binary);
    if(not archCond.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo Conductores.bin"<<endl;
        exit(1);
    }
    fstream archFalCom("FaltasCometidas.bin", ios::in | ios ::out | ios::binary);
    if(not archFalCom.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo FaltasCometidas.bin"<<endl;
        exit(1);
    }
    fstream archListInf("ListadoDeInfracciones.bin", ios::in | ios ::out | ios::binary);
    if(not archListInf.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo ListadoDeInfracciones.bin"<<endl;
        exit(1);
    }
    
    int tamDelRegistro,tamDelArchivo,numRegistros;
    tamDelRegistro = sizeof(int) * 4 + sizeof(char) * 50 + sizeof(double) * 4;
    archCond.seekg(0,ios::end);
    tamDelArchivo = archCond.tellg();
    archCond.seekg(0,ios::beg);
    numRegistros = tamDelArchivo/tamDelRegistro;
    
    while(true){
        archFalCom.read(reinterpret_cast<char *> (placa),sizeof(char) *10);
        if(archFalCom.eof()) break;
        archFalCom.read(reinterpret_cast<char *> (&licencia),sizeof(int));
        archFalCom.read(reinterpret_cast<char *> (&fecha),sizeof(int));  
        archFalCom.read(reinterpret_cast<char *> (gravedad),sizeof(char) * 20);
        archFalCom.read(reinterpret_cast<char *> (&codigoFalta),sizeof(int));
        montoFalta = obtenerMonto(codigoFalta,archListInf);
        archFalCom.write(reinterpret_cast<const char *> (&montoFalta),sizeof(double));
        actualizarConductores(licencia,gravedad,montoFalta,archCond,
                              tamDelRegistro,tamDelArchivo,numRegistros);
    }
}




