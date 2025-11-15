#include "mylib.h"
#include "studentas.h"

char Iv_raid_patikra(char ivestis, string raides) {
    bool tesiam = true;
    while (tesiam) {
        ivestis = tolower(ivestis);
        for (auto &raide : raides) {
            if (ivestis == raide) {
                tesiam = false;
                break;
            }
        }
        if (tesiam) {
            cout << "Neteisinga ivestis! Bandykite dar karta: "; cin >> ivestis;
        }
    }
    return(ivestis);
}

int Iv_paz_patikra(string ivestis, bool egzas) {
    bool tesiam = true;
    int paz;
    while (tesiam) {
        try {
            paz = stoi(ivestis); 
            for (int sk = 0; sk <=10; sk++) {
                if (egzas && sk == 0) {
                    continue;
                }
                if (paz == sk) {
                    tesiam = false;
                    break;
                }
            }
            if (tesiam) {
                cout << "Neteisinga ivestis! Bandykite dar karta: "; cin >> ivestis;
            }
        }
        catch(...) {
            cout << "Neteisinga ivestis! Bandykite dar karta: "; cin >> ivestis;
        }
    }
    return(paz);
}

Studentas Stud_ivestis(int sk){
    int laik_paz, n = 1, tempEgz;
    char testi, atsit;
    string tempVar, tempPav;
    vector <int> tempPaz;
    cout << "Kuo vardu " << sk+1 << "-asis studentas(-e)? "; cin >> tempVar;
    cout << "Kokia jo (jos) pavarde? "; cin >> tempPav;
    cout << "Ar noretumete sio studento pazymius sugeneruoti atsitiktinai? [T/N] "; cin >> atsit;
    atsit = Iv_raid_patikra(atsit, "tn");
    if (atsit == 't') {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution dist(1,10);
        while (true) {
            cout << "Generuojama..." << endl;
            int p = dist(gen);
            cout << "Sugeneruotas pazymys: " << p << endl;
            tempPaz.push_back(p);
            cout << "Ar norite toliau rasyti pazymius? [T/N] "; cin >> testi;
            testi = Iv_raid_patikra(testi, "tn");
            if (testi == 'n'){
                break;
            }
        }
        cout << "Generuojama..." << endl;
        tempEgz = dist(gen);
        cout << "Sugeneruotas egzamino ivertinimas: " << tempEgz << endl;
    }
    else {
        string egz_iv, paz_iv;
        cout << "Iveskite pazymius (baige iveskite 0)." << endl;
        while (true) {
            cout << n << "-asis pazymys: "; cin >> paz_iv;
            laik_paz = Iv_paz_patikra(paz_iv, 0);
            if (laik_paz == 0) {
                if (tempPaz.size() != 0) {
                    break;
                } else {
                    cout << "Prasome ivesti pazymiu!\n";
                }
            }
            else {
                tempPaz.push_back(laik_paz);
                n++;
            }
        }
        cout << "Koks egzamino ivertinimas? "; cin >> egz_iv;
        tempEgz = Iv_paz_patikra(egz_iv, 1);
    }
    Studentas stud{tempVar, tempPav, tempPaz, tempEgz};
    
    return(stud);
}

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

void Ekrano_isvestis(const vector <Studentas>& Vargsai, const vector <Studentas>& Moksliukai) {
    if(Moksliukai.size()!=0) {
        cout << "Islaike studentai:" << endl;
        cout << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(17) << left << "Galutinis (Vid.) " << setw(17) << left << "Galutinis (Med.)" << setw(17) << left << "Adresas atmintyje" << endl;
        cout << string(86,'-');
        for (const auto &Past : Moksliukai) {
            cout << endl << setw(15) << left << Past.vardas() << setw(20) << left << Past.pavarde() << setw(17) << left << fixed << setprecision(2) << Past.balasVid() << setw(17) << left << fixed << setprecision(2) << Past.balasMed() << setw(17) << left << &Past;
        }
    }
    else {
        cout << "Islaikiusiu studentu nera! :(";
    }
    cout << endl << endl;
    if(Vargsai.size()!=0) {
        cout << "Neislaike studentai:" << endl;
        cout << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(17) << left << "Galutinis (Vid.) " << setw(17) << left << "Galutinis (Med.)" << setw(17) << left << "Adresas atmintyje" << endl;
        cout << string(86,'-');
        for (const auto &Past : Vargsai) {
            cout << endl << setw(15) << left << Past.vardas() << setw(20) << left << Past.pavarde() << setw(17) << left << fixed << setprecision(2) << Past.balasVid() << setw(17) << left << fixed << setprecision(2) << Past.balasMed() << setw(17) << left << &Past;
        }
    }
    else {
        cout << "Neislaikiusiu studentu nera! :)";
    }
    cout << endl;
}

void Ivestis_ranka(vector <Studentas> &Vargsai, vector <Studentas> &Moksliukai) {
    int m;
    char rik;
    cout << "Kiek studentu grupeje? "; cin >> m;
    for (auto i = 0; i < m; i++) {
        Studentas laik;
        laik = Stud_ivestis(i);
        if (laik.balasVid() >= 5) {
            Moksliukai.push_back(laik);
        }
        else {
            Vargsai.push_back(laik);
        }
    }
}
char Rikiavimo_tipas() {
    char rik;
    cout << "Pasirinkite, pagal ka norite isrikiuoti duomenis:" << endl;
    cout << "[A] pavardes\t[B] vardus\t[C] galutini bala pagal vidurki\t [D] galutini bala pagal mediana" << endl; cin >> rik;
    rik = Iv_raid_patikra(rik, "abcd");
    return rik;
}

vector <Studentas> Rikiavimas(vector <Studentas> Rikiuojamas, char rik) {
    sort(Rikiuojamas.begin(), Rikiuojamas.end(), [rik](const Studentas &a, const Studentas &b) {
        if (rik == 'a') {
            return a.pavarde() < b.pavarde();
        } else if (rik == 'b') {
            return a.vardas() < b.vardas();
        } else if (rik == 'c') {
            return a.balasVid() > b.balasVid();
        } else {
            return a.balasMed() > b.balasMed();
        }
    });
    return Rikiuojamas;
}

string Failo_patikra(string failo_pav) {
    while (true) {
        ifstream in(failo_pav);
        if(in.fail()) {
            cout << "Failo pavadinimas neteisingas! Bandykite dar karta: "; cin >> failo_pav;
        }
        else {
            in.close();
            break;
        }
    }
    return failo_pav;
}

void Failo_nuskaitymas_paprastas(vector <Studentas> &Moksliukai, vector <Studentas>& Vargsai, string failo_pav) {
    failo_pav = Failo_patikra(failo_pav);
    cout << "Puiku! Nuskaitomas failas..." << endl;
    stringstream buferis;
    ifstream in(failo_pav);
    buferis << in.rdbuf();
    in.close();
    string stulp;
    getline(buferis, stulp);
    while (!buferis.eof()) {
        string eil, tempVar, tempPav;
        int pazymys, tempEgz;
        vector <int> tempPaz;
        getline(buferis, eil);
        istringstream srautas(eil);
        srautas >> tempVar >> tempPav;
        while(srautas >> pazymys) {
            tempPaz.push_back(pazymys);
        }
        tempEgz = tempPaz.back();
        tempPaz.pop_back();
        Studentas stud{tempVar, tempPav, tempPaz, tempEgz};
        if (stud.balasVid() >= 5) {
            Moksliukai.push_back(stud);
        }
        else {
            Vargsai.push_back(stud);
        }
    }
}


void Spausdinimas_paprastas(const vector <Studentas>& Spausd_gr, char rodinys) {
    stringstream ss;
    if (rodinys == 'v') {
        ss << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(16) << left << "Galutinis (Vid.)" << endl;
        ss << string(51,'-');
        for (const auto &Past : Spausd_gr) {
            ss << endl << setw(15) << left << Past.vardas() << setw(20) << left << Past.pavarde() << setw(16) << left << fixed << setprecision(2) << Past.balasVid();
        }
    } else if (rodinys == 'm') {
        ss << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(16) << left << "Galutinis (Med.)" << endl;
        ss << string(51,'-');
        for (const auto &Past : Spausd_gr) {
            ss << endl << setw(15) << left << Past.vardas() << setw(20) << left << Past.pavarde() << setw(16) << left << fixed << setprecision(2) << Past.balasMed();
        }
    } else if (rodinys == 'a') {
        ss << setw(15) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(17) << left << "Galutinis (Vid.) " << setw(16) << left << "Galutinis (Med.)" << endl;
        ss << string(68,'-');
        for (const auto &Past : Spausd_gr) {
            ss << endl << setw(15) << left << Past.vardas() << setw(20) << left << Past.pavarde() << setw(17) << left << fixed << setprecision(2) << Past.balasVid() << setw(16) << left << fixed << setprecision(2) << Past.balasMed();
        }
    }
    if (Spausd_gr[0].balasVid() >= 5) {
        ofstream out("kietiakai.txt");
        out << ss.str();
        out.close();
    } else {
        ofstream out("nuskriaustukai.txt");
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
        if (stud.balasVid() >= 5) {
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

void Paskirstymas_list_1_strategija(const list <Studentas> &Grupe, const int &irasu_sk) {
    Timer t;

    list <Studentas> Vargsai, Moksliukai;

    for (auto stud : Grupe) {
        if (stud.balasVid() >= 5) {
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

void Paskirstymas_vector_2_strategija(vector <Studentas> Grupe, const int &irasu_sk) {
    Timer t;
    vector <Studentas> Vargsai;
    Vargsai.reserve(irasu_sk);
    size_t newSize = 0;
    for (size_t i = 0; i<Grupe.size(); i++) {
        if(Grupe[i].balasVid() < 5) {
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

void Paskirstymas_list_2_strategija(list <Studentas> Grupe, const int &irasu_sk) {
    Timer t;
    
    list <Studentas> Vargsai;
    for (auto it = Grupe.begin(); it != Grupe.end();) {
        if (it->balasVid() < 5) {
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

void Paskirstymas_vector_3_strategija(vector <Studentas> &Grupe, const int &irasu_sk) {
    Timer t;
    
    vector <Studentas> Vargsai;
    Vargsai.reserve(irasu_sk);

    std::remove_copy_if(Grupe.begin(), Grupe.end(), std::back_inserter(Vargsai),[](const Studentas &stud) {
        return stud.balasVid() >= 5;
    });

    Vargsai.shrink_to_fit();

    auto new_end = std::remove_if(Grupe.begin(), Grupe.end(), [](const Studentas &stud) {
        return stud.balasVid() < 5;
    });
    Grupe.erase(new_end, Grupe.end());

    cout << irasu_sk << " dydzio vektoriaus dalijimo i dvi grupes, taikant 3 STRATEGIJA, laikas: " << t.elapsed() << " s\n";

    Spausdinimas(Grupe, 3);
    Spausdinimas(Vargsai, 3);
}

void Paskirstymas_list_3_strategija(list <Studentas> &Grupe, const int &irasu_sk) {
    Timer t;

    list <Studentas> Vargsai;

    std::remove_copy_if(Grupe.begin(), Grupe.end(), std::back_inserter(Vargsai),[](const auto &stud) {
        return stud.balasVid() >= 5;
    });

    auto border = std::partition(Grupe.begin(),Grupe.end(),[](const Studentas &stud){
        return stud.balasVid() >= 5;
    });
    Grupe.erase(border, Grupe.end());
    cout << irasu_sk << " dydzio saraso dalijimo i dvi grupes, taikant 3 STRATEGIJA, laikas: " << t.elapsed() << " s\n";

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
