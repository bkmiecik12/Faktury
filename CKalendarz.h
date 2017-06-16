//
// Created by bkmiecik on 16.06.17.
//

#ifndef FAKTURY_CKALENDARZ_H
#define FAKTURY_CKALENDARZ_H


class CKalendarz {
public:
    CKalendarz();
    CKalendarz(int, int, int);
    ~CKalendarz();
    int dzien;
    int miesiac;
    int rok;
    void drukujdate();
    bool sprawdzdate();
};


#endif //FAKTURY_CKALENDARZ_H
