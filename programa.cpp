#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ofstream out("krepsinis_res.txt");

struct komanda{
    string vardas;
    int amzius;
    int taskai;
    };

void skaitom(komanda Duomenys1[], komanda Duomenys2[], string &pavadinimasKomandos1, string &pavadinimasKomandos2, int &kiekis1, int &kiekis2, const char byla[]);


int main(){
    int kiek1, kiek2;
    string pavadinimas1, pavadinimas2;
    komanda pirmieji[100], antrieji[100];

    const char duomenys1[] = "krepsinis_data.txt";

    skaitom(pirmieji, antrieji, pavadinimas1,  pavadinimas2, kiek1, kiek2, duomenys1);

    cout<<pavadinimas1<<kiek1<<pirmieji[0].vardas<<endl;
    cout<<pavadinimas2<<kiek2<<antrieji[2].taskai;




    out.close();
    return 0;

}

void skaitom(komanda Duomenys1[], komanda Duomenys2[], string &pavadinimasKomandos1, string &pavadinimasKomandos2, int &kiekis1, int &kiekis2, const char byla[]){
    ifstream in(byla);

    in>>pavadinimasKomandos1>>kiekis1;

    for(int i=0; i<kiekis1; i++){

        in>>Duomenys1[i].vardas>>Duomenys1[i].amzius>>Duomenys1[i].taskai;
    }

    in>>pavadinimasKomandos2>>kiekis2;

    for(int i=0; i<kiekis2; i++){

        in>>Duomenys2[i].vardas>>Duomenys2[i].amzius>>Duomenys2[i].taskai;
    }

    in.close();
}
