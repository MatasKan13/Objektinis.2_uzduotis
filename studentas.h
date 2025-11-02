#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::istringstream;

class Studentas{
    string vardas_;
    string pavarde_;
    vector <int> paz_;
    int egz_;
    double gal_;

    public:
        Studentas() : egz_(0) {};
        Studentas(istringstream& iss);
        inline string vardas() const {return vardas_;}
        inline string pavarde() const {return pavarde_;}
        inline double balas() const {return gal_;};
        double balo_sk() const;
        void keistiDuomenis(string, string, vector <int>, int);
        ~Studentas() {};
};

#endif
