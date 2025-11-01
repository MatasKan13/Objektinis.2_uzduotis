**Matas Kantautas** <br>
**Vilniaus universiteto duomenų mokslo programa** <br>
**Objektinio programavimo 1 laboratorinis darbas**

**V0.1** <br>
1. Sukurta galutinio balo skaičiavimo sistema;
2. Sukurta galimybė pasirinkti skaičiuoti galutinį balą pagal vidurkį arba medianą;
3. Sukurtas atsitiktinių pažymių generavimas;
4. Sukurta galimybė nuskaityti duomenis iš .txt failo;
5. Pridėta išvestis į vartotojo nurodomą failą;
6. Pridėtas rezultatų rikiavimas pagal pavardę ir vardą.

**V0.2** <br>
1. Sukurta studentų duomenų generavimo programa (failai su atitinkamai 1000, 10000, 100000, 1000000, 10000000 eilučių duomenų);
2. Sukurtas studentų išskaidymas į išlaikiusius ir neišlaikiusius, šių grupių rezultatai pateikiami skirtinguose failuose;
3. Funkcijos ir struktūros perkeltos į atskirus failus;
4. Pridėta galimybė vartotojui pasirinkti parametrą, pagal kurį rikiuoti rezultatus;
5. Sukurta programos spartos analizė.

**V0.3** <br>
1. Pridėta galimybė įrašius duomenis ranka pamatyti objekto adresą atmintyje;
2. Pridėta galimybė duomenis talpinti ir std::list struktūroje;
3. Atlikta programos spartos analizė taikant std::vector ir std::list konteinerius. <br>

Analizės apžvalga: matuoti trys programos atlikimo etapai – visų studentų surūšiavimas į išlaikiusius ir neišlaikiusius, duomenų išrikiavimas pagal galutinį pažymį, rezultatų įrašymas į failus. Visi bandymai atlikti su failais, turinčiais 5 ND pažymius bei rikiavimas vykdomas pagal vidurkio reikšmes. Visi testai atlikti 5 kartus, jų vidurkius galite matyti lentelėse (duomenys pateikti sekundėmis).

Rezultatai:
<table>
  <caption><b>Surūšiavimas į dvi grupes</b></caption>
  <thead>
    <tr>
      <th>Įrašų skaičius</th>
      <th>Vector</th>
      <th>List</th>
      <th>Ar skirtumas bent 10%?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1.000</td>
      <td>0,0014</td>
      <td>0,0014</td>
      <td>-</td>
    </tr>
    <tr>
      <td>10.000</td>
      <td>0,0073</td>
      <td>0,0068</td>
      <td>-</td>
    </tr>
    <tr>
      <td>100.000</td>
      <td>0,0471</td>
      <td>0,071</td>
      <td>+</td>
    </tr>
    <tr>
      <td>1.000.000</td>
      <td>0,4304</td>
      <td>0,4971</td>
      <td>+</td>
    </tr>
    <tr>
      <td>10.000.000</td>
      <td>4,1767</td>
      <td>5,372</td>
      <td>+</td>
    </tr>
  </tbody>
</table>

<table>
  <caption><b>Išrikiavimas pagal galutinį balą</b></caption>
  <thead>
    <tr>
      <th>Įrašų skaičius</th>
      <th>Vector</th>
      <th>List</th>
      <th>Ar skirtumas bent 10%?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1.000</td>
      <td>0,0009</td>
      <td>0,0009</td>
      <td>-</td>
    </tr>
    <tr>
      <td>10.000</td>
      <td>0,0043</td>
      <td>0,0051</td>
      <td>-</td>
    </tr>
    <tr>
      <td>100.000</td>
      <td>0,0331</td>
      <td>0,0647</td>
      <td>+</td>
    </tr>
    <tr>
      <td>1.000.000</td>
      <td>0,3208</td>
      <td>0,8092</td>
      <td>+</td>
    </tr>
    <tr>
      <td>10.000.000</td>
      <td>4,1193</td>
      <td>11,1987</td>
      <td>+</td>
    </tr>
  </tbody>
</table>

<table>
  <caption><b>Įrašymas į failą</b></caption>
  <thead>
    <tr>
      <th>Įrašų skaičius</th>
      <th>Vector</th>
      <th>List</th>
      <th>Ar skirtumas bent 10%?</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1.000</td>
      <td>0,0101</td>
      <td>0,0148</td>
      <td>+</td>
    </tr>
    <tr>
      <td>10.000</td>
      <td>0,0359</td>
      <td>0,0385</td>
      <td>-</td>
    </tr>
    <tr>
      <td>100.000</td>
      <td>0,2087</td>
      <td>0,2386</td>
      <td>+</td>
    </tr>
    <tr>
      <td>1.000.000</td>
      <td>1,6276</td>
      <td>1,8461</td>
      <td>+</td>
    </tr>
    <tr>
      <td>10.000.000</td>
      <td>19,9074</td>
      <td>19,2783</td>
      <td>-</td>
    </tr>
  </tbody>
</table>

**Išvados**: Su nedideliais duomenų kiekiais abu konteineriai dirba apylygiai, tačiau nuo 100.000 įrašų matomas ryškus std::vector pranašumas prieš std::list (su viena išimtimi įrašyme į failus 10 mln. eilučių atveju). Didžiausias skirtumas matomas rikiavimo užduotyje, kurią vektorius atlieka net 2–3 kartus greičiau nei sąrašas.

Kompiuterio, su kuriuo atlikta analizė, parametrai: 1,2 GHz procesorius, 8 GB RAM, SSD 238 GB.

**V1.0** <br>
Atlikta studentų rūšiavimo į išlaikiusius ir neišlaikiusius spartos analizė, taikant 3 skirtingas strategijas:
* 1 strategija – ankstesnėje versijoje taikytas metodas – pradinio konteinerio Grupė skaidymas į du atskirus konteinerius Moksliukai ir Vargšai, paprastai iteruojant ir naudojant vektorių push_back() metodą;
* 2 strategija – iteravimas per konteinerį Grupė, išlaikiusius studentus paliekant konteineryje, o neišlaikiusius pašalinant ir įkeliant į konteinerį Vargšai. Viskas įvykdoma per vieną iteraciją. Algoritmai iš `<algorithm>` bibliotekos nenaudojami;
* 3 strategija – 2 strategija papildoma algoritmais iš `<algorithm>` bibliotekos, tikrinant, ar bus išvystyta greitesnė sparta; <br>

Rezultatai (duomenys lentelėje pateikiami sekundėmis; vidurkis išvestas atlikus 5 bandymus):

<table>
  <caption><b>Studentų išskaidymas į dvi dalis pagal strategiją ir konteinerį</b></caption>
  <thead>
    <tr>
      <th></th>
      <th colspan = "2">1</th>
      <th colspan = "2">2</th>
      <th colspan = "2">3</th>
    </tr>
    <tr>
      <th>Įrašų skaičius</th>
      <th>Vector</th>
      <th>List</th>
      <th>Vector</th>
      <th>List</th>
      <th>Vector</th>
      <th>List</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>1.000</td>
      <td>0,001</td>
      <td>0,0008</td>
      <td>0,0009</td>
      <td>0,0005</td>
      <td><b>0,0004</b></td>
      <td>0,0005</td>
    </tr>
    <tr>
      <td>10.000</td>
      <td>0,0025</td>
      <td>0,0032</td>
      <td><b>0,0017</b></td>
      <td>0,0019</td>
      <td>0,0018</td>
      <td>0,0022</td>
    </tr>
    <tr>
      <td>100.000</td>
      <td>0,0091</td>
      <td>0,026</td>
      <td><b>0,0066</b></td>
      <td>0,0078</td>
      <td>0,0083</td>
      <td>0,0178</td>
    </tr>
    <tr>
      <td>1.000.000</td>
      <td>0,0845</td>
      <td>0,2272</td>
      <td><b>0,0579</b></td>
      <td>0,0712</td>
      <td>0,0829</td>
      <td>0,01527</td>
    </tr>
    <tr>
      <td>10.000.000</td>
      <td>0,9757</td>
      <td>2,9958</td>
      <td>0,8691</td>
      <td><b>0,8333</b></td>
      <td>0,8725</td>
      <td>1,8701</td>
    </tr>
  </tbody>
</table>

**Išvados**: 2 strategija yra greičiausia su visais įrašų skaičiais išskyrus 1.000, t. y.  išmanus vienos iteracijos metodas buvo spartesnis net ir už algoritmus iš `<algorithm>` bibliotekos. Konteinerių atžvilgiu, vektorius pasirodė esantis spartesnis visose kategorijose išskyrus 10 mln. įrašų; vektoriaus veikimą ypač paspartino nuorodų (&) naudojimas ir išankstinis atminties rezervavimas su reserve() metodu. Vis dėlto didžiausio įrašų skaičiaus kategorijoje greičiausiai veikė sąrašas, kuris 10 mln. elementų perskirstydavo vidutiniškai per 0,8333 sekundės.

Naudojimosi instrukcija:
1. Įsitikinkite, kad kompiuteryje turite įdiegtus C++ kompiliatorių bei projekto generavimo įrankius cmake ir make, jei ne – įsidiekite;
2. Parsisiųskite failus main.cpp, mylib.cpp, mylib.h, timer.h ir CMakeLists.txt;
3. Pasirinkite aplanką, kuriame bus vykdomi kodo paleidimo veiksmai (toliau – DA (darbinis aplankas)). Į jį įkelkite failą CMakeLists.txt ir sukurkite aplankus „src“ bei „include“;
4. Į aplanką „src“ perkelkite visus projekto .cpp failus, į aplanką „include“ – visus projekto .h failus.
5. Per komandinę eilutę (terminalą) nueikite iki savo pasirinkto DA. Tuomet jame įvykdykite šias komandas: <br>
    5.1. mkdir build <br>
    5.2. cd build <br>
    5.3. cmake [-DCMAKE_BUILD_TYPE=Release] ..<br>
    5.4. cmake --build .<br>
6. Buvo sukurtas vykdomasis failas (v1_0.exe). Belieka jį pavykdyti, į komandinę eilutę parašant „v1_0.exe“.

Gero naudojimo!

**V1.1** <br>
1. Objektų laikymas struktūrose pakeistas klasėmis;
2. Atlikta struktūrų, klasių bei optimizavimo lygių įtakos vykdomojo failo (.exe) dydžiui bei programos spartai analizė. <br>

Analizės apžvalga:
Buvo matuojamas vykdomojo failo dydis kiekvienam optimizavimo lygiui bei struct ir class objektams. Matavimai atlikti su 100'000 ir 1'000'000 įrašų failais. Sparta matuota studentų išrūšiavimo į išlaikiusius ir neišlaikiusius užduotyje (taip pat, kaip ir v1.0).

Rezultatai:
