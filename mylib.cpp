#include "mylib.h"

vector <Studentas> Generuoti_vector(const int &stud_sk) {
    vector <Studentas> Grupe;
    Grupe.reserve(stud_sk);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution dist(1,10);

    for (int i = 1; i<=stud_sk; i++) {
        Studentas temp;
        int suma = 0;
        temp.vardas = "Vardas" + to_string(i);
        temp.pavarde = "Pavarde" + to_string(i);
        for (int j = 1; j <= 5; j++) {
            int p = dist(gen);
            suma += p;
            temp.paz.push_back(p);
        }
        temp.egz = dist(gen);
        temp.gal = 0.4 * (suma*1.0 / 5.0) + 0.6 * temp.egz;
        Grupe.push_back(temp);
    }
    return Grupe;
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
}

void Paskirstymas_list_3_strategija(list <Studentas> &Grupe, const int &irasu_sk) {
    Timer t;

    list <Studentas> Vargsai;

    std::remove_copy_if(Grupe.begin(), Grupe.end(), std::back_inserter(Vargsai),[](const auto &stud) {
        return stud.gal < 5;
    });

    auto border = std::partition(Grupe.begin(),Grupe.end(),[](const Studentas &stud){
        return stud.gal >= 5;
    });
    Grupe.erase(border, Grupe.end());
    cout << irasu_sk << " dydzio saraso dalijimo i dvi grupes, taikant 3 STRATEGIJA, laikas: " << t.elapsed() << " s\n";
}

void Paskirstymas_vector_3_strategija(vector <Studentas> &Grupe, const int &irasu_sk) {
    Timer t;
    
    vector <Studentas> Vargsai;
    Vargsai.reserve(irasu_sk);

    std::remove_copy_if(Grupe.begin(), Grupe.end(), std::back_inserter(Vargsai),[](const auto &stud) {
        return stud.gal < 5;
    });

    auto new_end = std::remove_if(Grupe.begin(), Grupe.end(), [](const Studentas &stud) {
        return stud.gal < 5;
    });
    Grupe.erase(new_end, Grupe.end());

    cout << irasu_sk << " dydzio vektoriaus dalijimo i dvi grupes, taikant 3 STRATEGIJA, laikas: " << t.elapsed() << " s\n";
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
    Timer t;
    cout << "\nGeneruojami " << irasu_sk << " dydzio duomenys..." << endl;
    vector <Studentas> Grupe_vector;
    Grupe_vector.reserve(irasu_sk);
    Grupe_vector = Generuoti_vector(irasu_sk);
    list <Studentas> Grupe_list(Grupe_vector.size());
    std::copy(Grupe_vector.begin(), Grupe_vector.end(), Grupe_list.begin());
    cout << "Pradedamas testavimas su " << irasu_sk << " irasu failu!\n";
    Testavimas_vector(irasu_sk, Grupe_vector);
    cout << endl;
    Testavimas_list(irasu_sk, Grupe_list);
    Grupe_vector.clear();
    Grupe_list.clear();
}
