#include "mylib.h"

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
        Studentas stud;
        string eil;
        int pazymys;
        vector <int> pazymiai;
        getline(buferis, eil);
        istringstream srautas(eil);
        srautas >> stud.vardas >> stud.pavarde;
        while(srautas >> pazymys) {
            stud.paz.push_back(pazymys);
        }
        stud.egz = stud.paz.back();
        stud.paz.pop_back();
        int suma = 0, n = stud.paz.size();
        for (int p : stud.paz) {
            suma+=p;
        }
        stud.gal = 0.4 * double(suma)/double(n) + 0.6 * stud.egz;
        Grupe.push_back(stud);
    }
}

void Paskirstymas_list_1_strategija(const list <Studentas> &Grupe, const int &irasu_sk) {
    Timer t;

    list <Studentas> Vargsai, Moksliukai;

    for (auto stud : Grupe) {
        if (stud.gal >= 5) {
            Moksliukai.push_back(stud);
        }
        else {
            Vargsai.push_back(stud);
        }
    }
    cout << irasu_sk << " dydzio saraso dalijimo i dvi grupes, taikant 1 STRATEGIJA, laikas: " << t.elapsed() << " s\n";
    
    Spausdinimas(Moksliukai, 1);
    Spausdinimas(Vargsai, 1);
}

void Paskirstymas_vector_1_strategija(const vector <Studentas> &Grupe, const int &irasu_sk) {
    Timer t;

    vector <Studentas> Vargsai, Moksliukai;
    Vargsai.reserve(irasu_sk);
    Moksliukai.reserve(irasu_sk);

    for (auto &stud : Grupe) {
        if (stud.gal >= 5) {
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

void Paskirstymas_list_2_strategija(list <Studentas> Grupe, const int &irasu_sk) {
    Timer t;
    
    list <Studentas> Vargsai;
    for (auto it = Grupe.begin(); it != Grupe.end();) {
        if (it->gal < 5) {
            Vargsai.push_back(*it);
            it = Grupe.erase(it);
        }
        else {
            ++it;
        }
    }
    cout << irasu_sk << " dydzio saraso dalijimo i dvi grupes, taikant 2 STRATEGIJA, laikas: " << t.elapsed() << " s\n";

    Spausdinimas(Grupe, 2);
    Spausdinimas(Vargsai, 2);
}

void Paskirstymas_vector_2_strategija(vector <Studentas> Grupe, const int &irasu_sk) {
    Timer t;

    vector <Studentas> Vargsai;
    Vargsai.reserve(irasu_sk);
    size_t newSize = 0;
    for (size_t i = 0; i<Grupe.size(); i++) {
        if(Grupe[i].gal < 5) {
            Vargsai.push_back(Grupe[i]);
        }
        else {
            Grupe[newSize++] = std::move(Grupe[i]);
        }
    }
    Grupe.erase(Grupe.begin() + newSize, Grupe.end());

    cout << irasu_sk << " dydzio vektoriaus dalijimo i dvi grupes, taikant 2 STRATEGIJA, laikas: " << t.elapsed() << " s\n";

    Spausdinimas(Grupe, 2);
    Spausdinimas(Vargsai, 2);
}

void Paskirstymas_list_3_strategija(list <Studentas> &Grupe, const int &irasu_sk) {
    Timer t;

    list <Studentas> Vargsai;

    std::remove_copy_if(Grupe.begin(), Grupe.end(), std::back_inserter(Vargsai),[](const auto &stud) {
        return stud.gal >= 5;
    });

    auto border = std::partition(Grupe.begin(),Grupe.end(),[](const Studentas &stud){
        return stud.gal >= 5;
    });
    Grupe.erase(border, Grupe.end());
    cout << irasu_sk << " dydzio saraso dalijimo i dvi grupes, taikant 3 STRATEGIJA, laikas: " << t.elapsed() << " s\n";

    Spausdinimas(Grupe, 3);
    Spausdinimas(Vargsai, 3);
}

void Paskirstymas_vector_3_strategija(vector <Studentas> &Grupe, const int &irasu_sk) {
    Timer t;
    
    vector <Studentas> Vargsai;
    Vargsai.reserve(irasu_sk);

    std::remove_copy_if(Grupe.begin(), Grupe.end(), std::back_inserter(Vargsai),[](const auto &stud) {
        return stud.gal >= 5;
    });

    Vargsai.shrink_to_fit();

    auto new_end = std::remove_if(Grupe.begin(), Grupe.end(), [](const Studentas &stud) {
        return stud.gal < 5;
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

void Testavimas_list(const int &irasu_sk, list <Studentas>& Grupe) {
    Paskirstymas_list_1_strategija(Grupe, irasu_sk);
    Paskirstymas_list_2_strategija(Grupe, irasu_sk);
    Paskirstymas_list_3_strategija(Grupe, irasu_sk);
}

void Testavimas(const int &irasu_sk) {
    vector <Studentas> Grupe_vector;
    Grupe_vector.reserve(irasu_sk);
    cout << "\nNuskaitomi " << irasu_sk << " dydzio duomenys..." << endl;
    Failo_nuskaitymas(Grupe_vector, irasu_sk);
    list <Studentas> Grupe_list(Grupe_vector.size());
    std::copy(Grupe_vector.begin(), Grupe_vector.end(), Grupe_list.begin());

    cout << "Pradedamas testavimas su " << irasu_sk << " irasu failu!\n";
    Testavimas_vector(irasu_sk, Grupe_vector);
    cout << endl;
    Testavimas_list(irasu_sk, Grupe_list);
    Grupe_vector.clear();
    Grupe_list.clear();
}
