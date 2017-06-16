//
// Created by bkmiecik on 16.06.17.
//

#include "CPodmiot.h"

CPodmiot::CPodmiot() {

}

CPodmiot::CPodmiot(string a, string b, string c, string d) {
    nazwa = a;
    adres = b;
    nip = c;
    regon = d;
}

CPodmiot::~CPodmiot() {

}

string CPodmiot::getNazwa() {
    return nazwa;
}

string CPodmiot::getAdres() {
    return adres;
}

string CPodmiot::getNIP() {
    return nip;
}

string CPodmiot::getREGON() {
    return regon;
}

void CPodmiot::setNazwa(string s) {
    nazwa=s;
}

void CPodmiot::setAdres(string s) {
    adres=s;
}

void CPodmiot::setNIP(string s) {
    nip=s;
}

void CPodmiot::setREGON(string s) {
    regon=s;
}
