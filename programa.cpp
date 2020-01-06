#include <iostream>
#include <fstream>

using namespace std;

ifstream in("krepsinis_data.txt");
ofstream out("krepsinis_res.txt");

struct komanda{
    string vardas;
    int amzius;
    int taskai;
    };

void kiekis(int &kiekis, string &pavadinimasKomandos);
void skaitom(komanda Duomenys[], int kiekis);
void jauniausioMetai(komanda Duomenys[], int kiekis, int &jauniausioAmzius);
void pelnytiMaxTaskai(komanda Duomenys[], int kiekis, int &daugTasku);
void jauniausiuMasyvas(komanda Duomenys[], int kiekis, int jauniausioAmzius, komanda Jaunikaiciai[], int &jaunikaiciuKiekis);
void taikliausiuMasyvas(komanda Duomenys[], int kiekis, int daugTasku, komanda Taikliausi[], int &taikliuKiek);
void rasymasIausiu(string pavadinimas, komanda Duomenys[], int kiekis);
void misriosKomandosSudarymas(komanda Duomenys1[], int kiekis1, int jauniausioAmzius, komanda Duomenys2[], int kiekis2, int daugTasku, komanda misri[], int &bendrasKiekis);
void misriosRasymas(string tekstas, komanda misri[], int bendrasKiekis);

int main(){
    int kiek1, kiek2;
    string pavadinimas1, pavadinimas2;

    kiekis(kiek1, pavadinimas1);
    komanda pirmieji[kiek1];
    skaitom(pirmieji, kiek1);
    //kursorius sustojo faile po pirma komanda, galime imtis atros skaitymo
    kiekis(kiek2, pavadinimas2);
    komanda antrieji[kiek2];
    skaitom(antrieji, kiek2);
    //ieskom jaunystes metu senuku kolektyve
    int jaunystesMetaiPirmuju, jaunystesMetaiAntruju;
    jauniausioMetai(pirmieji, kiek1, jaunystesMetaiPirmuju);
    jauniausioMetai(antrieji, kiek2, jaunystesMetaiAntruju);
    //cout<<jaunystesMetaiPirmuju<<jaunystesMetaiAntruju;
    //ieskom tasku skaiciu, daugiausia surinktu
    int taskaiMax1, taskaiMax2;
    pelnytiMaxTaskai(pirmieji, kiek1, taskaiMax1);
    pelnytiMaxTaskai(antrieji, kiek2, taskaiMax2);
    //cout<<taskaiMax1<<taskaiMax2;
    komanda jauni1[kiek1], jauni2[kiek2];
    int jaunuKiek1, jaunuKiek2;
    jauniausiuMasyvas(pirmieji, kiek1, jaunystesMetaiPirmuju, jauni1, jaunuKiek1);
    jauniausiuMasyvas(antrieji, kiek2, jaunystesMetaiAntruju, jauni2, jaunuKiek2);
    //cout<<jaunuKiek1<<jaunuKiek2;
    komanda taiklus1[kiek1], taiklus2[kiek2];
    int taikliuKiek1, taikliuKiek2;
    taikliausiuMasyvas(pirmieji, kiek1, taskaiMax1, taiklus1, taikliuKiek1);
    taikliausiuMasyvas(antrieji, kiek2, taskaiMax2, taiklus2, taikliuKiek2);
    //cout<<taikliuKiek1<<taikliuKiek2;
    out<<"JAUNIAUSI"<<endl;
    rasymasIausiu(pavadinimas1, jauni1, jaunuKiek1);
    rasymasIausiu(pavadinimas2, jauni2, jaunuKiek2);
    out<<"TAIKLIAUSI"<<endl;
    rasymasIausiu(pavadinimas1, taiklus1, taikliuKiek1);
    rasymasIausiu(pavadinimas2, taiklus2, taikliuKiek2);
    //bendra komanda
    int kiekis = kiek1+kiek2;
    komanda nauja[kiekis];
    int kiekBendras;
    misriosKomandosSudarymas(pirmieji, kiek1, jaunystesMetaiPirmuju, antrieji, kiek2, taskaiMax2, nauja, kiekBendras);
    misriosRasymas("NAUJA KOMANDA", nauja, kiekBendras);

    in.close();
    out.close();
    return 0;

}
void kiekis(int &kiekis, string &pavadinimasKomandos){
     in>>pavadinimasKomandos>>kiekis;
}
void skaitom(komanda Duomenys[], int kiekis){

    for(int i=0; i<kiekis; i++){
        in>>Duomenys[i].vardas>>Duomenys[i].amzius>>Duomenys[i].taskai; }
}
void jauniausioMetai(komanda Duomenys[], int kiekis, int &jauniausioAmzius){

    jauniausioAmzius = Duomenys[0].amzius;
    for(int i=0; i<kiekis; i++){
        if(Duomenys[i].amzius < jauniausioAmzius) jauniausioAmzius=Duomenys[i].amzius;
    }
}
void pelnytiMaxTaskai(komanda Duomenys[], int kiekis, int &daugTasku){
    daugTasku = Duomenys[0].taskai;
    for(int i=0; i<kiekis; i++){
        if(Duomenys[i].taskai>daugTasku) daugTasku=Duomenys[i].taskai;
    }
}
void jauniausiuMasyvas(komanda Duomenys[], int kiekis, int jauniausioAmzius, komanda Jaunikaiciai[], int &jaunikaiciuKiekis){
    jaunikaiciuKiekis=0;
    for(int i=0; i<kiekis; i++){
        if(Duomenys[i].amzius==jauniausioAmzius){
           Jaunikaiciai[jaunikaiciuKiekis].vardas=Duomenys[i].vardas;
           //ar mums tikrai reikia priskyrineti i nauja masyva ir kitus duomenis, jei isvedinesime tik vardus?
           Jaunikaiciai[jaunikaiciuKiekis].amzius=Duomenys[i].amzius;
           Jaunikaiciai[jaunikaiciuKiekis].taskai=Duomenys[i].taskai;
           jaunikaiciuKiekis++;
           }
    }
}
void taikliausiuMasyvas(komanda Duomenys[], int kiekis, int daugTasku, komanda Taikliausi[], int &taikliuKiek){
    taikliuKiek=0;
    for(int i=0; i<kiekis; i++){
        if(Duomenys[i].taskai==daugTasku){
            Taikliausi[taikliuKiek].vardas=Duomenys[i].vardas;
            Taikliausi[taikliuKiek].amzius=Duomenys[i].amzius;
            Taikliausi[taikliuKiek].taskai=Duomenys[i].taskai;
            taikliuKiek++;
            }
    }
}
void rasymasIausiu(string pavadinimas, komanda Duomenys[], int kiekis){
    out<<pavadinimas<<endl;
    for(int i=0; i<kiekis; i++){
        out<<Duomenys[i].vardas<<endl;
}
}
void misriosKomandosSudarymas(komanda Duomenys1[], int kiekis1, int jauniausioAmzius, komanda Duomenys2[], int kiekis2, int daugTasku, komanda misri[], int &bendrasKiekis){
                  //pirmos komandos jauniausi
                  bendrasKiekis=0;
                  for(int i=0; i<kiekis1; i++){
                    if(Duomenys1[i].amzius==jauniausioAmzius){
                           misri[bendrasKiekis].vardas=Duomenys1[i].vardas;
                           bendrasKiekis++;
                           }
                  }
                  //o antrosios komandos   taikliausi
                  for(int i=0; i<kiekis2; i++)  {
                    if(Duomenys2[i].taskai==daugTasku){
                        misri[bendrasKiekis].vardas=Duomenys2[i].vardas;
                           bendrasKiekis++; }
                }
}
void misriosRasymas(string tekstas, komanda misri[], int bendrasKiekis){
    out<<tekstas<<endl;
    for(int i=0; i<bendrasKiekis; i++){
        out<<misri[i].vardas<<endl;
    }
}
