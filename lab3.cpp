#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
bool provjera(int v, int *matricaS, int boja[], int c, int brojVrhova) {
    for (int i = 0; i < v; i++) {
        if (*(matricaS + v * brojVrhova + i) && c == boja[i]) {
            return false;
        }
    }
    return true;
}
bool rekurzivnoBojanje(int *matricaS, int m, int boja[], int v, int brojVrhova) {
    if (v == brojVrhova) {
        return true;
    }
    for (int c = 1; c <= m; c++) {
        if (provjera(v, matricaS, boja, c, brojVrhova)) {
            boja[v] = c;
            if (rekurzivnoBojanje(matricaS, m, boja, v + 1, brojVrhova) == true) {
                return true;
            }
            boja[v] = 0;
        }
    }
    return false;
}
bool bojanjeGrafova(int *matricaS, int m, int brojVrhova) {
    int boja[brojVrhova] = {0};
    if (rekurzivnoBojanje(matricaS, m, boja, 0, brojVrhova) == false) {
        return false;
    }
    return true;
}

int main() {
    string brojVrhova, brojClanova, linija;
    vector<int> clanovi;

    ifstream MyFile("graf.txt");

    getline(MyFile, brojVrhova);
    getline(MyFile, brojClanova);

    int n = stoi(brojVrhova);
    //cout<<n<<endl;
    int t = stoi(brojClanova);
    //cout<<t<<endl;

    getline(MyFile, linija);
    stringstream lineStream(linija);
    int clan;
    while(lineStream >> clan) {
        clanovi.push_back(clan);
    }
    int S[t];
    copy(clanovi.begin(), clanovi.end(), S);
    /* for(int i: S) {
        cout<<i<<" ";
    }
    cout<<endl; */

    int matricaS[n][n] = {0};
    int z, m = 0, zbroj;
    for (int i = 1; i <= n; i++) {
        zbroj = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < t; k++) {
                z = i - j >= 0 ? i - j : j - i;
                if (z == S[k]) {
                    matricaS[i - 1][j - 1] = 1;
                    zbroj++;
                }
            }
        }
        m = max(m, zbroj);
    }
    int rezultat;
    m++;
    // cout<<m<<endl;
    for (m; m >= 1; m--) {
        if (!bojanjeGrafova(*matricaS, m, n)) {
            rezultat = m + 1;
            break;
        }
    }
    cout<<"Kromatski broj zadanog grafa je "<<rezultat<<endl;
    MyFile.close();
    return 0;
}