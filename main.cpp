#include "mylib.h"

int main() {
    char ar_f, rik, sp, rodinys;
    string ivesties_pav;
    cout << "Pasirinkite, ar norite studentu duomenis irasyti patys [P], ar nuskaityti is failo [F]? "; cin >> ar_f;
    ar_f = Iv_raid_patikra(ar_f, "pf");
    if (ar_f == 'p') {
            vector <Studentas> Vargsai, Moksliukai;
            Ivestis_ranka(Vargsai, Moksliukai);
            rik = Rikiavimo_tipas();
            Moksliukai = Rikiavimas(Moksliukai, rik);
            Vargsai = Rikiavimas(Vargsai, rik);
            Ekrano_isvestis(Vargsai, Moksliukai);
        }
    else {
        cout << "Ar norite atlikti spartos tikrinima? [T/N] "; cin >> sp;
        sp = Iv_raid_patikra(sp, "tn");
        if (sp == 'n') {   
            vector <Studentas> Vargsai, Moksliukai;
            cout << "Iveskite failo pavadinima: "; cin >> ivesties_pav;
            Failo_nuskaitymas_paprastas(Moksliukai, Vargsai, ivesties_pav);
            rik = Rikiavimo_tipas();
            Moksliukai = Rikiavimas(Moksliukai, rik);
            Vargsai = Rikiavimas(Vargsai, rik);
            cout << "Kaip skaiciuoti galutini ivertinima? Pasirinkite: su vidurkiu [V], su mediana [M] ar abu [A]? "; cin >> rodinys;
            rodinys = Iv_raid_patikra(rodinys, "vma");
            // Kopijavimo konstruktoriaus ir priskyrimo operatoriaus veikimo pavyzdys:
            // Studentas stud {Moksliukai[0]}, stud3;
            // cout << "stud: " << stud.vardas() << " " << stud.pavarde() << " " << stud.balasVid() << '\n';
            // Studentas stud2 = stud;
            // cout << "stud2: " << stud2.vardas() << " " << stud2.pavarde() << " " << stud2.balasVid() << '\n';
            // cin >> stud3;
            // cout << "stud3: " << stud3;
            Spausdinimas_paprastas(Vargsai, rodinys);
            Spausdinimas_paprastas(Moksliukai, rodinys);
        }
        else {
            Testavimas(1'000);
            Testavimas(10'000);
            Testavimas(100'000);
            Testavimas(1'000'000);
            Testavimas(10'000'000);
        }
    }
}
