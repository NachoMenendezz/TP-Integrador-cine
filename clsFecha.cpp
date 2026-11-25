#include <iostream>
#include "clsFecha.h"
#include <ctime>
using namespace std;


Fecha::Fecha(int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
}

void Fecha::setDia(int d){
    dia = d;
}
void Fecha::setMes(int m){
    mes = m;
}
void Fecha::setAnio(int a){
    anio = a;
}
int Fecha::getDia(){
    return dia;
}
int Fecha::getMes(){
    return mes;
}
int Fecha::getAnio(){
    return anio;
}
void Fecha::Cargar(){
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
}
void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio;
}

bool Fecha::esValida(){
int maxDias = 31;
if (dia<1||dia>31)return false;
if (mes<1||mes>12)return false;
if (anio<1) return false;
if (mes==4||mes==6||mes==9||mes==11){
    maxDias=30;
}
if (mes == 2) {
    maxDias = 28;

    bool esBisiesto = (anio % 400 == 0) ||
                      (anio % 4 == 0 && anio % 100 != 0);

    if (esBisiesto) {
        maxDias = 29;
    }
}

return dia <= maxDias;
}

void Fecha::setHoy(){
time_t t = time(NULL);
tm* hoy = localtime(&t);
dia = hoy->tm_mday;
mes = hoy->tm_mon + 1;
anio = hoy->tm_year + 1900;

}



Fecha::~Fecha(){
}

