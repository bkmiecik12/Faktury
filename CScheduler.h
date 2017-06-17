//
// Created by bkmiecik on 16.06.17.
//

#ifndef FAKTURY_CSCHEDULER_H
#define FAKTURY_CSCHEDULER_H


#include "CTowar.h"
#include "CNabywca.h"
#include "CSprzedawca.h"
#include "CFaktura.h"
#include <stdio.h>

class CScheduler {
public:
    CScheduler();
    ~CScheduler();

    CSprzedawca zalogowany;

    CFaktura *tabF=NULL;
    int ileFaktur = 0;

    CSprzedawca *tabS;
    int iluSprzed=0;

    CNabywca *tabN;
    int iluNab=0;

    CTowar *tabT;
    int ileTowarow=0;

    void zapiszF();
    void odczytF();

    void logowanie();

    void dodajFakture(CFaktura);
    void dodajSprzedawce(CSprzedawca);
    void dodajNabywce(CNabywca);
    void dodajTowar(CTowar);

    CFaktura wprowadzFakture();
    CNabywca wprowadzNabywce();
    CKalendarz wprowadzDate();
    int wybierzNabywce();
    int wybierzTowar();
    int wprowadzNumer();
    string sposobZaplaty();


};


#endif //FAKTURY_CSCHEDULER_H
