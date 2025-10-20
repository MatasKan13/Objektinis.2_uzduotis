#include "mylib.h"

double Mediana(vector <int> vekt) {
    int n = vekt.size();
    double med;
    sort(vekt.begin(), vekt.end());
    if (n % 2 == 0) {
        med = double(vekt[n/2] + vekt[n/2 - 1]) / 2.0;
    } else {
        med = vekt[n/2];
    }
    return(med);
}

Studentas Balo_skaiciavimas(Studentas stud) {
    int suma = 0, n = stud.paz.size();
    for (int p : stud.paz) {
        suma+=p;
    }
    stud.galVid = 0.4 * double(suma)/double(n) + 0.6 * stud.egz;
    stud.galMed = 0.4 * Mediana(stud.paz) + 0.6 * stud.egz;
    if (stud.galVid >= 5) {
        stud.islaike = true;
    } else {
        stud.islaike = false;
    }
    return stud;
}

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

char Rikiavimo_tipas() {
    char rik;
    cout << "Pasirinkite, pagal ka norite isrikiuoti duomenis:" << endl;
    cout << "[A] pavardes\t[B] vardus\t[C] galutini bala pagal vidurki\t [D] galutini bala pagal mediana" << endl; cin >> rik;
    rik = Iv_raid_patikra(rik, "abcd");
    return rik;
}

pair <string, int> Failo_pasirinkimas() {
    string ivesties_pav;
    char f_tip, rik;
    cout << "Pasirinkite, kokio studentu skaiciaus faila tikrinsite:\n[A] 1.000\t[B] 10.000\t[C] 100.000\t[D] 1.000.000\t[E] 10.000.000\n";
    cin >> f_tip;
    f_tip = Iv_raid_patikra(f_tip, "abcde");
    rik = Rikiavimo_tipas();
    map <char, int> tipai = {{'a', 1000}, {'b', 10000}, {'c', 100000}, {'d', 1000000}, {'e', 10000000}};
    int irasu_sk = tipai[f_tip];
    ivesties_pav = "stud" + to_string(irasu_sk) + ".txt";
    return {ivesties_pav, irasu_sk};
}

vector <Studentas> Rikiavimas_vector(vector <Studentas> Rikiuojamas, char rik) {
    sort(std::execution::par, Rikiuojamas.begin(), Rikiuojamas.end(), [rik](const Studentas &a, const Studentas &b) {
        if (rik == 'a') {
            return a.pavarde < b.pavarde;
        } else if (rik == 'b') {
            return a.vardas < b.vardas;
        } else if (rik == 'c') {
            return a.galVid > b.galVid;
        } else {
            return a.galMed > b.galMed;
        }
    });
    return Rikiuojamas;
}

list <Studentas> Rikiavimas_list(list <Studentas> Rikiuojamas, char rik) {
    Rikiuojamas.sort([rik](const Studentas &a, const Studentas &b){
        if (rik == 'a') {
            return a.pavarde < b.pavarde;
        } else if (rik == 'b') {
            return a.vardas < b.vardas;
        } else if (rik == 'c') {
            return a.galVid > b.galVid;
        } else {
            return a.galMed > b.galMed;
        }
    });
    return Rikiuojamas;
}
