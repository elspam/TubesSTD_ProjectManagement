#include <iostream>
#include "ProMan.h"

using namespace std;

int menuLogin(){
    cout<<"========MENU LOGIN========="<<endl;
    cout<<"1. Login sebagai Admin"<<endl;
    cout<<"2. Login sebagai Manager"<<endl;
    cout<<"3. Login sebagai Programmer"<<endl;

    int input = 0;
    cin >> input;
    return input;

}

int menuAdmin(){
    cout<<"==========MENU ADMIN==========="<<endl;
    cout<<"1. Insert Data Programmer "<<endl;
    cout<<"2. Insert Data Project "<<endl;
    cout<<"4. Edit data programmer"<<endl;
    cout<<"5. Edit data project"<<endl;
    cout<<"6. Delete data programmer"<<endl;
    cout<<"7. Delete data project"<<endl;
    cout<<"8. View project "<<endl;

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
    nextPrj(prj) = NULL;
    prevPrj(prj) = NULL;
}

void createElmPenugasan(adrProgrammer p, adrProject q, adrPenugasan &png){
    png = new penugasan;
    pPrg(png) = p;
    pPrj(png) = q;
    infoPng(png).status = "on going";
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
            cout<<"Username ini sudah pernah dimasukkan"<<endl;
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

void deleteLastProgrammer(LPrg &l, adrProgrammer p){
    if (firstPrg(l) == NULL){
        cout<<"Data kosong";
    }else if (firstPrg(l) == lastPrg(l)){
        p = lastPrg(l);
        firstPrg(l) = NULL;
        lastPrg(l) = NULL;
    }else {
        p = lastPrg(l);
        lastPrg(l) = prevPrg(p);
        nextPrg(lastPrg(l))=NULL;
    }
}

void deleteAfterProgrammer(LPrg &l, adrProgrammer prec, adrProgrammer p){
    if(nextPrg(prec) == lastPrg(l)){
        deleteLastProgrammer(l,p);
    }else if (nextPrg(prec) == NULL) {
        cout<< "Tidak ada elemen setelah prec";
    }else{
        p = nextPrg(prec);
        nextPrg(prec) = nextPrg(p);
        prevPrg(nextPrg(p)) = prec;
        prevPrg(p) = NULL;
        nextPrg(p) = NULL;

    }
}

void deleteProgrammer(LPrg &l, dataProgrammer x){
    adrProgrammer p;
    p = findDataProgrammer(l,x);
    if (p==NULL){
        cout<<"Data yang ingin dihapus tidak ada dalam list"<<endl;
    }else{
        if(p==firstPrg(l)){
            deleteFirstProgrammer(l,p);
        }else if (p == lastPrg(l)){
            deleteLastProgrammer(l,p);
        }else {
            deleteAfterProgrammer(l,prevPrg(p),p);
        }
    }

    cout<<"Data setelah dihapus: "<<endl;
    viewDataProgrammer(l);
}


//delete data project
void deleteFirstProject(LPrj &l, adrProject &p){
    if(firstPrj(l) == NULL ){
        cout<<"list Project Kosong!"<<endl;
    } else {
        p = firstPrj(l);
        if (firstPrj(l) == lastPrj(l)){
            firstPrj(l) = NULL;
            lastPrj(l) = NULL;
        } else {
            firstPrj(l) = nextPrj(p);
            prevPrj(firstPrj(l)) = NULL;
        }
    }
}

void deleteLastProject(LPrj &l, adrProject &p){
    if(firstPrj(l)==NULL){
        cout<< "List project kosong!" << endl;
    } else if (firstPrj(l) == lastPrj(l)) {
        p = firstPrj(l);
        firstPrj(l) = NULL;
        lastPrj(l) = NULL;
    } else {
        p = lastPrj(l);
        lastPrj(l) = prevPrj(p);
        prevPrj(p)= NULL;
        nextPrj(lastPrj(l))== NULL;
    }

}

void deleteAfterProject(LPrj &l, adrProject prec, adrProject &p){
    if(prec == NULL || nextPrj(prec) == NULL){
        cout << "tidak ada elemen setelah elemen ini" <<endl;
    } else {
        p = nextPrj(prec);
        nextPrj(prec) = nextPrj(p);
        if (nextPrj(p)!= NULL){
            prevPrj(nextPrj(p)) = prec;
        } else {
            lastPrj(l) = prec;
        }
    }
}

void deleteProject(LPrj &l, dataProject x) {
    adrProject p;
    p = findDataProject(l, x);
    if(p == NULL){
        cout<< "List project kosong"<<endl;
    }else {
        if(p==firstPrj(l)){
            deleteFirstProject(l,p);
        }else if (p == lastPrj(l)){
            deleteLastProject(l,p);
        }else {
            deleteAfterProject(l,prevPrj(p),p);
        }
    }
    cout<<"Data setelah dihapus: "<<endl;
    viewDataProject(l);
}

//delete data penugasan
void deletePenugasan(LPng &l, adrPenugasan &p){
    dataProgrammer xPrg;
    dataProject xPrj;
    p = findRelasiPenugasan(l,xPrj,xPrg);
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
        cout << "Username baru:";
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
        cout << "Deadline baru:";
        cin >> infoPrj(p).deadline;
        cout << "Data telah diperbaharui" << endl;
    }
    viewDataProject(l);
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
        }else if (p==NULL){
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
    cout<<endl;

}

void disconnect(LPng &png, LPrg prg, LPrj prj, dataProgrammer xPrg, dataProject xPrj){
    adrPenugasan p = findRelasiPenugasan(png,xPrj,xPrg);
    if (p!=NULL){

    }

}

void viewPengugasan(LPng png, LPrg prg, LPrj prj){
    adrProgrammer aPrg = firstPrg(prg);

    cout<< "============================================="<<endl;
    cout<< "                View Penugasan               "<<endl;
    cout<< "============================================="<<endl;
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


