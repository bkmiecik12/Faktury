//
// Created by bkmiecik on 16.06.17.
//

#ifndef FAKTURY_CPODMIOT_H
#define FAKTURY_CPODMIOT_H

#include <iostream>

using namespace std;


class CPodmiot {
public:
    CPodmiot();
    CPodmiot(string, string, string, string);
    ~CPodmiot();
    string getNazwa();
    string getAdres();
    string getNIP();
    string getREGON();
    void setNazwa(string);
    void setAdres(string);
    void setNIP(string);
    void setREGON(string);

private:
    string nazwa;
    string adres;
    string nip;
    string regon;
};


#endif //FAKTURY_CPODMIOT_H
