#include <iostream>
#include "ProMan.h"

using namespace std;

int main()
{
    LPrg lprg;
    LPrj lprj;
    LPng lpng;
    int Nprogrammer;
    dataProgrammer dataprg;
    dataProject dataprj;

    //insert data programmer
    createListProgrammer(lprg);
    buildListProgrammer(lprg);
    viewDataProgrammer(lprg);

    /*cout<<"Delete data programmer"<<endl;
    cout<<"Masukkan username yang ingin dihapus: ";
    cin >>dataprg.username;
    cout<<endl;
    //deleteProgrammer(lprg,dataprg);*/

    //insert data Project
    createListProject(lprj);
    buildListProject(lprj);
    viewDataProject(lprj);

    // Delete data project
    /*cout << "Delete data project" << endl;
    cout << "Masukkan nama project yang ingin dihapus: ";
    cin >> dataprj.namaProject;
    cout << endl;
    deleteProject(lprj, dataprj);*/


    //buat relasi penugasan
    /*cout << "Buat penugasan untuk programmer"<<endl;
    createListPenugasan(lpng);
    viewDataProgrammer(lprg);
    viewDataProject(lprj);

    cout<< "Inputkan 'selesai' jika ingin mengakhiri input penugasan! "<<endl;
    connect(lpng, lprg, lprj, dataprg, dataprj);
    viewPengugasan(lpng, lprg,lprj);*/

    return 0;
}
