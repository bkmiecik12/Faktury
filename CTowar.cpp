//
// Created by bkmiecik on 16.06.17.
//

#include "CTowar.h"

CTowar::CTowar() {

}

CTowar::~CTowar() {

}

string CTowar::getNazwaTowaru() {
    return nazwatowaru;
}

float CTowar::getCenaNetto() {
    return cenanetto;
}

string CTowar::getJM() {
    return jm;
}

int CTowar::getVAT() {
    return vat;
}

float CTowar::getIlosc() {
    return ilosc;
}

void CTowar::setNazwaTowaru(string s) {
    nazwatowaru = s;
}

void CTowar::setCenaNetto(float f) {
    cenanetto = f;
}

void CTowar::setJM(string s) {
    jm = s;
}

void CTowar::setVAT(int i) {
    vat=i;
}

void CTowar::setIlosc(float f) {
    ilosc=f;
}

float CTowar::podatek()
{
    return getIlosc()*getCenaNetto()*getVAT()/100;
}

float CTowar::wartoscnetto()
{
    return getIlosc()*getCenaNetto();
}

float CTowar::brutto()
{
    return getCenaNetto()*getIlosc()*((100+getVAT())/100);
}
