#include "mylib.h"
#include "timer.h"

int main() {
    char kont, rik;
    string ivesties_pav;
    cout << "Sveiki!" << endl << "Pasirinkite, ar norite studentu duomenis laikyti vektoriuje [V], ar sarase [S]? "; cin >> kont;
    kont = Iv_raid_patikra(kont, "vs");
    if (kont == 'v') {
        vector <Studentas> Grupe, Vargsai, Moksliukai;
        pair <string, int> duom = Failo_pasirinkimas();
        ivesties_pav = duom.first;
        int irasu_sk = duom.second;

        Timer t, visas;
        Failo_nuskaitymas(Grupe, ivesties_pav);
        cout << "Failo is " << irasu_sk << " irasu nuskaitymo laikas: " << t.elapsed() << " s\n";

        t.reset();
        Paskirstymas(Grupe,Moksliukai,Vargsai);
        cout << irasu_sk << " dalijimo i dvi grupes, isvalant pradini vektoriu, laikas: " << t.elapsed() << " s\n";

        t.reset();
        Moksliukai = Rikiavimas_vector(Moksliukai, rik);
        Vargsai = Rikiavimas_vector(Vargsai, rik);
        cout << irasu_sk << " irasu dvieju grupiu isrikiavimo su sort funkcija laikas: " << t.elapsed() << " s\n";

        t.reset();
        Spausdinimas(Vargsai);
        cout << irasu_sk << " irasu vargseliu irasymo i faila laikas: " << t.elapsed() << " s\n";

        t.reset();
        Spausdinimas(Moksliukai);
        cout << irasu_sk << " irasu kietiaku irasymo i faila laikas: " << t.elapsed() << " s\n\n";

        cout << irasu_sk << " irasu testo su VECTOR bendras laikas: " << visas.elapsed() << " s\n";
    }
    else {
        list <Studentas> Grupe, Vargsai, Moksliukai;
        pair <string, int> duom = Failo_pasirinkimas();
        ivesties_pav = duom.first;
        int irasu_sk = duom.second;

        Timer t, visas;
        Failo_nuskaitymas(Grupe, ivesties_pav);
        cout << "Failo is " << irasu_sk << " irasu nuskaitymo laikas: " << t.elapsed() << " s\n";

        t.reset();
        Paskirstymas(Grupe,Moksliukai,Vargsai);
        cout << irasu_sk << " dalijimo i dvi grupes, isvalant pradini sarasa, laikas: " << t.elapsed() << " s\n";

        t.reset();
        Moksliukai = Rikiavimas_list(Moksliukai, rik);
        Vargsai = Rikiavimas_list(Vargsai, rik);
        cout << irasu_sk << " irasu dvieju grupiu isrikiavimo su saraso sort metodu laikas: " << t.elapsed() << " s\n";

        t.reset();
        Spausdinimas(Vargsai);
        cout << irasu_sk << " irasu vargseliu irasymo i faila laikas: " << t.elapsed() << " s\n";

        t.reset();
        Spausdinimas(Moksliukai);
        cout << irasu_sk << " irasu kietiaku irasymo i faila laikas: " << t.elapsed() << " s\n\n";

        cout << irasu_sk << " irasu testo su LIST bendras laikas: " << visas.elapsed() << " s\n";
    }
}
