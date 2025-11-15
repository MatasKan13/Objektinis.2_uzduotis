#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using std::string;
using std::vector;
using std::istringstream;
using std::pair;
using std::sort;

class Studentas{
    string vardas_;
    string pavarde_;
    vector <int> paz_;
    int egz_;
    double gal_, galMed_;

    public:
        Studentas() : egz_(0) {};
        Studentas(istringstream& iss);
        Studentas(string v, string pav, vector <int> paz, int egz);
        inline string vardas() const {return vardas_;}
        inline string pavarde() const {return pavarde_;}
        inline double balasVid() const {return gal_;}
        inline double balasMed() const {return galMed_;}
        pair <double,double> balo_sk() const;
        void keistiDuomenis(string, string, vector <int>, int);
        ~Studentas() {
            vardas_.clear();
            pavarde_.clear();
            paz_.clear();
            paz_.shrink_to_fit();
            egz_ = 0;
            gal_ = 0;
        };
};

#endif
