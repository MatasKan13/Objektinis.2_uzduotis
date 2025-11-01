#ifndef MYLIB_H
#define MYLIB_H

#include "timer.h"
#include "studentas.h"

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

void Failo_nuskaitymas(vector <Studentas> &, const int&);
void Paskirstymas_vector_1_strategija(const vector <Studentas>&, const int&);
void Paskirstymas_vector_2_strategija(vector <Studentas>, const int&);
void Paskirstymas_vector_3_strategija(vector <Studentas>&, const int&);
void Testavimas_vector(const int&, vector <Studentas>&);
void Testavimas(const int&);
void Spausdinimas(const vector <Studentas> &, const int&);

#endif
