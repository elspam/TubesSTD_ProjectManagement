#include <iostream>
#include "ProMan.h"

using namespace std;

int menuLogin(){
    cout<<"=============================================="<<endl;
    cout<<"<<<<<********     MENU LOGIN     ********>>>>>"<<endl;
    cout<<"=============================================="<<endl;
    cout<<"1. Login sebagai Admin"<<endl;
    cout<<"2. Login sebagai Manager"<<endl;
    cout<<"3. Login sebagai Programmer"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"Masukkan pilihan(1/2/3/4): ";

    int input = 0;
    cin >> input;
    cout<<endl;
    return input;

}

int menuAdmin(){
    cout<<"=============================================="<<endl;
    cout<<"<<<<<********     MENU ADMIN     ********>>>>>"<<endl;
    cout<<"=============================================="<<endl;
    cout<<"1. Insert Data Programmer "<<endl;
    cout<<"2. Insert Data Project "<<endl;
    cout<<"3. Edit data programmer"<<endl;
    cout<<"4. Edit data project"<<endl;
    cout<<"5. Delete data programmer"<<endl;
    cout<<"6. Delete data project"<<endl;
    cout<<"7. View project "<<endl;
    cout<<"8. View programmer"<<endl;
    cout<<"9. Back"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"Masukkan pilihan(1/2/3/4): ";

    int input = 0;
    cin >> input;
    return input;
}

int menuManager(){
    cout<<"=============================================="<<endl;
    cout<<"<<<<<********    MENU MANAGER    ********>>>>>"<<endl;
    cout<<"=============================================="<<endl;
    cout<<"1. Input penugasan "<<endl;
    cout<<"2. Cabut penugasan "<<endl;
    cout<<"3. View detail penugasan programmer"<<endl;
    cout<<"4. View detail penugasan project"<<endl;
    cout<<"5. Edit status penugasan"<<endl;
    cout<<"6. Back"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"Masukkan pilihan(1/2/3/4): ";

    int input = 0;
    cin >> input;
    return input;
}

int menuProgrammer(){
    cout<<"=============================================="<<endl;
    cout<<"<<<<<********   MENU PROGRAMMER  ********>>>>>"<<endl;
    cout<<"=============================================="<<endl;
    cout<<"1. Lihat detail penugasan"<<endl;
    cout<<"2. Back"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"Masukkan pilihan(1/2/3/4): ";

    int input = 0;
    cin >> input;
    return input;
}

//create list
void createListProgrammer(LPrg &prg){
    firstPrg(prg) = NULL;
    lastPrg(prg) = NULL;
}
void createListProject(LPrj &prj){
    firstPrj(prj) = NULL;
    lastPrj(prj) = NULL;
}

void createListPenugasan(LPng &png){
    firstPng(png) = NULL;
}

//create elemen
void createElmProgrammer(dataProgrammer x, adrProgrammer &prg){
    prg = new programmer;
    infoPrg(prg).username = x.username;
    infoPrg(prg).keahlian = x.keahlian;
    infoPrg(prg).totalPenugasan = 0;
    nextPrg(prg) = NULL;
    prevPrg(prg) = NULL;
}
void createElmProject(dataProject y, adrProject &prj){
    prj = new project;
    infoPrj(prj).namaProject = y.namaProject;
    infoPrj(prj).deadline = y.deadline;
    infoPrj(prj).status = y.status;
    nextPrj(prj) = NULL;
    prevPrj(prj) = NULL;
}

void createElmPenugasan(adrProgrammer p, adrProject q, adrPenugasan &png){
    png = new penugasan;
    pPrg(png) = p;
    pPrj(png) = q;
    infoPng(png).status = "on_going";
    nextPng(png) = NULL;
}

//insert data programmer
void insertProgrammer(LPrg &l, dataProgrammer x){
    adrProgrammer p;
    createElmProgrammer(x,p);
    if (firstPrg(l) == NULL){
        firstPrg(l) = p;
        lastPrg(l) = p;
    }else{
        nextPrg(p) = firstPrg(l);
        prevPrg(firstPrg(l)) = p;
        firstPrg(l) = p;
    }

}


//insert Data project
void insertProject(LPrj &l, dataProject x){
    adrProject p;
    createElmProject(x, p);
    if (firstPrj(l) == NULL){
        firstPrj(l) = p;
        lastPrj(l) = p;
    } else {
        prevPrj(p) = lastPrj(l);
        nextPrj(lastPrj(l)) = p;
        lastPrj(l) = p;
    }
}


//Insert data penugasan
void insertPenugasan(LPng &l, adrPenugasan p){
    if (firstPng(l) == NULL){
        firstPng(l) = p;
    }else{
        nextPng(p) = firstPng(l);
        firstPng(l) = p;
    }
}


//buildListProgrammer
void buildListProgrammer(LPrg &l){
    adrProgrammer p;
    dataProgrammer x;
    int i = 1 ;
    int n;
    cout<< "============================================="<<endl;
    cout<< "             Insert Data Programmer          "<<endl;
    cout<< "============================================="<<endl;
    cout<<"Masukkan banyak data yang ingin disimpan: ";
    cin >> n;
    cout<<endl;
    cout << "Username ke-1: ";
    cin >> x.username;
    cout << "keahlian: ";
    cin >> x.keahlian;
    cout<<endl;
    if (firstPrg(l) == NULL){
        insertProgrammer(l, x);
    }
    while(i<n){
        adrProgrammer p;
        cout << "Username ke- " << i+1 <<" : ";
        cin >> x.username;
        cout << "keahlian: ";
        cin >> x.keahlian;
        cout<<endl;
        p = findDataProgrammer(l,x);
        if (p==NULL){
            insertProgrammer(l, x);
        }else {
            cout<<"Username ini sudah pernah dimasukkan! "<<endl;
        }
        i++;

    }

}

//build Project
void buildListProject(LPrj &l){
    adrProject p;
    dataProject x;
    int i = 1;
    int n;
    cout<< "============================================="<<endl;
    cout<< "             Insert Data Project             "<<endl;
    cout<< "============================================="<<endl;
    cout<< "Masukan jumlah project yang ingin disimpan: ";
    cin>>n;
    cout<<endl;
    cout << "Project ke-1: ";
    cin >> x.namaProject;
    cout << "deadline (satuan hari): ";
    cin >> x.deadline;
    x.status = "on_going";
    cout<<endl;
    if (firstPrj(l) == NULL){
        insertProject(l, x);
    }
    while(i<n){
        adrProject p;
        cout << "Project ke- " << i+1 <<" : ";
        cin >> x.namaProject;
        cout << "deadline (satuan hari): ";
        cin >> x.deadline;
        x.status = "on_going";
        cout<<endl;
        p = findDataProject(l,x);
        if (p==NULL){
            insertProject(l, x);
        }else {
            cout<<"Username ini sudah pernah dimasukkan"<<endl;
        }
        i++;

    }
}

//delete data programmer
void deleteFirstProgrammer(LPrg &l, adrProgrammer p){
    if (firstPrg(l) == NULL){
        cout<<"Data kosong";
    }else if (firstPrg(l) == lastPrg(l)){
        p = firstPrg(l);
        firstPrg(l) = NULL;
        lastPrg(l) = NULL;
    }else {
        p = firstPrg(l);
        firstPrg(l) = nextPrg(p);
        nextPrg(p) = NULL;
        prevPrg(firstPrg(l)) = NULL;
    }

}

void deleteLastProgrammer(LPrg &l, adrProgrammer q){
    if (firstPrg(l) == NULL){
        cout<<"Data kosong";
    }else if (firstPrg(l) == lastPrg(l)){
        q = lastPrg(l);
        firstPrg(l) = NULL;
        lastPrg(l) = NULL;
    }else {
        q = lastPrg(l);
        lastPrg(l) = prevPrg(lastPrg(l));
        nextPrg(lastPrg(l))=NULL;
        prevPrg(q) = NULL;
    }

}

void deleteAfterProgrammer(LPrg &l, adrProgrammer prec, adrProgrammer r){
    if (firstPrg(l) == NULL){
        cout<<"List Kosong"<<endl;
    }else if(nextPrg(prec) == lastPrg(l)){
        deleteLastProgrammer(l,r);
    }else if (nextPrg(prec) == NULL) {
        cout<< "Tidak ada elemen setelah prec";
    }else{
        r = nextPrg(prec);
        nextPrg(prec) = nextPrg(r);
        prevPrg(nextPrg(r)) = prec;
        prevPrg(r) = NULL;
        nextPrg(r) = NULL;

    }
}

void deleteProgrammer(LPrg &l, dataProgrammer xPrg){
    adrProgrammer adrPrg;
    adrPrg = findDataProgrammer(l,xPrg);
    if (adrPrg==NULL){
        cout<<"Data yang ingin dihapus tidak ada dalam list"<<endl;
    }else{
        if(adrPrg==firstPrg(l)){
            deleteFirstProgrammer(l,adrPrg);
        }else if (adrPrg == lastPrg(l)){
            deleteLastProgrammer(l,adrPrg);
        }else {
            deleteAfterProgrammer(l,prevPrg(adrPrg),adrPrg);
        }
        cout<<"Data setelah dihapus: "<<endl;
        viewDataProgrammer(l);
    }


}


//delete data project
void deleteFirstProject(LPrj &l, adrProject &a){
    if(firstPrj(l) == NULL ){
        cout<<"list Project Kosong!"<<endl;
    } else {
        a = firstPrj(l);
        if (firstPrj(l) == lastPrj(l)){
            firstPrj(l) = NULL;
            lastPrj(l) = NULL;
        } else {
            a = firstPrj(l);
            firstPrj(l) = nextPrj(a);
            nextPrj(a) = NULL;
            prevPrj(firstPrj(l)) = NULL;
        }
    }
}

void deleteLastProject(LPrj &l, adrProject &b){
    if(firstPrj(l)==NULL){
        cout<< "List project kosong!" << endl;
    } else if (firstPrj(l) == lastPrj(l)) {
        b = firstPrj(l);
        firstPrj(l) = NULL;
        lastPrj(l) = NULL;
    } else {
        b = lastPrj(l);
        lastPrj(l) = prevPrj(b);
        prevPrj(b)= NULL;
        nextPrj(lastPrj(l)) = NULL;
    }

}

void deleteAfterProject(LPrj &l, adrProject prec, adrProject &c){
    if(prec == NULL || nextPrj(prec) == NULL){
        cout << "tidak ada elemen setelah elemen ini" <<endl;
    } else if(nextPrj(prec) == lastPrj(l)){
        deleteLastProject(l,c);
    }else {
        c = nextPrj(prec);
        nextPrj(prec) = nextPrj(c);
        prevPrj(nextPrj(c)) = prec;
        prevPrj(c) = NULL;
        nextPrj(c) = NULL;
    }
}

void deleteProject(LPrj &l, dataProject xPrj) {
    adrProject adrPrj;
    adrPrj = findDataProject(l, xPrj);
    if(adrPrj == NULL){
        cout<< "Data yang ingin dihapus tidak ada dalam list "<<endl;
    }else {
        if(adrPrj==firstPrj(l)){
            deleteFirstProject(l,adrPrj);
        }else if (adrPrj == lastPrj(l)){
            deleteLastProject(l,adrPrj);
        }else {
            deleteAfterProject(l,prevPrj(adrPrj),adrPrj);
        }
        cout<<"Data setelah dihapus: "<<endl;
        viewDataProject(l);
    }

}

//delete data penugasan
void deletePenugasan(LPng &l, adrPenugasan &p){
    if (p==NULL){
        cout<<"Data yang ingin dihapus tidak ada dalam list";
    }else{
        if(p==firstPng(l)){
            deleteFirstPenugasan(l,p);
        }else if (nextPng(p)==NULL){
            deleteLastPenugasan(l,p);
        }else {
           adrPenugasan prec = firstPng(l);
           while(nextPng(prec)!=NULL){
            prec = nextPng(prec);
           }
           deleteAfterPenugasan(l,prec,p);
        }
    }
}

void deleteFirstPenugasan(LPng &l, adrPenugasan &p){
    if(firstPng(l)==NULL){
        cout<<"List penugasan kosong "<<endl;
    }else if (nextPng(firstPng(l))==NULL){
        p = firstPng(l);
        firstPng(l) = NULL;
    }else {
        p = firstPng(l);
        firstPng(l) = nextPng(p);
        nextPng(p) = NULL;
    }
}

void deleteLastPenugasan(LPng &l, adrPenugasan &p){
     if(firstPng(l)==NULL){
        cout<<"List penugasan kosong "<<endl;
    }else if (nextPng(firstPng(l))==NULL){
        p = firstPng(l);
        firstPng(l) = NULL;
    }else {
        adrPenugasan q = firstPng(l);
        while(nextPng(nextPng(q))!=NULL){
            q = nextPng(q);
        }
        p = nextPng(q);
        nextPng(q) = NULL;
    }
}

void deleteAfterPenugasan(LPng &l, adrPenugasan prec, adrPenugasan &p){
     if(firstPng(l)==NULL){
        cout<<"List penugasan kosong "<<endl;
    }else if (nextPng(firstPng(l))==NULL && nextPng(prec) == NULL){
       cout<<"Data tidak ada, tidak dapat di delete"<<endl;
    }else {
        p = nextPng(prec);
        nextPng(prec)= nextPng(p);
        nextPng(p) = NULL;
    }

}


//view data programmer
void viewDataProgrammer(LPrg l){
    adrProgrammer p = firstPrg(l);
    int jumlahProgrammer = countProgrammer(l);
    cout << "-------------- Data programmer --------------"<<endl;
    cout<< "Jumlah programmer: " << jumlahProgrammer << " orang" <<endl;
    cout<<endl;
    while (p!=NULL){
        cout << "Username: " << infoPrg(p).username <<endl;
        cout << "Keahlian: "<< infoPrg(p).keahlian <<endl;
        cout << "Total penugasan: " << infoPrg(p).totalPenugasan <<endl;
        cout<<endl;
        p = nextPrg(p);

    }
      cout<< "---------------------------------------------"<<endl;

}

//view data Project
void viewDataProject(LPrj l){
    adrProject p = firstPrj(l);
    int jumlahProject = countProject(l);
    cout<<"-------------- Data Project -----------------"<<endl;
    cout<<"Jumlah project: " << jumlahProject << " buah"<<endl;
    cout<<endl;
    while (p != NULL){
        cout << "Nama Project: "<< infoPrj(p).namaProject << endl;
        cout << "Deadline    : "<< infoPrj(p).deadline<< " hari"<<endl;
        cout <<endl;
        p = nextPrj(p);
    }
      cout<<"---------------------------------------------"<<endl;
}


//Find data
adrProgrammer findDataProgrammer(LPrg l, dataProgrammer x){
    adrProgrammer p;
    p = firstPrg(l);
    while(p!=NULL){
        if (infoPrg(p).username == x.username){
            return p;
        }
        p = nextPrg(p);
    }
    return NULL;

}

//find penugasan
adrProject findDataProject(LPrj &l, dataProject x){
    adrProject p = firstPrj(l);
    while(p != NULL){
        if(infoPrj(p).namaProject == x.namaProject){
            return p;
        }
        p = nextPrj(p);
    }
    return NULL;
}

adrPenugasan findRelasiPenugasan(LPng &l, dataProject xPrj, dataProgrammer xPrg){
    adrPenugasan p = firstPng(l);
    while(p != NULL){
        if (infoPrg(pPrg(p)).username == xPrg.username && infoPrj(pPrj(p)).namaProject == xPrj.namaProject){
            return p;
        }
        p = nextPng(p);
    }
    return NULL;
}

//Edit data
void editProgrammer(LPrg &l, dataProgrammer x){
    adrProgrammer p = findDataProgrammer(l, x);

    if(p == NULL){
        cout << "Data dengan username :"<< x.username << "tidak ditemukan";
    } else {
        cout << "Data ditemukan. Silahkan masukan username baru"<< endl;
        cout << "Username baru : ";
        cin >> infoPrg(p).username;
        cout << "Data telah diperbaharui"<<endl;
    }
    viewDataProgrammer(l);
}

void editProject(LPrj &l, dataProject x){
    adrProject p = findDataProject(l, x);
    if(p == NULL){
        cout<< "Project dengan nama :" << x.namaProject << "tidak ditemukan"<<endl;
    } else {
        cout<< "Data ditemukan. Masukkan data baru"<< endl;
        cout << "Deadline baru : ";
        cin >> infoPrj(p).deadline;
        cout << "Data telah diperbaharui" << endl;
    }
    cout<<endl;
    viewDataProject(l);
}

void editPenugasan(LPng &l, LPrg prg, LPrj prj,  dataProgrammer xPrg, dataProject xPrj){
    cout<< "============================================="<<endl;
    cout<< "              Edit Status Penugasan          "<<endl;
    cout<< "============================================="<<endl;
    cout<< "Masukkan username: ";
    cin>> xPrg.username;
    cout<< "Masukkan project yang dikerjakan: ";
    cin>> xPrj.namaProject;
    adrPenugasan p = findRelasiPenugasan(l,xPrj, xPrg);
    adrProject q = findDataProject(prj, xPrj);
    dataPenugasan xPng;

    if(p==NULL){
        cout<<"Data penugasan tidak ditemukan"<<endl;
    }else{
        cout<<"Update status terkini: ";
        cin>>infoPng(p).status;
        infoPrj(q).status = infoPng(p).status;
        cout<<"status diperbarui"<<endl;
    }
    cout<<endl;
    cout<<"Data setelah update status: "<<endl;
    cout<<endl;
    viewPenugasanProgrammer(l,prg,prj);
    viewPenugasanProject(l,prg,prj);


}

//count data
int countProgrammer(LPrg l){
    adrProgrammer p = firstPrg(l);
    int jumlah = 0;
    while (p !=NULL){
       jumlah++;
        p = nextPrg(p);
    }
    return jumlah;
}

int countProject(LPrj l){
    adrProject p = firstPrj(l);
    int jumlah = 0;
    while(p!=NULL){
        jumlah++;
        p = nextPrj(p);
    }
    return jumlah;
}


//Connect dan disconnect
void connect(LPng &png, LPrg prg, LPrj prj, dataProgrammer xPrg, dataProject xPrj){
    adrPenugasan r;
    cout<< "Masukkan username: ";
    cin>> xPrg.username;
    cout<< "Masukkan project yang ditugaskan: ";
    cin>>xPrj.namaProject;
    adrProgrammer p = findDataProgrammer(prg, xPrg);
    adrProject q = findDataProject(prj, xPrj);
    while(xPrg.username!="selesai"){
        if (p!=NULL && q!=NULL){
            createElmPenugasan(p, q, r);
            insertPenugasan(png, r);
        }if (p==NULL){
            cout<<"Data programmer yang anda masukkan tidak ada dalam list! "<<endl;
        }
        cout<< "Masukkan username: ";
        cin>> xPrg.username;
        if (xPrg.username == "selesai"){
            return;
        }
        cout<< "Masukkan project yang ditugaskan: ";
        cin>>xPrj.namaProject;
        infoPng(r).status = "on going";
        p = findDataProgrammer(prg, xPrg);
        q = findDataProject(prj, xPrj);
    }
    cout<<"Input penugasan berhasil :) "<<endl;
    cout<<endl;

}

void disconnect(LPng &png, LPrg prg, LPrj prj, dataProgrammer xPrg, dataProject xPrj){
    cout<< "Masukkan username: ";
    cin>> xPrg.username;
    cout<< "Masukkan project yang ingin dicabut: ";
    cin>>xPrj.namaProject;
    adrPenugasan p = findRelasiPenugasan(png,xPrj,xPrg);
    while(xPrg.username != "selesai"){
        if (p!=NULL){
            deletePenugasan(png,p);
        }else if (p==NULL){
            cout<<"Data penugasan yang anda masukkan tidak ada dalam list! "<<endl;
        }
        cout<< "Masukkan username: ";
        cin>> xPrg.username;
       if (xPrg.username == "selesai"){
            return;
        }

        cout<< "Masukkan project yang ingin dicabut: ";
        cin>>xPrj.namaProject;
        adrPenugasan p = findRelasiPenugasan(png,xPrj,xPrg);

    }
    cout<<"Pencabutan penugasan berhasil :)"<<endl;
    cout<<endl;

}

void viewPenugasanProgrammer(LPng png, LPrg prg, LPrj prj){
    adrProgrammer aPrg = firstPrg(prg);

    cout<< "============================================="<<endl;
    cout<< "          View Penugasan Programmer          "<<endl;
    cout<< "============================================="<<endl;
    int jumPrg = countProgrammer(prg);
    cout<<"Total programmer : "<< jumPrg <<endl;
    cout<<endl;
    while (aPrg!=NULL){
        int tPenugasan = 0;
        cout<< "Username : " <<infoPrg(aPrg).username<<endl;
        cout<< "Keahlian : " <<infoPrg(aPrg).keahlian<< endl;
        cout<<"Project yang dikerjakan: "<<endl;

        adrPenugasan aPng = firstPng(png);
        while(aPng!=NULL){
            if (pPrg(aPng)== aPrg){
                cout<<infoPrj(pPrj(aPng)).namaProject<< ", ";
                cout<<"Deadline: "<<infoPrj(pPrj(aPng)).deadline<< " hari, ";
                cout<<"Status: "<<infoPng(aPng).status<<endl;
                if (pPrj(aPng) !=NULL){
                    tPenugasan++;
                }
            }

            aPng = nextPng(aPng);
        }
        infoPrg(aPrg).totalPenugasan = tPenugasan;
        cout<<"Total project yang dikerjakan: "<< infoPrg(aPrg).totalPenugasan<<endl;
        cout<<endl;
        aPrg = nextPrg(aPrg);
    }
}

void viewPenugasanProject(LPng png, LPrg prg, LPrj prj){
    adrProject aPrj = firstPrj(prj);

    cout<< "============================================="<<endl;
    cout<< "            View Penugasan Project           "<<endl;
    cout<< "============================================="<<endl;
    while (aPrj!= NULL){
        int tprogrammer = 0;
        bool relation = false;
        cout << "Project: "<< infoPrj(aPrj).namaProject<<endl;
        cout << "Deadline: "<< infoPrj(aPrj).deadline<<endl;
        cout << "Programmer yang mengerjakan: "<<endl;

        adrPenugasan aPng = firstPng(png);
        while(aPng!=NULL){
            if(pPrj(aPng)==aPrj){
                cout<<infoPrg(pPrg(aPng)).username<<" ";
                cout<<"\nStatus: "<<infoPrj(pPrj(aPng)).status<<endl;
                relation = true;
                tprogrammer++;
            }
            aPng = nextPng(aPng);
        }if (!relation){
            cout << "Tidak ada"<<endl;
            cout << "Status: "<<infoPrj(aPrj).status <<endl;
        }

        aPrj = nextPrj(aPrj);
        cout<<endl;

    }
}

