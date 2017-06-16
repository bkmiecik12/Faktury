//
// Created by bkmiecik on 16.06.17.
//

#ifndef FAKTURY_CTOWAR_H
#define FAKTURY_CTOWAR_H

#include <iostream>

using namespace std;


class CTowar {
public:
    CTowar();
    CTowar(string nazwa, float cena, float i, string jed, int v);
    ~CTowar();
    string getNazwaTowaru();
    float getCenaNetto();
    string getJM();
    int getVAT();
    float getIlosc();
    void setNazwaTowaru(string);
    void setCenaNetto(float);
    void setJM(string);
    void setVAT(int);
    void setIlosc(float);
    float podatek();
    float wartoscnetto();
    float brutto();
private:
    string nazwatowaru;
    float cenanetto;
    string jm;
    int vat;
    float ilosc;
};


#endif //FAKTURY_CTOWAR_H
