#include <iostream>
#include "CSprzedawca.h"
#include "CNabywca.h"
#include "CTowar.h"

using namespace std;

int main() {
    CSprzedawca s1("Polak rodak","0","2137-2137","1234-1488","aaa","bbb");
    CNabywca n1("Polak43rodak", "3", "2132337", "22332");
    cout<<s1.getNazwa();
    //printf("%30s%30s\n%30s%30s\n%30s%30s\n%30s%30s\n", s1.getNazwa(), n1.getNazwa(), s1.getAdres(), n1.getAdres(), s1.getNIP(), n1.getNIP(), s1.getREGON(), n1.getREGON());
    CTowar t1();

}