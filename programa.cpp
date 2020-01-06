#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

ifstream in("krepsinis_data.txt");
ofstream out("krepsinis_res.txt");

struct komanda{
    string vardas;
    int amzius;
    int taskai;
    };

void skaitom(komanda Duomenys[], string &pavadinimasKomandos, int &kiekis);


int main(){
    int kiek1, kiek2;
    string pavadinimas1, pavadinimas2;
    komanda pirmieji[100], antrieji[100];

    skaitom(pirmieji, pavadinimas1, kiek1);
    skaitom(antrieji, pavadinimas2, kiek2);

    cout<<pavadinimas1<<kiek1<<pirmieji[0].vardas<<endl;
    cout<<pavadinimas2<<kiek2<<antrieji[2].taskai;



    in.close();
    out.close();
    return 0;

}

void skaitom(komanda Duomenys[], string &pavadinimasKomandos, int &kiekis){


    in>>pavadinimasKomandos>>kiekis;

    for(int i=0; i<kiekis; i++){

        in>>Duomenys[i].vardas>>Duomenys[i].amzius>>Duomenys[i].taskai;
    }

}
