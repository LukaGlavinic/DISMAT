#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int bruteForce(int** lista_bridova, int broj_cvorova) {
    int pocetni = 0;
    vector<int> cvorovi;
    for(int i = 0; i < broj_cvorova; i++) {
        if(i != pocetni) {
            cvorovi.push_back(i);
        }
    }
    int n = cvorovi.size();
    int najkraci_put = INT_MAX;
    while(next_permutation(cvorovi.begin(), cvorovi.end())) {
        int prijedeni_put = 0;
        int j = pocetni;
        for(int i = 0; i < n; i++) {
            prijedeni_put += lista_bridova[j][cvorovi[i]];
            j = cvorovi[i];
        }
        prijedeni_put += lista_bridova[j][pocetni];
        najkraci_put = min(najkraci_put, prijedeni_put);
    }
    return najkraci_put;
}

int pohlepni(int** matricaTezina, int broj_vrhova) {
    int suma = 0, prviVrh, drugiVrh, najmanji_brid = INT_MAX;
    for(int i = 0; i < broj_vrhova; i++) {
        for(int j = i; j < broj_vrhova; j++) {
             if(i != j) {
                if(matricaTezina[i][j] < najmanji_brid) {
                    najmanji_brid = matricaTezina[i][j];
                    prviVrh = i;
                    drugiVrh = j;
                }
             }
        }
    }
    bool prijedeniVrhovi[broj_vrhova] = {false};
    prijedeniVrhovi[prviVrh] = true;
    prijedeniVrhovi[drugiVrh] = true;
    suma += matricaTezina[prviVrh][drugiVrh];
    int brojac = 0, najmanjBridPVrha, najmanjBridDVrha, indexP, indexD; 
    while (brojac < (broj_vrhova - 2)){
        najmanjBridPVrha = INT_MAX;
        najmanjBridDVrha = INT_MAX;
        for(int i = 0; i < broj_vrhova; i++) {
            if(matricaTezina[prviVrh][i] != 0 && matricaTezina[prviVrh][i] < najmanjBridPVrha && !prijedeniVrhovi[i]) {
                najmanjBridPVrha = matricaTezina[prviVrh][i];
                indexP = i;
            }
            if(matricaTezina[drugiVrh][i] != 0 && matricaTezina[drugiVrh][i] < najmanjBridDVrha && !prijedeniVrhovi[i]) {
                najmanjBridDVrha = matricaTezina[drugiVrh][i];
                indexD = i;
            }
        }
        if(najmanjBridPVrha < najmanjBridDVrha) {
            suma += najmanjBridPVrha;
            prviVrh = indexP;
            prijedeniVrhovi[prviVrh] = true;
        } else {
            suma += najmanjBridDVrha;
            drugiVrh = indexD;
            prijedeniVrhovi[drugiVrh] = true;
        }
        brojac++;
    }
    suma += matricaTezina[prviVrh][drugiVrh];
    return suma;
}
int main(void) {
    int n, a, b;
    int R1, R2;

    cout<<"Unesite redom, odvojene razmajom, parametre n, a i b: ";
    cin>>n>>a>>b;

    int** matricaSusjedstva = new int* [n];
    for(int i = 0; i < n; i++) {
        matricaSusjedstva[i] = new int[n];
        for(int j = 0; j < n; j++) {
            matricaSusjedstva[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i < j) {
                matricaSusjedstva[i][j] = (a * (i+1) + b * (j+1)) * (a * (i+1) + b * (j+1)) + 1;
                matricaSusjedstva[j][i] = (a * (i+1) + b * (j+1)) * (a * (i+1) + b * (j+1)) + 1;
            }
        }
    }
    //ispis matrice susjedstva
    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<matricaSusjedstva[i][j]<<" ";
        }
        cout<<endl; 
    }*/

    R1 = pohlepni(matricaSusjedstva, n);
    cout<<"Pohlepan algoritam nalazi ciklus duljine "<<R1<<endl;
    cout<<endl;

    R2 = bruteForce(matricaSusjedstva, n);
    cout<<"Iscrpni algoritam nalazi ciklus duljine "<<R2<<endl;
    cout<<endl;
    
    if(R1 != R2) {
        cout<<"Pohlepni algoritam na ovom grafu ne daje optimalno rjesenje!"<<endl;
    }else {
        cout<<"Pohlepni algoritam na ovom grafu daje optimalno rjesenje!"<<endl;
    }
    return 0;
}