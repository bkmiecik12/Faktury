//
// Created by bkmiecik on 16.06.17.
//

#ifndef FAKTURY_CSCHEDULER_H
#define FAKTURY_CSCHEDULER_H


#include "CTowar.h"
#include "CNabywca.h"
#include "CSprzedawca.h"
#include "CFaktura.h"

class CScheduler {
public:
    CScheduler();
    ~CScheduler();
    CFaktura *tabF=NULL;
    int ileFaktur = 0;
    CSprzedawca *tabS;
    int iluSprzed=0;
    CNabywca *tabN;
    int iluNab=0;
    void zapiszF();
    void odczytF();
    void dodajFakture(CFaktura);
    void dodajSprzedawce(CSprzedawca);
    void dodajNabywce(CNabywca);
    void dodajtowar(CTowar);
};


#endif //FAKTURY_CSCHEDULER_H
