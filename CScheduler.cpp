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
        plik << ileFaktur << endl;
        for (int q = 0; q < tabsize; q++)
        {
            plik << tabF[q].numer << endl;
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
            plik << "--------------" << endl;
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
        int tabsize = ileFaktur;
        CFaktura *tab2 = new CFaktura[tabsize + 1];
        for (int i = 0; i < tabsize; i++)
        {
            tab2[i] = tabF[i];
        }
        tab2[tabsize] = t;
        tabF = tab2;
    }
    ileFaktur++;
}

void CScheduler::dodajSprzedawce(CSprzedawca s) {
    if (tabS == NULL)
    {
        tabS = new CSprzedawca[1];
        tabS[0] = s;
    }
    else
    {
        int tabsize = iluSprzed;
        CSprzedawca *tab2 = new CSprzedawca[tabsize + 1];
        for (int i = 0; i < tabsize; i++)
        {
            tab2[i] = tabS[i];
        }
        tab2[tabsize] = s;
        tabS = tab2;
    }
    iluSprzed++;
}

void CScheduler::dodajNabywce(CNabywca n) {
    if (tabN == NULL)
    {
        tabN = new CNabywca[1];
        tabN[0] = n;
    }
    else
    {
        int tabsize = iluNab;
        CNabywca *tab2 = new CNabywca[tabsize + 1];
        for (int i = 0; i < tabsize; i++)
        {
            tab2[i] = tabN[i];
        }
        tab2[tabsize] = n;
        tabN = tab2;
    }
    iluNab++;
}

void CScheduler::dodajTowar(CTowar t) {
    if (tabT == NULL)
    {
        tabT = new CTowar[1];
        tabT[0] = t;
    }
    else
    {
        int tabsize = ileTowarow;
        CTowar *tab2 = new CTowar[tabsize + 1];
        for (int i = 0; i < tabsize; i++)
        {
            tab2[i] = tabT[i];
        }
        tab2[tabsize] = t;
        tabT = tab2;
    }
    ileTowarow++;
}



CFaktura CScheduler::wprowadzFakture() {
    CFaktura f;
    cout<<"WPROWADZANIE NOWEJ FAKTURY\n";
    f.sprzedawca = zalogowany;
    f.datawystawienia = wprowadzDate();
    f.numer = wprowadzNumer();
    int nab= wybierzNabywce();
    if(nab>=0) f.nabywca=tabN[nab];
    else f.nabywca = wprowadzNabywce();
    int n=0;
    while(n>=0){
        n=wybierzTowar();
        if(n>=0)
            f.dodajtowar(tabT[n]);
    }
    cout<<"Do zapłaty brutto: "<<f.dozaplatyB()<<endl;
    f.sposobZaplaty = sposobZaplaty();
    if(f.sposobZaplaty=="Przelew" && f.sprzedawca.NumerKonta=="") {
        cout<<"PODAJ NUMER KONTA: ";
        string konto;
        cin>>konto;
        f.sprzedawca.NumerKonta=konto;
    }
    dodajFakture(f);
    return f;
}

void CScheduler::logowanie() {
//    system("cls"); //czyszczenie konsoli dla windowsa
    cout<< "Login: ";
    string login;
    cin >> login;
    cout<< "Haslo: ";
    string haslo;
    cin >> haslo;

    for(int i=0;i<iluSprzed;i++){
        if(tabS[i].getLogin()==login && tabS[i].getPassword()==haslo) {
            zalogowany = tabS[i];
            cout << zalogowany.getNazwa() << " witaj w systemie" << endl;
            return;
        }
    }
    cout<<"Niepoprawne dane\n";
    logowanie();

}

int CScheduler::wybierzNabywce() {
    cout<<"Lista nabywcow:\n";
    for(int i=0;i<iluNab;i++){
        printf("%2d. %-15s%-15s\n",i+1,tabN[i].getNazwa().c_str(),tabN[i].getAdres().c_str());
    }
    printf("%2d. Nowy nabywca\n",0);
    int wynik;
    cin>>wynik;
    if(wynik>0 && wynik<=iluSprzed) return wynik-1;
    else return -1;
}

CNabywca CScheduler::wprowadzNabywce() {
    string nazwa,adres,nip,regon;
    cout<<"NOWY NABYWCA\n";
    cout<<"Nazwa: ";
    cin>>nazwa;
    cout<<"\nAdres: ";
    cin>>adres;
    cout<<"\nNIP: ";
    cin>>nip;
    cout<<"\nREGON: ";
    cin>>regon;
    CNabywca wynik(nazwa,adres,nip,regon);
    dodajNabywce(wynik);
    return wynik;
}

int CScheduler::wybierzTowar() {
    //system("cls");
    cout<<"Lista towarow:\n";
    for(int i=0;i<ileTowarow;i++){
        printf("%2d. %s\n",i+1,tabT[i].getNazwaTowaru().c_str());
    }
    printf("%2d. Zakończ\n",0);
    int wynik;
    cin>>wynik;
    if(wynik>0 && wynik<=ileTowarow) return wynik-1;
    else return -1;
}

CKalendarz CScheduler::wprowadzDate() {
    int d,m,r;
    cout<<"Dzień: ";
    cin>>d;
    cout<<"Miesiąc: ";
    cin>>m;
    cout<<"Rok: ";
    cin>>r;
    CKalendarz k(d,m,r);
    if(k.sprawdzdate()) return k;
    else return wprowadzDate();
}

int CScheduler::wprowadzNumer() {
    int nr;
    cout<<"Wprowadź numer faktury: ";
    cin>>nr;
    return nr;
}

string CScheduler::sposobZaplaty() {
    string s;
    int n;
    cout<<"PODAJ SPOSÓB ZAPŁATY\n";
    cout<<"1. Gotówka\n";
    cout<<"2. Przelew\n";
    cin>>n;
    switch (n){
        case 1:
            return "Gotówka";
        case 2:
            return "Przelew";
        case 69:
            return "W naturze";
        default:
            return "Sposób niestandardowy";
    }
}




