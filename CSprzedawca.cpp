//
// Created by bkmiecik on 16.06.17.
//

#include "CSprzedawca.h"

CSprzedawca::CSprzedawca() {

}

CSprzedawca::CSprzedawca(string a, string b, string c, string d, string e, string f) : CPodmiot(a,b,c,d) {
    login=e;
    password=f;
}

CSprzedawca::~CSprzedawca() {

}

string CSprzedawca::getLogin() {
    return login;
}

string CSprzedawca::getPassword() {
    return password;
}

void CSprzedawca::setLogin(string s) {
    login=s;
}

void CSprzedawca::setPassword(string s) {
    password=s;
}

void CSprzedawca::setNumerKonta(string s) {
    NumerKonta=s;
}
