#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm> // Skirta sort metodui
#include <cctype> // Skirta toupper ir tolower metodams
#include <random> // Skirta atsitiktinių skaičių generavimui
#include <fstream> // Skirta darbui su failais
#include <sstream> // Skirta stringstream (eilutės pavertimo srautu) metodui
#include <chrono> // Skirta laiko matavimams
#include <map>
#include <list>
#include <execution>
#include "timer.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;
using std::sort;
using std::toupper;
using std::tolower;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::ws;
using std::stringstream;
using std::istringstream;
using std::map;
using std::to_string;
using std::list;
using std::stoi;
using std::pair;
using std::copy;

struct Studentas {
    string vardas;
    string pavarde;
    vector <int> paz;
    int egz;
    double gal;
};

void Paskirstymas_vector_1_strategija(const vector <Studentas>&, const int&);
void Paskirstymas_list_1_strategija(const list <Studentas>&, const int&);
void Paskirstymas_vector_2_strategija(vector <Studentas>, const int&);
void Paskirstymas_list_2_strategija(list <Studentas>, const int&);
void Testavimas_vector(const int&, vector <Studentas>);
void Testavimas_list(const int&, list <Studentas>);
void Testavimas(int);

