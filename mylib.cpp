#include "mylib.h"
#include "studentas.h"

void Failo_nuskaitymas(vector <Studentas> &Grupe, const int& irasu_sk) {
    cout << "Puiku! Nuskaitomas failas..." << endl;
    string failo_pav = "stud" + to_string(irasu_sk) + ".txt";
    stringstream buferis;
    ifstream in(failo_pav);
    buferis << in.rdbuf();
    in.close();
    string stulp;
    getline(buferis, stulp);
    while (!buferis.eof()) {
        string eil;
        getline(buferis, eil);
        istringstream srautas(eil);
        Studentas stud{srautas};
        Grupe.push_back(stud);
    }
}


void Spausdinimas(const vector <Studentas> &Spausd_gr, const int& strat) {
    stringstream ss;
    ss << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(17) << left << "Galutinis (Vid.) " << endl;
    ss << string(52,'-');
    for (const auto &Past : Spausd_gr) {
        ss << endl << setw(15) << left << Past.vardas() << setw(20) << left << Past.pavarde() << setw(17) << left << fixed << setprecision(2) << Past.balas();
    }
    
    if (Spausd_gr[0].balas() >= 5) {
        ofstream out("kietiakai" + to_string(strat) + ".txt");
        out << ss.str();
        out.close();
    } else {
        ofstream out("nuskriaustukai" + to_string(strat) + ".txt");
        out << ss.str();
        out.close();
    }
}

void Paskirstymas_vector_1_strategija(const vector <Studentas> &Grupe, const int &irasu_sk) {
    Timer t;

    vector <Studentas> Vargsai, Moksliukai;
    Vargsai.reserve(irasu_sk);
    Moksliukai.reserve(irasu_sk);

    for (auto &stud : Grupe) {
        if (stud.balas() >= 5) {
            Moksliukai.push_back(stud);
        }
        else {
            Vargsai.push_back(stud);
        }
    }

    cout << irasu_sk << " dydzio vektoriaus dalijimo i dvi grupes, taikant 1 STRATEGIJA, laikas: " << t.elapsed() << " s\n";

    Spausdinimas(Moksliukai, 1);
    Spausdinimas(Vargsai, 1);
}

void Paskirstymas_vector_2_strategija(vector <Studentas> Grupe, const int &irasu_sk) {
    Timer t;
    vector <Studentas> Vargsai;
    Vargsai.reserve(irasu_sk);
    size_t newSize = 0;
    for (size_t i = 0; i<Grupe.size(); i++) {
        if(Grupe[i].balas() < 5) {
            Vargsai.push_back(Grupe[i]);
        }
        else {
            if (newSize != i) {
                Grupe[newSize++] = std::move(Grupe[i]);
            }
            else {
                ++newSize;
            }
        }
    }
    Grupe.erase(Grupe.begin() + newSize, Grupe.end());
    cout << irasu_sk << " dydzio vektoriaus dalijimo i dvi grupes, taikant 2 STRATEGIJA, laikas: " << t.elapsed() << " s\n";

    Spausdinimas(Grupe, 2);
    Spausdinimas(Vargsai, 2);
}

void Paskirstymas_vector_3_strategija(vector <Studentas> &Grupe, const int &irasu_sk) {
    Timer t;
    
    vector <Studentas> Vargsai;
    Vargsai.reserve(irasu_sk);

    std::remove_copy_if(Grupe.begin(), Grupe.end(), std::back_inserter(Vargsai),[](const Studentas &stud) {
        return stud.balas() >= 5;
    });

    Vargsai.shrink_to_fit();

    auto new_end = std::remove_if(Grupe.begin(), Grupe.end(), [](const Studentas &stud) {
        return stud.balas() < 5;
    });
    Grupe.erase(new_end, Grupe.end());

    cout << irasu_sk << " dydzio vektoriaus dalijimo i dvi grupes, taikant 3 STRATEGIJA, laikas: " << t.elapsed() << " s\n";

    Spausdinimas(Grupe, 3);
    Spausdinimas(Vargsai, 3);
}

void Testavimas_vector(const int &irasu_sk, vector <Studentas>& Grupe) {
    Paskirstymas_vector_1_strategija(Grupe, irasu_sk);
    Paskirstymas_vector_2_strategija(Grupe, irasu_sk);
    Paskirstymas_vector_3_strategija(Grupe, irasu_sk);
}

void Testavimas(const int &irasu_sk) {
    vector <Studentas> Grupe_vector;
    Grupe_vector.reserve(irasu_sk);
    cout << "\nNuskaitomi " << irasu_sk << " dydzio duomenys..." << endl;
    Failo_nuskaitymas(Grupe_vector, irasu_sk);

    cout << "Pradedamas testavimas su " << irasu_sk << " irasu failu!\n";
    Testavimas_vector(irasu_sk, Grupe_vector);
    Grupe_vector.clear();
}
