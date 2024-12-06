#ifndef PROMAN_H_INCLUDED
#define PROMAN_H_INCLUDED
#include <iostream>
#define infoPrg(l) l->infoPrg
#define infoPrj(l) l->infoPrj
#define infoPng(l) l->infoPng
#define nextPrg(l) l->nextPrg
#define nextPrj(l) l->nextPrj
#define prevPrg(l) l->prevPrg
#define prevPrj(l) l->prevPrj
#define firstPrg(l) l.firstPrg
#define firstPrj(l) l.firstPrj
#define lastPrg(l) l.lastPrg
#define lastPrj(l) l.lastPrj
#define firstPng(l) l.firstPng
#define pPrg(l) l->pPrg
#define pPrj(l) l->pPrj
#define nextPng(l) l->nextPng

using namespace std;


typedef struct programmer *adrProgrammer;
typedef struct project *adrProject;
typedef struct penugasan *adrPenugasan;


//struct info dari programmer
struct dataProgrammer {
    string username, keahlian;
    int totalPenugasan;
};

//strcut info dari project
struct dataProject {
    string namaProject;
    int deadline;
};

//struct info dari penugasan
struct dataPenugasan{
    string status;
};

//struct elemen programmer
struct programmer{
    dataProgrammer infoPrg;
    adrProgrammer nextPrg;
    adrProgrammer prevPrg;
};

//struct elemen project
struct project{
    dataProject infoPrj;
    adrProject nextPrj;
    adrProject prevPrj;
};

//struct elemen penugasan
struct penugasan{
    adrProgrammer pPrg;
    adrProject pPrj;
    adrPenugasan nextPng;
    dataPenugasan infoPng;
};

//struct list programmer
struct LPrg{
   adrProgrammer firstPrg;
   adrProgrammer lastPrg;
};

//struct list project
struct LPrj{
    adrProject firstPrj;
    adrProject lastPrj;
};

//struct list penugasan
struct LPng{
    adrPenugasan firstPng;
};

//menu untuk login dan menu yang bisa diakses akktor
int menuLogin();
int menuAdmin();
int menuManager();
int menuProgrammer();



//insert first data programmer
void insertProgrammer(LPrg &l, dataProgrammer x);

//insert last data project
void insertProject(LPrj &l, dataProject x);

//inset first relasi penugasan
void insertPenugasan(LPng &l, adrPenugasan p);


//Delete data programmer
void deleteProgrammer(LPrg &l, dataProgrammer x);
void deleteFirstProgrammer(LPrg &l, adrProgrammer p);
void deleteLastProgrammer(LPrg &l, adrProgrammer p);
void deleteAfterProgrammer(LPrg &l, adrProgrammer prec, adrProgrammer p);

//Delete data project
void deleteProject(LPrj &l, dataProject x);
void deleteFirstProject(LPrj &l, adrProject &p);
void deleteLastProject(LPrj &l, adrProject &p);
void deleteAfterProject(LPrj &l, adrProject prec, adrProject &p);

//Delete relasi penugasan
void deletePenugasan(LPng &l, adrPenugasan &p);
void deleteFirstPenugasan(LPng &l, adrPenugasan &p);
void deleteLastPenugasan(LPng &l, adrPenugasan &p);
void deleteAfterPenugasan(LPng &l, adrPenugasan prec, adrPenugasan &p);

//edit data
void editProgrammer(LPrg &l, dataProgrammer x);
void editProject(LPrj &l, dataProject x);
void editPenugasan(LPng &l, dataProgrammer xPrg, dataProject xPrj);

//count data
int countProgrammer(LPrg l);
int countProject(LPrj l);

//view data
void viewDataProgrammer(LPrg l);
void viewDataProject(LPrj l);
void viewPengugasan(LPng png, LPrg prg, LPrj prj);


//create list
void createListProgrammer(LPrg &prg);
void createListProject(LPrj &prj);
void createListPenugasan(LPng &png);


//create elemen
void createElmProgrammer(dataProgrammer x, adrProgrammer &prg);
void createElmProject(dataProject y, adrProject &prj);
void createElmPenugasan(adrProgrammer prg, adrProject prj, adrPenugasan &png);


//Build List memasukkan data ke dalam list berdasarkan syarat tertentu, misal Progammer username harus unik
void buildListProgrammer(LPrg &l);
void buildListProject(LPrj &l);

//Find data
adrProgrammer findDataProgrammer(LPrg l, dataProgrammer x);
adrProject findDataProject(LPrj &l, dataProject x);
adrPenugasan findRelasiPenugasan(LPng &l, dataProject xPrj, dataProgrammer xPrg);

//Edit data
void editProgrammer(LPrg &l, dataProgrammer x);
void editProject(LPrj &l, dataProject x);
//void editPenugasan(LPng &l, dataProject x);

//connect & disconnect
void connect(LPng &png, LPrg prg, LPrj prj, dataProgrammer xPrg, dataProject xPrj);
void disconnect(LPng &png, dataProgrammer xPrg, dataProject xPrj);

#endif // PROMAN_H_INCLUDED
