#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

struct Dalykas // Programoje naudokite strukturos duomenu tipo masyva apklaustu mokiniu duomenims saugoti
{
    std::string pavadinimas{};
    std::vector <std::string> mokiniai;
    int pasirinktas{};
};

void skaityti_duomenis(std::vector <Dalykas>& dalykai);
float vidurkis(std::ifstream &fin);
void atnaujinti_duomenis(std::vector <Dalykas>& dalykai, const std::string pavadinimas, const std::string vardas);
void surikiuoti_duomenis(std::vector <Dalykas>& dalykai);
void spausdinti_duomenis(std::vector <Dalykas> dalykai);

int main()
{
    std::vector <Dalykas> dalykai;

    skaityti_duomenis(dalykai);

    surikiuoti_duomenis(dalykai);

    spausdinti_duomenis(dalykai);

    return 0;
}

void skaityti_duomenis(std::vector <Dalykas>& dalykai)
{
    std::ifstream fin;
    fin.open("U2.txt");

    int m{}; // Mokiniu skaicius
    fin >> m;
    for(int i = 0; i < m; ++i)
    {
        std::string vardas{};
        std::string pavadinimas{};

        fin >> vardas;
        fin >> pavadinimas;

        if(vidurkis(fin) >= 9)
        {
            atnaujinti_duomenis(dalykai, pavadinimas, vardas);
        }
    }
}
float vidurkis(std::ifstream &fin)
{
    int pazymiu_skaicius{};
    fin >> pazymiu_skaicius;
    int suma{};
    for(int i = 0; i < pazymiu_skaicius; ++i)
    {
        int temp{};
        fin >> temp;
        suma+=temp;
    }
    return suma/pazymiu_skaicius;
}

void atnaujinti_duomenis(std::vector <Dalykas>& dalykai, const std::string pavadinimas, const std::string vardas)
{
    int count{};

    for(int i = 0; i < dalykai.size(); ++i)
    {
        if(dalykai[i].pavadinimas.compare(pavadinimas) != 0) // Jeigu pavadinimai nesutampa
        {
            ++count;
        }
        else // Jeigu randame, pridedame duomenis
        {
            dalykai[i].pasirinktas++;
            dalykai[i].mokiniai.push_back(vardas);
            break;
        }
    }
    if(count == dalykai.size()) // Jeigu nesutapo su jokiu jau esanciu pavadinimu
    {
        // Sukuriame nauja struktura, ja push_backinam ant vektoriaus
        Dalykas temp{};
        temp.pavadinimas = pavadinimas;
        temp.mokiniai.push_back(vardas);
        ++temp.pasirinktas;
        dalykai.push_back(temp);
    }
}
void surikiuoti_duomenis(std::vector <Dalykas>& dalykai)
{ //Sukurkite ir parasykite funkcija, kuri surikiuoja populiariausiu dalyku sarasa.
    for(int i = 0; i < dalykai.size(); ++i) // Surikiuojame populiauriausias pamokas, Bubble Sort algoritmas
    {
        for(int j = 0; j < dalykai.size()-1; ++j)
        {
            if(dalykai.at(j).pasirinktas < dalykai.at(j+1).pasirinktas)
            {
                std::swap(dalykai.at(j), dalykai.at(j+1));
            }
        }
    }

    for(int i = 0; i < dalykai.size(); ++i) // Surikiuojame vienodo populiarumo dalykus, abeceles tvarka.
    {
        for(int j = 0; j < dalykai.size() - 1; ++j)
        {
            if( dalykai.at(j).pasirinktas == dalykai.at(j+1).pasirinktas
               &&
               dalykai.at(j).pavadinimas.at(0) > dalykai.at(j+1).pavadinimas.at(0) // Palyginam pirma raide
               )
            {
                std::swap(dalykai.at(j), dalykai.at(j+1));
            }
        }
    }
}
void spausdinti_duomenis(std::vector <Dalykas> dalykai)
{
    std::ofstream fout;
    fout.open("U2rez.txt");
    if(dalykai.empty())
    {
        // Nera ne vieno dalyko, kuri pasirinkusiu mokiniu pazymiu vidurkis ne mazesnis kaip 9.
        fout << "Neatitinka vidurkis";
    }
    else
    {
        for(int i = 0; i < dalykai.size(); ++i)
            {
                fout << dalykai.at(i).pavadinimas << " " << dalykai.at(i).pasirinktas << std::endl;
                for(auto mokinys: dalykai[i].mokiniai)
                    {
                        fout << mokinys << std::endl;
                    }
            }
    }

}
