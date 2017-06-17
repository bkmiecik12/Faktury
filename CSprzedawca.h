//
// Created by bkmiecik on 16.06.17.
//

#ifndef FAKTURY_CSPRZEDAWCA_H
#define FAKTURY_CSPRZEDAWCA_H


#include "CPodmiot.h"

class CSprzedawca: public CPodmiot {
public:
    CSprzedawca();
    CSprzedawca(string, string, string, string, string, string);
    ~CSprzedawca();
    string getLogin();
    string getPassword();
    void setLogin(string);
    void setPassword(string);
    string NumerKonta = "";
    void setNumerKonta(string);
private:
    string login;
    string password;

};


#endif //FAKTURY_CSPRZEDAWCA_H
