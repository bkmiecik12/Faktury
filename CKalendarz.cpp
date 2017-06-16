//
// Created by bkmiecik on 16.06.17.
//

#include <cstdio>
#include "CKalendarz.h"

CKalendarz::CKalendarz() {

}

CKalendarz::CKalendarz(int d, int m, int r) {
    dzien = d;
    miesiac = m;
    rok = r;
}

CKalendarz::~CKalendarz() {

}

void CKalendarz::drukujdate() {
    printf("%2d.%2d.%4d", dzien, miesiac, rok);
}

bool CKalendarz::sprawdzdate() {
    if ((miesiac == 1 || miesiac == 3 || miesiac == 5 || miesiac == 7 || miesiac == 8 || miesiac == 10 || miesiac == 12) && (dzien > 0 && dzien < 32))
    {
        return true;
    }
    else if (miesiac == 2)
    {
        if ((rok % 4 == 0 && rok % 100 != 0) && (dzien > 0 && dzien < 30))
        {
            return true;
        }
        else if(dzien > 0 && dzien < 29)
        {
            return true;
        }
    }
    else return (dzien > 0 && dzien < 31) && (miesiac > 2 && miesiac < 12);
}
