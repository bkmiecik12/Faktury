//
// Created by bkmiecik on 16.06.17.
//

#ifndef FAKTURY_CFAKTURA_H
#define FAKTURY_CFAKTURA_H


#include "CKalendarz.h"
#include "CNabywca.h"
#include "CSprzedawca.h"
#include "CTowar.h"

class CFaktura {
public:
    CFaktura();
    ~CFaktura();
    CSprzedawca sprzedawca;
    CNabywca nabywca;
    CTowar *tab;
    int ileTow=0;
    CKalendarz datawystawienia;
    int numer;
    string sposobZaplaty;
    void dodajtowar(CTowar);
    double dozaplatyB();
    double dozaplatyN();
    double dozaplatyP();

};


#endif //FAKTURY_CFAKTURA_H
