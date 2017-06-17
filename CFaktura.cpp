//
// Created by bkmiecik on 16.06.17.
//

#include "CFaktura.h"

CFaktura::CFaktura() {

}

CFaktura::~CFaktura() {

}

double CFaktura::dozaplatyB() {
    double suma = 0;
    int tabsize = ileTow;
    for (int i = 0; i < tabsize; i++)
    {
        suma = suma + tab[i].brutto();
    }
    return suma;
}

double CFaktura::dozaplatyN() {
    double suma = 0;
    int tabsize = ileTow;
    for (int i = 0; i < tabsize; i++)
    {
        suma = suma + tab[i].wartoscnetto();
    }
    return suma;
}

double CFaktura::dozaplatyP() {
    double suma = 0;
    int tabsize = ileTow;
    for (int i = 0; i < tabsize; i++)
    {
        suma = suma + tab[i].podatek();
    }
    return suma;
}

void CFaktura::dodajtowar(CTowar t) {
    if (tab == NULL)
    {
        tab = new CTowar[1];
        tab[0] = t;
    }
    else
    {
        int tabsize = ileTow;
        CTowar *tab2 = new CTowar[tabsize + 1];
        for (int i = 0; i < tabsize; i++)
        {
            tab2[i] = tab[i];
        }
        tab2[tabsize] = t;
        tab = tab2;
    }
    ileTow++;
}
