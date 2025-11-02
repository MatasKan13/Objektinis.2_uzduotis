#include "studentas.h"

Studentas::Studentas(istringstream& iss) {
    int pazymys;
    iss >> vardas_ >> pavarde_;
    while(iss >> pazymys) {
        paz_.push_back(pazymys);
    }
    egz_ = paz_.back();
    paz_.pop_back();
    gal_ = balo_sk();
}

double Studentas::balo_sk() const {
    int suma = 0, n = paz_.size();
    for (int p : paz_) {
        suma+=p;
    }
    double gal = 0.4 * double(suma)/double(n) + 0.6 * egz_;
    return gal;
}

void Studentas::keistiDuomenis(string v, string p, vector <int> pz, int e) {
    vardas_ = v;
    pavarde_ = p;
    paz_ = pz;
    egz_ = e;
    gal_ = balo_sk();
}
