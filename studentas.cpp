#include "studentas.h"
#include <iostream>

double Mediana(vector <int> vekt) {
    int n = vekt.size();
    double med;
    sort(vekt.begin(), vekt.end());
    if (n % 2 == 0) {
        med = double(vekt[n/2] + vekt[n/2 - 1]) / 2.0;
    } else {
        med = vekt[n/2];
    }
    return(med);
}

pair <double,double> Studentas::balo_sk() const {
    int suma = 0, n = paz_.size();
    for (int p : paz_) {
        suma+=p;
    }
    double galVid = 0.4 * double(suma)/double(n) + 0.6 * egz_;
    double galMed = 0.4 * Mediana(paz_) + 0.6 * egz_;
    pair <double,double> balai = {galVid, galMed};
    return balai;
}

Studentas::Studentas(istringstream& iss) {
    int pazymys;
    iss >> vardas_ >> pavarde_;
    while(iss >> pazymys) {
        paz_.push_back(pazymys);
    }
    egz_ = paz_.back();
    paz_.pop_back();
    pair <double,double> balai = balo_sk();
    gal_ = balai.first;
    galMed_ = balai.second;
}

Studentas::Studentas(string v, string pav, vector <int> paz, int egz) : vardas_{v}, pavarde_{pav}, paz_{paz}, egz_{egz} {
    pair <double,double> balai = balo_sk();
    gal_ = balai.first;
    galMed_ = balai.second;
}

void Studentas::keistiDuomenis(string v, string p, vector <int> pz, int e) {
    vardas_ = v;
    pavarde_ = p;
    paz_ = pz;
    egz_ = e;
    pair <double,double> balai = balo_sk();
    gal_ = balai.first;
    galMed_ = balai.second;
}
