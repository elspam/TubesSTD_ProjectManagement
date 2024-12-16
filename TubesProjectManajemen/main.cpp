#include <iostream>
#include "ProMan.h"

using namespace std;

int main()
{
    LPrg lprg;
    LPrj lprj;
    LPng lpng;
    adrPenugasan aPng;
    int login;
    dataProgrammer dataprg;
    dataProject dataprj;

    login = menuLogin();
    cout<<endl;
    while (login!=4){
        switch(login){
        //menu admin
        case 1:
            int admin;
            admin = menuAdmin();
            cout<<endl;
            while(admin!=9){
                switch(admin){
                case 1:
                    //insert programmer
                    createListProgrammer(lprg);
                    buildListProgrammer(lprg);
                    viewDataProgrammer(lprg);
                    cout<<endl;
                    break;

                case 2:
                    //insert project
                    createListProject(lprj);
                    buildListProject(lprj);
                    viewDataProject(lprj);
                    cout<<endl;
                    break;

                case 3:
                    //edit programmer
                    cout<< "============================================="<<endl;
                    cout<< "              Edit Data Programmer           "<<endl;
                    cout<< "============================================="<<endl;
                    viewDataProgrammer(lprg);
                    cout << "Masukan Username yang ingin diperbarui : ";
                    cin >> dataprg.username;
                    cout << endl;
                    editProgrammer(lprg, dataprg);
                    cout<<endl;
                    break;

                case 4:
                    //edit project
                    cout<< "============================================="<<endl;
                    cout<< "                Edit Data Project            "<<endl;
                    cout<< "============================================="<<endl;
                    cout<<endl;
                    viewDataProject(lprj);
                    cout<<endl;
                    cout << "Masukan Project yang ingin diperbarui DL nya : ";
                    cin >> dataprj.namaProject;
                    editProject(lprj, dataprj);
                    cout<<endl;
                    break;

                case 5:
                    //delete programmer
                    cout<< "============================================="<<endl;
                    cout<< "              Delete Data Programmer         "<<endl;
                    cout<< "============================================="<<endl;
                    cout<<endl;
                    viewDataProgrammer(lprg);
                    cout << "Masukan username yang ingin dihapus : ";
                    cin >> dataprg.username;
                    deleteProgrammer(lprg, dataprg);
                    cout<<endl;
                    break;

                case 6:
                    //delete project
                    cout<< "============================================="<<endl;
                    cout<< "               Delete Data Project           "<<endl;
                    cout<< "============================================="<<endl;
                    cout<<endl;
                    viewDataProject(lprj);
                    cout<<endl;
                    cout << "Masukan nama project yang ingin dihapus : ";
                    cin >> dataprj.namaProject;
                    deleteProject(lprj, dataprj);
                    cout<<endl;
                    break;

                case 7:
                    //view project
                    viewDataProject(lprj);
                    break;

                case 8:
                    //view programmer
                    viewDataProgrammer(lprg);
                    break;

                case 9:
                    //back
                    break;
                }
                admin = menuAdmin();
                cout<<endl;
            }
            break;
        case 2:
            //menu manager
            int manager;
            manager = menuManager();
            cout<<endl;
            while(manager != 6){
                switch(manager){
                case 1:
                    //Input penugasan
                    createListPenugasan(lpng);
                    cout<< "============================================="<<endl;
                    cout<< "         Buat Penugasan Untuk Programmer     "<<endl;
                    cout<< "============================================="<<endl;
                    viewDataProgrammer(lprg);
                    viewDataProject(lprj);
                    cout<<"Jika sudah inputkan 'selesai'! "<<endl;
                    connect(lpng,lprg,lprj,dataprg,dataprj);
                    cout<<endl;
                    break;

                case 2:
                    //Cabut penugasan
                    cout<< "============================================="<<endl;
                    cout<< "        Cabut Penugasan Untuk Programmer     "<<endl;
                    cout<< "============================================="<<endl;
                    viewDataProgrammer(lprg);
                    viewDataProject(lprj);
                    cout<<"Jika sudah inputkan 'selesai'! "<<endl;
                    disconnect(lpng, lprg, lprj, dataprg, dataprj);
                    cout<<endl;
                    break;

                case 3:
                    //view penugasan programmer
                    viewPenugasanProgrammer(lpng, lprg,lprj);
                    cout<<endl;
                    break;

                case 4:
                    //view detail penugasan project
                    viewPenugasanProject(lpng, lprg,lprj);
                    cout<<endl;
                    break;

                case 5:
                    //edit status penugasan
                    viewDataProgrammer(lprg);
                    viewDataProject(lprj);
                    editPenugasan(lpng,lprg,lprj,dataprg,dataprj);
                    cout<<endl;
                    break;

                case 6:
                    //back
                    break;

                }
                manager = menuManager();
                cout<<endl;
            }
            break;
        case 3:
            //menu programmer
            int menPrg;
            menPrg = menuProgrammer();
            cout<<endl;
            while (menPrg!=2){
                switch (menPrg){
                case 1:
                    //lihat penugasan programmer
                    cout<<endl;
                    break;

                case 2:
                    //back
                    break;
                }
                menPrg = menuProgrammer();
                cout<<endl;
            }
            break;

        case 4:
            //back
            break;
        }
        login = menuLogin();
        cout<<endl;

    }


//    //insert data programmer
//    createListProgrammer(lprg);
//    buildListProgrammer(lprg);
//    viewDataProgrammer(lprg);
//
//   /* cout<<"Delete data programmer"<<endl;
//    cout<<"Masukkan username yang ingin dihapus: ";
//    cin >>dataprg.username;
//    cout<<endl;
//    deleteProgrammer(lprg,dataprg);*/
//
//    //insert data Project
//    createListProject(lprj);
//    buildListProject(lprj);
//    viewDataProject(lprj);
//
//    // Delete data project
//   /* cout << "Delete data project" << endl;
//    cout << "Masukkan nama project yang ingin dihapus: ";
//    cin >> dataprj.namaProject;
//    cout << endl;
//    deleteProject(lprj, dataprj);
//
//    // Edit data Programmer
//    cout << "Edit data Programmer" << endl;
//    cout << "Masukan Username yang ingin di perbaharui: ";
//    cin >> dataprg.username;
//    cout << endl;
//    editProgrammer(lprg, dataprg);
//
//    // Edit data Project
//    cout << "Edit data project" << endl;
//    cout << "Masukan Nama Project yang ingin diperbaharui: ";
//    cin >> dataprj.namaProject;
//    cout <<endl;
//    editProject(lprj, dataprj); */
//
//    //buat relasi penugasan
//    cout << "Buat penugasan untuk programmer"<<endl;
//    createListPenugasan(lpng);
//    viewDataProgrammer(lprg);
//    viewDataProject(lprj);
//
//    cout<< "Inputkan 'selesai' jika ingin mengakhiri input penugasan! "<<endl;
//    connect(lpng, lprg, lprj, dataprg, dataprj);
//    viewPenugasanProgrammer(lpng, lprg,lprj);
//
//    editPenugasan(lpng,lprg,lprj,dataprg,dataprj);
//    viewPenugasanProject(lpng, lprg,lprj);
//
//
//    cout<< "Inputkan 'selesai' jika ingin mengakhiri cabut penugasan! "<<endl;
//    disconnect(lpng, lprg, lprj, dataprg, dataprj);
//    viewPenugasanProgrammer(lpng, lprg,lprj);
//    viewPenugasanProject(lpng, lprg,lprj);

    return 0;
}
