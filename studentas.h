#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using std::string;
using std::vector;
using std::istringstream;
using std::pair;
using std::sort;
using std::cout;

class Studentas{
    string vardas_;
    string pavarde_;
    vector <int> paz_;
    int egz_;
    double gal_, galMed_;

    public:
        Studentas() : egz_(0) {};
        Studentas(istringstream& iss);
        Studentas(string, string, vector <int>, int);
        Studentas(const Studentas& ); // kopijavimo konstruktorius
        inline string vardas() const {return vardas_;}
        inline string pavarde() const {return pavarde_;}
        inline double balasVid() const {return gal_;}
        inline double balasMed() const {return galMed_;}
        pair <double,double> balo_sk() const;
        void keistiDuomenis(string, string, vector <int>, int);
        Studentas& operator=(const Studentas&); // priskyrimo operatorius
        ~Studentas() {
            vardas_.clear();
            pavarde_.clear();
            paz_.clear();
            paz_.shrink_to_fit();
            egz_ = 0;
            gal_ = 0;
        };
        friend std::ostream& operator<<(std::ostream& out, const Studentas& stud) {
            out << stud.vardas_ << " " << stud.pavarde_ << " " << stud.gal_ << '\n';
            return out;
        }

        friend std::istream& operator>>(std::istream& in, Studentas& stud) {
            int n, p;
            cout << "Iveskite studento varda: "; in >> stud.vardas_;
            cout << "Iveskite studento pavarde: "; in >> stud.pavarde_;
            cout << "Iveskite pazymiu skaiciu: "; in >> n;
            for (int i=1;i<=n;i++) {
                cout << "Iveskite " << i << "-aji pazymi: "; in >> p;
                stud.paz_.push_back(p);
            }
            cout << "Iveskite egzamino ivertinima: "; in >> stud.egz_;
            pair <double, double> balai = stud.balo_sk();
            stud.gal_ = balai.first;
            stud.galMed_ = balai.second;
            return in;
        }
};

#endif
