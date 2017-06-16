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
    int tabsize = (sizeof(tab) / sizeof(tab[0]));
    for (int i = 0; i < tabsize; i++)
    {
        suma = suma + tab[i].brutto();
    }
    return suma;
}

double CFaktura::dozaplatyN() {
    double suma = 0;
    int tabsize = (sizeof(tab) / sizeof(tab[0]));
    for (int i = 0; i < tabsize; i++)
    {
        suma = suma + tab[i].wartoscnetto();
    }
    return suma;
}

double CFaktura::dozaplatyP() {
    double suma = 0;
    int tabsize = (sizeof(tab) / sizeof(tab[0]));
    for (int i = 0; i < tabsize; i++)
    {
        suma = suma + tab[i].podatek();
    }
    return suma;
}

void CFaktura::sposobzaplaty(int s) {
    if (s == 1)
        sposobZaplaty = "Przelew";

    else if (s == 2)
        sposobZaplaty = "Gotowka";
    else if (s == 69)
        sposobZaplaty = "W naturze";
    else
        cout << "Błšd";
}

void CFaktura::dodajtowar(CTowar t) {
    if (tab == NULL)
    {
        tab = new CTowar[1];
        tab[0] = t;
    }
    else
    {
        int tabsize = (sizeof(tab) / sizeof(tab[0]));
        CTowar *tab2 = new CTowar[tabsize + 1];
        for (int i = 0; i < tabsize; i++)
        {
            tab2[i] = tab[i];
        }
        tab2[tabsize] = t;
        tab = tab2;
    }
}
