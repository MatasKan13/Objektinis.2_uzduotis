#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm> // Skirta sort ir kietiems metodams
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
void Paskirstymas_vector_3_strategija(vector <Studentas>&, const int&);
void Paskirstymas_list_3_strategija(list <Studentas>&, const int&);
void Testavimas_vector(const int&, vector <Studentas>&);
void Testavimas_list(const int&, list <Studentas>&);
void Testavimas(const int&);

// Galimam surūšiavimo į grupes patikrinimui:

// template <typename T>
// void Spausdinimas(const T &Spausd_gr) {
//     stringstream ss;
//     ss << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(17) << left << "Galutinis (Vid.) " << endl;
//     ss << string(52,'-');
//     for (const auto &Past : Spausd_gr) {
//         ss << endl << setw(15) << left << Past.vardas << setw(20) << left << Past.pavarde << setw(17) << left << fixed << setprecision(2) << Past.gal;
//     }
    
//     auto it = Spausd_gr.begin();
//     if (it->gal >= 5) {
//         ofstream out("kietiakai.txt");
//         out << ss.str();
//         out.close();
//     } else {
//         ofstream out("nuskriaustukai.txt");
//         out << ss.str();
//         out.close();
//     }
// }

