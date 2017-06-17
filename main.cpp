#include <iostream>
#include "CSprzedawca.h"
#include "CNabywca.h"
#include "CTowar.h"
#include "CScheduler.h"

using namespace std;

int main() {
    CSprzedawca s1("Polak rodak","0","2137-2137","1234-1488","aaa","bbb");
    CNabywca n1("Polak43rodak", "3", "2132337", "22332");
    //cout<<s1.getNazwa();
    //printf("%-30s%-30s\n\n%-30s%-30s\n%-30s%-30s\n%-30s%-30s\n%-30s%-30s\n\n\n","SPRZEDAWCA","NABYWCA", s1.getNazwa().c_str(), n1.getNazwa().c_str(), s1.getAdres().c_str(), n1.getAdres().c_str(), s1.getNIP().c_str(), n1.getNIP().c_str(), s1.getREGON().c_str(), n1.getREGON().c_str());
    CTowar t1("Kremówki",2.30,3,"szt.",23);
    CTowar t2("Kremówki2",5.30,4,"szt.",23);
    CTowar t3("Kremówki3",1.30,0.3,"szt.",8);
    CScheduler scheduler;
    CFaktura f1;

    f1.nabywca=n1;
    f1.sprzedawca=s1;
    f1.dodajtowar(t1);
    f1.dodajtowar(t2);
    f1.dodajtowar(t3);
    f1.sposobZaplaty= "Gotówka";
    f1.datawystawienia = CKalendarz(16,06,17);
//    scheduler.dodajFakture(f1);
    scheduler.dodajTowar(t1);
    scheduler.dodajTowar(t2);
    scheduler.dodajTowar(t3);
    scheduler.dodajSprzedawce(s1);
    scheduler.dodajNabywce(n1);
//    scheduler.zapiszF();
    scheduler.odczytF();
    scheduler.menu0();

//    cout<<scheduler.ileFaktur<<endl;
//    cout<<scheduler.ileTowarow;

}