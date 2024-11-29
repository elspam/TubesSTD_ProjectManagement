#ifndef PROMAN_H_INCLUDED
#define PROMAN_H_INCLUDED
#include <iostream>
#define infoPrg(l) l->infoPrg
#define infoPrj(l) l->infoPrj
#define nextPrg(l) l->nextPrg
#define nextPrj(l) l->nextPrj
#define prevPrg(l) l->prevPrg
#define prevPrj(l) l->prevPrj
#define firstPrg(l) l.firstPrg
#define firstPrj(l) l.firstPrj
#define lastPrg(l) l.lastPrg
#define lastPrj(l) l.lastPrj
#define firstRls(l) l.firstRls
#define pPrg(l) l->pPrg
#define pPrj(l) l->pPrj
#define nextRls(l) l->nextRls

using namespace std;


typedef struct programmer *adrProgrammer;
typedef struct project *adrProject;
typedef struct relasi *adrRelasi;

struct dataProgrammer {
    string username, nama, keahlian;
    int umur;
};

struct dataProject {
    string nama;
    int deadline;
};

struct programmer{
    dataProgrammer infoPrg;
    adrProgrammer nextPrg;
    adrProgrammer prevPrg;
};

struct project{
    dataProject infoPrj;
    adrProject nextPrj;
    adrProject prevPrj;
};

struct relasi{
    adrProgrammer pPrg;
    adrProject pPrj;
    adrRelasi nextRls;
};

struct LPrg{
   adrProgrammer firstPrg;
   adrProgrammer lastPrg;
};

struct LPrj{
    adrProject firstPrj;
    adrProject lastPrj;
};

struct LRls{
    adrRelasi firstRls;
};

int menuLogin();
int menuAdmin();
int menuManager();
int menuProgrammer();

void



#endif // PROMAN_H_INCLUDED
