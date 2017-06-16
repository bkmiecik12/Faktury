//
// Created by bkmiecik on 16.06.17.
//

#include "CScheduler.h"
#include <fstream>

CScheduler::CScheduler() {

}

CScheduler::~CScheduler() {

}

void CScheduler::zapiszF() {
    fstream plik;
    plik.open("faktury.txt", ios::out); //zapis

    if (plik.good() == false)
    {
        cout << "Plik nie istnieje!";
        return;
    }
    if (tabF != NULL)
    {

        int tabsize = ileFaktur;
        for (int q = 0; q < tabsize; q++)
        {
            plik << tabF[q].datawystawienia.dzien << endl;
            plik << tabF[q].datawystawienia.miesiac << endl;
            plik << tabF[q].datawystawienia.rok << endl;


            CSprzedawca s = tabF[q].sprzedawca;
            plik << s.getNazwa() << endl;
            plik << s.getAdres() << endl;
            plik << s.getNIP() << endl;
            plik << s.getREGON() << endl;

            CNabywca n = tabF[q].nabywca;
            plik << n.getNazwa() << endl;
            plik << n.getAdres() << endl;
            plik << n.getNIP() << endl;
            plik << n.getREGON() << endl;

            plik << tabF[q].sposobZaplaty << endl;

            if (tabF[q].tab != NULL)
            {
                int ileTowarow = tabF[q].ileTow;
                plik<<ileTowarow<<endl;
                for (int j = 0; j < ileTowarow; j++)
                {
                    plik << tabF[q].tab[j].getNazwaTowaru() << endl;
                    plik << tabF[q].tab[j].getCenaNetto() << endl;
                    plik << tabF[q].tab[j].getIlosc() << endl;
                    plik << tabF[q].tab[j].getJM() << endl;
                    plik << tabF[q].tab[j].getVAT() << endl;


                }
            }
            plik << "_________________" << endl;
        }
        plik.close();
    }
}

void CScheduler::odczytF() {

}

void CScheduler::dodajFakture(CFaktura t) {
    if (tabF == NULL)
    {
        tabF = new CFaktura[1];
        tabF[0] = t;
    }
    else
    {
        int tabsize = (sizeof(*tabF) / sizeof(tabF[0]));
        CFaktura *tab2 = new CFaktura[tabsize + 1];
        for (int i = 0; i < tabsize; i++)
        {
            tab2[i] = tabF[i];
        }
        tab2[tabsize] = t;
        tabF = tab2;
    }
}

void CScheduler::dodajSprzedawce(CSprzedawca) {

}

void CScheduler::dodajNabywce(CNabywca) {

}

void CScheduler::dodajtowar(CTowar) {

}
